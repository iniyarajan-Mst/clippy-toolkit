#import <Foundation/Foundation.h>

struct AVControllerPrivate;

@class AVQueue;

@interface AVController : NSObject
{
    struct AVControllerPrivate *_priv;
}

+ (id)avControllerWithQueue:(AVQueue *)queue error:(NSError **)error;
- (id)initWithQueue:(AVQueue *)queue error:(NSError **)error;

- (BOOL)play:(NSError **)error; // Is this right?
- (BOOL)playNextItem:(NSError **)error; // Is this right?
- (void)pause;

- (float)volume;
- (void)setVolume:(float)newVolume;
- (BOOL)muted;
- (void)setMuted:(BOOL)newMuted;
- (int)eqPreset;
- (void)setEQPreset:(int)newPreset;

- (double)currentTime;
- (void)setCurrentTime:(double)fp8;
- (void)setCurrentTime:(double)fp8 options:(int)fp16;

- (id)delegate;
- (void)setDelegate:(id)newDelegate;

@end

@interface AVControllerFig : AVController
@end

@interface AVControllerMission : AVController
@end

@interface AVControllerRemoteFig : AVController
@end

@interface AVControllerRemoteFigStream : AVController
@end

@interface AVControllerRemoteMarlowStream : AVController
@end

@interface AVControllerRemoteMission : AVController
@end
