#import <Foundation/Foundation.h>
#import <OcLib/OcBaseNoInit.h>
#import <OcLib/RtoDefs.h>


@interface OcDoubleNDimArray : OcBaseNoInit

+ (instancetype)newWithData:(double *)data dimLengths:(long *)dimLengths headSymbols:(char **)headSymbols numDims:(long)numDims
               releaseBlock:(OcDataReleaseBlock)releaseBlock;

+ (instancetype)newAllocedDataBufferWithCapacityForNumDims:(long)numDims dimLengths:(long *)dimLengths;

+ (instancetype)newNullObject;

@property (nonatomic, readonly, assign) double *data;
@property (nonatomic, readonly, assign) long *numValuesInDims;
@property (nonatomic, readonly, assign) char **dimCNames;
@property (nonatomic, readonly, assign) long numDims;
@property (nonatomic, readonly, assign) long numValuesTotal;

@end
