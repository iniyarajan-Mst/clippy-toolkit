#import "DOMObject.h"

@interface DOMRange : DOMObject
- (void)setStart:(DOMNode *)container offset:(NSInteger)offset;
- (void)setEnd:(DOMNode *)container offset:(NSInteger)offset;
- (BOOL)collapsed;
- (DOMNode *)startContainer;
- (NSInteger)startOffset;
- (DOMNode *)endContainer;
- (NSInteger)endOffset;
- (NSArray *)lineBoxRects;
- (void)selectNode:(DOMNode *)node;
- (void)selectNodeContents:(DOMNode *)node;
- (void)deleteContents;
@end