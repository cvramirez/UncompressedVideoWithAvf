//
//  OcUtilsForNSException.h
//  Showtime
//
//  Created by Cesar V Ramirez on 11/28/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OcUtilsForNSException : NSObject

+(void) throwInvalidInitializerExceptionWithClassName:(NSString *)className functionName:(NSString *)functionName;
+(void) throwSubclassHasntImplementedAbstractMethodExceptionWithClassName:(NSString *)className functionName:(NSString *)functionName;
+(void) throwValueNotInRangeExceptionWithClassName:(NSString *)className functionName:(NSString *)functionName objectName:(NSString *)name objectValue:(NSString *)value;

+ (void)throwInvalidArgumentExceptionWithClassName:(NSString *)className functionName:(NSString *)functionName message:(NSString *)message;

+ (void)throwInvalidSingletonReconfigurationExceptionWithClassName:(NSString *)className functionName:(NSString *)functionName;
+ (void)throwSingletonNotConfiguredExceptionWithClassName:(NSString *)className functionName:(NSString *)functionName;
@end
