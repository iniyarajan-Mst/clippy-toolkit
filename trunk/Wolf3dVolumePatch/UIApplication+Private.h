#import <UIKit/UIKit.h>

@interface UIApplication (Private)

- (void)setSystemVolumeHUDEnabled:(BOOL)enabled forAudioCategory:(NSString *)category;
- (void)setSystemVolumeHUDEnabled:(BOOL)enabled;

@end
