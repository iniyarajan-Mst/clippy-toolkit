#import <UIKit/UIKit.h>
#import <UIKit/UIKit-Private.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <OCHook/OCHook.h>
#import <GraphicsServices/GraphicsServices.h>
#import "../HapticPro/HapticPro.h"

#include <substrate.h>
#include <notify.h>
#include <objc/runtime.h>

#define kSettingsChangeNotification "com.booleanmagic.rotationinhibitor.settingschange"
#define kSettingsFilePath "/User/Library/Preferences/com.booleanmagic.rotationinhibitor.plist"

static BOOL rotationEnabled;
static UIDeviceOrientation desiredOrientation;

#pragma mark Preferences

static void ReloadPreferences()
{
	NSDictionary *dict = [[NSDictionary alloc] initWithContentsOfFile:@kSettingsFilePath];
	if (dict == nil) {
		rotationEnabled = NO;
		desiredOrientation = UIDeviceOrientationPortrait;
	} else {
		id setting = [dict objectForKey:@"RotationEnabled"];
		if (setting)
			rotationEnabled = [setting boolValue];
		else
			rotationEnabled = NO;
		setting = [dict objectForKey:@"DesiredOrientation"];
		if (setting)
			desiredOrientation = (UIDeviceOrientation)[setting integerValue];
		else
			desiredOrientation = UIDeviceOrientationPortrait;
	}
	[dict release];
	if (!rotationEnabled) {
		/*GSEvent event;
		memset(&event, 0, sizeof(event));
		[[UIApplication sharedApplication] deviceOrientationChanged:&event];*/
		[[UIDevice currentDevice] setOrientation:desiredOrientation];
	}
	OCDebugLogSource(@"rotationEnabled=%s", (rotationEnabled)?"YES":"NO");
}

static void PreferencesCallback(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo)
{
	ReloadPreferences();
}

#pragma mark SBSettings Toggle

@interface UIApplication (RotationInhibitor)
+ (void)_dismissRotationInhibitorFromTimer:(NSTimer *)timer;
@end

@implementation UIApplication (RotationInhibitor)
+ (void)_dismissRotationInhibitorFromTimer:(NSTimer *)timer
{
	UIActionSheet *actionSheet = [timer userInfo];
	[actionSheet dismissWithClickedButtonIndex:0 animated:YES];
}
@end

BOOL isCapable()
{
	return YES;
}

BOOL isEnabled()
{
	return rotationEnabled;
}

BOOL getStateFast()
{
	return rotationEnabled;
}

float getDelayTime()
{
	return 0.0f;
}

void setState(BOOL enable)
{
	NSMutableDictionary *dict = [[NSMutableDictionary alloc] initWithContentsOfFile:@kSettingsFilePath];
	if (dict == nil)
		dict = [[NSMutableDictionary alloc] init];
	[dict setObject:[NSNumber numberWithBool:enable] forKey:@"RotationEnabled"];
	[dict writeToFile:@kSettingsFilePath atomically:YES];
	[dict release];
	notify_post(kSettingsChangeNotification);
}

static inline UIWindow *SBSettingsWindow()
{
	UIApplication *app = [UIApplication sharedApplication];
	for (UIWindow *window in [app windows]) {
		if ([window respondsToSelector:@selector(getCurrentTheme)])
			return window;
	}
	return [app keyWindow];
}

static inline NSString *OrientationTitle()
{
	switch (desiredOrientation) {
		case UIDeviceOrientationPortrait:
			return @"Portrait";
		case UIDeviceOrientationPortraitUpsideDown:
			return @"Portrait Upside Down";
		case UIDeviceOrientationLandscapeLeft:
			return @"Landscape Left";
		case UIDeviceOrientationLandscapeRight:
			return @"Landscape Right";
		default:
			return @"Unknown Orientation";
	}
}

void invokeHoldAction()
{
	HPPerformHapticFeedback(HPHapticFeedbackTypeRepeated);
	desiredOrientation--;
	if (desiredOrientation == UIDeviceOrientationUnknown)
		desiredOrientation = UIDeviceOrientationLandscapeRight;
	NSMutableDictionary *dict = [[NSMutableDictionary alloc] initWithContentsOfFile:@kSettingsFilePath];
	if (dict == nil)
		dict = [[NSMutableDictionary alloc] init];
	[dict setObject:[NSNumber numberWithInteger:desiredOrientation] forKey:@"DesiredOrientation"];
	[dict writeToFile:@kSettingsFilePath atomically:YES];
	[dict release];
	notify_post(kSettingsChangeNotification);
	// Show action sheet
	UIActionSheet *actionSheet = [[UIActionSheet alloc] initWithTitle:OrientationTitle() delegate:nil cancelButtonTitle:nil destructiveButtonTitle:nil otherButtonTitles:nil];
	[actionSheet setActionSheetStyle:UIBarStyleBlackTranslucent];
	[actionSheet setDimsBackground:NO];
	[actionSheet showInView:SBSettingsWindow()];
	[NSTimer scheduledTimerWithTimeInterval:1.5f target:[UIApplication class] selector:@selector(_dismissRotationInhibitorFromTimer:) userInfo:actionSheet repeats:NO];
	[actionSheet release];
}

#define OverrideOrientation(superValue) \
	(rotationEnabled)?superValue:desiredOrientation

#pragma mark GraphicsServices

MSHook(UIDeviceOrientation, GSEventDeviceOrientation, GSEvent *event)
{
	return OverrideOrientation(_GSEventDeviceOrientation(event));
}

#pragma mark UIDevice

OCReplacement(UIDeviceOrientation, UIDevice, orientation){	return OverrideOrientation(OCSuper(UIDevice, orientation));}

#pragma mark UIHardwareOCClassReplacement(UIDeviceOrientation, UIHardware, deviceOrientation, BOOL something){
	return OverrideOrientation(OCSuper(UIHardware, deviceOrientation, something));}

#pragma mark Initialization

void ToggleInit()
{
	NSAutoreleasePool *pool = [NSAutoreleasePool new];
	ReloadPreferences();
	CFNotificationCenterAddObserver(
		CFNotificationCenterGetDarwinNotifyCenter(), //center
		NULL, // observer
		PreferencesCallback, // callback
		(CFStringRef)@kSettingsChangeNotification, // name
		NULL, // object
		CFNotificationSuspensionBehaviorHold
	);

	// GraphicsServices
	MSHookFunction(&GSEventDeviceOrientation, &$GSEventDeviceOrientation, (void **)&_GSEventDeviceOrientation);

	// UIDevice	OCWithClass(OCClass(UIDevice)) {		OCHook(orientation, UIDevice, orientation);	}	OCCatchNilClass {		OCDebugLog(@"Could not load class: UIDevice");	}
		// UIHardware	OCWithClass(OCMetaclass(UIHardware)) {		OCHook(deviceOrientation:, UIHardware, deviceOrientation);	}	OCCatchNilClass {		OCDebugLog(@"Could not load class: UIHardware");	}
	
	[pool release];
}

