//
// Created by cvramirez on 10/17/12.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <Foundation/Foundation.h>
#import "RtoConstants.h"


@interface OcResultCode : NSObject

+ (instancetype)resultCodeWithType:(RtoResultType)type code:(OcErrType)code message:(NSString *)message;

@property (nonatomic, readwrite, retain) RtoResultType type;
@property (nonatomic, readwrite, copy  ) NSString *message;
@property (nonatomic, readwrite, retain) OcErrType code;
@end
