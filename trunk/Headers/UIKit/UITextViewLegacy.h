#import <UIKit/UIKit.h>

#import "UIScroller.h"

@class WebFrame, WebCoreFrameBridge, DOMHTMLElement, UIDelayedAction, UIWebDocumentView;

@interface UITextViewLegacy : UIScroller
{
@public
    WebFrame *m_frame;
    WebCoreFrameBridge *m_bridge;
    DOMHTMLElement *m_body;
    int m_marginTop;
    UIDelayedAction *m_selectionTimer;
    UIView *m_topAccessoryView;
    UIDelayedAction *m_longPressAction;
    CGPoint m_mouseDownPoint;
    CGPoint m_mouseDownOffset;
    void *m_mouseDownEvent;
    BOOL m_selecting;
    BOOL m_handlingMouse;
    BOOL m_sentMouseDown;
    BOOL m_passMouseDownToOther;
    BOOL m_scrollOnMouseUp;
    BOOL m_clearsSelectionOnBecomingFirstResponder;
    UIWebDocumentView *m_webView;
    UIFont *m_font;
    UIColor *m_textColor;
    int m_textAlignment;
    NSRange m_selectedRange;
    BOOL m_editable;
}

- (NSRange)selectedRange;
- (void)setSelectedRange:(NSRange)range;
- (CGRect)rectForSelection:(NSRange)range;
- (UIWebDocumentView *)webView;
- (void)setSelectionWithPoint:(CGPoint)point;
- (void)textLoupeTimerAction;
- (BOOL)isEditable;
@end