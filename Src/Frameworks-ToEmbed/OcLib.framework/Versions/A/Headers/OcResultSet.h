/*! RtoResultSet
 *
 * Created by Cesar V. Ramirez on 9/11/13.
 *
 */
#import <OcLib/OcLib.h>
#import <OcLib/OcResultCodeList.h>
#import <OcLib/OcResultValueList.h>
@class OcResultCodeList;


@interface OcResultSet : NSObject

- (instancetype)init;

//! codeList has no explicitly set errors.  might have "uninitialized err, but that is ok, not explicit.
- (BOOL)isOk;
+ (instancetype)resultSet;

@property (nonatomic, readonly, strong) OcResultCodeList *codeList;
@property (nonatomic, readonly, strong) OcResultValueList *valueList;
@end
