#import <Foundation/Foundation.h>
#import "SBDisplay.h"

@class UIRemoteApplication, SBCFBundle;

@interface SBApplication : SBDisplay
{
    NSString *_bundleIdentifier;
    NSString *_roleIdentifier;
    NSString *_path;
    NSString *_iconPath;
    SBCFBundle *_cachedBundle;
    NSString *_displayName;
    NSString *_demoRole;
    NSMutableSet *_statusBarItemSet;
    NSMutableArray *_tags;
    UIRemoteApplication *_remoteApplication;
    struct __CFSet *_launchAlerts;
    NSString *_seatbeltProfilePath;
    NSDictionary *_seatbeltEnvVars;
    NSString *_signerIdentity;
    unsigned int _eventPort;
    double _launchTime;
    unsigned int _doingBackgroundNetworking;
    unsigned int _failedLaunchCount:8;
    unsigned int _memoryWarningCount:8;
    unsigned int _enabled:1;
    unsigned int _useDemoRole:1;
    unsigned int _relauchesOnAbnormalExit:1;
    unsigned int _isDefaultRole:1;
    unsigned int _isSystemApplication:1;
    unsigned int _hasMiniAlerts:1;
    unsigned int _applicationSignatureState:4;
    unsigned int _applicationSignatureStateValid:1;
    unsigned int _isRevealable:1;
    unsigned int _uiPrerederedIcon:1;
    unsigned int _uiRequiresPersistentWiFi:1;
    unsigned int _sbUsesNetworkIsSet:1;
    unsigned int _dataFlagsIsSet:1;
    int _defaultStatusBarStyle;
    int _defaultInterfaceOrientaton;
    unsigned int _sbUsesNetwork;
    unsigned int _dataFlags;
    unsigned int _uiPriority;
    Class _iconClass;
    NSArray *_customMachServices;
}

- (id)initWithBundleIdentifier:(NSString *)identifier roleIdentifier:(NSString *)roleIdentifier path:(NSString *)path bundle:(SBCFBundle *)cachedBundle infoDictionary:(NSDictionary *)infoDictionary isSystemApplication:(BOOL)isSystemApplication;
- (BOOL)shouldWatchdog;
- (BOOL)isBeingDebugged;
- (float)autoDimTime;
- (float)autoLockTime;
- (void)dealloc;
- (BOOL)isSameExecutableAsApplication:(id)isSameExecutable;
- (NSString *)bundleIdentifier;

- (void)setRoleIdentifier:(NSString *)newIdentifier;
- (NSString *)roleIdentifier;

- (void)setIsDefaultRole:(BOOL)newIsDefaultRole;
- (BOOL)isDefaultRole;

- (NSString *)path;
- (SBCFBundle *)bundle;
- (void)purgeBundleCaches;

- (BOOL)enabled;
- (void)setEnabled:(BOOL)isEnabled;

- (NSString *)demoRole;
- (void)setDemoRole:(NSString *)newDemoRole;

- (void)setUseDemoRole:(BOOL)useDemoRole;

- (void)setTags:(NSMutableArray *)newTags;
- (NSMutableArray *)tags;

- (BOOL)hasMiniAlerts;
- (void)setHasMiniAlerts:(BOOL)newHasMiniAlerts;

- (NSUInteger)dataUsage;
- (void)_setDataUsage:(NSUInteger)dataUsage;
- (void)_resetDataUsage;

- (void)setUsesBackgroundNetwork:(BOOL)usesBackgroundNetwork;
- (void)_setDoingBackgroundNetworking:(NSUInteger)usesBackgroundNetwork;
- (void)setUsesEdgeNetwork:(BOOL)usesEdgeNetwork;
- (void)setUsesWiFiNetwork:(BOOL)usesWiFiNetwork;

- (NSString *)displayIdentifier;
- (NSString *)urlScheme;
- (NSString *)pathForIcon;
- (BOOL)isSystemApplication;
- (BOOL)isWidgetApplication;
- (BOOL)isUserRatable;
- (void)flushSnapshotsForAllRoles;
- (BOOL)shouldLaunchPNGless;

- (Class)iconClass;
- (BOOL)isRevealable;
- (BOOL)isPrerenderedIcon;

- (NSString *)displayName;
- (void)setDisplayName:(NSString *)displayName;

- (void)_sendCurrentDeviceOrientation;

- (BOOL)activate;
- (BOOL)sendActivationEvent:(int)event;
- (BOOL)deactivate;

- (void)watchdogForDeactivate;
- (void)watchdogForResume;
- (void)watchdogForLaunch;
- (void)watchdogForTermination;
- (void)deactivated;
- (BOOL)kill;
- (void)removeStatusBarItems;
- (int)defaultStatusBarMode;
- (int)defaultStatusBarOrientation;
- (void)willActivateOtherRole:(id)fp8;
- (void)exitedCommon;
- (void)exitedAbnormally;
- (void)exitedNormally;
- (NSUInteger)priority;

- (int)pid;
- (void)setPid:(int)pid;

- (NSUInteger)eventPort;

- (id)launchdJobLabel;
- (void)setLaunchdJobLabel:(id)launchdLabel;

- (NSString *)seatbeltProfilePath;
- (void)setSeatbeltProfilePath:(NSString *)profilePath;

- (NSDictionary *)seatbeltEnvironmentVariables;
- (void)setSeatbeltEnvironmentVariables:(NSDictionary *)dictionary;

- (id)signerIdentity;
- (void)setSignerIdentity:(id)signerIdentity;

- (int)applicationSignatureState;
- (void)clearApplicationSignatureStateCache;
- (void)markApplicationIdentityAsTrusted;
- (int)failedLaunchCount;
- (void)removeAppPrefs;
- (void)launchFailed;
- (void)launchSucceeded;
- (void)prepareForUninstallation;

- (NSUInteger)memoryWarningCount;
- (void)setMemoryWarningCount:(NSUInteger)memoryWarningCount;

- (BOOL)relaunchesAfterAbnormalExit;
- (void)setRelaunchesAfterAbnormalExit:(BOOL)relaunches;

- (void)noteAddedStatusBarItem:(id)something;
- (void)noteRemovedStatusBarItem:(id)something;
- (UIRemoteApplication *)remoteApplication;

- (BOOL)showLaunchAlertForType:(int)type;
- (void)resetLaunchAlertForType:(int)type;
- (void)playBundleAlertSound:(id)alertSound;

@end

