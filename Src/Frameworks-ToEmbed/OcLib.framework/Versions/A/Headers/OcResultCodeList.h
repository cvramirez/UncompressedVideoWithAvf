/*! RtoResultCodeList
 *
 * Created by Cesar V. Ramirez on 9/11/13.
 * Copyright (c) 2013 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <Foundation/Foundation.h>
#import <OcLib/OcResultCode.h>
#import <OcLib/OcLib.h>
#import "RtoConstants.h"



@interface OcResultCodeList : OcBaseNoInit

@property (nonatomic, readonly, assign) BOOL isUninitialized;

- (id)initWithUnassignedError;
+ (id)resultCodeListWithUnassignedError;


- (RtoResultType)resultType;
- (BOOL)hasNoError;


- (BOOL)hasNoInitializedError;

- (NSArray*)resultCodes;
- (OcResultCode *)codeAtIndex:(NSUInteger)index;
- (NSUInteger)count;

- (NSString *)debugDescription;


- (void)addResultCode:(OcResultCode *)resultCode;
- (void)addResultType:(RtoResultType)eType code:(OcErrType)code message:(NSString *)sMsg;


- (void)addSuccessWithMessage:(NSString *)sMsg;

- (void)addSuccessWithFormat:(NSString *)formatString, ... NS_FORMAT_FUNCTION(1,2);

- (void)addSuccessWithMessage:(NSString *)message andCode:(OcErrType)code;

- (void)addWarningWithMessage:(NSString *)sMsg;
- (void)addWarningWithMessage:(NSString *)message andCode:(OcErrType)code;

- (void)addWarningWithCode:(OcErrType)code format:(NSString *)formatString, ... NS_FORMAT_FUNCTION(2,3);

- (void)addWarningWithFormat:(NSString *)formatString, ...;

- (void)addWarningWithMessage:(NSString *)sErrorMsg andErrorObject:(NSError *)oErrorObj;
- (void)addWarningWithMessage:(NSString *)sErrorMsg code:(OcErrType)code andErrorObject:(NSError *)oErrorObj;


- (void)addErrorWithCode:(OcErrType)code format:(NSString *)formatString, ... NS_FORMAT_FUNCTION(2,3);

- (void)addErrorWithMessage:(NSString *)sErrorMsg;
- (void)addErrorWithMessage:(NSString *)message andCode:(OcErrType)code;
- (void)addErrorWithMessage:(NSString *)sErrorMsg andErrorObject:(NSError *)oErrorObj;
- (void)addErrorWithMessage:(NSString *)message code:(OcErrType)code andErrorObject:(NSError *)errorObj;
@end
