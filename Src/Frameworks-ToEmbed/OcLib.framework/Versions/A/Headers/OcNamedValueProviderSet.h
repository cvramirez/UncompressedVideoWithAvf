/*! OcRuleSet
 *
 * Created by Cesar V. Ramirez on 6/5/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */


#import <Foundation/Foundation.h>
#import <OcLib/OcBaseNoInit.h>
#import "RtoDefs.h"

@class OcLinkWriter;
@class OcNamedValueProvider;


@interface OcNamedValueProviderSet : OcBaseNoInit

@property (nonatomic, readonly, strong) NSMutableDictionary *nameValuePairs;

- (BOOL)useDefinedValueProviderToUpdatePropertyWithName:(NSString*)propertyName;

- (void)addNameValueProvider:(OcNamedValueProvider *)namedValueProvider;
- (void)addName:(NSString*)name withValueProvider:(OcNamedValueProviderBlock)valueProviderBlock;
- (void)addNames:(NSArray*)names withValueProvider:(OcNamedValueProviderBlock)valueProvider;


@end
