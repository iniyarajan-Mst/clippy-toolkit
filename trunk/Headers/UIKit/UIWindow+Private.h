#import <UIKit/UIKit.h>

@interface UIWindow (Private)

+ (UIWindow *)keyWindow;

- (UIResponder *)firstResponder;
- (void)matchDeviceOrientation;

@end

enum {
    UIWindowLevelSBSettings = 1101,
};