#import <CocoaLumberjack/CocoaLumberjack.h>

#ifndef __OCLIB_LOG_STUFFS_
#define __OCLIB_LOG_STUFFS_

#ifdef DEBUG
    #define OCLIB_LOG_LEVEL_FOR_DEBUG LOG_LEVEL_WARN
#else
    #define OCLIB_LOG_LEVEL_FOR_DEBUG LOG_LEVEL_WARN
#endif

#define OCLIB_LOG_Is_Static true
#define OCLIB_LOG_Is_Using_Global false


/*!

 */
#if OCLIB_LOG_Is_Static
    #define OcLogDef(localLevel)                         \
    static const int _ocLogLevel = OCLIB_LOG_Is_Using_Global ? OCLIB_LOG_LEVEL_FOR_DEBUG : localLevel;

#else
    #define OcLogDef(localLevel)                          \
    static int _ocLogLevel = OCLIB_LOG_Is_Using_Global ? OCLIB_LOG_LEVEL_FOR_DEBUG : localLevel;
#endif




#define OcLib_Log_Context 333

#define OcLog_SYNC_LOG_OBJC_MAYBE(lvl, flg, ctx, format, ...) SYNC_LOG_OBJC_MAYBE(lvl, flg, ctx, (@"%s [Line %d] " format), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define OcLog_ASYNC_LOG_OBJC_MAYBE(lvl, flg, ctx, format, ...) ASYNC_LOG_OBJC_MAYBE(lvl, flg, ctx, (@"%s [Line %d] " format), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)


#define OcLogError(format, ...)     OcLog_SYNC_LOG_OBJC_MAYBE(_ocLogLevel, LOG_FLAG_ERROR,     OcLib_Log_Context, format, ##__VA_ARGS__)
#define OcLogWarn(format, ...)       OcLog_SYNC_LOG_OBJC_MAYBE(_ocLogLevel, LOG_FLAG_WARN,      OcLib_Log_Context, format, ##__VA_ARGS__)
#define OcLogInfo(format, ...)       OcLog_SYNC_LOG_OBJC_MAYBE(_ocLogLevel, LOG_FLAG_INFO,      OcLib_Log_Context, format, ##__VA_ARGS__)
#define OcLogDebug(format, ...)      OcLog_SYNC_LOG_OBJC_MAYBE(_ocLogLevel, LOG_FLAG_DEBUG,     OcLib_Log_Context, format, ##__VA_ARGS__)
#define OcLogVerbose(format, ...)    OcLog_SYNC_LOG_OBJC_MAYBE(_ocLogLevel, LOG_FLAG_VERBOSE,   OcLib_Log_Context, format, ##__VA_ARGS__)


#define OcLogSuccessFailString(isSuccess) (isSuccess ? @"success" : @"** Fail! **")
#define OcLogTrueFalseString(isSuccess) (isSuccess ? @"True" : @"False")


#define OcLogEnteredMethod() OcLogDebug(@"Entered method.")
#define OcLogExitMethodWithSuccessBool(isSuccess)   \
            if (isSuccess) OcLogDebug(@"Exiting method with %@",OcLogSuccessFailString(isSuccess)); \
            else           OcLogError(@"Exiting method with %@",OcLogSuccessFailString(isSuccess));
#define OcLogVerboseOrError(isSuccess, format, ...)   \
            if (isSuccess) OcLogVerbose(format, ##__VA_ARGS__); \
            else           OcLogError(format, ##__VA_ARGS__);

#define OcLogWarnOrError(isSuccess, format, ...)   \
            if (isSuccess) OcLogWarn(format, ##__VA_ARGS__); \
            else           OcLogError(format, ##__VA_ARGS__);


#define OcLogPrePrepForVerbose(code)


#endif