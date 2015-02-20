/*! RandomUtils
 *
 * Created by Cesar V. Ramirez on 9/12/13.
 * Copyright (c) 2013 Cesar V. Ramirez. All rights reserved.
 *
 */


#import <Foundation/Foundation.h>


@interface OcRandomUtils : NSObject


+ (int32_t)getRandomIntWithMin:(int32_t)min max:(int32_t)max;
+ (int32_t)getRandomInt;


+ (double_t)getRandomDoubleWithMin:(double)min max:(double)max;

@end