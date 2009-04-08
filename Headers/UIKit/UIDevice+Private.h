#import <UIKit/UIKit.h>

@interface UIDevice (Private)
- (void)beginGeneratingDeviceOrientationNotifications;
- (void)endGeneratingDeviceOrientationNotifications;
- (BOOL)isGeneratingDeviceOrientationNotifications;
- (void)_enableDeviceOrientationEvents:(BOOL)enabled;
- (void)setOrientation:(UIDeviceOrientation)orientation;
@end