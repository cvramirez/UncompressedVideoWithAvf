/*! NSInvocation(Constructors)
 *
 * Created by Cesar V. Ramirez on 4/30/14.
 *
 * Inspired by http://a-coding.com/making-nsinvocations
 */

@interface NSInvocation (Constructors)

// Returns an initialized invocation from a target and a selector.
+ (id)invocationForInstanceTargetWithInstance:(NSObject *)targetObject selector:(SEL)selector;

// Returns an invocation from a class and a selector. The selector property of the
// invocation is initialized but you still need to set the target before invoking it.
+ (id)invocationForClassTargetWithClass:(Class)targetClass selector:(SEL)selector;

// Returns an invocation from a protocol and a selector. The selector property of the
// invocation is initialized but you still need to set the target before invoking it.
+ (id)invocationWithProtocol:(Protocol*)targetProtocol selector:(SEL)selector;

@end