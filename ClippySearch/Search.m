#import <Clippy/Clippy.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>

@interface SearchCommand : CPCommand
@end

@implementation SearchCommand

- (NSString *)title
{
	return @"Search";
}

- (NSString *)searchAddressWithQuery:(NSString *)query
{
	NSDictionary *safariSettings = [NSDictionary dictionaryWithContentsOfFile:@"/var/mobile/Library/Preferences/com.apple.mobilesafari.plist"];
	NSNumber *searchEngineSetting = [safariSettings objectForKey:@"SearchEngineSetting"];
	NSString *baseURL;
	if ([searchEngineSetting intValue] == 1)
		baseURL = @"http://m.yahoo.com/apple/onesearch?p=%@";
	else
		baseURL = @"http://www.google.com/search?q=%@&ie=UTF-8&oe=UTF-8&client=safari";
	return [NSString stringWithFormat:baseURL, [query stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
}

- (BOOL)compatibleWithObject:(id)object
{
	NSString *text = [CPCommand textForObject:object];
	// Require text to search, but disallow text with newlines
	if ([text length] == 0)
		return false;
	if ([text rangeOfString:@"\n"].length != 0)
		return false;
	if ([text rangeOfString:@"\r"].length != 0)
		return false;
	return true;
}
- (void)performWithObject:(id)object
{
	NSString *text = [CPCommand textForObject:object];
	NSURL *url = [NSURL URLWithString:[self searchAddressWithQuery:text]];
	[[UIApplication sharedApplication] openURL:url];
}

@end

void SearchInitialize()
{
	[SearchCommand registerClass];
}
