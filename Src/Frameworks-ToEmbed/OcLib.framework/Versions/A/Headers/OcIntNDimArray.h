/** Read-Only multi-dim array with support for "head symbols" for rows.

    This best supports Mathlink's MLGetArray functions since accessing data *must be* read only and has head symbols.
 */
#import <Foundation/Foundation.h>
#import "IOcIntNDimArray.h"
#import <OcLib/RtoDefs.h>
#import <OcLib/OcBaseNoInit.h>


@interface OcIntNDimArray : OcBaseNoInit <IOcIntNDimArray>

+ (instancetype)newWithData:(int *)data dimLengths:(long *)dimLengths headSymbols:(char **)headSymbols numDims:(long)numDims
               releaseBlock:(OcDataReleaseBlock)releaseBlock;
+ (instancetype)newAllocedDataBufferWithCapacityForNumDims:(long)numDims dimLengths:(long *)dimLengths;
+ (instancetype)newNullObject;

@property (nonatomic, readonly, assign) int *data;
@property (nonatomic, readonly, assign) long *numValuesInDims;
@property (nonatomic, readonly, assign) char **dimCNames;
@property (nonatomic, readonly, assign) long numDims;
@property (nonatomic, readonly, assign) long numValuesTotal;

@end
