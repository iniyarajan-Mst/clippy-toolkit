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
extern CGPoint GSEventGetLocationInWindow(GSEvent *event);
extern UIDeviceOrientation GSEventDeviceOrientation(GSEvent *event);

typedef struct {
	unsigned char pathIndex;
	unsigned char pathIdentity;
	unsigned char pathProximity;
	float pathPressure;
	float pathMajorRadius;
	CGPoint pathLocation;
	void *pathWindow;
} GSPathInfo;

#define GSEventPointInView() [self convertPoint:GSEventGetLocationInWindow(gsEvent) fromView:[self window]]
#define GSEventPointInWindow() GSEventGetLocationInWindow(gsEvent)

