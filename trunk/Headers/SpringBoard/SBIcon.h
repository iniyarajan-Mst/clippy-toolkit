#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SBIconBadge, SBIconImageView, SBIconLabel, UIPushButton;

@interface SBIcon : UIControl
{
    SBIconImageView *_image;
    UIImageView *_reflection;
    UIView *_grayFilterView;
    SBIconBadge *_badge;
    SBIconLabel *_label;
    UIPushButton *_closeBox;
    unsigned int _isShowingImages:1;
    unsigned int _drawsLabel:1;
    unsigned int _isHidden:1;
    unsigned int _isRevealable:1;
    unsigned int _inDock:1;
    unsigned int _isGrabbed:1;
    unsigned int _isGrabbing:1;
    unsigned int _isJittering:1;
    unsigned int _allowJitter:1;
    unsigned int _mouseDownInIcon:1;
    CGPoint _unjitterPoint;
    CGPoint _grabPoint;
    NSTimer *_grabTimer;
}

+ (CGSize)defaultIconSize;
+ (void)enqueueReusableIconImageView:(SBIconImageView *)iconImageView;
+ (SBIconImageView *)dequeueReusableIconImageView;
+ (id)_jitterPositionAnimation;
+ (id)_jitterTransformAnimation;

- (id)initWithDefaultSize;
- (BOOL)shouldListInCapabilities;
- (BOOL)ignoresMouseEvents;

- (void)setIsHidden:(BOOL)isHidden animate:(BOOL)animation;
- (BOOL)isHidden;

- (void)setIsRevealable:(BOOL)isRevealable;
- (BOOL)isRevealable;

- (NSString *)displayName;
- (NSString *)displayIdentifier;

- (id)tags;
- (BOOL)launchEnabled;

- (void)setDisplayedIcon:(id)fp8;
- (id)icon;

- (id)reflectedIcon:(BOOL)fp8;

- (BOOL)isShowingImages;
- (void)setShowsImages:(BOOL)fp8;

- (void)updateLabelOrigin;
- (BOOL)shouldEllipsizeLabel;
- (BOOL)shouldKernLabel;
- (void)setDrawsLabel:(BOOL)fp8;
- (void)updateLabelKerningAndEllipsing;

- (id)badge;
- (void)setBadge:(id)fp8;

- (BOOL)shouldTrack;
- (id)darkenedIcon:(id)fp8 alpha:(float)fp12;
- (void)setHighlighted:(BOOL)fp8;
- (void)setInDock:(BOOL)fp8;
- (void)setOrigin:(CGPoint)fp8;
- (void)setIsJittering:(BOOL)fp8;
- (void)setAllowJitter:(BOOL)fp8;
- (BOOL)allowJitter;
- (void)removeAllIconAnimations;
- (void)setIconPosition:(CGPoint)fp8;
- (void)setIsGrabbed:(BOOL)fp8;
- (void)grabTimerFired;
- (void)cancelGrabTimer;
- (void)mouseCancelInIcon:(id)fp8;
- (BOOL)cancelMouseTracking;
- (id)dictionaryRepresentation;
- (void)launch;
- (BOOL)allowsCloseBox;
- (void)setIsShowingCloseBox:(BOOL)fp8;
- (BOOL)isShowingCloseBox;
- (void)closeBoxClicked:(id)fp8;
- (void)completeUninstall;
- (id)description;
- (id)uninstallAlertTitle;
- (id)uninstallAlertBody;
- (id)uninstallAlertConfirmTitle;
- (id)uninstallAlertCancelTitle;

@end

