/**
 * This header is generated by class-dump-z 0.1-11o.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 */

#import "SpringBoard-Structs.h"
#import <UIKit/UIKit.h>

@class NSDictionary, NSString, NSMutableArray, NSNumberFormatter, SBApplication, SBDimmingWindow, NSTimer, SBUIController, NSURL;

@interface SpringBoard : UIApplication {
	SBUIController* _uiController;
	NSTimer* _menuButtonTimer;
	NSTimer* _lockButtonTimer;
	NSTimer* _idleTimer;
	NSTimer* _autoLockTimer;
	double _lastTimeIdleCausedDim;
	double _headsetButtonDownTime;
	GSEventRef _headsetDownEvent;
	SBDimmingWindow* _simulatedBlankingWindow;
	unsigned _headsetButtonClickCount : 8;
	unsigned _menuButtonClickCount : 8;
	unsigned _screenshotWasTaken : 1;
	unsigned _disableAutoDimming : 1;
	unsigned _nextLockUpLocks : 1;
	unsigned _poweringDown : 1;
	unsigned _autoDimmed : 1;
	unsigned _autoDimmedToBlack : 1;
	unsigned _headsetDownDelayedActionPerformed : 1;
	unsigned _nowPlayingAppIsPlaying : 1;
	int _UIOrientation;
	NSURL* _menuDoubleTapURL;
	int _notifyDontAnimateREOToken;
	int _notifyDontAllowMediaHUDToken;
	double _sampleSystemStartTime;
	NSDictionary* _startAppsCPUTimes;
	CFDictionaryRef _registeredSimpleRemoteAppToPriority;
	SBApplication* _registeredSimpleRemoteApp;
	SBApplication* _nowPlayingApp;
	NSString* _originatingOpenURLDisplayId;
	NSMutableArray* _disableNowPlayingHUDAssertionBundleIds;
	NSNumberFormatter* _decimalFormatter;
	NSNumberFormatter* _percentFormatter;
}
+(BOOL)registerForSystemEvents;
+(BOOL)rendersLocally;
-(void)_createLogFile;
-(void)writeLogFile;
-(BOOL)handleEvent:(GSEventRef)event;
-(void)updatePowerlog;
-(void)applicationDidFinishLaunching:(id)application;
-(void)appleIconViewRemoved;
-(void)timeZoneChanged;
-(void)wipeDeviceNow;
-(void)checkForExpiredPasscode;
-(void)showEDGEActivationFailureAlert:(id)alert reason:(id)reason;
-(void)showWiFiAlert;
-(void)showWiFiEnterpriseTrustAlert:(id)alert;
-(void)wifiManager:(id)manager scanCompleted:(id)completed;
-(void)userDefaultsDidChange:(id)userDefaults;
-(void)_testPhoneAlerts;
-(void)runFieldTestScript;
-(void)_significantTimeChange;
-(void)significantTimeChange;
-(void)batteryStatusDidChange:(id)batteryStatus;
-(void)simulateInCallStatusBar;
-(BOOL)shouldRunFieldTestScript;
-(BOOL)iapIsInExtendedMode;
-(BOOL)canShowLockScreenHUDControls;
-(BOOL)canShowNowPlayingHUD;
-(void)setAppDisabledNowPlayingHUD:(BOOL)hud bundleIdentifier:(id)identifier;
-(BOOL)allowMenuDoubleTap;
-(void)handleMenuDoubleTap;
-(void)_setMenuButtonTimer:(id)timer;
-(void)_setLockButtonTimer:(id)timer;
-(void)clearMenuButtonTimer;
-(void)_menuButtonWasHeld;
-(void)menuButtonDown:(GSEventRef)down;
-(void)menuButtonUp:(GSEventRef)up;
-(void)_handleMenuButtonEvent;
-(void)lockButtonDown:(GSEventRef)down;
-(void)lockButtonWasHeld;
-(void)extendButtonTimersForWake;
-(void)_powerDownNow;
-(void)_rebootNow;
-(void)reboot;
-(void)powerDown;
-(void)powerDownRequested:(id)requested;
-(void)powerDownCanceled:(id)canceled;
-(void)relaunchSpringBoard;
-(void)_relaunchSpringBoardNow;
-(void)_initLockButtonBearTrap;
-(void)_setLockButtonBearTrap;
-(void)_unsetLockButtonBearTrap;
-(void)_fireLockButtonBearTrap;
-(void)lockButtonUp:(GSEventRef)up;
-(void)_performDelayedHeadsetAction;
-(void)sendSimpleRemoteActionToRegisteredApp:(int)registeredApp;
-(void)sendSimpleRemoteActionToRegisteredApp:(int)registeredApp preferNowPlaying:(BOOL)playing;
-(void)_sendGSEventToSimpleRemoteRegisteredApp:(GSEventRef)simpleRemoteRegisteredApp;
-(void)_setDeferredHeadsetButtonDownEvent:(GSEventRef)event;
-(void)headsetButtonDown:(GSEventRef)down;
-(void)headsetButtonUp:(GSEventRef)up;
-(void)smsPrefsChanged;
-(void)ALSPrefsChanged:(id)changed;
-(id)parentalControlsDisabledApplications;
-(void)updateCapabilitiesAndIconVisibility;
-(void)loadDebuggingAndDemoPrefs;
-(void)debuggingAndDemoPrefsWereChanged;
-(void)clockFormatChanged;
-(void)autoLockPrefsChanged;
-(void)pinPolicyChanged;
-(void)ringerChanged:(int)changed;
-(void)accessoryAvailabilityChanged:(GSEventRef)changed;
-(void)accessoryKeyStateChanged:(GSEventRef)changed;
-(void)accessoryEvent:(GSEventRef)event;
-(unsigned)_portForEvent:(GSEventRef)event;
-(void)quitTopApplication:(GSEventRef)application;
-(void)applicationExited:(GSEventRef)exited;
-(void)anotherApplicationFinishedLaunching:(GSEventRef)launching;
-(void)applicationSuspend:(GSEventRef)suspend;
-(void)applicationSuspended:(GSEventRef)suspended;
-(void)applicationSuspendedSettingsUpdated:(GSEventRef)updated;
-(void)showAlertForUnhandledURL:(id)unhandledURL error:(int)error;
-(void)_applicationOpenURL:(id)url event:(GSEventRef)event;
-(void)applicationOpenURL:(id)url;
-(void)applicationOpenURL:(id)url publicURLsOnly:(BOOL)only;
-(void)volumeChanged:(GSEventRef)changed;
-(void)setBacklightFactor:(float)factor;
-(void)animateBacklightToFactor:(float)factor duration:(double)duration didFinishTarget:(id)target selector:(SEL)selector;
-(void)setBacklightLevel:(float)level;
-(void)setProximitySensorEnabled:(int)enabled;
-(void)systemWillSleep;
-(void)setupMidnightTimer;
-(void)_midnightPassed;
-(void)_adjustMidnightTimerAfterSleep;
-(void)handleOutOfLineDataResponse:(id)lineDataResponse requestID:(unsigned)id;
-(void)dim;
-(void)turnOffBacklight;
-(void)cancelTurnOffBacklightAfterDelay;
-(void)turnOffBacklightAfterDelay;
-(void)showSimulatedScreenBlank;
-(void)hideSimulatedScreenBlank;
-(void)dimToBlack;
-(void)finishedDimmingScreenToBlack;
-(void)undim;
-(void)lockAfterCall;
-(BOOL)shouldDimToBlackInsteadOfLock;
-(void)autoLock;
-(void)didIdle;
-(double)nextIdleTimeDuration;
-(double)nextLockTimeDuration;
-(void)clearIdleTimer;
-(void)resetIdleTimerAndUndim:(BOOL)undim;
-(void)userEventOccurred:(id)occurred;
-(void)resetIdleTimer;
-(void)resetIdleDuration:(double)duration;
-(void)updateRejectedInputSettings;
-(void)updateRejectedInputSettingsForInCallState:(BOOL)callState isOutgoing:(BOOL)outgoing;
-(void)handleOutOfLineDataRequest:(GSEventRef)lineDataRequest;
-(void)lockDevice:(GSEventRef)device;
-(void)showThermalAlertIfNecessary;
-(void)respondToCurrentThermalCondition;
-(void)_beginThermalJetsamCPUSampling;
-(void)_killThermallyActiveApplication;
-(id)_createAppsCPUTimesDictionary;
-(void)didReceiveMemoryWarning;
-(void)noteSubstantialTransitionOccured;
-(int)_frontMostAppOrientation;
-(void)noteUIOrientationChanged:(int)changed display:(id)display;
-(int)UIOrientation;
-(void)updateMenuDoubleTapSettings;
-(void)setZoomTouchEnabled:(BOOL)enabled;
-(id)springBoardPluginsDirectory;
-(void)updateProximitySettings;
-(void)updateAirPortForDisplay:(id)display;
-(void)frontDisplayDidChange;
-(void)applicationWillOrderInContext:(unsigned)application windowLevel:(float)level windowOutput:(int)output;
-(void)applicationDidOrderOutContext:(unsigned)application;
-(void)didDismissMiniAlert;
-(void)willDisplayMiniAlert:(int*)alert;
-(void)willDismissMiniAlert:(int*)alert andShowAnother:(BOOL)another;
-(void)setHasMiniAlerts:(BOOL)alerts;
-(BOOL)canShowAlerts;
-(BOOL)isLocked;
-(int)alertOrientation;
-(void)_tearDownNow;
-(void)tearDown;
-(BOOL)isMusicPlayerInNowPlayingView;
-(id)nowPlayingApp;
-(BOOL)isNowPlayingAppPlaying;
-(BOOL)isMusicPlayerPlaying;
-(void)setNowPlayingInfo:(id)info forApplication:(id)application;
-(void)_updateRegisteredSimpleRemoteApp;
-(void)setSimpleRemoteRoutingPriority:(unsigned)priority forApplication:(id)application;
-(unsigned)simpleRemoteRoutingPriorityForApplication:(id)application;
-(id)formattedDecimalStringForNumber:(id)number;
-(id)formattedPercentStringForNumber:(id)number;
-(id)_accessibilityRunningApplications;
-(void)_accessibilitySetEventTapCallback:(void*)callback;
-(void*)_accessibilityEventTapCallback;
-(double)_accessibilityActivationAnimationStartDelay;
-(void)_accessibilityActivationAnimationWillBegin;
-(double)_accessibilityDeactivationAnimationStartDelay;
-(void)_accessibilityDeactivationAnimationWillBegin;
@end

@interface SpringBoard (ScriptingAdditions)
-(id)setNextVoiceRecognitionAudioInputPaths:(id)paths;
@end

@interface SpringBoard (SBApplicationTesting)
-(BOOL)runTest:(id)test options:(id)options;
-(void)_retryLaunchTestWithOptions:(id)options;
-(void)startLaunchTestNamed:(id)named options:(id)options;
-(void)startResumeTestNamed:(id)named options:(id)options;
-(void)endLaunchTest;
-(void)finishedTest:(id)test extraResults:(id)results;
@end

@interface SpringBoard (AlertSheetAdditions)
-(void)_alertSheetStackChanged;
@end

