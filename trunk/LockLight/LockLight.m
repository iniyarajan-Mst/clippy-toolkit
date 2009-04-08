#import <UIKit/UIKit.h>
#import <UIKit/UIKit-Private.h>
#import <OCHook/OCHook.h>
#import <GraphicsServices/GraphicsServices.h>
#import <SpringBoard/SpringBoard.h>

#include <objc/runtime.h>

static UIWindow *whiteWindow;
static float previousBacklight;

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
	}
	OCSuper(SpringBoard, menuButtonDown, gsEvent);
}

#pragma mark Initialization

void LockLightInit()
{
	NSAutoreleasePool *pool = [NSAutoreleasePool new];

	// SpringBoard
	OCWithClass(OCLateClass(SpringBoard)) {
		OCHook(_menuButtonWasHeld, SpringBoard, _menuButtonWasHeld);
		OCHook(menuButtonDown:, SpringBoard, menuButtonDown);
	}
	OCCatchNilClass {
		OCDebugLog(@"Could not load class: SpringBoard");
	}
	
	[pool release];
}

