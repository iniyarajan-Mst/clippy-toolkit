#import "WAKResponder.h"

#import <CoreGraphics/CoreGraphics.h>

struct WKView;

struct _WKViewContext {
    void *drawCallback;
    void *drawUserInfo;
    void *eventCallback;
    void *eventUserInfo;
    void *notificationCallback;
    void *notificationUserInfo;
    void *layoutCallback;
    void *layoutUserInfo;
    void *responderCallback;
    void *responderUserInfo;
    void *hitTestCallback;
    void *hitTestUserInfo;
    void *willRemoveSubviewCallback;
    void *invalidateGStateCallback;
};

@interface WAKView : WAKResponder
{
    struct _WKViewContext viewContext;
    struct WKView *viewRef;
    NSMutableSet *subviewReferences;
}
@end
