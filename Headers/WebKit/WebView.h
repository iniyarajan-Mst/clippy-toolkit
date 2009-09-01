#import <WebCore/WebCore.h>
#import "WebElementDictionary.h"

@interface WebView : WAKView
- (WebElementDictionary *)elementAtPoint:(CGPoint)point;
- (void)setSelectedDOMRange:(DOMRange *)range affinity:(NSSelectionAffinity)affinity;
- (DOMRange *)selectedDOMRange;
- (NSSelectionAffinity)selectionAffinity;
- (id)_UIKitDelegate;
@end