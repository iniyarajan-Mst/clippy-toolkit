#import "DOMNode.h"

@class DOMRange, DOMText, DOMXPathResult;
@protocol DOMXPathNSResolver;

enum {
	ANY_TYPE = 0,
	NUMBER_TYPE = 1,
	STRING_TYPE = 2,
	BOOLEAN_TYPE = 3,
	UNORDERED_NODE_ITERATOR_TYPE = 4,
	ORDERED_NODE_ITERATOR_TYPE = 5,
	UNORDERED_NODE_SNAPSHOT_TYPE = 6,
	ORDERED_NODE_SNAPSHOT_TYPE = 7,
	ANY_UNORDERED_NODE_TYPE	= 8,
	FIRST_ORDERED_NODE_TYPE = 9
};

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

- (DOMRange *)createRange;
- (DOMText *)createTextNode:(NSString *)text;

//- (DOMXPathResult *)evaluate:(NSString *)expression :(DOMNode *)contextNode :(id <DOMXPathNSResolver>)resolver :(unsigned short)type :(DOMXPathResult *)inResult;
- (DOMXPathResult *)evaluate:(NSString *)expression contextNode:(DOMNode *)contextNode resolver:(id <DOMXPathNSResolver>)resolver type:(unsigned short)type inResult:(DOMXPathResult *)inResult;

@end