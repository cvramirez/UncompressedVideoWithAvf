#import <Foundation/Foundation.h>
@class OcResultValueList;
@class OcResultValue;
@class MLinkFuncDef;
@class OcResultSet;


typedef NS_ENUM(uint32, MLinkProcBlockResultType) {
    kMLinkProcBlockResultError = 0,
    kMLinkProcBlockResultSuccess,
    kMLinkProcBlockResultDoingAsync,
    kMLinkProcBlockResultCompleteAsync
};


typedef BOOL(^ProcessResultSetReturningBOOL)(OcResultValueList *);


typedef BOOL(^ProcessResultValueListReturningBool)(OcResultValueList *, id);
typedef BOOL(^ProcessResultValueReturningBool)(OcResultValue *, id);
typedef int(^ProcessVoidReturningInt)( void );
typedef id(^ProcessVoidReturningId)( void );

typedef OcResultValue*(^ProcessVoidReturningOcResultValue)( void );

//! Block passed to an async function, so that it can return values via resultSet and indicate completion type.
typedef BOOL(^ProcessFuncDefProcBlockReturningBOOL)( OcResultSet *resultSet, MLinkProcBlockResultType procResultType );

typedef MLinkProcBlockResultType(^ProcessFuncDefReturningResultType)( MLinkFuncDef *funcDef, OcResultSet *resultSet, ProcessFuncDefProcBlockReturningBOOL completionBlock );
//typedef MLinkProcBlockResultType(^ProcessFuncDefReturningResultType)( MLinkFuncDef *funcDef, OcResultSet *resultSet, (return_type (^)(var_type))blockName );
//typedef MLinkProcBlockResultType(^ProcessFuncDefReturningResultType)( MLinkFuncDef *funcDef, OcResultSet *resultSet, BOOL (^procBlock)( OcResultSet *resultSet, MLinkProcBlockResultType procResultType) );


//! Used to provide a little generic context, since ProcessFuncDefProcBlockReturningBOOL can't do it.
typedef void(^ContextObjectAsyncCompletionBlock)( id contextObject, BOOL isSuccess, OcResultSet *resultSet );


typedef BOOL(^OcNamedValueProviderBlock)( id );

typedef void (^OcDataReleaseBlock) ( void );

#ifndef __OC_RANGE__
#define __OC_RANGE__

typedef struct _OcRange {
    int start;
    int length;
} OcRange;


NS_INLINE OcRange OcMakeRange(int start, int length) {
    OcRange r;
    r.start = start;
    r.length = length;
    return r;
}

#endif