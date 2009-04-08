#import <UIKit/UIKit.h>

@interface UIAccelerometer (Private)
- (void)_acceleratedInX:(UIAccelerationValue)x y:(UIAccelerationValue)y z:(UIAccelerationValue)z timestamp:(NSTimeInterval)timestamp;
@end