#import <Foundation/Foundation.h>
#import <OcLib/OcBaseNoInit.h>
#import <OcLib/RtoDefs.h>


@interface OcIntArray : OcBaseNoInit

+ (instancetype)newWithData:(int *)data numValues:(long)numValues releaseBlock:(OcDataReleaseBlock)releaseBlock;
+ (instancetype)newByCopyingInt32Data:(int *)data numValues:(long)numValues;
+ (instancetype)newByCopyingUnsignedShortData:(unsigned short *)data numValues:(long)numValues;
+ (instancetype)newAllocedDataBufferWithCapacityForNumValues:(long)numValues;
+ (instancetype)newNullObject;

@property(nonatomic, readonly , assign) int *data;


@property(nonatomic, readonly , assign) long numValues;

@end
