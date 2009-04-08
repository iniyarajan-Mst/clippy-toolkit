#import "AVController.h"

@interface AVController (Celeste)

- (BOOL)vibrationEnabled;
- (void)setVibrationEnabled:(BOOL)enabled;

- (NSDictionary *)vibrationPattern;
- (void)setVibrationPattern:(NSDictionary *)pattern;

- (void)setBuzzerPattern:(id)fp8;
- (id)buzzerPattern;

@end