//! Access command line args anywhere, anytime, :)
#import "OcBaseNoInit.h"


@interface OcCommandLineArgsHelper : OcBaseNoInit

+ (instancetype)instance;
@property (nonatomic, readonly, assign) int argC;
@property (nonatomic, readonly, assign) const char** argV;

@end
