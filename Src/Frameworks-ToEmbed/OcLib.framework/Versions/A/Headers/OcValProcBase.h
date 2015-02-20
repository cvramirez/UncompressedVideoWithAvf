/*! ValueProcessorDef
 *
 * Created by Cesar V. Ramirez on 6/18/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <OcLib/OcLinkWriter.h>
#import <OcLib/OcResultValue.h>


#import "RtoConstants.h"
#import "RtoDefs.h"
@class OcResultValue;
@class OcValueLink;


@interface OcValProcBase : OcBaseNoInit

+ (instancetype)newWithNewWithParentValueLink:(OcValueLink*)valueLink valueMonkey:(OcLinkWriter *)linkWriter;

- (instancetype)initWithNewWithParentValueLink:(OcValueLink *)valueLink linkWriter:(OcLinkWriter *)linkWriter;

@property (nonatomic, readonly,  retain) OcValueLink *parentValueLink;
//! I don't like this here, but Obj-C has no "protected" members
@property (nonatomic, readonly, retain) OcLinkWriter *linkWriter;
@property (nonatomic, readonly, assign) RtoValueType type;


- (BOOL)getNextValueFromLink:(OcResultValue **)valuePtr assigningItName:(NSString *)name;
- (BOOL)putValue:(OcResultValue *)value;
- (BOOL)putListValue:(OcResultValue *)value resultSet:(OcResultSet *)resultSet;

@end
