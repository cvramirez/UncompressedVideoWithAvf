/*! OcTestUtils
 *
 * Created by Cesar V. Ramirez on 4/27/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */


#import <Foundation/Foundation.h>


@interface OcTestUtils : NSObject

/** Indicates whether currently running app is doing so in the context of a test project
 */
+ (BOOL)isApplicationRunningInTestProject;

@end