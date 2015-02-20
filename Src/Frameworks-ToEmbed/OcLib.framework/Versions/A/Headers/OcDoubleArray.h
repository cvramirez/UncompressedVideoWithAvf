/*! RtoDoubleList
 *
 * Created by Cesar V. Ramirez on 9/19/13.
 * Copyright (c) 2013 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <OcLib/RtoDefs.h>
#import <OcLib/OcBaseNoInit.h>


@interface OcDoubleArray : OcBaseNoInit

+ (instancetype)newWithData:(double *)data numValues:(long)numValues releaseBlock:(OcDataReleaseBlock)releaseBlock;
+ (instancetype)newByCopyingData:(double *)data numValues:(long)numValues;

+ (instancetype)newAllocedDataBufferWithCapacityForNumValues:(long)numValues;

@property (nonatomic, readonly, assign) double *data;
@property (nonatomic, readonly, assign) long numValues;

@end
