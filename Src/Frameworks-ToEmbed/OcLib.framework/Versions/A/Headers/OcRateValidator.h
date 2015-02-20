/*! OcRateValidator
 *
 * Created by Cesar V. Ramirez on 1/4/15.
 * Copyright (c) 2015 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <OcLib/OcLib.h>
#import "OcTimersAndTiming.h"

@class OcRate;


@interface OcRateValidator : NSObject
+ (instancetype)new;

- (BOOL)calcFrameInterval:(int *)frameIntervalPtr withRate:(OcRate *)rate displayRefreshHz:(double)displayRefreshHz resultSet:(OcResultSet *)resultSet;

@end
