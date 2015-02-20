/*! @class OcValueLink
 *
 * Created by Cesar V. Ramirez on 6/18/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 * ToDo: Do we have too many classes floating around for "links" et al? Should this class be a part of another composed object or service?
 *
 */
#import <Foundation/Foundation.h>
#import "RtoConstants.h"
@class OcResultSet;
@class OcValProcBase;
@class OcResultValue;


@interface OcValueLink : NSObject

+ (instancetype)new;

- (BOOL)createWriterSetWithName:(NSString *)name resultSet:(OcResultSet *)resultSet;

- (BOOL)addWriterValueProcessor:(OcValProcBase *)valueProcessor forValueTypeName:(RtoValueType)valueTypeName resultSet:(OcResultSet *)resultSet;
- (BOOL)addWriterValueProcessor:(OcValProcBase *)valueProcessor forValueTypeName:(RtoValueType)valueTypeName forWriterSet:(NSString *)setName
                                                                                                                resultSet:(OcResultSet *)resultSet;
- (BOOL)addReaderValueProcessor:(OcValProcBase *)valueProcessor forValueTypeName:(RtoValueType)valueTypeName resultSet:(OcResultSet *)resultSet;

- (BOOL)sendValueToLinks:(OcResultValue *)value resultSet:(OcResultSet *)resultSetForSendProcess;

- (BOOL)getValueFromLink:(OcResultValue **)valuePtr ofType:(RtoValueType)type assigningItName:(NSString *)name resultSet:(OcResultSet *)resultSet;
@end
