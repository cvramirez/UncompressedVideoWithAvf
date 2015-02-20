//
//  ObjectUtils.h
//  Showtime
//
//  Created by Cesar V Ramirez on 11/28/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OcObjectUtils : NSObject


+(NSString*)getClassNameForObject:(id)theObject;
+(NSString*)getClassNameForSuperclassOfObject:(id)theObject;

@end
