//
// Created by Cesar V. Ramirez on 7/17/13.
//
// To change the template use AppCode | Preferences | File Templates.
//
#import <Foundation/Foundation.h>
#import "QuartzCore/QuartzCore.h"
@class CVDisplayLinkTimer;
@class PlayerTimerCallbackInfo;

typedef BOOL (*CVDisplayLinkTimerOutputCallback)(CVDisplayLinkTimer *displayLinkTimer,
                                                const PlayerTimerCallbackInfo *callbackInfo,
                                                void *instancePointer);



@interface CVDisplayLinkTimer : NSObject {


    BOOL _doingHackTest;
    NSMutableString *_hackTestOutput;



    CVDisplayLinkRef _displayLink;

    int32_t _frameInterval;


    int64_t _startVideoTime;
    int64_t _frameDuration;
    int64_t _partialFrameDuration;

    int64_t _currCallbackFrameIndex;
    CVDisplayLinkTimerOutputCallback _callbackFunction;
    void *_callbackInstance;

    BOOL _areValsInitialized;

    int _playerId;
    int _lastFrameIndex;

    NSDate *_firstFrameStartTime;
    BOOL _isDone;

    int _frameDelay;

}

@property int playerId;
@property int lastFrameIndex;

@property (readonly) int32_t frameInterval;
@property(readonly, nonatomic) BOOL isDone;
@property int frameDelay;


- (id)initWithRate:(double)rate rateType:(int)rateType callbackInstance:(void *)callbackInstance callbackFunction:(CVDisplayLinkTimerOutputCallback)callbackFunction;

- (id)initWithFrameInterval:(int32_t)frameInterval callbackInstance:(void *)callbackInstance callbackFunction:(CVDisplayLinkTimerOutputCallback)callbackFunction;

- (BOOL)start;
- (BOOL)stop;

//! The "ideal" refresh period from config, not calculated (as is actualRefreshPeriod).
- (double)nominalRefreshPeriod;

//! Refresh period, calculated using host clock, not "pretty" value from config (as is nominalRefreshPeriod).
- (double)actualRefreshPeriod;
@end
