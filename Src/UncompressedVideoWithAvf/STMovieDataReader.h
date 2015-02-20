/*! STMovieDataReader

    A somewhat quick & dirty helper class to get data from the *First Video Track*

    ORIGINAL USE:

    Was originally created to 'get a chunk' of data for testing purposes: to read and copy 1-n frames
    of data to a buffer so that it could be compared to expected results in a testing context.

    Note that getData... can only be called once per instance, for now. Perhaps will flesh out and improve
    this class at a later time...  Maybe add multiple calls to getData, ability to get data from
    other tracks, and maybe audio too.


    CURRENT USE:

    Used for forward-only reading of individual frames into CMSampleBufferRef or NSData objects.

 */
#import <AVFoundation/AVFoundation.h>


@interface STMovieDataReader : NSObject

+ (instancetype)newWithUrl:(NSURL *)movieUrl resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithUrl:(NSURL *)movieUrl decompressionSettings:(NSDictionary *)decompressionSettings resultSet:(OcResultSet *)resultSet;

@property (nonatomic, readonly, assign) CMVideoDimensions videoDimensions;
@property (nonatomic, readonly, assign) CMTime duration;
@property (nonatomic, readonly, assign) AVAssetReaderStatus status;
@property (nonatomic, readonly, strong) NSString *statusName;
@property (nonatomic, readonly, assign) CMTimeRange timeRange;
@property (nonatomic, readonly, assign) uint numPixelsPerFrame;
@property (nonatomic, readonly, assign) uint numBitsPerPixel;
@property (nonatomic, readonly, assign) uint numFrames;

- (BOOL)copyNextSampleBuffer:(CMSampleBufferRef *)sampleBufferPtr resultSet:(OcResultSet *)resultSet;




// this may be outdated.. was orig use.
- (BOOL)getData:(NSData **)dataPtr withStartFrameIndex:(int)startFrameIndex
              maxNumFrames:(int)maxNumFrames
andActualNumFramesReturned:(int *)actualNumFramesReturnedPtr
                  outError:(NSError **)outError;

@end
