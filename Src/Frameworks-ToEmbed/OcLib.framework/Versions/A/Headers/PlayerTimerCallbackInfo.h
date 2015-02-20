/*! PlayerTimerCallbackInfo
 *
 * Created by Cesar V. Ramirez on 7/23/13.
 */


#import <Foundation/Foundation.h>


@interface PlayerTimerCallbackInfo : NSObject {

@private
    NSDate *_currTime;
    NSDate *_outputTime;
    int _currFrameIndex;
    int64_t _videoTimeTicks;
    int32_t _videoTimeScale;
    NSTimeInterval _currTimeSeconds;
    int64_t _currTimeTicks;
    uint64_t _currSystemTimeTicks;
    int _playerId;
}


@property int playerId;

@property int currFrameIndex;
@property(nonatomic, copy) NSDate *currTime;
@property(nonatomic) int64_t currTimeTicks;
@property(nonatomic, copy)  NSDate *outputTime;
@property(nonatomic) NSTimeInterval currTimeSeconds;
@property(nonatomic) int64_t videoTimeTicks;
@property(nonatomic) int32_t videoTimeScale;
@property(nonatomic) uint64_t currSystemTimeTicks;

@property (nonatomic, readwrite, assign) uint finalFrameIndex;
@end