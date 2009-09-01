#import <UIKit/UIKit.h>
#import "UIKeyboardInput.h"

@interface UIKeyboardImpl : UIView

+ (UIKeyboardImpl *)activeInstance;
+ (UIKeyboardImpl *)sharedInstance;

- (void)updateLayout;
- (id<UIKeyboardInput>)delegate;
- (void)callChanged;
- (void)addInputString:(NSString *)text;

- (id<UITextInputTraits>)textInputTraits;

- (void)autoDeleteTimerFired:(NSTimer *)timer;
- (void)startAutoDeleteTimer;
- (void)stopAutoDelete;

- (void)setChanged;

- (BOOL)callShouldInsertText:(NSString *)text;

@end

#define ActiveKeyboardImpl [UIKeyboardImpl activeInstance]
