#import <Foundation/Foundation.h>

struct AVSystemControllerPrivate;

@interface AVSystemController : NSObject
{
    struct AVSystemControllerPrivate *_priv;
}

+ (void)initialize;
+ (id)sharedAVSystemController;

- (BOOL)changeActiveCategoryVolumeBy:(float)amount fallbackCategory:(NSString *)fallback resultVolume:(float *)resultVolume affectedCategory:(NSString **)affectedCategory;
- (BOOL)changeActiveCategoryVolumeBy:(float)amount;

- (BOOL)setActiveCategoryVolumeTo:(float)volume fallbackCategory:(NSString *)fallback resultVolume:(float *)result affectedCategory:(NSString **)affectedCategory;
- (BOOL)setActiveCategoryVolumeTo:(float)volume;

- (BOOL)getActiveCategoryVolume:(float *)volume andName:(NSString **)name fallbackCategory:(NSString *)fallback;
- (BOOL)getActiveCategoryVolume:(float *)volume andName:(NSString **)name;

- (BOOL)changeActiveCategoryVolumeBy:(float)amount forRoute:(id)route andDeviceIdentifier:(id)deviceId;
- (BOOL)setActiveCategoryVolumeTo:(float)volume forRoute:(id)route andDeviceIdentifier:(id)deviceId;

- (BOOL)activeCategoryVolumeDidChangeTo:(float)amount forRoute:(id)route andDeviceIdentifier:(id)deviceId;

- (BOOL)getActiveCategoryVolume:(float *)volume andName:(NSString **)name forRoute:(id)route andDeviceIdentifier:(id)deviceId;

- (BOOL)toggleActiveCategoryMuted;
- (BOOL)toggleActiveCategoryMutedForRoute:(id)route andDeviceIdentifier:(id)deviceId;

- (BOOL)getActiveCategoryMuted:(char *)what;
- (BOOL)getActiveCategoryMuted:(char *)what forRoute:(id)route andDeviceIdentifier:(id)deviceIdentifier;

- (BOOL)changeVolumeBy:(float)amount forCategory:(NSString *)category;

- (BOOL)setVolumeTo:(float)volume forCategory:(NSString *)category;
- (BOOL)getVolume:(float *)volume forCategory:(NSString *)category;

- (id)routeForCategory:(NSString *)category;
- (id)volumeCategoryForAudioCategory:(id)volumeCategory;

- (id)attributeForKey:(id)key;
- (BOOL)setAttribute:(id)attribute forKey:(id)key error:(NSError **)error;

- (void)makeError:(NSError **)error withDescription:(NSString *)description code:(long)code;

- (BOOL)okToNotifyFromThisThread;
- (void)handleServerDied;

@end

