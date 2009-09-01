#import "DOMDocument+WebDOMDocumentOperations.h"
#import "WAKView+WebDocumentViewExtras.h"
#import "WebElementDictionary.h"
#import "WebFrame.h"
#import "WebHTMLView.h"
#import "WebView.h"

#import <UIKit/UIGraphics.h>

UIKIT_EXTERN CGContextRef WKGetCurrentGraphicsContext(void);
UIKIT_EXTERN void WKSetCurrentGraphicsContext(CGContextRef context);
