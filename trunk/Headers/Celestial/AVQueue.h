#import <Foundation/Foundation.h>
#import "AVItem.h"

@interface AVQueue : NSObject
{
    NSRecursiveLock *_mutex;
    NSMutableArray *_items;
    void *_reserved;
    unsigned int _flags;
}

+ (id)avQueue;
+ (id)queueWithArray:(NSArray *)array error:(NSError **)error;
- (id)initWithArray:(NSArray *)array error:(NSError **)error;
- (id)initWithError:(NSError **)error;

- (NSUInteger)itemCount;

- (id)itemAtIndex:(NSUInteger)index;

- (NSUInteger)indexOfItem:(AVItem *)item;
- (AVItem *)itemAfterItem:(AVItem *)item;

- (BOOL)appendItemsFromArray:(NSArray *)array error:(NSError **)error;
- (BOOL)appendItem:(AVItem *)item error:(NSError **)error;

- (BOOL)insertItem:(AVItem *)item atIndex:(NSUInteger)index error:(NSError **)error;
- (BOOL)insertItem:(AVItem *)item afterItem:(AVItem *)existingItem error:(NSError **)error;

- (BOOL)removeItem:(AVItem *)item;

- (BOOL)removeItemAtIndex:(NSUInteger)index;
- (void)removeItemsInRange:(NSRange)range;
- (void)removeAllItems;

@end

