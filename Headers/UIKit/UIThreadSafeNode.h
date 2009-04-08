#import <Foundation/Foundation.h>
#import <WebCore/WebCore.h>

@interface UIThreadSafeNode : NSObject
{
    DOMNode *_node;
}
+ (id)threadSafeNodeWithNode:(DOMNode *)node;
- (id)initWithNode:(DOMNode *)node;

- (BOOL)isEqual:(id)object;
- (BOOL)isEqualToNode:(id)node;

- (id)nextFormControl;
- (id)previousFormControl;
- (int)compareTabIndex:(id)fp8;

// Acts as a proxy for DOMNode and pretends to be one
- (NSString *)description;
- (BOOL)isKindOfClass:(Class)class;
- (BOOL)respondsToSelector:(SEL)sel;
- (void)forwardInvocation:(id)invocation;
- (id)methodSignatureForSelector:(SEL)sel;
@end