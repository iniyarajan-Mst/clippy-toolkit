/*
 
 Copyright (C) 2009 Id Software, Inc.
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 
 */

#import "wolf3dAppDelegate.h"
//#import "wolf_player.h"
#import "EAGLView.h"
#import <AudioToolbox/AudioServices.h>

#import "wolfiphone.h"

#import "AVSystemController.h"
#import "UIApplication+Private.h"

extern int iphoneStartup();
extern void iphoneShutdown();

char iphoneDocDirectory[1024];
char iphoneAppDirectory[1024];


void vibrateDevice() {
	printf( "vibrate\n" );
	AudioServicesPlaySystemSound( kSystemSoundID_Vibrate );
}

@implementation wolf3dAppDelegate

@synthesize window;
@synthesize glView;

- (float)getAndRestrictVolume
{
	AVSystemController *avc = SharedAVSystemController;
	NSString *categoryName;
	float currentVolume;
	if ([avc getActiveCategoryVolume:&currentVolume andName:&categoryName]) {
		if (currentVolume == 1.0f) {
			currentVolume = 1.0f - 0.063f;
			[avc setActiveCategoryVolumeTo:currentVolume];
		} else if (currentVolume < 0.063f) {
			currentVolume = 0.063f;
			[avc setActiveCategoryVolumeTo:currentVolume];
		}
	}
	return currentVolume;
}

- (void)_interceptVolumeEvents
{
	activeVolume = [self getAndRestrictVolume];
	[volumeTimer invalidate];
	[volumeTimer release];
	volumeTimer = nil;
}

- (void)scheduleInterceptingVolumeEvents
{
	activeVolume = 0.0f;
	if (volumeTimer) {
		[volumeTimer invalidate];
		[volumeTimer release];
	}
	volumeTimer = [[NSTimer scheduledTimerWithTimeInterval:1.0f target:self selector:@selector(_interceptVolumeEvents) userInfo:nil repeats:NO] retain];
}

- (void)volumeChanged:(NSNotification *)notification
{
	if (activeVolume != 0.0f) {
		// Volume Interception is active
		AVSystemController* avc = SharedAVSystemController;
		float newVolume;
		NSString *categoryName;
		if ([avc getActiveCategoryVolume:&newVolume andName:&categoryName]) {
			if (activeVolume < newVolume) {
				volumeButtonState = VOLUME_STATE_UP;
				[avc setActiveCategoryVolumeTo:activeVolume];
				return;
			} else if (activeVolume == newVolume) {
				return;
			}
		}
	}
	// Default volume processing, but restrict volume range and schedule intercepting events
	[self getAndRestrictVolume];
	[self scheduleInterceptingVolumeEvents];
}

- (void)applicationDidFinishLaunching:(UIApplication *)application {
	application.statusBarHidden = YES;
	application.statusBarOrientation = UIInterfaceOrientationLandscapeLeft;
	
	// get the documents directory, where we will write configs and save games
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString *documentsDirectory = [paths objectAtIndex:0];
	[documentsDirectory getCString: iphoneDocDirectory 
							maxLength: sizeof( iphoneDocDirectory ) - 1
							encoding: NSASCIIStringEncoding ];
	
	// get the app directory, where our data files live
	paths = NSSearchPathForDirectoriesInDomains(NSApplicationDirectory, NSUserDomainMask, YES);
	NSString *appDirectory = documentsDirectory = [paths objectAtIndex:0];
	[appDirectory getCString: iphoneAppDirectory 
							maxLength: sizeof( iphoneAppDirectory ) - 1
							encoding: NSASCIIStringEncoding ];
	
	// start the flow of accelerometer events
	UIAccelerometer *accelerometer = [UIAccelerometer sharedAccelerometer];
	accelerometer.delegate = self;
	accelerometer.updateInterval = 0.01;
	
	// disable the volume HUD
	UIApplication *app = [UIApplication sharedApplication];
	[app setSystemVolumeHUDEnabled:NO forAudioCategory:@"Ringtone"];
	[app setSystemVolumeHUDEnabled:NO];
	
	// listen for volume events
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:@selector(volumeChanged:) 
												 name:@"AVSystemController_SystemVolumeDidChangeNotification" 
											   object:nil];	
	
	// schedule getting the active volume
	[self scheduleInterceptingVolumeEvents];
	
	// do all the game startup work
	iphoneStartup();
}


- (void)applicationWillResignActive:(UIApplication *)application {
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
}

- (void)applicationWillTerminate:(UIApplication *)application {
	iphoneShutdown();
}



- (void)dealloc {
	[window release];
	[glView release];
	[super dealloc];
}

- (void)restartAccelerometerIfNeeded {
	W32 Sys_Milliseconds();

	// I have no idea why this seems to happen sometimes...
	if ( Sys_Milliseconds() - lastAccelUpdateMsec > 1000 ) {
		static int count;
		if ( ++count < 100 ) {
			printf( "Restarting accelerometer updates.\n" );
		}
		UIAccelerometer *accelerometer = [UIAccelerometer sharedAccelerometer];
		accelerometer.delegate = self;
		accelerometer.updateInterval = 0.01;
	}
}

- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration
{	
	W32 Sys_Milliseconds();
	void WolfensteinTilts( float *tilts );
	float acc[4];
	acc[0] = acceleration.x;
	acc[1] = acceleration.y;
	acc[2] = acceleration.z;
	acc[3] = acceleration.timestamp;
	WolfensteinTilts( acc );
	lastAccelUpdateMsec = Sys_Milliseconds();
}

@end



