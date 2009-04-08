#import "SBIcon.h"

@class SBApplication;

@interface SBApplicationIcon : SBIcon
{
    SBApplication *_app;
}

- (id)initWithApplication:(SBApplication *)application;

- (SBApplication *)application;
- (id)icon;
- (NSString *)displayName;
- (NSString *)displayIdentifier;
- (BOOL)shouldEllipsizeLabel;
- (id)tags;
- (BOOL)launchEnabled;
- (void)launch;
- (void)setBadge:(id)badgeValue;

@end