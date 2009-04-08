#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

struct AVItemPrivate;
@interface AVItem : NSObject{    struct AVItemPrivate *_priv;}+ (id)avItem;+ (id)avItemWithPath:(NSString *)path error:(NSError **)error;
- (id)initWithError:(NSError *)error;- (id)initWithPath:(NSString *)path error:(NSError **)error;
- (BOOL)setPath:(NSString *)path error:(NSError **)error;- (NSString *)path;
- (double)duration;
- (CGSize)naturalSize;
- (float)volume;- (void)setVolume:(float)newVolume;
- (void)setEQPreset:(int)newEQPreset;- (int)eqPreset;
- (id)attributeForKey:(id)key;- (BOOL)setAttribute:(id)attribute forKey:(id)key error:(NSError **)error;
- (id)chapterImageForImageID:(int)imageId;@end