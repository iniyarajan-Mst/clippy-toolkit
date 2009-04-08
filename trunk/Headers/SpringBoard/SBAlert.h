#import <UIKit/UIKit.h>
#import "SBDisplay.h"

@class SBAlertDisplay, SBAlertWindow;

@interface SBAlert : SBDisplay
{
    SBAlertDisplay *_display;
    NSMutableDictionary *_dictionary;
    SBAlertWindow *_deferredAlertWindow;
}

+ (void)registerForAlerts;
+ (id)alertWindow;
+ (void)test;

- (SBAlertDisplay *)display;
- (void)setDisplay:(SBAlertDisplay *)display;

- (id)alertDisplayViewWithSize:(CGSize)size;

- (void)setObject:(id)object forKey:(id)key;
- (id)objectForKey:(id)key;

- (BOOL)allowsStackingOfAlert:(id)something;
- (BOOL)displaysAboveLock;
- (BOOL)undimsDisplay;
- (CGFloat)finalAlpha;
- (double)animateInDuration;
- (CGRect)alertWindowRect;
- (Class)alertWindowClass;
- (BOOL)activate;
- (void)tearDownAlertWindow:(id)something;
- (void)removeFromView;
- (BOOL)deactivate;
- (BOOL)animatesDismissal;
- (BOOL)allowsDoubleHeightStatusBar;
- (float)autoDimTime;
- (int)statusBarMode;
- (int)statusBarOrientation;
- (void)didAnimateLockKeypadIn;
- (void)didAnimateLockKeypadOut;
- (void)didFinishAnimatingIn;
- (void)didFinishAnimatingOut;

@end

