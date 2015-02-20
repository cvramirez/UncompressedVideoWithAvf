//
//  ErrorUtils.h
//  ShowtimeX
//
//  Created by Cesar V Ramirez on 10/25/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>




/*! Centralized Error Object creation utility functions
 
	All functions in this utility class are class functions that standardize the way
	NSError objects are created.  All the function variats are overlaods to make
	filling error objects easier.
 
	All functions will prepend new errors, not replace errors.
 
	All functions work in the following way:
 
	<table>
	  <tr>
		<td>outError == nil </td>
		<td>doesn't have anything; doesn't have variable/storage associated to it, so can't create/add error object to it.</td>
	  </tr>
	  <tr>
		<td>*outError == nil </td>
		<td>error object is empty; creates a new error.</td>
	  </tr>
	   <tr>
		<td>*outError != nil </td>
		<td>error object has existing error; prepend by creating a new error and making the existing error an underlying error.</td>
	   </tr>
	</table>
 
 
	If outError == nil, doesn't do anything.
	Else if *outError == nil, creates a new error
	Else *outError != nil, there is already an existing error, create a new error and make the existing error an underlying error.
 
	
 */

enum{
    kQT_InvalidMoviePointerError = -999,
    kQT_InvalidWindowPointerError,
    kQT_InsufficientMemoryError,
    kQT_NoVideoTrackError,
    kQT_InvalidTrackError,
    kQT_InvalidParameterError,
    kQT_FilespcError,
    kQT_CantCreateFileError,
    kQT_CantOpenFileError,
    kQT_QuicktimeNotInstalledError,
    kQT_EnterMoviesError,
    kQT_AtExitError,
    kQT_QuicktimeAPIError,
    kQT_CreationLevelPermissionsError,
    kQT_ShowtimeError
};



@interface OcUtilsForNSError : NSObject



+(void) StdError:(NSNumber *)errNumber withDesciption:(NSString *)errDescription withUnderlyingError:(NSError **)underlyingError;
+(void) fillError:(NSError **)outError withCode:(NSInteger)iCode withDesciption:(NSString *)sDescription;
+(void) fillError:(NSError **)outError withCode:(NSInteger)iCode withDesciption:(NSString *)sDescription andWithOSError:(long)osErrorNumber;
+(void) fillSystemError:(NSError **)outError withDesciption:(NSString *)sDescription;
+(void) fillBugError:(NSError **)outError withDesciption:(NSString *)sDescription;



+(void) fillError:(NSError **)outError withClassName:(NSString *)className functionName:(NSString *)functionName
                                          codeNumber:(NSInteger)codeNumber desciption:(NSString *)description;
+(void) fillError:(NSError **)outError withClassName:(NSString *)className functionName:(NSString *)functionName
                                          desciption:(NSString *)description;
+(void) fillError:(NSError **)outError withClassName:(NSString *)className functionName:(NSString *)functionName
                                          desciption:(NSString *)description underlyingError:(NSError **)underlyingError;



+(void) fillNullParamError:(NSError **)outError withClassName:(NSString *)className functionName:(NSString *)functionName paramName:(NSString *)paramName;
+(void) fillInvalidParamError:(NSError **)outError withClassName:(NSString *)className functionName:(NSString *)functionName paramName:(NSString *)paramName
                   paramValue:(NSString *)paramValue;
+(void) fillInvalidParamError:(NSError **)outError withClassName:(NSString *)className functionName:(NSString *)functionName paramName:(NSString *)paramName
                   paramValue:(NSString *)paramValue validValues:(NSString *)validValues;

@end
