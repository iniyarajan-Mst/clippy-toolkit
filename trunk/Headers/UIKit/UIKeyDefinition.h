#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum UIKeyType {
        UIKeyTypeNormal = 1,
        UIKeyTypeDelete = 3,
        UIKeyTypeSpace  = 4,
        UIKeyTypeReturn = 5,
        UIKeyTypeShift  = 6,
        UIKeyTypeInternational = 7
} UIKeyType;

typedef enum UIKeyDefinitionDownActionFlag {
        UIKeyFlagActivateKey           = 1,
        UIKeyFlagSendActionOnTouchDown = 2,
        UIKeyFlagPlaySound             = 4,
        UIKeyFlagShiftKey              = 0x10,
        UIKeyFlagInternationalKey      = 0x20,
        UIKeyFlagDeleteKey             = 0x40,
        UIKeyFlagHasLongPressAction    = 0x80,
        UIKeyFlagRomanAccents          = 0x8000,
        UIKeyFlagURLDomainVariants     = 0x10000,
        UIKeyFlagEmailDomainVariants   = 0x20000,
        UIKeyFlagCurrencyVariants      = 0x40000,       // ?
        UIKeyFlagFunctionKeysUnknown   = 0x80000
} UIKeyDefinitionDownActionFlag;

typedef enum UIKeyDefinitionUpActionFlag {
        UIKeyFlagOutputValue           = 2,             // do not set this field if the value is intended to be invisible, e.g. "shift", "delete", etc.
        UIKeyFlagDeactivateKey         = 8,
        UIKeyFlagSwitchPlane           = 0x100,
        UIKeyFlagToggleShift           = 0x400,
        UIKeyFlagStopAutoDelete        = 0x800,
        UIKeyFlagChangeInputMode       = 0x1000,        // effective only for the intl key.
        UIKeyFlagSkipCandidateList     = 0x10000
} UIKeyDefinitionUpActionFlag;

typedef struct {
	CGRect bg_area;
	CGRect pop_bg_area;
	CGRect pop_char_area;
	CGRect accent_frame;
	CGRect pop_padding;
	NSString* value;
	NSString* shifted;
	enum UIKeyDefinitionDownActionFlag down_flags;
	enum UIKeyDefinitionUpActionFlag up_flags;
	enum UIKeyType key_type;
	NSString* pop_type;
} UIKeyDefinition;