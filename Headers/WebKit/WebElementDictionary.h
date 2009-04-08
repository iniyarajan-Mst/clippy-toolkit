#import <Foundation/Foundation.h>
#import <WebCore/WebCore.h>

@interface WebElementDictionary : NSDictionary
- (DOMNode *)_domNode;
- (id)_webFrame;
- (id)_altDisplayString;
- (id)_spellingToolTip;
- (id)_image;
- (id)_imageRect;
- (id)_absoluteImageURL;
- (id)_isSelected;
- (id)_title;
- (id)_absoluteLinkURL;
- (id)_targetWebFrame;
- (id)_titleDisplayString;
- (id)_textContent;
- (id)_isLiveLink;
- (id)_isContentEditable;
- (id)_linkRect;
@end