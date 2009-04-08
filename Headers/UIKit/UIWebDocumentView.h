#import <UIKit/UIView.h>
#import <WebCore/WebCore.h>
#import <WebKit/WebKit.h>

@interface UITiledView : UIView
{
    NSMutableArray *_rows;
    NSMutableArray *_unusedTiles;
    NSString *_minificationFilter;
    CGRect _visibleRect;
    CGRect _requiredDrawRect;
    CGRect _dirtyRect;
    CGSize _tileSize;
    CGSize _firstTileSize;
    CGPoint _tileOrigin;
    NSUInteger _maxTileCount;
    BOOL _drawsGrid;
    BOOL _isTilingEnabled;
    BOOL _logsTilingChanges;
    BOOL _tileDrawingEnabled;
    BOOL _inLayout;
    BOOL _allNewTilesNeeded;
    BOOL _positionsTilesFromOrigin;
    BOOL _sizesTilesToFit;
    BOOL _tilesOpaque;
    BOOL _adjustsMaxTileCountDynamically;
}
@end

@class WebViewReachabilityObserver, UITextLoupe, UIAutoscrollTimer, CALayer, UIInformalDelegate, WebPDFView, UIModalView;
@protocol UIFormControl;

@interface UIWebDocumentView : UITiledView
{
@public
    struct WKWindow *_window;
    WebView *_webView;
    WebViewReachabilityObserver *_reachabilityObserver;
    id m_parentTextView;
    id _delegate;
    id _textSuggestionDelegate;
    id _editingDelegate;
    float _doubleTapDelay;
    struct CGRect _doubleTapRect;
    struct CGRect _mainDocumentDoubleTapRect;
    struct CGPoint _scrollPoint;
    struct CGPoint _doubleTapStartPosition;
    double _doubleTapStartTime;
    struct CGSize _pendingSize;
    int _orientation;
    UITextLoupe *_textLoupe;
    DOMHTMLElement *_standaloneEditingElement;
    CGPoint _mouseDownPoint;
    double _mouseDownTime;
    UIAutoscrollTimer *_autoscrollTimer;
    struct __CFDictionary *_plugInViews;
    CGRect *_accurateDirtyRects;
    unsigned int _accurateDirtyRectCount;
    CALayer *_contentLayersHostingLayer;
    UITextInputTraits *_traits;
    struct {
        NSMutableArray *all;
        NSMutableArray *html;
        NSMutableArray *javascript;
        NSMutableArray *css;
        NSMutableArray *error;
        NSMutableArray *warning;
        NSMutableArray *tip;
        NSMutableArray *log;
    } _messages;
    struct {
        char isEdited;
        char isTransitioning;
        char allowsUnapprovedFocus;
        char zoomsFocusedFormControl;
        DOMNode<UIFormControl> *element;
        UIInformalDelegate *delegate;
    } _forms;
    struct {
        NSTimer *timer;
        CGPoint location;
        char isBlocked;
        char isCancelled;
        char isOnWebThread;
        char isDisplayingHighlight;
        char attemptedClick;
        char isGestureScrolling;
        struct CGPoint gestureScrollPoint;
        struct CGPoint gestureCurrentPoint;
        char hasAttemptedGestureScrolling;
        UIView *candidate;
        char forwardingGuard;
        SEL mouseUpForwarder;
        SEL mouseDraggedForwarder;
        DOMNode *element;
        UIInformalDelegate *delegate;
        UIModalView *imageSheet;
        char allowsImageSheet;
        struct {
            char active;
            char defaultPrevented;
            NSMutableArray *regions;
        } directEvents;
        NSMutableSet *touches;
    } _interaction;
    struct {
        WebPDFView *view;
        NSTimer *timer;
    } _pdf;
    struct {
        struct CGSize size;
        float initialScale;
        float minimumScale;
        float maximumScale;
        char allowsUserScaling;
    } _viewportConfigurations[6];
    struct CGSize _minimumSize;
    int _documentType;
    float _documentScale;
    struct CGRect _documentBounds;
    int _enabledGestures;
    unsigned int _customConfigurations;
    unsigned int _mouseDownCount;
    unsigned int _webCoreNeedsSetNeedsDisplay:1;
    unsigned int _webCoreNeedsDraw:1;
    unsigned int _ignoresFocusingMouse:1;
    unsigned int _ignoresKeyEvents:1;
    unsigned int _autoresizes:1;
    unsigned int _scalesToFit:1;
    unsigned int _hasCustomScale:1;
    unsigned int _userScrolled:1;
    unsigned int _pageNeedsReset:1;
    unsigned int _hasScrollPoint:1;
    unsigned int _setNeedsDisplayWasForced:1;
    unsigned int _gesturesDisabled:1;
    unsigned int _doubleTapRectIsReplaced:1;
    unsigned int _standaloneEditableView:1;
    unsigned int _isFieldEditor:1;
    unsigned int _widgetEditingView:1;
    unsigned int _mouseDragged:1;
    unsigned int _textLoupeActive:1;
    unsigned int _mouseReentrancyGuard:1;
    unsigned int _smoothsFonts:1;
    unsigned int _isShowingFullScreenPlugIn:1;
    unsigned int _isSettingRedrawFrame:1;
    unsigned int _needsScrollNotifications:1;
    unsigned int _loadsSynchronously:1;
    unsigned int _detectsPhoneNumbers:1;
    unsigned int _mouseDown:1;
    unsigned int _usePreTimberlineTransparencyBehavior:1;
}
- (NSString *)text;
// DOM Events
- (DOMRange *)selectedDOMRange;
- (void)setSelectedDOMRange:(DOMRange *)range affinityDownstream:(NSSelectionAffinity)affinity;
// Selection Events
- (void)updateSelectionWithPoint:(CGPoint)point;
// Legacy Selection
- (NSRange)selectionRange;
- (CGRect)rectForNSRange:(NSRange)range;
- (CGRect)rectContainingCaretSelection;
- (UIColor *)textColorForCaretSelection;
- (void)cancelInteraction;
// Text Loupe
- (BOOL)textLoupeActive;
- (void)textLoupeTimerAction;
- (UIView *)textLoupe;

- (BOOL)cancelMouseTracking;
- (BOOL)cancelTouchTracking;
- (void)cancelInteraction;

// Web View
- (WebView *)webView;
- (DOMNode *)approximateNodeAtViewportLocation:(CGPoint *)point;


@end