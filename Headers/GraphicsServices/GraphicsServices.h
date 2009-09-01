#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

struct GSPathPoint {
	char unk0;
	char unk1;
	short int status;
	int unk2;
	float x;
	float y;
};
typedef struct {
	int unk0;
	int unk1;
	int type;
	int subtype;
	float unk2;
	float unk3;
	float x;
	float y;
	int timestamp1;
	int timestamp2;
	int unk4;
	int modifierFlags;
	int unk5;
	int unk6;
	int mouseEvent;
	short int dx;
	short int fingerCount;
	int unk7;
	int unk8;
	char unk9;
	char numPoints;
	short int unk10;
	struct GSPathPoint points[10];// 0 to numPoints-1
} GSEvent;
typedef struct GSEvent *GSEventRef;

extern CGPoint GSEventGetLocationInWindow(GSEventRef event);
extern UIDeviceOrientation GSEventDeviceOrientation(GSEventRef event);
extern unsigned int GSEventGetType(GSEventRef event);

typedef struct {
	unsigned char pathIndex;
	unsigned char pathIdentity;
	unsigned char pathProximity;
	float pathPressure;
	float pathMajorRadius;
	CGPoint pathLocation;
	void *pathWindow;
} GSPathInfo;

#define GSEventPointInWindow() ((gsEvent)?GSEventGetLocationInWindow(gsEvent):(CGPoint){0.0f, 0.0f})
#define GSEventPointInView() [self convertPoint:GSEventPointInWindow() fromView:[self window]]
#define GSEventGetLocationInView(gsEvent, view) ({ \
	UIView *GSEventGetLocationInView = view; \
	[GSEventGetLocationInView convertPoint:GSEventGetLocationInWindow(gsEvent) fromView:[GSEventGetLocationInView window]]; \
})

