//
// Created by cvramirez on 10/17/12.
//
#import <OcLib/OcLib.h>
#import "RtoConstants.h"
@class OcIntArray;
@class OcIntNDimArray;
@class OcResultValueList;
@class OcResultCodeList;
@class OcDoubleArray;
@class OcIntROArray;
@class OcDoubleROArray;
@class OcDoubleNDimArray;


@interface OcResultValue : OcBaseNoInit

@property (nonatomic, readwrite, copy  ) NSString *name;
@property (nonatomic, readonly , assign) RtoValueType type;
- (BOOL)isType:(RtoValueType)type;
@property (nonatomic, readonly , assign) BOOL isObjectType;
@property (nonatomic, readonly , strong) id object;
@property (nonatomic, readonly , assign) BOOL hasName;

@property (nonatomic, readwrite, assign) RtoOutputType outputType;



+ (instancetype)newWithObject:(id)object type:(RtoValueType)type isObjectType:(BOOL)isObjectType;
+ (instancetype)newWithName:(NSString *)name object:(id)object type:(RtoValueType)type isObjectType:(BOOL)isObjectType;


+ (instancetype)newWithValueList:(OcResultValueList *)value name:(NSString *)name;
- (OcResultValueList *)valueListValue;

+ (instancetype)newWithResultCodeList:(OcResultCodeList *)value name:(NSString *)name;
- (OcResultCodeList *)resultCodeListValue;



+ (instancetype)newWithNullValueAndName:(NSString *)name;
- (void *)nullValue;

+ (OcResultValue *)newWithVoid;
- (void)voidValue;

+ (instancetype)newWithInt:(int)value name:(NSString *)name;
- (int)intValue;

+ (instancetype)newWithBool:(bool)value name:(NSString *)name;
+ (instancetype)newWithBoolSymbol:(NSString *)value name:(NSString *)name;
- (bool)boolValue;
- (NSString *)boolSymbolValue;

+ (instancetype)newWithIntArray:(OcIntArray *)array name:(NSString *)name;

+ (instancetype)newWithBOOL:(BOOL)value name:(NSString *)name;
+ (instancetype)newWithBOOLSymbol:(NSString *)value name:(NSString *)name;
- (BOOL)BOOLValue;
- (NSString *)BOOLSymbolValue;



+ (instancetype)newWithDouble:(double)value name:(NSString *)name;
- (double)doubleValue;



+ (instancetype)newWithString:(NSString *)string name:(NSString *)name;
- (NSString *)stringValue;

+ (instancetype)newWithSymbol:(NSString *)symbol name:(NSString *)name;
- (NSString *)symbolValue;

+ (instancetype)newWithObject:(id)object name:(NSString *)name;
- (id)objectValue;

+ (instancetype)newWithNSRect:(NSRect)value name:(NSString *)name;
- (NSRect)NSRectValue;

+ (instancetype)newWithNSSize:(NSSize)value name:(NSString *)name;
- (NSSize)NSSizeValue;

+ (instancetype)newWithNSPoint:(NSPoint)value name:(NSString *)name;
- (NSPoint)NSPointValue;



- (OcIntArray *)intArrayValue;
- (OcDoubleArray *)doubleArrayValue;
- (OcIntNDimArray *)intNDimArrayValue;

+ (instancetype)newWithDoubleArray:(OcDoubleArray *)array name:(NSString *)name;

- (OcDoubleNDimArray *)doubleNDimArrayValue;



+ (instancetype)newWithOcValueDictionary:(NSMutableDictionary *)string name:(NSString *)name;
- (NSMutableDictionary *)ocValueDictionaryValue;

+ (instancetype)newWithNameValueList:(NSMutableDictionary *)dictionary name:(NSString *)name;


- (NSMutableDictionary *)nameValueListValue;


- (NSArray *)nsArrayValue;

@end
