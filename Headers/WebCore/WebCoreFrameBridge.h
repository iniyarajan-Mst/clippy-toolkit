#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "DOMRange.h"

@interface WebCoreFrameBridge : NSObject
- (DOMRange *)selectedDOMRange;
- (CGRect)caretRect;
- (CGRect)caretRectAtNode:(DOMNode *)node offset:(NSInteger)offset affinity:(int)affinity;
- (CGRect)firstRectForDOMRange:(DOMRange *)range;
@end