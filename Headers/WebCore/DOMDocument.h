#import "DOMNode.h"

@interface DOMDocument : DOMNode
{
}

- (id)doctype;
- (id)implementation;
- (DOMNode *)documentElement;
- (id)inputEncoding;
- (id)xmlEncoding;
- (id)xmlVersion;
- (void)setXmlVersion:(id)fp8;
- (BOOL)xmlStandalone;
- (void)setXmlStandalone:(BOOL)fp8;
- (id)documentURI;
- (void)setDocumentURI:(id)fp8;
- (id)defaultView;
- (id)styleSheets;
- (id)title;
- (void)setTitle:(id)fp8;
- (id)referrer;
- (id)domain;
- (id)URL;
- (id)cookie;
- (void)setCookie:(id)fp8;
- (id)body;
- (void)setBody:(id)fp8;

@end