/*! OcTimerCVDisplayLink
 *
 * Created by Cesar V. Ramirez on 11/23/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <Foundation/Foundation.h>
#import "QuartzCore/QuartzCore.h"
#import "OcTimersAndTiming.h"
#import "OcBaseNoInit.h"
@class OcTimerCVDisplayLink;
@class PlayerTimerCallbackInfo;
@class OcResultSet;
@class OcRateValidator;
@class OcRate;

typedef BOOL (*OcTimerCVDisplayLinkOutputCallback)(OcTimerCVDisplayLink *displayLinkTimer,
                                                   const PlayerTimerCallbackInfo *callbackInfo,
                                                   id callbackContext);



@interface OcTimerCVDisplayLink : OcBaseNoInit

@property int playerId;
@property int lastFrameIndex;

@property (readonly) int32_t frameInterval;
@property(readonly, nonatomic) BOOL isDone;
@property int frameDelay;


+ (instancetype)newWithRate:(OcRate *)rate rateValidator:(OcRateValidator *)rateValidator callbackContext:(id)callbackContext
           callbackFunction:(OcTimerCVDisplayLinkOutputCallback)callbackFunction resultSet:(OcResultSet *)resultSet;

+ (instancetype)newWithRate:(OcRate *)rate callbackContext:(id)callbackContext callbackFunction:(OcTimerCVDisplayLinkOutputCallback)callbackFunction
                  resultSet:(OcResultSet *)resultSet;

+ (instancetype)newWithFrameInterval:(int32_t)frameInterval callbackContext:(id)callbackContext
                    callbackFunction:(OcTimerCVDisplayLinkOutputCallback)callbackFunction resultSet:(OcResultSet *)resultSet;

- (BOOL)start;
- (BOOL)stop;

//! The "ideal" refresh period from config, not calculated (as is actualRefreshPeriod).
- (double)nominalRefreshPeriod;

//! Refresh period, calculated using host clock, not "pretty" value from config (as is nominalRefreshPeriod).
- (double)actualRefreshPeriod;


- (BOOL)subscribeWithCallbackContext:(id)callbackContext callbackFunction:(OcTimerCVDisplayLinkOutputCallback)callbackFunction;

@end
