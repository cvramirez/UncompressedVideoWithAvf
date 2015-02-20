#ifndef _RtoGeneralConstants
#define _RtoGeneralConstants


typedef NSString* OcErrType;


#define kOcConst_numBitsPerDatumInOcIntNDimArray (sizeof(int) * 8)
#define kOcConst_numBitsPerComponentInBgra32 8



static OcErrType const kOcErr_None = @"kOcErr_None";
static OcErrType const kOcErr_Unspecified = @"Unspecified";

//these four constants describe different ways the user can give an invalid argument.  They are treated specially by PsychErrorExitC
// (called by macros PsychErrorExit and PsychErrorExitMsg) which gives an extra verbose report for these errors,  relying on
// cached argument descriptors to make its report.
static OcErrType const kOcErr_invalidArg_absent = @"xxxxxx";
static OcErrType const kOcErr_invalidArg_extra = @"xxxxxx";
static OcErrType const kOcErr_invalidArg_type = @"xxxxxx";
static OcErrType const kOcErr_invalidArg_size = @"xxxxxx";

//these three four contants are used for the cap an limit calls at the head of module sufunctions.  They don't cause the special behavior in
//PsychErrorExit.
static OcErrType const kOcErr_extraInputArg = @"xxxxxx";
static OcErrType const kOcErr_missingInputArg = @"xxxxxx";
static OcErrType const kOcErr_extraOutputArg = @"xxxxxx";
static OcErrType const kOcErr_MissingOutputArg = @"xxxxxx";
static OcErrType const kOcErr_ValueNotInitialized = @"err_ValueNotInitialized";
static OcErrType const kOcErr_ValueCannotBeReassigned = @"err_ValueCannotBeReassigned";  // value can only be set once
static OcErrType const kOcErr_ArgValueOutOfRange = @"err_ArgValueOutOfRange";  // Out of range, ie, not within [0,255].
static OcErrType const kOcErr_ArgValueNotRecognized = @"err_ArgValueNotRecognized";  // Arg meant to be an identifier, but not recognized.
static OcErrType const kOcErr_ArgValueInvalidDimensions = @"err_ArgValueInvalidDimensions";  // Arg wrong dimensions.


static OcErrType const kOcErr_toomanyWin = @"xxxxxx";
static OcErrType const kOcErr_OutOfMemory = @"err_OutOfMemory";
static OcErrType const kOcErr_scumberNotWindex = @"xxxxxx";
static OcErrType const kOcErr_windexNotScumber = @"xxxxxx";
static OcErrType const kOcErr_invalidIntegerArg = @"xxxxxx";
static OcErrType const kOcErr_invalidWindex = @"xxxxxx";
static OcErrType const kOcErr_invalidScumber = @"xxxxxx";
static OcErrType const kOcErr_invalidNumdex = @"xxxxxx";
static OcErrType const kOcErr_invalidColorArg = @"xxxxxx";
static OcErrType const kOcErr_invalidDepthArg = @"xxxxxx";
static OcErrType const kOcErr_invalidRectArg = @"xxxxxx";
static OcErrType const kOcErr_invalidNumberBuffersArg = @"xxxxxx";		//invalid number of video buffers specified to SCREEN OpenWindow
static OcErrType const kOcErr_nullWinRecPntr = @"xxxxxx";
static OcErrType const kOcErr_registerLimit = @"xxxxxx";
static OcErrType const kOcErr_registered = @"xxxxxx";
static OcErrType const kOcErr_longString = @"xxxxxx";
static OcErrType const kOcErr_longStringPassed = @"xxxxxx";
static OcErrType const kOcErr_unimplemented = @"xxxxxx";				//unimplemented feature
static OcErrType const kOcErr_internal = @"err_internal";			//catch-all category for INTERNAL PSYCHTOOLBOX ERRORS.
static OcErrType const kOcErr_system = @"xxxxxx";						//errors reported by system calls
static OcErrType const kOcErr_invalidArgRef = @"xxxxxx";
static OcErrType const kOcErr_OpenGL = @"xxxxxx";
static OcErrType const kOcErr_SDL = @"xxxxxx";
static OcErrType const kOcErr_SurfaceLockFailed = @"xxxxxx";
static OcErrType const kOcErr_SurfaceAlreadyLocked = @"xxxxxx";
static OcErrType const kOcErr_InvalidWindowRecord = @"xxxxxx";
static OcErrType const kOcErr_unsupportedVideoMode = @"xxxxxx";
static OcErrType const kOcErr_user = @"xxxxxx";							//catch-all category for USER ERRORS.
static OcErrType const kOcErr_unrecognizedPreferenceName = @"xxxxxx";
static OcErrType const kOcErr_unsupportedOS9Preference = @"xxxxxx";
static OcErrType const kOcErr_inputMatrixIllegalDimensionSize = @"xxxxxx";
static OcErrType const kOcErr_stringOverrun = @"xxxxxx";

static OcErrType const kOcErr_CantOpenFileError = @"kOcErr_CantOpenFileError";
static OcErrType const kOcErr_CantReadFileError = @"err_CantReadFile";
static OcErrType const kOcErr_CantCreateFileError = @"kOcErr_CantCreateFileError";



typedef const NSString* RtoResultType;
//static RtoResultType kRtoResultUninitialized = @"kRtoResultUninitialized";
static RtoResultType kRtoResultLinkError = @"kRtoResultLinkError";
static RtoResultType kRtoResultNoError = @"kRtoResultNoError";
static RtoResultType kRtoResultWarning = @"kRtoResultWarning";
static RtoResultType kRtoResultError = @"kRtoResultError";


// ToDo: this switched from stdErr to internal... how's it going...  ?
static OcErrType const kSTStdErr = @"Unspecified"; // kOcErr_Unspecified;
static OcErrType const kSTUseErrorObjectCode = @"kSTUseErrorObjectCode";

//#define kSTUseErrorObjectCode	-23001
//#define kSTStdErr				-1
#define kSTStdWarn				-2
#define kSTNoErr				 0



typedef enum {
    kOcLinkIsOk,
    kOcLinkHasErrors_AttemptErrorCorrection
} OcLinkStatus;

typedef NSString* OcRectLocationType;
static OcRectLocationType const kOcRectLocation_TopLeft = @"TopLeft";
static OcRectLocationType const kOcRectLocation_TopRight = @"TopRight";
static OcRectLocationType const kOcRectLocation_TopCenter = @"TopCenter";
static OcRectLocationType const kOcRectLocation_MiddleLeft = @"MiddleLeft";
static OcRectLocationType const kOcRectLocation_MiddleRight = @"MiddleRight";
static OcRectLocationType const kOcRectLocation_MiddleCenter = @"Center";
static OcRectLocationType const kOcRectLocation_BottomLeft = @"BottomLeft";
static OcRectLocationType const kOcRectLocation_BottomRight = @"BottomRight";
static OcRectLocationType const kOcRectLocation_BottomCenter = @"BottomCenter";
//
//@interface OcStringConstrants : NSObject
//@end
//@interface OcRectLocation: OcStringConstrants
//+ (NSString *)TopLeft;
//+ (NSString *)TopRight;
//+ (NSString *)TopCenter;
//@end
//@implementation OcRectLocation
//@end

typedef int RtoOutputType;
const static RtoOutputType kRtoOutputInvalid = -1;
const static RtoOutputType kRtoOutputAsValue = 0;
const static RtoOutputType kRtoOutputAsRule = 1;
const static RtoOutputType kRtoOutputAsAssociation = 2;
const static RtoOutputType kRtoOutputAsList = 3;

typedef int RtoOutputTypeInheritanceType;
const static RtoOutputType RtoOutputTypeInheritance_SelfOnly = 0;
const static RtoOutputType RtoOutputTypeInheritance_ChildrenFirstGeneration = 4;
const static RtoOutputType RtoOutputTypeInheritance_ChildrenAllGenerations = 1;
const static RtoOutputType RtoOutputTypeInheritance_SelfAndChildrenFirstGeneration = 2;
const static RtoOutputType RtoOutputTypeInheritance_SelfAndChildrenAllGenerations = 3;



typedef const char* RtoValueType;
#define AreEqualRtoValueTypeNames(cStr1, cStr2)(strcmp(cStr1, cStr2)==0)


static RtoValueType kRtoValueResultSet = "kRtoValueResultSet";  // Crit: this needs to be defined

//! OcReturnValue contains integer value for enum RtoOutputType
static RtoValueType kRtoValueOutputType = "kRtoValueOutputType";


static RtoValueType kRtoValueNotAValue = "kRtoValueNotAValue";  // Crit: this needs to be defined

static RtoValueType kRtoValueNDimIntegerList = "kRtoValueNDimIntegerList";
static RtoValueType kRtoValueNDimDoubleList = "kRtoValueNDimDoubleList";

static RtoValueType kRtoValueValueList = "kRtoValueValueList";
static RtoValueType kRtoValueResultCodeList = "kRtoValueResultCodeList";
static RtoValueType kRtoValueVoid = "kRtoValueVoid";
static RtoValueType kRtoValueNull = "kRtoValueNull";
static RtoValueType kRtoValueInt = "kRtoValueInt";
static RtoValueType kRtoValueDouble = "kRtoValueDouble";
static RtoValueType kRtoValueString = "kRtoValueString";
static RtoValueType kRtoValueStringArray = "kRtoValueStringArray";
static RtoValueType kRtoValueSymbol = "kRtoValueSymbol";
static RtoValueType kRtoValueSymbolArray = "kRtoValueSymbolArray";


static RtoValueType kRtoValueIntArray = "kRtoValueIntArray";
static RtoValueType kRtoValueDoubleArray = "kRtoValueDoubleArray";

static RtoValueType kRtoValueIntegerArray = "kRtoValueIntegerArray";

static RtoValueType kRtoValueNSRect = "kRtoValueNSRect";
static RtoValueType kRtoValueNSSize = "kRtoValueNSSize";
static RtoValueType kRtoValueNSPoint = "kRtoValueNSPoint";

static RtoValueType kRtoValueIntNSRect = "kRtoValueIntNSRect";
static RtoValueType kRtoValueIntNSSize = "kRtoValueIntNSSize";
static RtoValueType kRtoValueIntNSPoint = "kRtoValueIntNSPoint";


static RtoValueType kRtoValueObject = "kRtoValueObject";
static RtoValueType kRtoValueNSColor = "kRtoValueNSColor";


static RtoValueType kRtoOcValueDictionary = "kRtoOcValueDictionary";
static RtoValueType kRtoValueNameValueList = "kRtoValueNameValueList";
static RtoValueType kRtoValueRuleList = "kRtoValueRuleList";


static RtoValueType kRtoValueBool = "kRtoValueBool";
static RtoValueType kRtoValueBOOL = "kRtoValueBOOL";
static RtoValueType kRtoValueIntROArray = "kRtoValueIntROArray";
static RtoValueType kRtoValueIntNDimArray = "kRtoValueIntNDimArray";
static RtoValueType kRtoValueDoubleROArray = "kRtoValueDoubleROArray";
static RtoValueType kRtoValueDoubleNDimArray = "kRtoValueDoubleNDimArray";

#endif
