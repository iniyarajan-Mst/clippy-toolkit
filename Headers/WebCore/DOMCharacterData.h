#import "DOMNode.h"

@interface DOMCharacterData : DOMNode

- (id)data;
- (void)setData:(id)newData;
- (NSUInteger)length;
- (id)substringData:(NSUInteger)fp8 length:(NSUInteger)fp12;
- (void)appendData:(id)fp8;
- (void)insertData:(NSUInteger)fp8 data:(id)fp12;
- (void)deleteData:(NSUInteger)fp8 length:(NSUInteger)fp12;
- (void)replaceData:(NSUInteger)fp8 length:(NSUInteger)fp12 data:(id)fp16;

@end