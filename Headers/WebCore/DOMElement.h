#import "DOMNode.h"

@interface DOMElement : DOMNode
{
}

- (NSString *)tagName;
- (id)style;
- (int)offsetLeft;
- (int)offsetTop;
- (int)offsetWidth;
- (int)offsetHeight;
- (id)offsetParent;
- (int)clientLeft;
- (int)clientTop;
- (int)clientWidth;
- (int)clientHeight;
- (int)scrollLeft;
- (void)setScrollLeft:(int)fp8;
- (int)scrollTop;
- (void)setScrollTop:(int)fp8;
- (int)scrollWidth;
- (int)scrollHeight;
- (NSString *)innerText;
- (id)getAttribute:(id)fp8;
- (void)setAttribute:(id)fp8 value:(id)fp12;
- (void)removeAttribute:(id)fp8;
- (id)getAttributeNode:(id)fp8;
- (id)setAttributeNode:(id)fp8;
- (id)removeAttributeNode:(id)fp8;
- (id)getElementsByTagName:(id)fp8;
- (id)getAttributeNS:(id)fp8 localName:(id)fp12;
- (void)setAttributeNS:(id)fp8 qualifiedName:(id)fp12 value:(id)fp16;
- (void)removeAttributeNS:(id)fp8 localName:(id)fp12;
- (id)getElementsByTagNameNS:(id)fp8 localName:(id)fp12;
- (id)getAttributeNodeNS:(id)fp8 localName:(id)fp12;
- (id)setAttributeNodeNS:(id)fp8;
- (BOOL)hasAttribute:(id)fp8;
- (BOOL)hasAttributeNS:(id)fp8 localName:(id)fp12;
- (void)focus;
- (void)blur;
- (void)scrollIntoView:(BOOL)fp8;
- (id)insertAdjacentElement:(id)fp8 element:(id)fp12;
- (BOOL)contains:(id)fp8;
- (void)scrollIntoViewIfNeeded:(BOOL)fp8;
- (void)scrollByLines:(int)fp8;
- (void)scrollByPages:(int)fp8;
- (id)getElementsByClassName:(id)fp8;
- (id)querySelector:(id)fp8;
- (id)querySelectorAll:(id)fp8;

- (void)normalize;

@end