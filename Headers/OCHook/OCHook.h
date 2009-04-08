#import <objc/runtime.h>

#ifndef OCAppName
#define OCAppName "OCHook"
#endif

// Some Debugging/Logging Commands

#define OCStringify_(x) #x
#define OCStringify(x) OCStringify_(x)

#define OCLog(args...)			NSLog((NSString *)CFSTR(OCAppName ": %@"), [NSString stringWithFormat:args])
#define OCLogSource(args...)	NSLog((NSString *)CFSTR(OCAppName " @ " OCStringify(__LINE__) " in %s: %@"), __FUNCTION__, [NSString stringWithFormat:args])

#ifdef OCDebug
	#define OCDebugLog(args...)			OCLog(args)
	#define OCDebugLogSource(args...)	OCLogSource(args)
#else
	#define OCDebugLog(args...)			do { } while(0)
	#define OCDebugLogSource(args...)	do { } while(0)
#endif

#define OCCallStack \
	((NSArray *)({ \
		NSArray *callStack; \
		@try { \
			[NSException raise:@"Call Stack" format:""]; \
		} @catch(NSException *e) { \
			callStack = [e callStackReturnAddresses]; \
		} \
		callStack; \
	}))
#define OCCallStackAsString [OCCallStack description]

// To Load classes for hooking

#define OCWithClass(classValue) \
	for (Class withClass = classValue, fakeI = (Class)1; fakeI != Nil; fakeI = Nil) \
		if (withClass) { \
			unsigned int withClassMethodCount = 0; \
			Method *withClassMethods = class_copyMethodList(withClass, &withClassMethodCount); \
			do
#define OCWithClassHook(classValue, _shouldHook) \
	for (Class withClass = classValue, fakeI = (Class)1; fakeI != Nil; fakeI = Nil) \
		if (withClass) { \
			unsigned int withClassMethodCount = 0; \
			Method *withClassMethods = class_copyMethodList(withClass, &withClassMethodCount); \
			BOOL shouldHook = _shouldHook; \
			do
#define OCCatchNilClass \
			while(0); \
			free(withClassMethods); \
			break; \
		} else\
	
// To Hook/Restore inside OCWithClass blocks

#define OCHook(sel, class, imp) do { \
	Method method_ ## class ## _ ## imp = class_getInstanceMethod(withClass, @selector(sel)); \
	IMP oldImp_ ## class ## _ ## imp = method_getImplementation(method_ ## class ## _ ## imp); \
	if ((void *)oldImp_ ## class ## _ ## imp != (void *)&$ ## class ## _ ## imp) { \
		_ ## class ## _ ## imp = (void *)oldImp_ ## class ## _ ## imp; \
		for (unsigned int i = 0; i != withClassMethodCount; ++i) { \
			if (withClassMethods[i] == method_ ## class ## _ ## imp) { \
				method_setImplementation(method_ ## class ## _ ## imp, (IMP)&$ ## class ## _ ## imp); \
					OCDebugLogSource(@"Set Implementation on: " @#class @" %@", NSStringFromSelector(@selector(sel))); \
				goto foundMethod_ ## class ## _ ## imp; \
			} \
		} \
		class_addMethod(withClass, @selector(sel), (IMP)&$ ## class ## _ ## imp, method_getTypeEncoding(method_ ## class ## _ ## imp)); \
		OCDebugLogSource(@"Add Method on: " @#class @" %@", NSStringFromSelector(@selector(sel))); \
	} \
	foundMethod_ ## class ## _ ## imp:; \
} while(0)

#define OCRestore(sel, class, imp) do { \
	if (_ ## class ## _ ## imp) { \
		OCDebugLogSource(@"Removing hook on: " @#class @" %@", NSStringFromSelector(@selector(sel))); \
		Method method_ ## class ## _ ## imp = class_getInstanceMethod(withClass, @selector(sel)); \
		method_setImplementation(method_ ## class ## _ ## imp, (IMP)_ ## class ## _ ## imp); \
	} \
} while(0)

/*#define OCSetHook(sel, class, imp) do { \
	Method method_ ## class ## _ ## imp = class_getInstanceMethod(withClass, @selector(sel)); \
	if (shouldHook) { \
		IMP oldImp_ ## class ## _ ## imp = method_getImplementation(method_ ## class ## _ ## imp); \
		if ((void *)oldImp_ ## class ## _ ## imp != (void *)&$ ## class ## _ ## imp) { \
			_ ## class ## _ ## imp = (void *)oldImp_ ## class ## _ ## imp; \
			for (unsigned int i = 0; i != withClassMethodCount; ++i) \
				if (withClassMethods[i] == method_ ## class ## _ ## imp) { \
					method_setImplementation(method_ ## class ## _ ## imp, (IMP)&$ ## class ## _ ## imp); \
					OCDebugLogSource(@"Set Implementation on: " @#class @" %@", NSStringFromSelector(@selector(sel))); \
					goto foundMethod_ ## class ## _ ## imp; \
				} \
			class_addMethod(withClass, @selector(sel), (IMP)&$ ## class ## _ ## imp, method_getTypeEncoding(method_ ## class ## _ ## imp)); \
			OCDebugLogSource(@"Add Method on: " @#class @" %@", NSStringFromSelector(@selector(sel))); \
		} \
	} else if (_ ## class ## _ ## imp != NULL) { \
		OCDebugLogSource(@"Removing hook on: " @#class @" %@", NSStringFromSelector(@selector(sel))); \
		method_setImplementation(method_ ## class ## _ ## imp, (IMP)_ ## class ## _ ## imp); \
	} \
	foundMethod_ ## class ## _ ## imp:; \
} while(0)*/

#define OCAddMethod(sel, class, imp, encoding) do { \
	if (class_getInstanceMethod(withClass, @selector(sel)) == NULL) \
		class_addMethod(withClass, @selector(sel), (IMP)&$ ## class ## _ ## imp, encoding); \
} while(0)

// Retrieveing classes/testing against objects
#define OCClass(name) [name class]
#define OCLateClass(name) objc_getClass(#name)

#define OCMetaclass(name) object_getClass(OCClass(name))
#define OCLateMetaclass(name) object_getClass(OCMetaclass(name))

#define OCIsClass(obj, name) [obj isKindOfClass:OCClass(name)]
#define OCIsLateClass(obj, name) [obj isKindOfClass:objc_lookUpClass(#name)]

#define OCRespondsTo(obj, sel) [obj respondsToSelector:@selector(sel)]

#define OCRelease(var) do { \
	[var release]; \
	var = nil; \
} while(0)

//#define OCLateAlloc(name) NSAllocateObject(OCLateClass(name), 0, nil)
#define OCLateAlloc(name) [(id)OCLateClass(name) alloc]
		

// For Replacement Functions

#define OCReplacement(type, class_type, name, args...) \
	static type (*_ ## class_type ## _ ## name)(class_type *self, SEL _cmd, ##args); \
	static type $ ## class_type ## _ ## name(class_type *self, SEL _cmd, ##args) 
	
#define OCClassReplacement(type, class_type, name, args...) \
	static type (*_ ## class_type ## _ ## name)(Class self, SEL _cmd, ##args); \
	static type $ ## class_type ## _ ## name(Class self, SEL _cmd, ##args) 
	
#define OCSuper(class_type, name, args...) \
	_ ## class_type ## _ ## name(self, _cmd, ##args)
	
// Scope Autorelease
#ifdef __OBJC__
	#import <Foundation/Foundation.h>
	#define OCScopeReleased __attribute__((cleanup($scopeReleaseObject)))
	#define OCAutoreleasePoolForScope() NSAutoreleasePool *scopeReleasePool OCScopeReleased = [[NSAutoreleasePool alloc] init];
	static void inline $scopeReleaseObject(id *sro)
	{
	    [*sro release];
	}
#endif
