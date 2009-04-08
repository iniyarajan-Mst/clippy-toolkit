#import <WebCore/WAKView.h>
#import <UIKit/UIKit-Private.h>

@interface WAKView (WebDocumentViewExtras)
- (id)_frame;
- (UIWebDocumentView *)_webView;
@end