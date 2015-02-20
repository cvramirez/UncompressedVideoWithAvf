
/*! Utility macro to facilitate use of format strings and optional variadic arguments

    composedString - is the receiver and also the first arg.
    formatString   - containing the format string with optional percent sign escapes.

    Example use in method:

        - (void)addWarningWithCode:(NSString *)code message:(NSString *)formatString, ... NS_FORMAT_FUNCTION(1,2) {

            NSString *composedString = ComposeVariadicString(composedString, formatString);
            [self addWarningWithMessage:composedString code:code andErrorObject:nil];
        }

    *** Important:  To ensure we get compiler warnings about wrong number of variadic args
    *** Important:  compared to the number of escapes in the format string, be sure to specify
    *** Important:  the "NS_FORMAT_FUNCTION(1,2)" macro in the interface declaration.


    Notes:  because we want to use the more natural "assignment" looking form:

                NSString *composedString = ComposeVariadicString(composedString, formatString);

            we start the macro with "nil;" to complete the assignment, and then later
            assign an actual value to composedString.

            There is also a dorky initial if-statement that *uses* the value in composedString,
            so that we don't get IDE warnings that an assigned value was not used, even though
            that value was nil.

 */

#define ComposeVariadicString(composedString, formatString) \
    nil; \
    if (composedString != nil) { \
        NSLog(@"This is impossible, but the above line here only to prevent IDE warning of 'composedString variable value not used'"); \
    } \
    NSString *stringWithoutEscapedPercents = [formatString stringByReplacingOccurrencesOfString:@"%%" withString:@"XX"]; \
    long specifierCount = [stringWithoutEscapedPercents componentsSeparatedByString:@"%"].count - 1; \
    if (specifierCount>0) { \
        va_list args; \
        va_start(args, formatString); \
        composedString = [[NSString alloc] initWithFormat:formatString arguments:args]; \
        va_end(args); \
    } \
    else { \
        composedString = [NSString stringWithFormat:formatString]; \
    }
