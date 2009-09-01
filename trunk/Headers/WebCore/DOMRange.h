#import "DOMObject.h"

enum CompareHow { START_TO_START, START_TO_END, END_TO_END, END_TO_START };

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
- (void)insertNode:(DOMNode *)node;
- (DOMNode *)commonAncestorContainer;
- (short)compareBoundaryPoints:(unsigned short)how sourceRange:(DOMRange *)sourceRange;

- (void)collapse:(BOOL)toStart;
- (BOOL)collapsed;

- (NSString *)text;

- (DOMRange *)cloneRange;

@end