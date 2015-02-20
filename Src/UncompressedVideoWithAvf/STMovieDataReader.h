/*! STMovieDataReader

    A somewhat quick & dirty helper class to get data from the *First Video Track*

    NOTE: getData... can only be called once per instance, for now. Perhaps will flesh out and improve
          this class at a later time...  Maybe add multiple calls to getData, ability to get data from
          other tracks, and maybe audio too.
 */
#import <AVFoundation/AVFoundation.h>
@class OcResultSet;


@interface STMovieDataReader : NSObject

@property (nonatomic, readonly, assign) NSSize videoDimensions;
@property (nonatomic, readonly, assign) CMTime duration;
@property (nonatomic, readonly, assign) AVAssetReaderStatus status;
@property (nonatomic, readonly, assign) NSString *statusName;
@property (nonatomic, readonly, assign) CMTimeRange timeRange;
@property (nonatomic, readonly, assign) size_t numPixelsPerFrame;
@property (nonatomic, readonly, assign) size_t numBitsPerPixel;
@property (nonatomic, readonly, assign) uint numFrames;


+ (instancetype)newWithUrl:(NSURL *)movieUrl resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithUrl:(NSURL *)movieUrl decompressionSettings:(NSDictionary *)decompressionSettings resultSet:(OcResultSet *)resultSet;


- (BOOL)copyNextSampleBuffer:(CMSampleBufferRef *)sampleBufferPtr resultSet:(OcResultSet *)resultSet;

- (BOOL)getData:(NSData **)dataPtr withStartFrameIndex:(int)startFrameIndex
                                          maxNumFrames:(int)maxNumFrames
                            andActualNumFramesReturned:(int *)actualNumFramesReturnedPtr
                                              outError:(NSError **)outError;
@end
