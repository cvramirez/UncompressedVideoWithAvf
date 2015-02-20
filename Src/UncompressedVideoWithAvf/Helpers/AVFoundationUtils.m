#import "AVFoundationUtils.h"
#import <OcLib/OcLumberjackImports.h>
OcLogDef(LOG_LEVEL_WARN);


@implementation AVFoundationUtils

+ (NSString *)nameFromAVAssetReaderStatus:(AVAssetReaderStatus)status {

    NSString *statusName;
    switch (status) {
        case AVAssetReaderStatusCompleted:
            statusName = @"Completed";
            break;
        case AVAssetReaderStatusReading:
            statusName = @"Reading";
            break;
        case AVAssetReaderStatusFailed:
            statusName = @"Failed";
            break;
        case AVAssetReaderStatusCancelled:
            statusName = @"Cancelled";
            break;
        case AVAssetReaderStatusUnknown:
            statusName = @"Unknown";
            break;
        default: {
            NSString *errMsg = [NSString stringWithFormat:@"Status = '%d' not recognized. Case not handled.", status];
            @throw [NSException exceptionWithName:@"Unknown AVAssetReaderStatus Type" reason:errMsg userInfo:nil];
        }
    }
    return statusName;
}
@end
