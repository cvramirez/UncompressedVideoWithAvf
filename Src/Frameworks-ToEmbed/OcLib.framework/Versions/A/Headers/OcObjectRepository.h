/*! OcObjectRepository
 *
 * Created by Cesar V. Ramirez on 4/9/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */


#import <Foundation/Foundation.h>
#import <OcLib/OcLib.h>

@class OcResultSet;


@interface OcObjectRepository : OcBaseNoInit

+ (instancetype)newWithObjectName:(NSString *)objectName;
@property(nonatomic, readonly, strong) NSMutableDictionary *rawDictionary;


@property(nonatomic, readonly, strong) NSString* objectName;
@property(nonatomic, readonly, strong) NSString* templateForObjectWithKeyNotFoundErrorMsg;
@property(nonatomic, readonly, strong) NSString* templateForObjectAtIndexNotFoundErrorMsg;
@property(nonatomic, readonly, strong) NSString* templateForObjectWithKeyAlreadyExistsErrorMsg;
//@property(nonatomic, readonly, strong) NSString* templateForObjectWithKeyRemovedMsg;
//@property(nonatomic, readonly, strong) NSString* templateForAllObjectsRemovedMsg;


- (BOOL)addObject:(id)object withKey:(id)key resultSet:(OcResultSet *)resultSet;
- (BOOL)getObject:(id *)object withKey:(id)key resultSet:(OcResultSet *)resultSet;
- (BOOL)getObject:(id *)object atIndex:(NSUInteger)index resultSet:(OcResultSet *)resultSet;

//- (BOOL)getObject:(id *)object atIndex:(NSUInteger)index resultSet:(OcResultSet *)resultSet;
//- (BOOL)getAndRemoveObject:(id *)object withKey:(id)key resultSet:(OcResultSet *)resultSet;
//- (BOOL)getAndRemoveObject:(id *)object atIndex:(NSUInteger)index resultSet:(OcResultSet *)resultSet;
- (BOOL)removeObjectWithKey:(id)key resultSet:(OcResultSet *)resultSet;
- (void)removeAllObjects:(OcResultSet *)resultSet;
- (BOOL)hasObjectWithKey:(id)key;
- (int)numObjects;

@end