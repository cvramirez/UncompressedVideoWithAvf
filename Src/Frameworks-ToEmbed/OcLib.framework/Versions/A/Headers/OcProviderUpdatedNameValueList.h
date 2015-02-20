/*! ProviderUpdatedNameValueList
 *
 * Created by Cesar V. Ramirez on 6/5/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */


#import <Foundation/Foundation.h>

@class OcNamedValueProviderSet;


@interface OcProviderUpdatedNameValueList : NSObject

@property (nonatomic, readonly, strong) OcNamedValueProviderSet *namedValueProviderSet;
@property (nonatomic, readonly, strong) NSMutableDictionary *values;

@end
