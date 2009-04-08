#import <UIKit/UIKit.h>

#import "UIScroller.h"

@interface UITextViewLegacy : UIScroller
- (NSRange)selectedRange;
- (void)setSelectedRange:(NSRange)range;
- (CGRect)rectForSelection:(NSRange)range;
- (UIWebDocumentView *)webView;
- (void)setSelectionWithPoint:(CGPoint)point;
- (void)textLoupeTimerAction;
- (BOOL)isEditable;
@end