//
//  STRectUtils.h
//  ShowtimeX
//
//  Created by Cesar V Ramirez on 10/3/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "RtoConstants.h"

@class OcResultSet;


#ifndef _ResizePinLocation_
#define _ResizePinLocation_

typedef enum {
    PinnedTopLeft           = 1,
    PinnedTop,
    PinnedTopRight,
    PinnedLeft,
    PinnedCenter,
    PinnedRight,
    PinnedBottomRight,
    PinnedBottom,
    PinnedBottomLeft
} ResizePinLocation;

#endif


@interface OcRectUtils : NSObject

Rect convertToTruncatedRectFromNSRect(NSRect theNSRect, NSRect parentNSRect);



+(NSRect) centerRect: (NSRect) smallRect inRect: (NSRect) bigRect;


+(NSRect) getCenteredRectWithSize:(NSSize)innerRectSize inRect:(NSRect)containerRect;
+(NSRect) getCenteredRectWithSize:(NSSize)innerRectSize inSize:(NSSize)containerRectSize;


+(NSRect) convertToNSRectFromRect:(Rect)theRect;
+(NSRect) convertToNSRectFromRect:(Rect)theRect withinParentNSRect:(NSRect)theParent;


+(BOOL) isNSRectEmpty:(NSRect)theRect;
+(NSRect) emptyNSRect;


+(NSRect) makeOriginRectWithRect:(NSRect)theRect;
+(NSPoint) makeOriginWithTopLeftPoint:(NSPoint)topLeftPoint rectSize:(NSSize)rectSize;


+(NSRect) makeRectWithTopLeftPoint:(NSPoint)topLeftPoint size:(NSSize)desiredSize andParentRectSize:(NSSize)parentFrameSize;


+(NSRect) makeScreenCoordsRectWithTopLeftPoint:(NSPoint)topLeftPoint size:(NSSize)desiredSize andParentRect:(NSRect)parentFrame;
+(NSRect) makeScreenCoordsRectWithOrigin:(NSPoint)desiredOrigin size:(NSSize)desiredSize andParentRect:(NSRect)parentFrame;


+ (NSPoint) getTopLeftPointWithRect:(NSRect)theRect;
+ (NSPoint) getLeftTopPointWithWindow:(NSWindow *)theWindow;


+(BOOL) getScaledSize:(NSSize *)newSizePtr withSize:(NSSize)currSize widthScale:(float)widthScale heightScale:(CGFloat)heightScale
			  maxSize:(NSSize)maxSize error:(NSError **)outError;


+ (BOOL)getScaledSize:(NSSize *)newSizePtr withSize:(NSSize)currSize widthScale:(float)widthScale heightScale:(CGFloat)heightScale maxSize:(NSSize)maxSize1 resultSet:(OcResultSet *)resultSet;

+(NSRect) getRectWithCurrentRect:(NSRect)currRect desiredSize:(NSSize)desiredSize resizePinPosition:(ResizePinLocation)pinPosition;

+ (NSRect)getTlcRectWithCurrentTlcRect:(NSRect)currRect desiredSize:(NSSize)desiredSize resizePinPosition:(ResizePinLocation)pinPosition;

+ (void)legacySetRect:(Rect *)rectPtr left:(short)left top:(short)top right:(short)right bottom:(short)bottom;


+ (NSRect)getRectWithinParentRect:(NSRect)parentRect desiredSize:(NSSize)desiredSize position:(OcRectLocationType)location;

+ (NSRect)getRectWithCurrentRect:(NSRect)currRect desiredSize:(NSSize)desiredSize position:(OcRectLocationType)location;
@end
