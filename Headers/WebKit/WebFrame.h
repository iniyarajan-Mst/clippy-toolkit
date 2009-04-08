#import <Foundation/Foundation.h>
#import <WebCore/WebCore.h>
#import "WebView.h"

@class WebFramePrivate, WebFrameView;

@interface WebFrame : NSObject
{
    WebFramePrivate *_private;
}
- (NSString *)name;
- (WebFrameView *)frameView;
- (WebView *)webView;
- (DOMDocument *)DOMDocument;
- (id)frameElement;

@end