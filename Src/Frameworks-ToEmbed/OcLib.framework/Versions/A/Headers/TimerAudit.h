/*! TimerAudit
 *
 * Created by Cesar V. Ramirez on 7/24/13.
 *
 */


#import <Foundation/Foundation.h>
#import "PlayerTimerCallbackInfo.h"


@interface TimerAudit : PlayerTimerCallbackInfo  {

@private
    NSTimeInterval _postSetTimeSeconds;
    BOOL _isSetSuccess;
    int64_t _videoVsCurrTimeTickDiff;
}

@property BOOL isSetSuccess;
@property NSTimeInterval postSetTimeSeconds;
@property(nonatomic) int64_t videoVsCurrTimeTickDiff;

@end