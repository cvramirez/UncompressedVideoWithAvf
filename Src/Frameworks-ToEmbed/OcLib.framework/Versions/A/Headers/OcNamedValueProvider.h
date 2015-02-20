/*! OcNameValue
 *
 * Created by Cesar V. Ramirez on 6/5/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <Foundation/Foundation.h>
#import <OcLib/RtoDefs.h>
#import <OcLib/OcBaseNoInit.h>


@interface OcNamedValueProvider : OcBaseNoInit

+ (instancetype)newWithName:(NSString *)name valueProviderBlock:(OcNamedValueProviderBlock)valueProviderBlock;

@property (nonatomic, readonly, copy  ) NSString *name;
@property (nonatomic, readonly, copy  ) OcNamedValueProviderBlock valueProviderBlock;

@end
