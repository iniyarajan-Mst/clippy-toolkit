#import <UIKit/UIResponder.h>
#import <GraphicsServices/GraphicsServices.h>

@interface UIResponder (Private)
- (void)mouseDown:(GSEvent *)gsevent;
- (void)mouseUp:(GSEvent *)gsevent;
- (void)mouseDragged:(GSEvent *)gsevent;
- (void)mouseEntered:(GSEvent *)gsevent;
- (void)mouseExited:(GSEvent *)gsevent;
- (void)mouseMoved:(GSEvent *)gsevent;
@end
