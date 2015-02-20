/*! OcWindowSizeHelper
 *
 * Created by Cesar V. Ramirez on 8/5/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <Foundation/Foundation.h>
#import "OcBaseNoInit.h"

@class OcResultSet;


@interface OcWindowSizeHelper : OcBaseNoInit
@property (nonatomic, readonly, assign) NSRect windowFrame;
@property (nonatomic, readonly, assign) NSRect localRect;
@property (nonatomic, readonly, assign) uint screenIndex;
@property (nonatomic, readonly, assign) BOOL isFullscreen;


+ (instancetype)newWithFrame:(NSRect)windowFrame resultSet:(OcResultSet *)resultSet;
+ (instancetype)newFullscreenWithScreenIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;
+ (instancetype)newCenteredWithScreenIndex:(uint)screenIndex size:(NSSize)desiredWindowSize resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithScreenIndex:(uint)screenIndex rectInLocalCoordinates:(NSRect)rectInLocalCoordinates resultSet:(OcResultSet *)resultSet;
+ (instancetype)newWithScreenIndex:(uint)screenIndex topLeftPoint:(NSPoint)topLeftPoint size:(NSSize)desiredSize resultSet:(OcResultSet *)resultSet;


#pragma mark :----- Frame properties :-----
- (NSRect)frame;
- (NSSize)frameSize;
- (NSPoint)frameOrigin;
- (NSPoint)frameTopLeftPoint;


#pragma mark :----- Frame methods :-----
- (BOOL)setFrameFullscreenWithResultSet:(OcResultSet *)resultSet;
- (BOOL)setFrameFullscreenWithScreenIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;
- (BOOL)setFrameCenteredWithResultSet:(OcResultSet *)resultSet;
- (BOOL)setFrameCenteredWithSize:(NSSize)windowSize resultSet:(OcResultSet *)resultSet;
- (BOOL)setFrameCenteredWithScreenIndex:(uint)screenIndex size:(NSSize)windowSize resultSet:(OcResultSet *)resultSet;


@end
