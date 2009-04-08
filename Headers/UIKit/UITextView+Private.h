#import <UIKit/UITextView.h>
#import "UIWebDocumentView.h"

@interface UITextView(Private)
- (CGRect)rectForSelection:(NSRange)range;
- (UIWebDocumentView *)webView;
- (void)setSelectionWithPoint:(CGPoint)point;
- (UIView *)textLoupe;
@end