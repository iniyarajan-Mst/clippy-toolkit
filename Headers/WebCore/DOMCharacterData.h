#import "DOMNode.h"

@interface DOMCharacterData : DOMNode

- (NSString *)data;
- (void)setData:(NSString *)newData;
- (NSUInteger)length;
- (NSString *)substringData:(NSUInteger)start length:(NSUInteger)length;
- (void)appendData:(NSString *)data;
- (void)insertData:(NSUInteger)start data:(NSString *)data;
- (void)deleteData:(NSUInteger)start length:(NSUInteger)length;
- (void)replaceData:(NSUInteger)start length:(NSUInteger)length data:(NSString *)data;

@end