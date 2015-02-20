//
//  SyncTimer.h
//  VPixxExamples
//
//  Created by Cesar V Ramirez on 2/15/13.
//
//

#import <Foundation/Foundation.h>

@interface SyncTimer : NSObject {
    NSDate *_startTime;
    NSDate *_endTime;
    NSDate *_nextTime;
    double _interval;
    unsigned long _milliSecUnitResolution;
}


- (id)initWithSecsInterval:(double)secsInterval millisecsResolution:(unsigned long)resolution;
- (id)initWithSecsInterval:(double)secsInterval secsResolution:(double)secsResolution;

@property (readonly)unsigned long milliSecUnitResolution;
@property (readonly)double interval;
@property (readonly, nonatomic, strong) NSDate *startTime;
@property (readonly, nonatomic, strong) NSDate *endTime;


@property (readonly)BOOL hasReachedEndTime;

- (void)start;

- (void)startWithSecsDuration:(double)secsDuration;

- (int)chillUntilNextInterval;

@end
