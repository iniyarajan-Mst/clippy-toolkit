#import <UIKit/UIKit.h>

#import "UINavigationItemView.h"

@interface UINavigationItemButtonView : UINavigationItemView
{
    int _style;
    BOOL _pressed;
}

- (UIImage *)image;
- (CGSize)imageSize;

- (void)setStyle:(int)style;

- (void)setPressed:(BOOL)pressed;
- (BOOL)pressed;

@end

