#import <Foundation/Foundation.h>

@interface PSSpecifier : NSObject
{
    id target;
    SEL getter;
    SEL setter;
    SEL action;
    Class detailControllerClass;
    int cellType;
    Class editPaneClass;
    int keyboardType;
    int autoCapsType;
    int autoCorrectionType;
    int textFieldType;
    NSString *_name;
    NSArray *_values;
    NSDictionary *_titleDict;
    NSDictionary *_shortTitleDict;
    id _userInfo;
    NSMutableDictionary *_properties;
}

+ (PSSpecifier *)preferenceSpecifierNamed:(NSString *)name target:(id)target set:(SEL)set get:(SEL)get detail:(Class)detailClass cell:(int)cellType edit:(Class)editClass;
+ (PSSpecifier *)groupSpecifierWithName:(NSString *)name;
+ (PSSpecifier *)emptyGroupSpecifier;

- (void)setProperties:(NSDictionary *)properties;
- (id)propertyForKey:(NSString *)key;
- (void)setProperty:(id)value forKey:(NSString *)key;
- (void)removePropertyForKey:(NSString *)key;

- (void)setTarget:(id)target;

- (NSString *)name;
- (void)setName:(NSString *)newName;

@end

@class PSListController;

NSMutableArray* SpecifiersFromPlist (
                                                          NSDictionary*     plist,      // r0
                                                          PSSpecifier*      specifier,  // r1
                                                          id                target,     // r2
                                                          NSString*         plistName,  // r3
                                                          NSBundle*         curBundle,           // sp[0x124]
                                                          NSString**        pTitle,              // sp[0x128]
                                                          NSString**        pSpecifierID,        // sp[0x12C]
                                                          PSListController* callerList,          // sp[0x130]
                                                          NSMutableArray**  pBundleControllers   // sp[0x134]
);
#define SpecifiersFromPlistOnSelf(plist) SpecifiersFromPlist([NSDictionary dictionaryWithObject:(plist) forKey:@"items"], nil, self, nil, [self bundle], NULL, NULL, self, NULL)

