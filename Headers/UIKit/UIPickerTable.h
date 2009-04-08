#import "UITable.h"

@class UIPickerScrollAnimation;

@interface UIPickerTable : UITable
{
    CGRect _selectionBarRect;
    UIPickerScrollAnimation *_scrollAnimation;
    NSInteger _selectionBarRow;
    CGPoint _lastOffset;
    NSInteger _lastClickRow;
    unsigned int _allowSelectingCells:1;
    unsigned int _allowsMultipleSelection:1;
    unsigned int _lastShouldStick:1;
    unsigned int _disableDidSelect:1;
}

- (BOOL)canHandleSwipes;
- (BOOL)didSelectDisabled;

- (NSInteger)lastClickRow;
- (void)setLastClickRow:(NSInteger)lastClickRow;

- (void)setAllowsMultipleSelection:(BOOL)allowsMultipleSelection;
- (BOOL)allowsMultipleSelection;

- (void)setAllowsSelectingRows:(BOOL)allowsSelectingRows;

// TODO: Finish this
- (void)_scrollSelectionBarRect:(struct CGRect)fp8 animated:(BOOL)fp24 notify:(BOOL)fp28;
- (void)selectCell:(id)fp8 inRow:(int)fp12 column:(int)fp16 withFade:(BOOL)fp20;
- (void)contentMouseUpInView:(id)fp8 withEvent:(struct __GSEvent *)fp12;
- (int)selectionBarRow;
- (id)selectedTableCell;
- (void)selectRow:(int)fp8 animated:(BOOL)fp12 notify:(BOOL)fp16;
- (void)setSelectionBarRect:(struct CGRect)fp8;
- (CGRect)selectionBarRect;
- (void)animationSetOffset:(struct CGPoint)fp8;
- (void)mouseDown:(struct __GSEvent *)fp8;
- (void)mouseUp:(struct __GSEvent *)fp8;
- (void)_pickerScrollAnimationEnded;
- (void)_didMoveFromWindow:(id)fp8 toWindow:(id)fp12;
- (CGPoint)newOffsetWithCenteredRectFromOffset:(struct CGPoint)fp8;
- (BOOL)scrollCenterCellToSelectionBar;
- (BOOL)fixupCenterCellToSelectionBar:(BOOL)fp8;
- (void)setRowHeight:(float)fp8;
- (void)removeFromSuperview;
- (void)updateSelectionBarRow;

@end

