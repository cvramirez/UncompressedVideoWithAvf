#import <Foundation/Foundation.h>
#import <OcLib/OcBaseNoInit.h>
#import <OcLib/RtoDefs.h>


@interface OcUInt8Array : OcBaseNoInit

+ (instancetype)newAllocedDataBufferWithCapacityForNumValues:(long)numValues;
+ (instancetype)newWithData:(UInt8 *)data numValues:(long)numValues releaseBlock:(OcDataReleaseBlock)releaseBlock;
+ (instancetype)newByCopyingUInt8Data:(UInt8 *)data numValues:(long)numValues;
+ (instancetype)newByCopyingIntData:(int *)data numValues:(long)numValues;

@property(nonatomic, readonly , assign) UInt8 *data;
@property(nonatomic, readonly , assign) long numValues;

@end
