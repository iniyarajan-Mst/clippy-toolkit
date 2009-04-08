#import <UIKit/UIKit.h>

@class UIFont, UINavigationItem;

@interface UINavigationItemView : UIView
{
    UIFont *_font;
    UINavigationItem *_item;
    float _titleWidth;
    BOOL _titleAutosizesToFit;
}

- (id)initWithNavigationItem:(UINavigationItem *)navItem;
- (UINavigationItem *)navigationItem;

- (void)drawText:(NSString *)text inRect:(CGRect)rect;

- (NSString *)title;

- (void)setTitleAutoresizesToFit:(BOOL)autoresizes;
- (BOOL)titleAutoresizesToFit;

- (void)setFont:(UIFont *)font;
- (UIFont *)font;

@end

