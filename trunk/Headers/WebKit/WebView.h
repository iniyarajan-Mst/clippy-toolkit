#import <WebCore/WebCore.h>
#import "WebElementDictionary.h"

@interface WebView : WAKView
- (WebElementDictionary *)elementAtPoint:(CGPoint)point;
- (void)setSelectedDOMRange:(NSRange *)range affinity:(NSSelectionAffinity)affinity;
- (NSRange *)selectedDOMRange;
- (NSSelectionAffinity)selectionAffinity;
- (id)_UIKitDelegate;
@end