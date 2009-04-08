#import <UIKit/UIKit.h>
#import <GraphicsServices/GraphicsServices.h>

@interface UIApplication (Private)
- (BOOL)_useLegacyEventSystem;
- (void)applicationDidResume;
- (void)applicationDidResumeFromUnderLock;
- (void)applicationDidResumeForEventsOnly;

// GSEvents
- (unsigned int)_portForEvent:(GSEvent *)gsEvent;

- (void)applicationStarted:(GSEvent *)gsEvent;
- (void)applicationSuspended:(GSEvent *)gsEvent;
- (void)applicationSuspendedSettingsUpdated:(GSEvent *)gsEvent;
- (void)applicationExited:(GSEvent *)gsEvent;
- (void)anotherApplicationFinishedLaunching:(GSEvent *)gsEvent;
- (void)quitTopApplication:(GSEvent *)gsEvent;
- (void)applicationSuspend:(GSEvent *)gsEvent;
- (void)_sendApplicationSuspend:(GSEvent *)gsEvent;
- (void)applicationResume:(GSEvent *)gsEvent;
- (void)applicationShowHideSettings:(GSEvent *)gsEvent;
- (void)otherApplicationWillSuspend:(GSEvent *)gsEvent;

- (void)lockButtonDown:(GSEvent *)gsEvent;
- (void)lockButtonUp:(GSEvent *)gsEvent;

- (void)headsetButtonDown:(GSEvent *)gsEvent;
- (void)headsetButtonUp:(GSEvent *)gsEvent;

- (void)menuButtonDown:(GSEvent *)gsEvent;
- (void)menuButtonUp:(GSEvent *)gsEvent;

- (void)statusBarMouseDown:(GSEvent *)gsEvent;
- (void)statusBarMouseDragged:(GSEvent *)gsEvent;
- (void)statusBarMouseUp:(GSEvent *)gsEvent;

- (void)volumeChanged:(GSEvent *)gsEvent;

- (void)deviceOrientationChanged:(GSEvent *)gsEvent;

- (void)accessoryAvailabilityChanged:(GSEvent *)gsEvent;
- (void)_handleAccessoryKeyStateChanged:(GSEvent *)gsEvent;
- (void)accessoryKeyStateChanged:(GSEvent *)gsEvent;
- (void)accessoryEvent:(GSEvent *)gsEvent;

- (void)handleOutOfLineDataResponse:(GSEvent *)gsEvent;
- (void)handleOutOfLineDataRequest:(GSEvent *)gsEvent;

- (void)lockDevice:(GSEvent *)gsEvent;

- (BOOL)_isInteractionEvent:(GSEvent *)gsEvent;
- (BOOL)_isTouchEvent:(GSEvent *)gsEvent;
- (void)_dumpUIHierarchy:(GSEvent *)gsEvent;
- (void)_dumpScreenContents:(GSEvent *)gsEvent;
- (void)_processScriptEvent:(GSEvent *)gsEvent;
- (void)_recordEvent:(GSEvent *)gsEvent;

- (BOOL)handleEvent:(GSEvent *)gsEvent;
- (BOOL)handleEvent:(GSEvent *)gsEvent withNewEvent:(UIEvent *)event;
@end