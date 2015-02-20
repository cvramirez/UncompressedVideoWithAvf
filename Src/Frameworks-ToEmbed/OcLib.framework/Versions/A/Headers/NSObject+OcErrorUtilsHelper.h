//
//  NSObject+ErrorUtilsHelper.h
//  Showtime
//
//  Created by Cesar V Ramirez on 11/28/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (OcErrorUtilsHelper)


- (void)fillNullParamError:(NSError **)outError withSelector:(SEL)selector paramName:(NSString *)paramName;

- (void)fillInvalidParamError:(NSError **)outError withSelector:(SEL)selector paramName:(NSString *)paramName
                   paramValue:(NSString *)paramValue;

- (void)fillInvalidParamError:(NSError **)outError withSelector:(SEL)selector paramName:(NSString *)paramName
                   paramValue:(NSString *)paramValue validValues:(NSString *)validValues;



- (void)fillError:(NSError **)outError withSelector:(SEL)selector codeNumber:(NSInteger)codeNumber desciption:(NSString *)description;
- (void)fillError:(NSError **)outError withSelector:(SEL)selector desciption:(NSString *)description;
- (void)fillError:(NSError **)outError withSelector:(SEL)selector desciption:(NSString *)description underlyingError:(NSError **)underlyingError;


- (void)throwInvalidInitializerExceptionWithSelector:(SEL)selector;
- (void)throwSubclassHasntImplementedAbstractMethodExceptionWithSelector:(SEL)selector;
- (void)throwValueNotInRangeExceptionWithSelector:(SEL)selector objectName:(NSString *)name objectValue:(NSString *)value;
- (void)throwInvalidArgumentExceptionWithSelector:(SEL)selector message:(NSString *)message;
- (void)throwInvalidSingletonReconfigurationExceptionWithSelector:(SEL)selector;
- (void)throwSingletonNotConfiguredExceptionWithSelector:(SEL)selector;

@end
