/*! OcRate
 *
 * Created by Cesar V. Ramirez on 1/4/15.
 * Copyright (c) 2015 Cesar V. Ramirez. All rights reserved.
 *
 */
#import "OcTimersAndTiming.h"
#import "OcBaseNoInit.h"


@interface OcRate : OcBaseNoInit
+ (instancetype)newWithRate:(double)rate rateType:(OcRateType)type;
@property (nonatomic, readonly, strong) OcRateType rateType;
@property (nonatomic, readonly, assign) double rate;
@end
