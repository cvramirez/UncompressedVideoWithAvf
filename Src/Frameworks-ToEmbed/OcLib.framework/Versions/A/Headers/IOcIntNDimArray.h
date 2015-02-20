/*! IRtoIntegerArray
 *
 * Created by Cesar V. Ramirez on 9/11/13.
 * Copyright (c) 2013 Cesar V. Ramirez. All rights reserved.
 *
 */


#import <Foundation/Foundation.h>

@protocol IOcIntNDimArray <NSObject>

@property (nonatomic, readonly, assign) int *data;
@property (nonatomic, readonly, assign) long *numValuesInDims;
@property (nonatomic, readonly, assign) char **dimCNames;
@property (nonatomic, readonly, assign) long numDims;
@property (nonatomic, readonly, assign) long numValuesTotal;
@end

typedef NSObject<IOcIntNDimArray> IRtoIntegerArray;