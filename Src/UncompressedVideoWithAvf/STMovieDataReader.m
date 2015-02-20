#import <AVFoundation/AVFoundation.h>
#import <OcLib/NSObject+OcErrorUtilsHelper.h>
#import <OcLib/OcResultSet.h>
#import <CoreMedia/CoreMedia.h>
#import <OcLib/OcSleepUtils.h>
#import "STMovieDataReader.h"
#import "STAVAssetHelper.h"
#import "AVFoundationUtils.h"


@interface STMovieDataReader () {
    CMSampleBufferRef _cachedFirstSampleBuffer;
}
@property (nonatomic, readwrite, strong) AVAsset *asset;
@property (nonatomic, readwrite, strong) AVAssetReader *assetReader;
@property (nonatomic, readwrite, strong) AVAssetReaderOutput *assetReaderOutput;
@property (nonatomic, readwrite, assign) BOOL hasBeenStartedBefore;
@end


OcLogDef(LOG_LEVEL_VERBOSE);

@implementation STMovieDataReader

+ (instancetype)newWithUrl:(NSURL *)movieUrl resultSet:(OcResultSet *)resultSet  {
    return [self newWithUrl:movieUrl decompressionSettings:[self defaultDecompressionSettings] resultSet:resultSet];
}

+ (instancetype)newWithUrl:(NSURL *)movieUrl decompressionSettings:(NSDictionary *)decompressionSettings resultSet:(OcResultSet *)resultSet {
    return [[[self class] alloc] initWithUrl:movieUrl decompressionSettings:decompressionSettings resultSet:resultSet];
}

- (instancetype)initWithUrl:(NSURL *)movieUrl decompressionSettings:(NSDictionary *)decompressionSettings resultSet:(OcResultSet *)resultSet  {

    self = [super init];
    if (self != nil) {
        _cachedFirstSampleBuffer = NULL;
        BOOL isSuccess = [self loadAssetWithUrl:movieUrl resultSet:resultSet];
        if (isSuccess) isSuccess = [self createAssetReader:resultSet];
        if (isSuccess) isSuccess = [self setUpAssetReaderOutputForFirstVideoTrackWithDecompressionSettings:decompressionSettings
                                                                                                 resultSet:resultSet];
        if (isSuccess) isSuccess = [self readFirstSampleBufferToGetPropertiesThenCacheItForTheFirstFrameRequest:resultSet];
        if (!isSuccess) {
            self = nil;
        }
        OcLogExitMethodWithSuccessBool(isSuccess);

    }
    return self;
}

+ (NSDictionary *)defaultDecompressionSettings  {

    // "If you need to work in the RGB domain is is recommended that on iOS the kCVPixelFormatType_32BGRA value is used,
    // and on OS X kCVPixelFormatType_32ARGB is recommended."  - from docs
    //
    // https://developer.apple.com/library/ios/documentation/AVFoundation/Reference/AVAssetReaderTrackOutput_Class/Reference/Reference.html
    //
    NSDictionary *decompressionSettings = nil;

    //
    // BUT(!!), even so, it seems that 'nil' is working best for now, so we'll let be the default
    //
//            decompressionSettings = @{(id)kCVPixelBufferPixelFormatTypeKey : @(kCVPixelFormatType_32ARGB),
//                    (id)kCVPixelBufferIOSurfacePropertiesKey : [NSDictionary dictionary] /*,
//                    (id)kCVPixelBufferCGImageCompatibilityKey : @(YES),
//                    (id)kCVPixelBufferCGBitmapContextCompatibilityKey : @(YES)*/};
//            decompressionSettings = @{(id)kCVPixelBufferPixelFormatTypeKey : @(kCVPixelFormatType_32BGRA)};

    return decompressionSettings;
}

- (BOOL)loadAssetWithUrl:(NSURL *)movieUrl resultSet:(OcResultSet *)resultSet  {

    STAVAssetHelper *assetHelper = [STAVAssetHelper newWithUrl:movieUrl resultSet:resultSet];
    BOOL isSuccess = ((assetHelper != nil) && (assetHelper.asset != nil));
    if (isSuccess) {
        self.asset = assetHelper.asset;
    }
    return isSuccess;
}

- (BOOL)createAssetReader:(OcResultSet *)resultSet  {

    NSError *outError = nil;
    self.assetReader = [[AVAssetReader alloc] initWithAsset:self.asset error:&outError];
    if (self.assetReader == nil){
        [resultSet.codeList addErrorWithMessage:@"Could not open asset reader" andErrorObject:outError];
        return NO;
    }
    return YES;
}

- (BOOL)setUpAssetReaderOutputForFirstVideoTrackWithDecompressionSettings:(NSDictionary *)decompressionSettings resultSet:(OcResultSet *)resultSet  {

    AVAssetReaderOutput *assetReaderOutput;
    AVAssetTrack *firstVideoTrack;
    CMVideoDimensions trackDimensions;
    BOOL isSuccess = [self getVideoTrack:&firstVideoTrack atIndex:0];
    if (isSuccess) isSuccess = [self addOutputToReader:self.assetReader forVideoTrack:firstVideoTrack
                             withDecompressionSettings:decompressionSettings
                                 returningReaderOutput:&assetReaderOutput];
    if (isSuccess) {
        [self getTrackDimensions:&trackDimensions fromVideoTrack:firstVideoTrack];
        self.assetReaderOutput = assetReaderOutput;
        _videoDimensions = trackDimensions;

        OcLogDebug(@"STMovieDataReader found first video track and is ready to read: width=%d, height=%d", trackDimensions.width, trackDimensions.height);
    }

    if (!isSuccess) {
        [resultSet.codeList addErrorWithMessage:@"Could not read first video track metadata."];
    }

    return isSuccess;
}

- (BOOL)getVideoTrack:(AVAssetTrack **)trackPtr atIndex:(uint)trackIndex  {

    NSArray *videoTracks = [self.asset tracksWithMediaType:AVMediaTypeVideo];
    OcLogDebug(@"videoTracks.count = %d", videoTracks.count);
    BOOL isSuccess = (videoTracks !=nil  &&  videoTracks.count > 0  &&  videoTracks.count > trackIndex);
    if (isSuccess) {
        *trackPtr = videoTracks[trackIndex];
    }
    return isSuccess;
}

- (BOOL)addOutputToReader:(AVAssetReader *)assetReader forVideoTrack:(AVAssetTrack *)videoTrack
withDecompressionSettings:(NSDictionary *)decompressionSettings
    returningReaderOutput:(AVAssetReaderOutput **)readerOutputPtr  {

    BOOL isSuccess = (videoTrack != nil && readerOutputPtr != nil);
    if (isSuccess)
    {
        AVAssetReaderOutput *output = [AVAssetReaderTrackOutput assetReaderTrackOutputWithTrack:videoTrack
                                                                                 outputSettings:decompressionSettings];
        isSuccess = (output != nil);
        if (isSuccess) {
            [assetReader addOutput:output];
            *readerOutputPtr = output;
        }
    }

    return isSuccess;
}

- (void)getTrackDimensions:(CMVideoDimensions *)trackDimensionsPtr fromVideoTrack:(AVAssetTrack *)videoTrack  {

    CMFormatDescriptionRef formatDescription;
    BOOL isSuccess = [self getFormatDescription:&formatDescription fromVideoTrack:videoTrack];
    if (isSuccess) {

        CFDictionaryRef pixelAspectRatioFromCMFormatDescription = CMFormatDescriptionGetExtension(formatDescription, kCMFormatDescriptionExtension_PixelAspectRatio);

        // was *trackDimensionsPtr = CMVideoFormatDescriptionGetPresentationDimensions(formatDescription, false, false);
        *trackDimensionsPtr = CMVideoFormatDescriptionGetDimensions(formatDescription);
        OcLogDebug(@"Got dimensions with CMVideoFormatDescriptionGetDimensions(): %d, %d (w,h).",
                trackDimensionsPtr->width, trackDimensionsPtr->height);    }
    else {
        CGSize naturalSize = [videoTrack naturalSize];
        trackDimensionsPtr->width  = (int32_t)naturalSize.width;
        trackDimensionsPtr->height = (int32_t)naturalSize.height;
        OcLogWarn(@"Couldn't get dimensions with CMVideoFormatDescriptionGetDimensions(), using "
                "videoTrack.naturalSize instead. %d, %d (w,h).", naturalSize.width, naturalSize.height);
    }


    CMVideoCodecType codecType = CMVideoFormatDescriptionGetCodecType(formatDescription);
    OcLogDebug(@"Codec type = %d =?= %d", codecType, kCMVideoCodecType_Animation);

}

- (BOOL)getFormatDescription:(CMFormatDescriptionRef *)formatDescriptionPtr fromVideoTrack:(AVAssetTrack *)videoTrack  {

    *formatDescriptionPtr = NULL;
    NSArray *formatDescriptions = [videoTrack formatDescriptions];
    BOOL isSuccessAssumedIfWeCanGrabFirstObject = (formatDescriptions.count > 0); // from code sample, ToDo: do we need to be more defensive?
    if (isSuccessAssumedIfWeCanGrabFirstObject) {
        *formatDescriptionPtr = (__bridge CMFormatDescriptionRef)formatDescriptions[0];
    }
    return (isSuccessAssumedIfWeCanGrabFirstObject);
}

- (BOOL)readFirstSampleBufferToGetPropertiesThenCacheItForTheFirstFrameRequest:(OcResultSet *)resultSet {

    int kMaxTimesToTryToReadTheFirstFrameBeforeGivingUp = 16;
    int numTriesToRead = 0;
    BOOL isSuccess = NO;

    while (!isSuccess  &&  numTriesToRead<kMaxTimesToTryToReadTheFirstFrameBeforeGivingUp) {
        numTriesToRead++;
        OcLogVerbose(@"Attempt #%d to read first frame:", numTriesToRead);
        isSuccess = [self copyNextSampleBuffer:&_cachedFirstSampleBuffer resultSet:resultSet];
        if (isSuccess) isSuccess = [self hasValidCMSampleBufferContainingSamples:_cachedFirstSampleBuffer];
        if (isSuccess) {
            uint totSampleSize = (uint)CMSampleBufferGetTotalSampleSize(_cachedFirstSampleBuffer);
            _numBitsPerPixel = (totSampleSize / self.numPixelsPerFrame) * 8;
            OcLogDebug(@"totSampleSize = %d", totSampleSize);
            OcLogDebug(@"numPixelsPerFrame = %d", self.numPixelsPerFrame);
            OcLogDebug(@"numBitsPerPixel = %d", self.numBitsPerPixel);


            CMTime duration = CMSampleBufferGetDuration(_cachedFirstSampleBuffer);
            CMTimeValue frameDuration = duration.value;
            CMTimeValue movieDuration = self.duration.value;
            _numFrames = (uint32)((movieDuration + frameDuration - 1)/ frameDuration);
            OcLogDebug(@"Calculated numFrames = %d", self.numFrames);
        }
        else {
            _cachedFirstSampleBuffer = NULL;
        }
    }

    if (!isSuccess) {
        [resultSet.codeList addErrorWithCode:kOcErr_CantReadFileError format:@"Cannot read first sample buffer."];
    }
    OcLogExitMethodWithSuccessBool(isSuccess);
    return isSuccess;
}



#pragma mark ---  Properties  ---

- (uint)numPixelsPerFrame  {
    return (uint)(self.videoDimensions.height * self.videoDimensions.width);
}

- (CMTime)duration {
    return self.asset.duration;
}

- (AVAssetReaderStatus)status  {
    return self.assetReader.status;
}

- (NSString *)statusName  {
    return [AVFoundationUtils nameFromAVAssetReaderStatus:self.status];
}

- (CMTimeRange)timeRange {
    return self.assetReader.timeRange;
}



#pragma mark ---  Reading Buffers  ---

- (BOOL)copyNextSampleBuffer:(CMSampleBufferRef *)sampleBufferPtr resultSet:(OcResultSet *)resultSet  {

    int kMaxTimesToTryToReadTheFirstFrameBeforeGivingUp = 16;
    int numTriesToRead = 0;

    BOOL isSuccess = [self copyNextSampleBufferInternal:sampleBufferPtr resultSet:resultSet];
    while (!isSuccess  &&  self.isAbleToAttemptToRead  &&  numTriesToRead<kMaxTimesToTryToReadTheFirstFrameBeforeGivingUp) {
        [self maybeWeShouldSleepForABitBeforeTryingToReadAgain];
        isSuccess = [self copyNextSampleBufferInternal:sampleBufferPtr resultSet:resultSet];
        numTriesToRead+=2;
        OcLogWarn(@"Initial attempt to read sample failed. Looping now. Attempt #%d, isSuccess=%d",
                numTriesToRead, isSuccess);
    }
    return isSuccess;
}

- (BOOL)copyNextSampleBufferInternal:(CMSampleBufferRef *)sampleBufferPtr resultSet:(OcResultSet *)resultSet  {


//            //CMTime decodeTime = CMSampleBufferGetDecodeTimeStamp(sampleBuffer);
//            CMTime presentationTime = CMSampleBufferGetPresentationTimeStamp(sampleBuffer);
//            //opaqueCMSampleBuffer buffy = *sampleBuffer;
//
//            [data wrapCMBuffer:sampleBuffer withPresentationTime:presentationTime];
//            CFRelease(sampleBuffer);

    OcLogEnteredMethod();
    BOOL isSuccess = [self ensureAssetReaderIsReadingAndOnlyStartedOnce:resultSet];
    if (isSuccess)
    {
        if (self.hasCachedFirstFrame) {
            OcLogVerbose(@"Attemp to get cachedFirstFrame");
            isSuccess = [self getAndClearCachedFirstSampleBuffer:sampleBufferPtr resultSet:resultSet];
        }
        else {
            OcLogVerbose(@"Attemp to copyNextSampleBuffer into buffer (%ld)(base addy %ld) from assetReaderOutput (%ld)", *sampleBufferPtr, sampleBufferPtr, self.assetReaderOutput);
            *sampleBufferPtr = [self.assetReaderOutput copyNextSampleBuffer];
            OcLogVerbose(@"*sampleBufferPtr=%ld", *sampleBufferPtr);
            isSuccess = [self hasValidCMSampleBufferContainingSamples:*sampleBufferPtr];

            if (!isSuccess)
            {
                if (*sampleBufferPtr != NULL) {
                    CFRelease(*sampleBufferPtr);
                    *sampleBufferPtr = NULL;
                }

                if (self.status == AVAssetReaderStatusReading) {
                    OcLogDebug(@"Got a CMSampleBuffer from reader output, but it had no samples. Status is "
                            "still AVAssetReaderStatusReading, so we will hang out for a bit while it does "
                            "it's 3 empty buff thing.");
                }
                else if (self.status == AVAssetReaderStatusCompleted) {
                    OcLogDebug(@"AVAssetReaderStatusCompleted reading.");
                }
                else {
                    OcLogError(@"Couldn't read next sample buffer. AVAssetReader status = '%@'", self.statusName);
                    [resultSet.codeList addErrorWithCode:kOcErr_CantReadFileError
                                                  format:@"Couldn't read next sample buffer. AVAssetReader status = '%@'",
                                                         self.statusName];
                }
            }
        }
    }
    OcLogExitMethodWithSuccessBool(isSuccess);
    return isSuccess;
}

/* Was thinking of doing this..., but maybe not.  If see here, and not Jan 2015, delete!

- (BOOL)copyNextSampleBufferToNewData:(NSData **)dataPtr resultSet:(OcResultSet *)resultSet  {

    CMSampleBufferRef sampleBuffer;
    BOOL isSuccess = [self copyNextSampleBuffer:&sampleBuffer resultSet:resultSet];
    if (isSuccess) {
        size_t totSize = CMSampleBufferGetTotalSampleSize(sampleBuffer);
        *dataPtr = [NSMutableData dataWithCapacity:totSize];
        isSuccess = (*dataPtr != nil);
        if (!isSuccess) {
            [resultSet.codeList addErrorWithCode:kOcErr_OutOfMemory
                                          format:@"Could not allocate %lu bytes for frame buffer.", totSize];
        }
    }
    return isSuccess;
}
*/

- (BOOL)getAndClearCachedFirstSampleBuffer:(CMSampleBufferRef *)sampleBufferPtr resultSet:(OcResultSet *)resultSet  {

    BOOL isSuccess = self.hasCachedFirstFrame;
    if (!isSuccess) {
        [resultSet.codeList addErrorWithCode:kOcErr_internal
                                      format:@"Attempted to get 'cached' first sample buffer, but there was none..."];
    }
    else {
        *sampleBufferPtr = _cachedFirstSampleBuffer;
        _cachedFirstSampleBuffer = nil;
    }
    OcLogExitMethodWithSuccessBool(isSuccess);
    return isSuccess;
}


- (void)maybeWeShouldSleepForABitBeforeTryingToReadAgain {
    millisecondSleep(50);
    OcLogVerbose(@"--- -- currently doesn nothing -- ---");
}


- (BOOL)hasValidCMSampleBufferContainingSamples:(CMSampleBufferRef)sampleBuffer  {
    BOOL isSuccess = ((CMSampleBufferIsValid(sampleBuffer))  &&  (CMSampleBufferGetNumSamples(sampleBuffer) > 0));
    OcLogExitMethodWithSuccessBool(isSuccess);
    return isSuccess;
}


- (BOOL)ensureAssetReaderIsReadingAndOnlyStartedOnce:(OcResultSet *)resultSet  {

    if (!self.isReading  &&  !self.hasBeenStartedBefore) {
        self.assetReader.timeRange = CMTimeRangeMake(kCMTimeZero, self.asset.duration);
        [self.assetReader startReading];
        self.hasBeenStartedBefore = YES;
        OcLogDebug(@"Started reading with range: %lld, %lld", self.assetReader.timeRange.start.value,
                self.assetReader.timeRange.duration.value);
    }

    if (!self.isReading  &&  !self.hasBeenStartedBefore) {
        NSString *errMsg = [NSString stringWithFormat:@"[assetReader startReading] failed!  assetReader.status = %li.",
                                                      self.assetReader.status];
        [resultSet.codeList addErrorWithCode:kOcErr_internal format:errMsg];
        OcLogError(@"%@", errMsg);
    }
    return self.isReading;
}


#pragma mark ---  Internal Properties  ---

- (BOOL)isReading  {
    OcLogVerbose(@"status=%@", self.statusName);
    return (self.status == AVAssetReaderStatusReading);
}

- (BOOL)isAbleToAttemptToRead  {
    return (self.isReading  ||  (!self.isReading  &&  !self.hasBeenStartedBefore));
}

- (BOOL)hasCachedFirstFrame  {
    return (_cachedFirstSampleBuffer != NULL);
}



- (void)dealloc  {
    if (self.hasCachedFirstFrame) {
        CFRelease(_cachedFirstSampleBuffer);
        _cachedFirstSampleBuffer = NULL;
    }
}



#pragma mark ---  Orig Use, for Testing  ---

- (BOOL)getData:(NSData **)dataPtr withStartFrameIndex:(int)startFrameIndex maxNumFrames:(int)maxNumFrames
        andActualNumFramesReturned:(int *)actualNumFramesReturnedPtr outError:(NSError **)outError  {

    int numFramesAdded = 0;
    NSMutableData *data = nil;

    [self.assetReader startReading];
    if (self.assetReader.status != AVAssetReaderStatusReading)
    {
        NSString *errMsg = [NSString stringWithFormat:@"[assetReader startReading] failed with status=%@.", self.statusName];
        [self fillError:outError withSelector:_cmd desciption:errMsg];
    }
    else
    {
        int currFrameIndex = 0;
        int endFrameIndex = startFrameIndex + maxNumFrames;
        data = [NSMutableData dataWithCapacity:0];
        while (self.assetReader.status == AVAssetReaderStatusReading  && currFrameIndex < endFrameIndex)
        {
            CMSampleBufferRef sampleBuffer = [self.assetReaderOutput copyNextSampleBuffer];
            if (sampleBuffer != nil)
            {
                CMTime decodeTime = CMSampleBufferGetDecodeTimeStamp(sampleBuffer);
                CMTime presentationTime = CMSampleBufferGetPresentationTimeStamp(sampleBuffer);

                //opaqueCMSampleBuffer buffy = *sampleBuffer;

                if (currFrameIndex >= startFrameIndex) {
                    BOOL wasAdded = [self ifSampleBufferIsCVImageBufferAddIt:sampleBuffer toData:data outError:outError];
                    if (!wasAdded) wasAdded =[self ifSampleBufferIsCMBlockBufferAddIt:sampleBuffer toData:data outError:outError];
                    if (wasAdded) {
                        numFramesAdded++;
                    }
                }
                CFRelease(sampleBuffer);
                currFrameIndex++;
            }
        }

    }

    *dataPtr =  data;
    *actualNumFramesReturnedPtr = numFramesAdded;
    return (numFramesAdded>0);
}

- (BOOL)ifSampleBufferIsCVImageBufferAddIt:(CMSampleBufferRef)sampleBuffer toData:(NSMutableData *)data outError:(NSError **)outError  {

    BOOL isSuccess = NO;
    CVImageBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    if (imageBuffer != nil) {
        NSLog(@"It was a CVImageBuffer");
        CVReturn result = CVPixelBufferLockBaseAddress(imageBuffer, 0);
        if (result == kCVReturnSuccess) {
            size_t dataSize = CVPixelBufferGetDataSize(imageBuffer);
            if (dataSize > 0) {
                uint8_t *baseAddress = (uint8_t *)CVPixelBufferGetBaseAddress(imageBuffer);
                [data appendBytes:baseAddress length:dataSize];
                isSuccess = YES;
            }
            CVPixelBufferUnlockBaseAddress(imageBuffer,0);
        }
        else {
            NSString *errMsg = [NSString stringWithFormat:@"CVPixelBufferLockBaseAddress failed with result=%d.", result];
            [self fillError:outError withSelector:_cmd desciption:errMsg];
        }
    }
    return isSuccess;
}

- (BOOL)ifSampleBufferIsCMBlockBufferAddIt:(CMSampleBufferRef)sampleBuffer toData:(NSMutableData *)data outError:(NSError **)outError  {

    BOOL isSuccess = NO;
    CMBlockBufferRef blockBuffer = CMSampleBufferGetDataBuffer(sampleBuffer);
    if (blockBuffer != nil) {
        NSLog(@"It was a CMBlockBuffer");
        size_t dataLength = CMBlockBufferGetDataLength(blockBuffer);
        if (dataLength > 0) {
            size_t const kNoOffsetForSrcData = 0;
            uint offsetForDestData = data.length;
            [data increaseLengthBy:dataLength];
            uint8 *addrForDestData = [data bytes] + offsetForDestData;
            OSStatus result = CMBlockBufferCopyDataBytes(blockBuffer,
                    kNoOffsetForSrcData,
                    dataLength,
                    addrForDestData);

            isSuccess = (result == kCMBlockBufferNoErr);
            if (!isSuccess) {
                NSString *errMsg = [NSString stringWithFormat:@"CMBlockBufferCopyDataBytes(..) returned resultStatus= %d.", result];
                [self fillError:outError withSelector:_cmd desciption:errMsg];
            }
        }
    }
    return isSuccess;
}

// TEMPORARY - Overrides behavior in error utils category -- this ONLY LOGS
//
// ToDo: this should be deleted when integrated with rest of library
//
-(void) fillError:(NSError **)outError withSelector:(SEL)selector desciption:(NSString *)description  {
    NSString *selectorName = NSStringFromSelector(selector);

    NSLog(@"HackFilleErrorLog: Error occurred in %@ - %@\n%@", selectorName, description, (*outError).debugDescription);
}

@end
