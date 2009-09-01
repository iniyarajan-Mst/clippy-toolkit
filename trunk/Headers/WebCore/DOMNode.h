#import "DOMObject.h"

@class DOMDocument, DOMNodeList;

@interface DOMNode : DOMObject

- (NSString *)nodeName;
- (id)nodeValue;
- (void)setNodeValue:(id)newNodeValue;
- (unsigned short)nodeType;
- (DOMNode *)parentNode;
- (DOMNode *)parentElement;
- (DOMNodeList *)childNodes;
- (DOMNode *)firstChild;
- (DOMNode *)lastChild;
- (DOMNode *)previousSibling;
- (DOMNode *)nextSibling;
- (id)attributes;
- (DOMDocument *)ownerDocument;
- (NSString *)textContent;
- (void)setTextContent:(NSString *)newTextContent;

- (id)removeChild:(DOMNode *)child;
- (id)appendChild:(DOMNode *)newChild;

- (CGRect)boundingBox;
- (NSArray *)lineBoxRects;

- (void)normalize;

- (void)setSelectionRange:(NSInteger)location end:(NSInteger)end;

- (BOOL)isFocused;

// only on some nodes
- (NSString *)value;

@end

@interface DOMNode (DOMNodeExtensions)
- (CGRect)boundingBox;
- (NSArray *)lineBoxRects;
- (NSString *)hrefURL;
- (NSString *)hrefTarget;
- (CGRect)hrefFrame;
- (id)hrefLabel;
- (NSString *)hrefTitle;
- (CGRect)boundingFrame;
- (CGRect)innerFrame;
- (CGFloat)computedFontSize;
- (DOMNode *)nextFocusNode;
- (DOMNode *)previousFocusNode;
@end
