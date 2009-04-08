#import "DOMObject.h"

@class DOMDocument;

@interface DOMNode : DOMObject

- (NSString *)nodeName;
- (id)nodeValue;
- (void)setNodeValue:(id)newNodeValue;
- (unsigned short)nodeType;
- (DOMNode *)parentNode;
- (NSArray *)childNodes;
- (DOMNode *)firstChild;
- (DOMNode *)lastChild;
- (DOMNode *)previousSibling;
- (DOMNode *)nextSibling;
- (id)attributes;
- (DOMDocument *)ownerDocument;
- (NSString *)textContent;
- (void)setTextContent:(NSString *)newTextContent;

@end
