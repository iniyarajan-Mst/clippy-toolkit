#import <UIKit/UIKit.h>

@interface UIHardware : NSObject
{
}

+ (CGFloat)statusBarHeight;
+ (void)_setStatusBarHeight:(CGFloat)fp8;

+ (CGSize)mainScreenSize;
+ (CGRect)fullScreenApplicationContentRect;
+ (CGRect)fullScreenApplicationContentRectForDeviceOrientation:(UIDeviceOrientation)orientation;
+ (CGRect)fullScreenApplicationContentRectForCurrentDeviceOrientation;
+ (int)ringerState;
+ (UIDeviceOrientation)deviceOrientation:(BOOL)unknown;
+ (BOOL)setSpeakerPhoneEnabled:(BOOL)speakerPhoneEnabled;
+ (BOOL)isTTYEnabled;
+ (CGSize)TVScreenSize;
+ (CGFloat)TVHorizontalPixelScale;
+ (BOOL)_TVOutStatus:(BOOL)something;
+ (BOOL)TVOutCapableAndPreferred;
+ (BOOL)TVOutCapable;
+ (void)TVOutResetPreferred;
+ (NSString *)deviceName;
+ (NSString *)localizedDeviceName;

+ (void)_playSystemSound:(unsigned long)soundId;

+ (void)_updateSystemSoundActiveStatus:(id)fp8;
+ (void)_registerForSystemSounds:(id)fp8;
+ (void)_unregisterForSystemSounds:(id)fp8;

+ (void)alertSheet:(id)fp8 buttonClicked:(int)fp12;
+ (void)accessoryAvailabilityChanged;

@end

