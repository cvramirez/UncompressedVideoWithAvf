/*! MLinkInvocationBuilder
 *
 * Created by Cesar V. Ramirez on 4/30/14.
 *
 */
#import <Foundation/Foundation.h>
#import <OcLib/OcBaseNoInit.h>

@class OcResultValue;


@interface OcInvocationBuilder : OcBaseNoInit

+ (instancetype)newWithTargetClass:(Class)targetClass selector:(SEL)selector;
+ (instancetype)newWithTargetInstance:(id)targetInstance selector:(SEL)selector;

@property (nonatomic, readonly, assign) int numArguments;
@property (nonatomic, readonly, strong) NSInvocation *invocation;

- (BOOL)addObjectTypeArgument:(id)object;
- (BOOL)addScalarTypeArgumentWithAddress:(void *)argAddress;
- (BOOL)addValue:(OcResultValue *)value;
@end
