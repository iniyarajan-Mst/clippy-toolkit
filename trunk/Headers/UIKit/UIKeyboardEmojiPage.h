#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UIKeyboardEmojiView;
@protocol UIKeyboardEmojiController;

@interface UIKeyboardEmojiPage : UIControl
{
    NSArray *_emoji;
    NSMutableArray *_emojiViews;
    int _numRows;
    int _numCols;
    int _numPages;
    float _horizontalGap;
    float _verticalGap;
    struct CGRect _keyActivationRect;
    NSString *_optionalText;
    id <UIKeyboardEmojiController> _controller;
    UITouch *_activeTouch;
    BOOL _needsLayout;
    UIKeyboardEmojiView *_touched;
    UIKeyboardEmojiView *_pendingDisplay;
    UIKeyboardEmojiView *_onDisplay;
}

- (CGRect)rectForRow:(NSInteger)row Col:(NSInteger)col;

- (int)takeEmoji:(id)fp8 fromIndex:(int)fp12;

- (void)generateSubviews;
- (void)clearSubviews;

- (UIKeyboardEmojiView *)closestForPoint:(CGPoint)point;

- (void)cancelPendingPopupChanges;
- (void)showPendingPopup:(id)fp8;
- (void)removeDisplayedPopup:(id)fp8;
- (void)checkForStalePopup:(id)fp8;

- (void)touchBegan:(UITouch *)touch;
- (void)touchMoved:(UITouch *)touch;
- (void)touchEnded:(UITouch *)touch;
- (void)touchCancelled:(UITouch *)touch;

- (CGRect)keyActivationRect;
- (void)setKeyActivationRect:(CGRect)newRect;

- (UIKeyboardEmojiView *)onDisplay;
- (void)setOnDisplay:(UIKeyboardEmojiView *)onDisplay;

- (UIKeyboardEmojiView *)pendingDisplay;
- (void)setPendingDisplay:(UIKeyboardEmojiView *)fp8;

- (UITouch *)activeTouch;
- (void)setActiveTouch:(UITouch *)touch;

- (NSString *)optionalText;
- (void)setOptionalText:(NSString *)optionalText;

- (id<UIKeyboardEmojiController>)controller;
- (void)setController:(id<UIKeyboardEmojiController>)controller;

- (NSArray *)emoji;
- (void)setEmoji:(NSArray *)emoji;

- (UIKeyboardEmojiView *)touched;
- (void)setTouched:(UIKeyboardEmojiView *)touched;

@end

