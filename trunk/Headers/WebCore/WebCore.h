#import <Foundation/Foundation.h>

#import "DOMCharacterData.h"
#import "DOMDocument.h"
#import "DOMElement.h"
#import "DOMHTMLElement.h"
#import "DOMHTMLInputElement.h"
#import "DOMHTMLImageElement.h"
#import "DOMNode.h"
#import "DOMNodeList.h"
#import "DOMObject.h"
#import "DOMRange.h"
#import "DOMText.h"
#import "DOMXPathResult.h"
#import "WAKResponder.h"
#import "WAKView.h"
#import "WebCoreFrameBridge.h"
#import "WebScriptObject.h"

#ifdef __cplusplus
extern "C" {
#endif

// The lock is automatically freed at the bottom of the runloop. No need to unlock.
// Note that calling this function may hang your UI for several seconds. Don't use
// unless you have to.
void WebThreadLock(void);
    
// This is a no-op for compatibility only. It will go away. Please don't use.
void WebThreadUnlock(void);

// 3.0 only
// These are for <rdar://problem/6817341> Many apps crashing calling -[UIFieldEditor text] in secondary thread
// Don't use them to solve any random problems you might have.
void WebThreadLockFromAnyThread();
void WebThreadUnlockFromAnyThread();

#ifdef __cplusplus
}
#endif

typedef enum {
	NSSelectionAffinityUpstream = 0,
	NSSelectionAffinityDownstream = 1
} NSSelectionAffinity;
