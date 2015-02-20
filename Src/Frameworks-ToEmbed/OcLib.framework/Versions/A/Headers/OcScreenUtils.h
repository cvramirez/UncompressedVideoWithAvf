//
//  ScreenUtils.h
//  QTKitPlayerExtras
//
//  Created by Cesar V Ramirez on 9/26/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class OcResultSet;


@interface OcScreenUtils : NSObject

+ (BOOL)screenFrameByIndex:(uint)screenIndex intoNSRect:(NSRect *)rectPtr resultSet:(OcResultSet *)resultSet;
+ (BOOL)screenFrameByIndex:(uint)screenIndex intoRect:(Rect *)rectPtr resultSet:(OcResultSet *)resultSet;
+ (BOOL)getScreenIndex:(int *)screenIndexPtr forScreen:(NSScreen *)theScreen resultSet:(OcResultSet *)resultSet;




+ (BOOL)screenFrameByIndex:(int)screenNumber intoNSRect:(NSRect *)rectPtr error:(NSError **)outError;
+ (BOOL)screenFrameByIndex:(int)screenIndex intoRect:(Rect *)rectPtr error:(NSError **)outError;
+ (BOOL)getScreenIndex:(int *)screenIndexPtr forScreen:(NSScreen *)theScreen error:(NSError **)outError;


+ (BOOL)getScreen:(NSScreen **)screenPtr withIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;

+ (BOOL)getScreenRefreshRate:(double *)refreshRatePtr withScreenIndex:(int)screenIndex error:(NSError **)outError;

+ (uint)getScreenCount;

+ (BOOL)getLocalPoint:(NSPoint *)localPointPtr inScreenWithIndex:(uint)screenIndex fromGlobalPoint:(NSPoint)globalPoint resultSet:(OcResultSet *)resultSet;

+ (BOOL)getGlobalPoint:(NSPoint *)globalPointPtr fromLocalPoint:(NSPoint)localPoint inScreenWithIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;

+ (BOOL)getLocalRect:(NSRect *)localRectPtr inScreenWithIndex:(uint)screenIndex fromGlobalRect:(NSRect)globalRect resultSet:(OcResultSet *)resultSet;

+ (BOOL)getGlobalRect:(NSRect *)globalRectPtr fromLocalRect:(NSRect)localRect inScreenWithIndex:(uint)screenIndex resultSet:(OcResultSet *)resultSet;

+ (int)getMaxScreenIndex;
@end
