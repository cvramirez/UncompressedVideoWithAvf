/*  @class OcLinkWriter

    @brief Base class for input/output of values to application from a link.



 */
#import <OcLib/OcLib.h>
@class OcIntArray;
@class OcDoubleArray;
@class OcIntROArray;
@class OcIntNDimArray;
@class OcDoubleNDimArray;


#define kNumItemsInPair 2

@interface OcLinkWriter : OcBaseNoInit

+ (instancetype)singleton;

- (BOOL)getNumItemsInListAndValidateEqualsTwo;

- (BOOL)getNumItemsInListAndValidateEquals:(long)numRequired;

- (BOOL)setSelfAsSharedInstance;
+ (BOOL)setSharedInstance:(id)instance;
+ (BOOL)releaseSharedInstance;





#pragma mark ---  Primitives  ---

- (BOOL)getBoolSymbol:(bool *)boolPtr;
- (BOOL)putBoolSymbol:(bool)value;


- (BOOL)getDouble:(double *)doublePtr;
- (BOOL)putDouble:(double)value;

- (BOOL)getInt:(int *)intPtr;
- (BOOL)putInt:(int)value;

- (BOOL)getString:(NSString **)stringPtr;
- (BOOL)putString:(NSString *)value;

- (BOOL)getSymbolAndValidateItWas:(NSString *)expectedSymbol;
- (BOOL)getSymbol:(NSString **)stringPtr;
- (BOOL)putSymbol:(NSString *)value;





#pragma mark ---  Special Types  ---

- (BOOL)getNSPoint:(NSPoint *)point;
- (BOOL)putNSPoint:(NSPoint)point;

- (BOOL)getNSSize:(NSSize *)size;
- (BOOL)putNSSize:(NSSize)size;

- (BOOL)getNSRect:(NSRect *)rect;
- (BOOL)putNSRect:(NSRect)rect;

- (BOOL)getIntNSPoint:(NSPoint *)point;
- (BOOL)putIntNSPoint:(NSPoint)point;

- (BOOL)getIntNSSize:(NSSize *)size;
- (BOOL)putIntNSSize:(NSSize)size;

- (BOOL)getIntNSRect:(NSRect *)rect;
- (BOOL)putIntNSRect:(NSRect)rect;

- (BOOL)getNullSymbol;
- (BOOL)putNullSymbol;

- (BOOL)getNSColor:(NSColor **)colorPtr;
- (BOOL)putNSColor:(NSColor *)color;



#pragma mark ---  Arrays  ---

- (BOOL)getIntArray:(OcIntArray **)arrayPtr;
- (BOOL)putIntArray:(OcIntArray *)array;

- (BOOL)getIntNDimArray:(OcIntNDimArray **)jaggedArrayPtr;
- (BOOL)putIntNDimArray:(OcIntNDimArray *)array;

- (BOOL)getDoubleArray:(OcDoubleArray **)arrayPtr;
- (BOOL)putDoubleArray:(OcDoubleArray *)array;

- (BOOL)getDoubleNDimArray:(OcDoubleNDimArray **)jaggedArrayPtr;
- (BOOL)putDoubleNDimArray:(OcDoubleNDimArray *)array;



#pragma mark ---  Collections  ---

- (BOOL)getNameValuePairStrings:(NSMutableDictionary *)nameValueDict;
- (BOOL)putNameValuePairStrings:(NSMutableDictionary *)nameValueDict;

- (BOOL)getStringArray:(NSMutableArray *)array;
- (BOOL)putStringArray:(NSArray *)array;

- (BOOL)getSymbolArray:(NSMutableArray *)array;
- (BOOL)putSymbolArray:(NSArray *)array;


#pragma mark ---  Utility Functions  ---


- (BOOL)getFunction:(NSString **)stringPtr numArgs:(int *)numArgsPtr;
- (BOOL)getTypeIdOfCurrent:(int *)typeIdPtr;
- (BOOL)getTypeIdOfNext:(int *)typeIdPtr;



- (BOOL)ensureAtEndOrCanSkipToEndOfArgsListAndBePreparedForSendingData;

- (BOOL)getNumItemsInList:(long *)numListItemsPtr;
- (BOOL)getNumItemsInCurrQueueItem:(long *)numListItemsPtr;


- (BOOL)putEmptyList;

- (BOOL)startNewResponse;

- (BOOL)startListWithNumItems:(uint)numItems;
- (BOOL)startFunctionDefinitionWithName:(NSString*)name numArgs:(uint)numArgs;

@end
