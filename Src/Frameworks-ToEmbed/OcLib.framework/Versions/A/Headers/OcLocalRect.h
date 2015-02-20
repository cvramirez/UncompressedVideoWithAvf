/*! OcRect
 *
 * Created by Cesar V. Ramirez on 4/11/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import "OcBaseNoInit.h"
#import "OcRectUtils.h"
#import "RtoConstants.h"
@class OcResultSet;

#ifndef _OcRectOriginLocation_
#define _OcRectOriginLocation_
typedef NS_ENUM(int, OcRectOriginLocation) {
    kOcRectOriginTopLeft = 0,
    kOcRectOriginBottomLeft = 1
};
#endif


@interface OcLocalRect : OcBaseNoInit

+ (instancetype)newWithTopLeftCornerRect:(NSRect)tlcRect parentScreenIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithTopLeftCornerRect:(NSRect)tlcRect parentGlobalRect:(NSRect)parentGlobalRect parentScreenIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithRect:(NSRect)rect parentScreenIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithRect:(NSRect)rect parentGlobalRect:(NSRect)parentGlobalRect resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithSize:(NSSize)size parentScreenIndex:(uint)screenIndex location:(OcRectLocationType)location resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithSize:(NSSize)size parentGlobalRect:(NSRect)parentGlobalRect location:(OcRectLocationType)location resultSet:(OcResultSet *)resultSet;
+ (instancetype)newFullscreenWithParentScreenIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;
+ (instancetype)newFullscreenWithParentGlobalRect:(NSRect)parentGlobalRect resultSet:(OcResultSet *)resultSet;


//@property(weak, nonatomic, readonly) OcLocalRect* parent;
//@property(nonatomic, readonly) OcRectOriginLocation originLocation;

@property (nonatomic, readonly,  assign) uint screenIndex;
@property (nonatomic, readonly,  assign) OcRectLocationType location;


@property(nonatomic, readonly,  assign) NSSize size;

@property(nonatomic, readonly,  assign) NSRect localRect;
@property(nonatomic, readonly,  assign) NSRect localTlcRect;


- (NSPoint)localTopLeftPoint;
- (NSPoint)localBottomLeftPoint;


@property(nonatomic, readonly,  assign) NSRect globalRect;
@property(nonatomic, readonly,  assign) NSRect globalTlcRect;
- (NSPoint)globalTopLeftPoint;
- (NSPoint)globalBottomLeftPoint;
@end
