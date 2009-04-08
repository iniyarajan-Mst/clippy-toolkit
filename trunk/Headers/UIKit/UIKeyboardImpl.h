#import <UIKit/UIKit.h>
#import "UIKeyboardInput.h"

@interface UIKeyboardImpl : UIView

+ (UIKeyboardImpl *)activeInstance;

- (void)updateLayout;
- (id<UIKeyboardInput>)delegate;
- (void)callChanged;
- (void)addInputString:(NSString *)text;

- (id<UITextInputTraits>)textInputTraits;

- (void)autoDeleteTimerFired:(NSTimer *)timer;
- (void)startAutoDeleteTimer;
- (void)stopAutoDelete;

@end

#define ActiveKeyboardImpl [UIKeyboardImpl activeInstance]
