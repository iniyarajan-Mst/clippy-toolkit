#import <UIKit/UIKit.h>
#import "SBAlert.h"

@class SBAlertItem, SBAwayItem, SBAwayModel, SBAwayView, SBSlidingAlertDisplay, SBUIController;

@interface SBAwayController : SBAlert
{
    SBUIController *_uiController;
    SBAwayModel *_model;
    SBAwayView *_awayView;
    NSTimer *_dimTimer;
    SBAwayItem *_clickedItem;
    unsigned int _isLocked:1;
    unsigned int _lockdownIsLocked:1;
    unsigned int _isDimmed:1;
    unsigned int _isDimming:1;
    unsigned int _orderedOutDimmed:1;
    unsigned int _frontDimmed:1;
    unsigned int _isBlocked:1;
    unsigned int _makingEmergencyCall:1;
    unsigned int _appRequestedPasscodeEntry:1;
    unsigned int _needToMakeEmergencyCall:1;
    unsigned int _isSyncing:1;
    unsigned int _relockAfterUnlock:1;
    unsigned int _wasLockedOrMakingEmergencyCallBeforeSync:1;
    unsigned int _wasDeviceLockedBeforeSync:1;
    unsigned int _willLockAfterDelay:1;
    unsigned int _showOverheatUI:1;
    unsigned int _lockBarTracking:1;
    NSDictionary *_nowPlayingInfo;
    SBSlidingAlertDisplay *_deviceUnlockDisplay;
    double _deviceLockBlockTime;
    double _deviceLockGracePeriodEndTimeInterval;
    NSTimeZone *_deviceLockGraceTimeZone;
    BOOL _devicePasscodeLoaded;
    NSString *_devicePasscode;
    NSMutableArray *_pendingAlertItems;
    SBAlertItem *_currentAlertItem;
    int _notifyLockStateToken;
    BOOL _notifyLockStateCurrentState;
    NSMutableDictionary *_awayViewPluginControllers;
    BOOL _smsMessageReceived;
    double _smsMessageReceivedTime;
    double _smsWakeTime;
    /*struct __CFDate*/void *_smsSoundWakeDate;
    NSTimer *_smsSoundWakeTimer;
    BOOL _smsPlayedSoundOnce;
}

+ (id)sharedAwayController;
+ (void)registerForAlerts;

- (void)_setLockdownLockState:(BOOL)lockdownLockState;
- (BOOL)_getLockdownLockState;

- (id)initWithUIController:(SBUIController *)UIController;

- (SBAwayModel *)awayModel;

- (void)applicationDidFinishLaunching:(id)something;
- (CGRect)alertWindowRect;
- (CGFloat)finalAlpha;
- (BOOL)undimsDisplay;
- (SBAwayView *)awayView;
- (id)alertDisplayViewWithSize:(CGSize)size;
- (void)alertDisplayWillBecomeVisible;
- (void)dealloc;
- (void)_releaseAwayView;
- (void)handleClickedItem:(id)item;
- (double)animateInDuration;
- (void)reactivatePendingAlertItems;
- (void)playLockSound;
- (void)_sendLockStateChangedNotification;

- (BOOL)showOverheatUI;
- (void)setShowOverheatUI:(BOOL)showOverheatUI;

- (void)_pendAlertItem:(id)something;
- (void)lock;
- (id)pendingAlertItems;
- (void)_unlockWithSound:(BOOL)sound;
- (void)unlockWithSound:(BOOL)sound;
- (void)unlockWithSound:(BOOL)sound alertDisplay:(id)alertDisplay;
- (void)_resetGracePeriod;
- (void)_timeChanged;
- (void)_setupDeviceLockGracePeriod;
- (void)loadPasscode;
- (id)devicePasscode;
- (BOOL)isPasswordProtected;
- (void)activationChanged:(id)fp8;
- (BOOL)isDeviceLocked;
- (void)setDeviceLocked:(BOOL)fp8;
- (void)applicationRequestedDeviceUnlock;
- (void)cancelApplicationRequestedDeviceLockEntry;
- (void)_clearBlockedState;
- (BOOL)isBlocked;
- (BOOL)isPermanentlyBlocked:(double *)outDouble;
- (void)noteSyncStateChanged;
- (BOOL)isSyncing;
- (void)noteResetRestoreStateChanged;
- (BOOL)isLocked;
- (BOOL)shouldShowLockStatusBarTime;
- (void)lockBarStartedTracking:(id)something;
- (void)lockBarStoppedTracking:(id)something;
- (void)resetAwayItems;
- (void)frontLockedAnimationFinished;
- (void)_frontForSuspendedLockAfterDelay;
- (void)frontForSuspendedLockAfterDelay:(float)delay;

- (BOOL)willLockAfterDelay;
- (void)setWillLockAfterDelay:(BOOL)willLockAfterDelay;

- (BOOL)shouldAnimateOtherDisplays;
- (void)printLockLog;
- (void)frontLocked:(BOOL)locked animate:(BOOL)animate automatically:(BOOL)automatically;
- (void)attemptUnlock;
- (BOOL)isAttemptingUnlock;
- (void)_finishedUnlockAttemptWithStatus:(BOOL)status;
- (BOOL)attemptDeviceUnlockWithPassword:(NSString *)password alertDisplay:(id)alertDisplay;
- (void)cancelDimTimer;
- (void)restartDimTimer:(float)something;
- (BOOL)isDimmed;
- (BOOL)moveAlertItemToAwayView:(id)something;
- (void)cleansePendingQueueOfAwayItems;
- (void)smsMessageReceived;
- (void)_unscheduleSMSWakeTime;
- (void)_setSMSWakeTime:(double)wakeTime;
- (void)_smsSoundWakeTimerFired:(NSTimer *)timer;
- (void)_wokeFromSleep;
- (void)dimTimerFired;
- (void)relockForButtonPress:(BOOL)press afterCall:(BOOL)afterCall;
- (void)relockForButtonPress:(BOOL)press afterCall:(BOOL)afterCall dimmed:(BOOL)dimmed;
- (void)allowIdleSleep;
- (void)preventIdleSleep;
- (void)preventIdleSleepForNumberOfSeconds:(float)time;
- (void)dimScreen:(BOOL)shouldDim;
- (void)_undimScreen;
- (void)undimScreen;
- (void)userEventOccurred;
- (Class)alertWindowClass;
- (BOOL)activate;
- (BOOL)deactivate;
- (BOOL)allowsStackingOfAlert:(id)something;
- (BOOL)allowsDoubleHeightStatusBar;
- (int)statusBarMode;
- (BOOL)animatesDismissal;
- (void)orderOut;
- (void)didFinishAnimatingOut;
- (void)animator:(id)animator stopAnimation:(id)stopAnimation;
- (void)clickItem:(id)item;
- (void)updateNowPlayingInfo:(id)something;
- (void)handleRequestedAlbumArtBytes:(char *)buffer length:(unsigned int)length;
- (void)updateClockFormat;
- (void)makeEmergencyCall;
- (void)_activateEmergencyCall;
- (void)emergencyCallWasDisplayed;
- (void)emergencyCallWasRemoved;
- (BOOL)isMakingEmergencyCall;
- (void)didAnimateLockKeypadIn;
- (void)didAnimateLockKeypadOut;
- (id)currentAlertItem;
- (void)pendOrDeactivateCurrentAlertItem;
- (BOOL)isCurrentAlertItemRinging;
- (BOOL)attemptSnoozeRingingAlertItem;
- (void)stopRingingAlertItem;
- (void)snoozeOrStopRingingAlertItem;
- (BOOL)activateAlertItem:(id)something;
- (BOOL)wantsToHandleAlert:(id)something;
- (void)deactivateAlertItem:(id)something;
- (void)updateInCallUI;
- (BOOL)isShowingMediaControls;
- (void)hideMediaControls;
- (BOOL)_disableShowingMediaControls;
- (BOOL)toggleMediaControls;
- (void)toggleShowsIMEIandICCID:(id)something;
- (BOOL)isAwayPluginViewVisible;
- (id)highestPriorityAwayPluginController;
- (id)springBoardPluginsDirectory;
- (void)enableLockScreenBundleWithName:(NSString *)name;
- (void)disableLockScreenBundleWithName:(NSString *)name;
- (void)disablePluginContainerNotification:(NSNotification *)notification;
- (BOOL)awayPluginControllerShouldAnimateOthersSuspension;
- (BOOL)handleMenuButtonTap;
- (BOOL)handleMenuButtonDoubleTap;
- (BOOL)handleMenuButtonHeld;
- (BOOL)isGestureDetectionEnabledFrom:(CGPoint)fromPoint to:(CGPoint)toPoint fingerCount:(NSUInteger)fingerCount;
- (void)gestureWasCompleted:(int)gesture fingerCount:(NSUInteger)fingerCount;

@end

