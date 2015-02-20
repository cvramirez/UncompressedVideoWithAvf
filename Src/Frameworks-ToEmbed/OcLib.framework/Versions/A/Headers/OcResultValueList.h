/*! @class OcResultValueList
 *
 * Created by Cesar V. Ramirez on 9/5/13.
 */
#import <Foundation/Foundation.h>
#import <OcLib/OcResultValue.h>
@class OcIntArray;
@class OcIntNDimArray;
@class OcDoubleArray;
@class OcDoubleNDimArray;


@interface OcResultValueList : NSObject

+ (instancetype)new;


#pragma Mark -
#pragma Mark - Collection accessors

- (NSArray *)values;
- (OcResultValue *)valueAtIndex:(NSUInteger)index;
- (NSUInteger)count;

- (NSString *)debugDescription;


#pragma Mark -
#pragma Mark - Value adding convenience methods

- (void)addValue:(OcResultValue *)value;
- (void)addValueList:(OcResultValueList *)value;
- (void)addValueList:(OcResultValueList *)value named:(NSString *)name;

- (void)addNullValue;
- (void)addNullValueNamed:(NSString*)name;
- (void)addInt:(int)value;
- (void)addInt:(int)value named:(NSString*)name;
- (void)addBool:(bool)value;
- (void)addBool:(bool)value named:(NSString*)name;
- (void)addBOOL:(BOOL)value;
- (void)addBOOL:(BOOL)value named:(NSString*)name;
- (void)addDouble:(double)value;
- (void)addDouble:(double)value named:(NSString*)name;
- (void)addString:(NSString *)value;
- (void)addString:(NSString *)value named:(NSString*)name;
- (void)addSymbol:(NSString *)value;
- (void)addSymbol:(NSString *)value named:(NSString *)name;

- (void)addIntArray:(OcIntArray *)value;
- (void)addIntArray:(OcIntArray *)value named:(NSString*)name;
- (void)addIntNDimArray:(OcIntNDimArray *)integerArray;
- (void)addIntNDimArray:(OcIntNDimArray *)integerArray named:(NSString*)name;
- (void)addDoubleArray:(OcDoubleArray *)value;
- (void)addDoubleArray:(OcDoubleArray *)value named:(NSString*)name;

- (void)addDoubleNDimArray:(OcDoubleNDimArray *)value;

- (void)addDoubleNDimArray:(OcDoubleNDimArray *)value named:(NSString *)name;
@end
