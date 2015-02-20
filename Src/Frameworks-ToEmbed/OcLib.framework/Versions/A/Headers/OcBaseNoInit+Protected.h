#import "OcBaseNoInit.h"

// For alternate, see:  http://stackoverflow.com/questions/3725857/protected-methods-in-objective-c

@interface OcBaseNoInit (Protected)

- (instancetype)initProtected;
//! same as initProtected except adds "out of memory error" if can't create object... even though they probably will never see it
- (instancetype)initProtectedResultSet:(OcResultSet *)resultSet;
- (BOOL)initializeIVars;

@end
