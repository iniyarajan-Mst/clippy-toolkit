#import <GraphicsServices/GraphicsServices.h>

#import "UIKeyboardLayout.h"
#import "UIKeyDefinition.h"

@class UIKeyboardSublayout;

@interface UIKeyboardLayoutRoman : UIKeyboardLayout
{
    NSMutableDictionary *m_keyedSublayouts;
    UIKeyboardSublayout *m_activeSublayout;
    UIKeyboardSublayout *m_deactivatingSublayout;
    id m_activeSublayoutKey;
    int m_activeKeyIndex;
    UIView *m_activeKeyView;
    UIView *m_accentedKeyView;
    int m_returnKeyIndex;
    UIView *m_enabledReturnKeyView;
    UIView *m_disabledReturnKeyView;
    UIView *m_pressedReturnKeyView;
    CGPoint m_dragPoint;
    unsigned int m_currentPathFlags;
    GSPathInfo m_activePathInfo;
    int m_shiftKeyPathIndex;
    int m_swipePathIndex;
    int m_preferredTrackingChangeCount;
    struct USet *m_accentInfo;
    struct USet *m_hasAccents;
    id m_spaceTarget;
    SEL m_spaceAction;
    SEL m_spaceLongAction;
    id m_returnTarget;
    SEL m_returnAction;
    SEL m_returnLongAction;
    id m_deleteTarget;
    SEL m_deleteAction;
    SEL m_deleteLongAction;
    BOOL m_shift;
    BOOL m_built;
    BOOL m_dragged;
    BOOL m_dragChangedKey;
    BOOL m_mouseDownInMoreKey;
    BOOL m_didLongPress;
}

+ (id)inputModesPreferringEuroToDollar;
+ (id)availableTopLevelDomains;

- (void)showKeyboardType:(int)keyboardType withAppearance:(int)appearance;
- (void)deactivateActiveKeys;
- (void)updateReturnKey;
- (void)updateLocalizedKeys;
- (BOOL)usesAutoShift;
- (BOOL)isShiftKeyBeingHeld;
- (BOOL)isShiftKeyPlaneChooser;
- (void)setShift:(BOOL)isShifted;
- (void)longPressAction;
- (BOOL)canHandleHandEvent:(GSEvent *)gsEvent;
- (NSUInteger)typeForKey:(UIKeyDefinition *)key;
- (NSUInteger)downActionFlagsForKey:(UIKeyDefinition *)key;
- (NSUInteger)upActionFlagsForKey:(UIKeyDefinition *)key;
- (struct CGRect)compositeFGLongPressFrameForKey:(UIKeyDefinition *)key orientation:(UIInterfaceOrientation)orientation;
- (Class)sublayoutClassForKeyboardType:(id)keyboardType;
- (void)setLabel:(NSString *)label forKey:(id)key;
- (void)setTarget:(id)target forKey:(id)key;
- (void)setAction:(SEL)selector forKey:(id)key;
- (void)setLongPressAction:(SEL)selector forKey:(id)key;
- (void)restoreDefaultsForKey:(id)key;
- (void)restoreDefaultsForAllKeys;
- (void)nextCandidatesAction;
- (void)confirmAction;
- (void)sendStringAction:(id)stringAction forKey:(UIKeyDefinition *)key;
- (void)deleteAction;
- (void)handleHardwareKeyDownFromSimulator:(GSEvent *)gsEvent;
- (void)addLocalizedCurrencyKeysToSublayout:(id)sublayout keyboardType:(id)type;
- (void)build;

- (id)buildSublayoutForKey:(id)key;
- (id)buildUIKeyboardLayoutMain;
- (id)buildUIKeyboardLayoutAlternate;
- (id)buildUIKeyboardLayoutAlphabet;
- (id)buildUIKeyboardLayoutNumbers;
- (id)buildUIKeyboardLayoutAlphabetTransparent;
- (id)buildUIKeyboardLayoutNumbersTransparent;
- (id)buildUIKeyboardLayoutPhonePad;
- (id)buildUIKeyboardLayoutPhonePadAlt;
- (id)buildUIKeyboardLayoutPhonePadTransparent;
- (id)buildUIKeyboardLayoutPhonePadAltTransparent;
- (id)buildUIKeyboardLayoutNumberPad;
- (id)buildUIKeyboardLayoutNumberPadTransparent;
- (id)buildUIKeyboardLayoutURL;
- (id)buildUIKeyboardLayoutURLAlt;
- (id)buildUIKeyboardLayoutURLTransparent;
- (id)buildUIKeyboardLayoutURLAltTransparent;
- (id)buildUIKeyboardLayoutSMSAddressing;
- (id)buildUIKeyboardLayoutSMSAddressingAlt;
- (id)buildUIKeyboardLayoutSMSAddressingTransparent;
- (id)buildUIKeyboardLayoutSMSAddressingAltTransparent;
- (id)buildUIKeyboardLayoutEmailAddress;
- (id)buildUIKeyboardLayoutEmailAddressAlt;
- (id)buildUIKeyboardLayoutEmailAddressTransparent;
- (id)buildUIKeyboardLayoutEmailAddressAltTransparent;

- (void)addSublayout:(UIView *)sublayout forKey:(id)key;
- (id)layoutKeyForKeyboardType:(int)keyboardType withAppearance:(int)appearance;
- (void)showKeyboardTypeForKey:(id)key;
- (UIView *)sublayoutForKey:(id)key;
- (UIView *)activeSublayoutKey;
- (UIView *)activeSublayout;

- (UIKeyDefinition *)activeKey;
- (UIImage *)overlayImageForKey:(UIKeyDefinition *)key;
- (BOOL)shouldCacheViewForKey:(UIKeyDefinition *)key;
- (void)activateCompositeKey:(UIKeyDefinition *)key;

- (void)touchDownWithKey:(UIKeyDefinition *)key atPoint:(CGPoint)point;
- (void)deactivateActiveKeys;

- (UIKeyDefinition *)activeKey;
- (UIKeyDefinition *)keyForPoint:(CGPoint)point;

- (void)activateCompositeKey:(UIKeyDefinition *)key;
- (void)activateKey:(UIKeyDefinition *)key;
- (void)activateKeyWithIndex:(NSUInteger)index;
- (void)activateFirstKeyOfType:(NSUInteger)keyType;

- (NSUInteger)keyHitTest:(CGPoint)point;

- (void)showPopupVariantsForKey:(UIKeyDefinition *)key;
- (void)layoutSubview:(id)subview selectedString:(id)selectedString;
- (BOOL)isLongPressedKey:(UIKeyDefinition *)key;
- (NSString *)inputStringForKey:(UIKeyDefinition *)key;
- (id)cacheKeyForKey:(UIKeyDefinition *)key;
- (UIKeyDefinition *)inputKeyboardKeyForKey:(UIKeyDefinition *)eky;
- (id)alternateSublayoutKey:(id)key;
- (BOOL)handleHandEvent:(GSEvent *)gsEvent;
- (void)touchDownWithKey:(UIKeyDefinition *)key atPoint:(CGPoint)point;

- (int)keyHitTestUniversal:(CGPoint)point touchStage:(int)touchStage atTime:(double)time withPathInfo:(GSPathInfo *)pathInfo;

- (void)touchDown:(GSEvent *)gsEvent withPathInfo:(GSPathInfo *)pathInfo;
- (void)touchDragged:(GSEvent *)gsEvent withPathInfo:(GSPathInfo *)pathInfo;
- (void)touchUp:(GSEvent *)gsEvent withPathInfo:(GSPathInfo *)pathInfo;

@end
