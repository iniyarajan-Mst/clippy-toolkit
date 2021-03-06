#import <Foundation/Foundation.h>

struct AVSystemControllerPrivate;

@interface AVSystemController : NSObject
{
    struct AVSystemControllerPrivate *_priv;
}

+ (void)initialize;
+ (id)sharedAVSystemController;
- (id)init;
- (void)dealloc;
- (BOOL)changeActiveCategoryVolumeBy:(float)fp8 fallbackCategory:(id)fp12 resultVolume:(float *)fp16 affectedCategory:(id *)fp20;
- (BOOL)changeActiveCategoryVolumeBy:(float)fp8;
- (BOOL)setActiveCategoryVolumeTo:(float)fp8 fallbackCategory:(id)fp12 resultVolume:(float *)fp16 affectedCategory:(id *)fp20;
- (BOOL)setActiveCategoryVolumeTo:(float)fp8;
- (BOOL)getActiveCategoryVolume:(float *)fp8 andName:(id *)fp12 fallbackCategory:(id)fp16;
- (BOOL)getActiveCategoryVolume:(float *)fp8 andName:(id *)fp12;
- (BOOL)changeActiveCategoryVolumeBy:(float)fp8 forRoute:(id)fp12 andDeviceIdentifier:(id)fp16;
- (BOOL)setActiveCategoryVolumeTo:(float)fp8 forRoute:(id)fp12 andDeviceIdentifier:(id)fp16;
- (BOOL)activeCategoryVolumeDidChangeTo:(float)fp8 forRoute:(id)fp12 andDeviceIdentifier:(id)fp16;
- (BOOL)getActiveCategoryVolume:(float *)fp8 andName:(id *)fp12 forRoute:(id)fp16 andDeviceIdentifier:(id)fp20;
- (BOOL)toggleActiveCategoryMuted;
- (BOOL)toggleActiveCategoryMutedForRoute:(id)fp8 andDeviceIdentifier:(id)fp12;
- (BOOL)getActiveCategoryMuted:(char *)fp8;
- (BOOL)getActiveCategoryMuted:(char *)fp8 forRoute:(id)fp12 andDeviceIdentifier:(id)fp16;
- (BOOL)changeVolumeBy:(float)fp8 forCategory:(id)fp12;
- (BOOL)setVolumeTo:(float)fp8 forCategory:(id)fp12;
- (BOOL)getVolume:(float *)fp8 forCategory:(id)fp12;
- (id)routeForCategory:(id)fp8;
- (id)volumeCategoryForAudioCategory:(id)fp8;
- (id)attributeForKey:(id)fp8;
- (BOOL)setAttribute:(id)fp8 forKey:(id)fp12 error:(id *)fp16;
- (void)makeError:(id *)fp8 withDescription:(id)fp12 code:(long)fp16;
- (BOOL)okToNotifyFromThisThread;
- (void)handleServerDied;

@end

#define SharedAVSystemController ((AVSystemController *)[objc_getClass("AVSystemController") sharedAVSystemController])
