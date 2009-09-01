#import "PSViewController.h"
#import "PSSpecifier.h"

#import <UIKit/UIKit.h>

@class UITransitionView, UIPreferencesTable, UIModalView;
@protocol PSBaseView;

@interface PSListController : PSViewController
{
    NSMutableDictionary *_cells;
    BOOL _cachesCells;
    NSString *_title;
    UITransitionView *_view;
    UIPreferencesTable *_table;
    NSArray *_specifiers;
    id <PSBaseView> _detailController;
    id <PSBaseView> _previousController;
    NSMutableArray *_controllers;
    NSMutableDictionary *_specifiersByID;
    BOOL _keyboardWasVisible;
    BOOL _showingSetupController;
    BOOL _selectingRow;
    NSString *_specifierID;
    PSSpecifier *_specifier;
    NSMutableArray *_groups;
    NSMutableArray *_bundleControllers;
    BOOL _bundlesLoaded;
    CGRect _cellRect;
    UIModalView *_alertSheet;
}

- (NSArray *)specifiers;
- (NSBundle *)bundle;

- (void)insertSpecifier:(PSSpecifier *)specifier afterSpecifier:(PSSpecifier *)specifier animated:(BOOL)animated;
- (void)insertContiguousSpecifiers:(NSArray *)specifiers afterSpecifierID:(NSString *)specifierId;

- (void)removeSpecifierID:(NSString *)specifierId;
- (void)removeSpecifier:(PSSpecifier *)specifier;

- (PSSpecifier *)specifierForID:(NSString *)specifierId;

- (NSInteger)indexOfSpecifier:(PSSpecifier *)specifier;
- (PSSpecifier *)specifierAtIndex:(NSInteger)index;

- (NSArray *)loadSpecifiersFromPlistName:(NSString *)plistName target:(id)target;


@end