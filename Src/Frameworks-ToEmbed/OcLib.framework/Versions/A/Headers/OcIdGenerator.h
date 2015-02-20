/*! OcIdGenerator
 *
 * Created by Cesar V. Ramirez on 4/19/14.
 *
 */
#import <OcLib/OcLib.h>


@interface OcIdGenerator : OcBaseNoInit

- (instancetype)initSerialNumberGeneratorWithFormat:(NSString *)format startNumber:(int)startNumber;
+ (instancetype)serialNumberGeneratorWithFormat:(NSString *)format startNumber:(int)startNumber;

- (int)numGeneratedIds;
- (NSString *)nextFormattedId;
@end