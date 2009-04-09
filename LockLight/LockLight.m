#import <UIKit/UIKit.h>
#import <UIKit/UIKit-Private.h>
#import <OCHook/OCHook.h>
#import <GraphicsServices/GraphicsServices.h>
#import <SpringBoard/SpringBoard.h>

#include <objc/runtime.h>

static UIWindow *whiteWindow;

static float previousBacklight;

static float previousDimDuration;
static SBAwayController *awayController;

#pragma mark SBAwayController

OCReplacement(void, SpringBoard, _menuButtonWasHeld)
{
	if (whiteWindow == nil) {
		if ([self isLocked]) {
			// Show Window
			whiteWindow = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
			[whiteWindow setBackgroundColor:[UIColor whiteColor]];
			[whiteWindow makeKeyAndVisible];
			[whiteWindow setWindowLevel:1102.0f];
			// Get Previous Backlight
			NSDictionary *springboardSettings = [NSDictionary dictionaryWithContentsOfFile:@"/var/mobile/Library/Preferences/com.apple.springboard.plist"];
			id setting = [springboardSettings objectForKey:@"SBBacklightLevel2"];
			if (setting)
				previousBacklight = [setting floatValue];
			else {
				setting = [springboardSettings objectForKey:@"SBBacklightLevel"];
				if (setting)
					previousBacklight = [setting floatValue];
				else
					previousBacklight = 0.5f;
			}
			// Cancel Dim timer
			[awayController cancelDimTimer];
			// Turn on screen
			[self undim];
			// Set Backlight
			[self setBacklightLevel:1.0f];
		}
	}
	OCSuper(SpringBoard, _menuButtonWasHeld);
}

OCReplacement(void, SpringBoard, menuButtonDown, GSEvent *gsEvent)
{
	if (whiteWindow) {
		// Hide Window
		[whiteWindow setHidden:YES];
		[whiteWindow release];
		whiteWindow = nil;
		// Return Backlight to previous state
		[self setBacklightLevel:previousBacklight];
		// Reenable Dim Timer on Away Controller
		[awayController restartDimTimer:previousDimDuration];
	}
	OCSuper(SpringBoard, menuButtonDown, gsEvent);
}

OCReplacement(void, SpringBoard, lockButtonDown, GSEvent *gsEvent)
{
	if (whiteWindow) {
		// Hide Window
		[whiteWindow setHidden:YES];
		[whiteWindow release];
		whiteWindow = nil;
		// Return Backlight to previous state
		[self setBacklightLevel:previousBacklight];
		// Reenable Dim Timer on Away Controller
		[awayController restartDimTimer:previousDimDuration];
	}
	OCSuper(SpringBoard, lockButtonDown, gsEvent);
}

#pragma mark SBAwayController

OCReplacement(void, SBAwayController, restartDimTimer, float duration)
{
	previousDimDuration = duration;
	if (awayController != self) {
		[awayController release];
		awayController = [self retain];
	}
	OCSuper(SBAwayController, restartDimTimer, duration);
}

#pragma mark Initialization

void LockLightInit()
{
	OCAutoreleasePoolForScope();

	// SpringBoard
	OCWithClass(OCLateClass(SpringBoard)) {
		OCHook(_menuButtonWasHeld, SpringBoard, _menuButtonWasHeld);
		OCHook(menuButtonDown:, SpringBoard, menuButtonDown);
		OCHook(lockButtonDown:, SpringBoard, lockButtonDown);
	}
	OCCatchNilClass {
		OCDebugLog(@"Could not load class: SpringBoard");
	}
	
	// SBAwayController
	OCWithClass(OCLateClass(SBAwayController)) {
		OCHook(restartDimTimer:, SBAwayController, restartDimTimer);
	}
	OCCatchNilClass {
		OCDebugLog(@"Could not load class: SBAwayController");
	}	
}

