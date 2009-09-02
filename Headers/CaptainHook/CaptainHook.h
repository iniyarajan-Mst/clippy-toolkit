#import <objc/runtime.h>
#import <Foundation/NSObject.h>

#ifndef CHAppName
#define CHAppName "CaptainHook"
#endif

// Some Debugging/Logging Commands

#define CHStringify_(x) #x
#define CHStringify(x) CHStringify_(x)
#define CHConcat_(a, b) a ## b
#define CHConcat(a, b) CHConcat_(a, b)

#define CHNothing() do { } while(0)

#define CHLocationInSource [NSString stringWithFormat:@CHStringify(__LINE__) " in %s", __FUNCTION__]

#define CHLog(args...)			NSLog(@CHAppName ": %@", [NSString stringWithFormat:args])
#define CHLogSource(args...)	NSLog(@CHAppName " @ " CHStringify(__LINE__) " in %s: %@", __FUNCTION__, [NSString stringWithFormat:args])

#ifdef CHDebug
	#define CHDebugLog(args...)			CHLog(args)
	#define CHDebugLogSource(args...)	CHLogSource(args)
#else
	#define CHDebugLog(args...)			CHNothing()
	#define CHDebugLogSource(args...)	CHNothing()
#endif

// Constructor
#define CHConstructor static __attribute__((constructor)) void CHConcat(CHConstructor, __LINE__)()
#define CHInline inline __attribute__((always_inline))

// Retrieveing classes/testing against objects

#define CHDeclareClass(name) \
	@class name; \
	static id name ## $;
	
#define CHLoadLateClass(name) ({ \
	name ## $ = objc_getClass(#name); \
})
#define CHLoadClass(name) ({ \
	name ## $ = [name class]; \
})

#define CHClass(name) name ## $
#define CHMetaClass(name) object_getClass(CHClass(name))
#define CHAlloc(name) [CHClass(name) alloc]
#define CHIsClass(obj, name) [obj isKindOfClass:CHClass(name)]
#define CHRespondsTo(obj, sel) [obj respondsToSelector:@selector(sel)]

// To Load classes for hooking

#define CHSelFromImpName(sel) ({ \
	size_t selector_len = strlen(#sel)+1; \
	char sel_name[selector_len]; \
	for (size_t i = 0; i < selector_len; i++) \
		sel_name[i] = (#sel[i] == '$')?':':#sel[i]; \
	sel_registerName(sel_name); \
})

#ifdef CHUseSubstrate
#define CHHookImpl(className, impName, classVar, sel) ({ \
	if (classVar) { \
		SEL selector = sel; \
		MSHookMessageEx(classVar, selector, (IMP)&$ ## className ## _ ## impName, (IMP *)&_ ## className ## _ ## impName); \
		if (!_ ## className ## _ ## impName) \
			class_addMethod(classVar, selector, (IMP)&$ ## className ## _ ## impName, "@@:"); \
	} \
})
#else
#define CHHookImpl(className, impName, classVal, sel) ({ \
	Class classVar = classVal; \
	if (classVar) { \
		SEL selector = sel; \
		Method method = class_getInstanceMethod(classVar, selector); \
		if (method) { \
			_ ## className ## _ ## impName = (__typeof__(_ ## className ## _ ## impName))method_getImplementation(method); \
			if (class_addMethod(classVar, selector, (IMP)&$ ## className ## _ ## impName, method_getTypeEncoding(method)) == NO) \
				method_setImplementation(method, (IMP)&$ ## className ## _ ## impName); \
		} else { \
			class_addMethod(classVar, selector, (IMP)&$ ## className ## _ ## impName, "@@:"); \
		} \
	} \
})
#endif

#define CHHook(class, imp) CHHookImpl(class, imp, class ## $, CHSelFromImpName(imp))
#define CHHook0(class, name) CHHookImpl(class, name, class ## $, @selector(name))
#define CHHook1(class, name1) CHHookImpl(class, name1 ## $, class ## $, @selector(name1:))
#define CHHook2(class, name1, name2) CHHookImpl(class, name1 ## $ ## name2 ## $, class ## $, @selector(name1:name2:))
#define CHHook3(class, name1, name2, name3) CHHookImpl(class, name1 ## $ ## name2 ## $ ## name3 ## $, class ## $, @selector(name1:name2:name3:))
#define CHHook4(class, name1, name2, name3, name4) CHHookImpl(class, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $, class ## $, @selector(name1:name2:name3:name4:))
#define CHHook5(class, name1, name2, name3, name4, name5) CHHookImpl(class, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $ ## name5 ## $, class ## $, @selector(name1:name2:name3:name4:name5:))

#define CHClassHook(class, imp) CHHookImpl(class, imp, object_getClass(class ## $), CHSelFromImpName(imp))
#define CHClassHook0(class, name) CHHookImpl(class, name, object_getClass(class ## $), @selector(name))
#define CHClassHook1(class, name1) CHHookImpl(class, name1 ## $, object_getClass(class ## $), @selector(name1:))
#define CHClassHook2(class, name1, name2) CHHookImpl(class, name1 ## $ ## name2 ## $, object_getClass(class ## $), @selector(name1:name2:))
#define CHClassHook3(class, name1, name2, name3) CHHookImpl(class, name1 ## $ ## name2 ## $ ## name3 ## $, object_getClass(class ## $), @selector(name1:name2:name3:))
#define CHClassHook4(class, name1, name2, name3, name4) CHHookImpl(class, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $, object_getClass(class ## $), @selector(name1:name2:name3:name4:))
#define CHClassHook5(class, name1, name2, name3, name4, name5) CHHookImpl(class, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $ ## name5 ## $, object_getClass(class ## $), @selector(name1:name2:name3:name4:name5:))

// For Replacement Functions
#define CHMethod(type, class_type, name, args...) \
	CHDeclareClass(class_type) \
	static type (*_ ## class_type ## _ ## name)(class_type *self, SEL _cmd, ##args); \
	static type $ ## class_type ## _ ## name(class_type *self, SEL _cmd, ##args) 
/*#define CHMethod(type, class_type, name, args...) \
	static type (*_ ## class_type ## _ ## name)(class_type *self, SEL _cmd, ##args); \
	static CHInline type $$ ## class_type ## _ ## name(class_type *self, SEL _cmd, ##args); \
	static type $ ## class_type ## _ ## name(class_type *self, SEL _cmd, type (*_CHSuper)(class_type *self, SEL _cmd, ##args), ##args) { \
		return 		
	}
	static CHInline type $$ ## class_type ## _ ## name(class_type *self, SEL _cmd, ##args); \*/
#define CHMethod0(type, class_type, name) \
	CHMethod(type, class_type, name)
#define CHMethod1(type, class_type, name1, arg1) \
	CHMethod(type, class_type, name1 ## $, arg1)
#define CHMethod2(type, class_type, name1, arg1, name2, arg2) \
	CHMethod(type, class_type, name1 ## $ ## name2 ## $, arg1, arg2)
#define CHMethod3(type, class_type, name1, arg1, name2, arg2, name3, arg3) \
	CHMethod(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $, arg1, arg2, arg3)
#define CHMethod4(type, class_type, name1, arg1, name2, arg2, name3, arg3, name4, arg4) \
	CHMethod(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $, arg1, arg2, arg3, arg4)
#define CHMethod5(type, class_type, name1, arg1, name2, arg2, name3, arg3, name4, arg4, name5, arg5) \
	CHMethod(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $ ## name5 ## $, arg1, arg2, arg3, arg4, arg5)
	
#define CHClassMethod(type, class_type, name, args...) \
	CHDeclareClass(class_type) \
	static type (*_ ## class_type ## _ ## name)(Class self, SEL _cmd, ##args); \
	static type $ ## class_type ## _ ## name(Class self, SEL _cmd, ##args) 
#define CHClassMethod0(type, class_type, name) \
	CHClassMethod(type, class_type, name)
#define CHClassMethod1(type, class_type, name1, arg1) \
	CHClassMethod(type, class_type, name1 ## $, arg1)
#define CHClassMethod2(type, class_type, name1, arg1, name2, arg2) \
	CHClassMethod(type, class_type, name1 ## $ ## name2 ## $, arg1, arg2)
#define CHClassMethod3(type, class_type, name1, arg1, name2, arg2, name3, arg3) \
	CHClassMethod(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $, arg1, arg2, arg3)
#define CHClassMethod4(type, class_type, name1, arg1, name2, arg2, name3, arg3, name4, arg4) \
	CHClassMethod(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $, arg1, arg2, arg3, arg4)
#define CHClassMethod5(type, class_type, name1, arg1, name2, arg2, name3, arg3, name4, arg4, name5, arg5) \
	CHClassMethod(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $ ## name5 ## $, arg1, arg2, arg3, arg4, arg5)
	
#define CHSuper(class_type, name, args...) \
	_ ## class_type ## _ ## name(self, _cmd, ##args)
#define CHSuper0(class_type, name) \
	CHSuper(class_type, name)
#define CHSuper1(class_type, name1, val1) \
	CHSuper(class_type, name1 ## $, val1)
#define CHSuper2(class_type, name1, val1, name2, val2) \
	CHSuper(class_type, name1 ## $ ## name2 ## $, val1, val2)
#define CHSuper3(class_type, name1, val1, name2, val2, name3, val3) \
	CHSuper(class_type, name1 ## $ ## name2 ## $ ## name3 ## $, val1, val2, val3)
#define CHSuper4(class_type, name1, val1, name2, val2, name3, val3, name4, val4) \
	CHSuper(class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $, val1, val2, val3, val4)
#define CHSuper5(class_type, name1, val1, name2, val2, name3, val3, name4, val4, name5, val5) \
	CHSuper(class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $ ## name5 ## $, val1, val2, val3, val4, val5)

// Declarative-style

#define CHDeclareMethod_(type, class_type, name, sel, args...) \
	CHDeclareClass(class_type) \
	static type (*_ ## class_type ## _ ## name)(class_type *self, SEL _cmd, ##args); \
	static type $ ## class_type ## _ ## name(class_type *self, SEL _cmd, ##args); \
	CHConstructor { \
		if (!class_type ## $) CHLoadLateClass(class_type); \
		CHHookImpl(class_type, name, class_type ## $, @selector(sel)); \
	} \
	static type $ ## class_type ## _ ## name(class_type *self, SEL _cmd, ##args)
#define CHDeclareMethod0(type, class_type, name) \
	CHDeclareMethod_(type, class_type, name, name)
#define CHDeclareMethod1(type, class_type, name1, arg1) \
	CHDeclareMethod_(type, class_type, name1 ## $, name1:, arg1)
#define CHDeclareMethod2(type, class_type, name1, arg1, name2, arg2) \
	CHDeclareMethod_(type, class_type, name1 ## $ ## name2 ## $, name1:name2:, arg1, arg2)
#define CHDeclareMethod3(type, class_type, name1, arg1, name2, arg2, name3, arg3) \
	CHDeclareMethod_(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $, name1:name2:name3:, arg1, arg2, arg3)
#define CHDeclareMethod4(type, class_type, name1, arg1, name2, arg2, name3, arg3, name4, arg4) \
	CHDeclareMethod_(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $, name1:name2:name3:name4:, arg1, arg2, arg3, arg4)
#define CHDeclareMethod5(type, class_type, name1, arg1, name2, arg2, name3, arg3, name4, arg4, name5, arg5) \
	CHDeclareMethod_(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $ ## name5 ## $, name1:name2:name3:name4:name5:, arg1, arg2, arg3, arg4, arg5)

#define CHDeclareClassMethod_(type, class_type, name, sel, args...) \
	CHDeclareClass(class_type) \
	static type (*_ ## class_type ## _ ## name)(class_type *self, SEL _cmd, ##args); \
	static type $ ## class_type ## _ ## name(class_type *self, SEL _cmd, ##args); \
	CHConstructor { \
		if (!class_type ## $) CHLoadLateClass(class_type); \
		CHHookImpl(class_type, name, object_getClass(class_type ## $), @selector(sel)); \
	} \
	static type $ ## class_type ## _ ## name(class_type *self, SEL _cmd, ##args)
#define CHDeclareClassMethod0(type, class_type, name) \
	CHDeclareClassMethod_(type, class_type, name, name)
#define CHDeclareClassMethod1(type, class_type, name1, arg1) \
	CHDeclareClassMethod_(type, class_type, name1 ## $, name1:, arg1)
#define CHDeclareClassMethod2(type, class_type, name1, arg1, name2, arg2) \
	CHDeclareClassMethod_(type, class_type, name1 ## $ ## name2 ## $, name1:name2:, arg1, arg2)
#define CHDeclareClassMethod3(type, class_type, name1, arg1, name2, arg2, name3, arg3) \
	CHDeclareClassMethod_(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $, name1:name2:name3:, arg1, arg2, arg3)
#define CHDeclareClassMethod4(type, class_type, name1, arg1, name2, arg2, name3, arg3, name4, arg4) \
	CHDeclareClassMethod_(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $, name1:name2:name3:name4:, arg1, arg2, arg3, arg4)
#define CHDeclareClassMethod5(type, class_type, name1, arg1, name2, arg2, name3, arg3, name4, arg4, name5, arg5) \
	CHDeclareClassMethod_(type, class_type, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $ ## name5 ## $, name1:name2:name3:name4:name5:, arg1, arg2, arg3, arg4, arg5)
	
// Add Ivar to a new class at runtime
#define CHAddIvar(targetClass, name, type) \
	class_addIvar(targetClass, #name, sizeof(type), log2(sizeof(type)), @encode(type))

// Retrieve reference to an Ivar value (can read and assign)
__attribute__((unused))
static inline char *CHIvar(id object, char *name)
{
	Ivar ivar = class_getInstanceVariable(object_getClass(object), name);
	if (ivar)
		return &((char *)object)[ivar_getOffset(ivar)];
	return NULL;
}
#define CHIvar(object, name, type) \
	(*(type*)CHIvar(object, #name))


// Scope Autorelease
__attribute__((unused))
static void CHInline CHScopeReleased(id sro)
{
    [sro release];
}
#define CHScopeReleased __attribute__((cleanup(CHScopeReleased)))

#ifdef __cplusplus
extern "C" void *NSPushAutoreleasePool(void *);
extern "C" void NSPopAutoreleasePool(void *);
#else
void *NSPushAutoreleasePool(void *);
void NSPopAutoreleasePool(void *);
#endif
#define CHAutoreleasePoolForScope() void *CHAutoreleasePoolForScope __attribute__((cleanup(NSPopAutoreleasePool))) = NSPushAutoreleasePool(0)

//#define CHAutoreleasePoolForScope() NSAutoreleasePool *CHAutoreleasePoolForScope CHScopeReleased = [[NSAutoreleasePool alloc] init];

#define CHBuildAssert(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
