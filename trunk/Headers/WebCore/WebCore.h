#import <Foundation/Foundation.h>

#import "DOMCharacterData.h"
#import "DOMDocument.h"
#import "DOMElement.h"
#import "DOMHTMLElement.h"
#import "DOMHTMLInputElement.h"
#import "DOMHTMLImageElement.h"
#import "DOMNode.h"
#import "DOMObject.h"
#import "DOMRange.h"
#import "DOMText.h"
#import "WAKResponder.h"
#import "WAKView.h"
#import "WebCoreFrameBridge.h"
#import "WebScriptObject.h"

void WebThreadLock(void);
void WebThreadUnlock(void);

typedef enum {
	NSSelectionAffinityUpstream = 0,
	NSSelectionAffinityDownstream = 1
} NSSelectionAffinity;
