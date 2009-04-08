#import <Foundation/Foundation.h>

#import "PSSpecifier.h"

@protocol PSBaseView;
@class PSRootController;

@interface PSViewController : NSObject
{
    id <PSBaseView> _parentController;
    PSRootController *_rootController;
}

- (void)setPreferenceValue:(id)value specifier:(PSSpecifier *)specifier;
- (id)readPreferenceValue:(id)value;

@end