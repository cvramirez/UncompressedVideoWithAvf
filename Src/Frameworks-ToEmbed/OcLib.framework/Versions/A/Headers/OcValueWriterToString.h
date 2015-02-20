/*! @class StringValueLink
 *
 * Writes values to a string formatted using Mathematica syntax.  This can be used for testing without needing Mathematica/Mathlink.
 *
 */
#import <OcLib/OcLinkWriter.h>



@class OcObjectStack;
@class OcIntArray;
@class OcDoubleArray;


@interface OcValueWriterToString : OcLinkWriter

- (NSString *)stringValue;
@end
