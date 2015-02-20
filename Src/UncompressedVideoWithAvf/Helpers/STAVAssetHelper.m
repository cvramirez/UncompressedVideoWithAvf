#import <OcLib/NSObject+OcErrorUtilsHelper.h>
#import <CoreMedia/CoreMedia.h>
#import <OcLib/OcLib.h>
#import "STAVAssetHelper.h"


@implementation STAVAssetHelper

+ (instancetype)newWithUrl:(NSURL *)movieUrl resultSet:(OcResultSet *)resultSet  {
    return [[self alloc] initWithUrl:movieUrl resultSet:resultSet];
}

- (instancetype)initWithUrl:(NSURL *)movieUrl resultSet:(OcResultSet *)resultSet  {

    self = [super init];
    if (self != nil) {
        BOOL isSuccess = [self openAssetWithUrl:movieUrl resultSet:resultSet];
        if (isSuccess) isSuccess = [self validateAssetHasPropertiesRequiredForReading:resultSet];
        if (!isSuccess) {
            self = nil;
        }
    }
    return self;
}

- (BOOL)openAssetWithUrl:(NSURL *)movieUrl resultSet:(OcResultSet *)resultSet  {

    NSDictionary *assetOptions = @{AVURLAssetPreferPreciseDurationAndTimingKey : @YES};
    _asset = [AVURLAsset URLAssetWithURL:movieUrl options:assetOptions];
    BOOL isSuccess = (self.asset != nil);
    if (!isSuccess) {
        [resultSet.codeList addErrorWithCode:@"kOcErr_ArgValueNotRecognized"
                                      format: @"Could not open movie at the specified location: %@", movieUrl.absoluteString];
    }
    return isSuccess;
}

- (BOOL)validateAssetHasPropertiesRequiredForReading:(OcResultSet *)resultSet  {

    // the following two lines are synchronous, UI-thread-blocking calls forcing properties to load.
    // the calls to get status below need not be async, since we already eager loaded, but left as is...
    self.asset.tracks;
    self.asset.duration;
    NSLog(@"self.asset.duration == %qi", self.asset.duration.value);
    NSLog(@"self.asset.tracks.count == %lu", self.asset.tracks.count);


    BOOL isSuccess = [self validateAssetLoadedStatusForProperty:@"tracks" resultSet:resultSet];
    if (isSuccess) isSuccess = [self validateAssetLoadedStatusForProperty:@"duration" resultSet:resultSet];
    return isSuccess;
}

- (BOOL)validateAssetLoadedStatusForProperty:(NSString *)propertyKey resultSet:(OcResultSet *)resultSet  {

    NSError *localError = nil;
    BOOL isSuccess = ([self.asset statusOfValueForKey:propertyKey error:&localError] == AVKeyValueStatusLoaded);
    if (!isSuccess) {
        [resultSet.codeList addErrorWithMessage:@"Underlying error for AVAsset's statusOfValueForKey:error:"
                                 andErrorObject:localError];
    }
    return isSuccess;
}

@end
