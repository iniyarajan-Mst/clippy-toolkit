#import <Foundation/Foundation.h>

@interface SBDisplay : NSObject
{
    NSMutableDictionary *_activationValues;
    NSMutableDictionary *_deactivationValues;
    int _activationSettings;
    int _deactivationSettings;
    NSMutableSet *_suppressVolumeHudCategories;
    float _autoDimOverride;
    float _autoLockOverride;
    double _accelerometerSampleInterval;
    unsigned int _expectsFaceContact:1;
    unsigned int _accelerometerDeviceOrientationChangedEventsEnabled:1;
    unsigned int _accelerometerRawEventsEnabled:1;
    unsigned int _proximityEventsEnabled:1;
    unsigned int _showsProgress;
}


- (id)displayIdentifier;
- (id)urlScheme;

- (BOOL)activate;
- (BOOL)deactivate;
- (BOOL)kill;

@end

