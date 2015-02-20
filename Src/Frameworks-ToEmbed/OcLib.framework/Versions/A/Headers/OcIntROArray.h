#import <OcLib/RtoDefs.h>
#import <OcLib/OcBaseNoInit.h>


@interface OcIntROArray : OcBaseNoInit

+ (instancetype)newWithData:(int *)data numValues:(long)numValues releaseBlock:(OcDataReleaseBlock)releaseBlock;
@property (nonatomic, readonly, assign) int *data;
@property (nonatomic, readonly, assign) long numValues;

@end
