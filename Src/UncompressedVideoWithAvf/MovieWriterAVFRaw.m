//
//  MyClass.m
//  MovieCreationHarness
//
//  Created by Cesar V Ramirez on 9/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "MovieWriterAVFRaw.h"
#import "BitmapDiagnostics.h"

// check it dawg
#import <AVFoundation/AVAsset.h>
#import <AVFoundation/AVAssetTrack.h>
#import <AVFoundation/AVAssetReader.h>
#import <AVFoundation/AVAssetReaderOutput.h>
#import <AVFoundation/AVAssetWriter.h>
#import <AVFoundation/AVAssetWriterInput.h>
#import <AVFoundation/AVMediaFormat.h>
#import <AVFoundation/AVAudioSettings.h>
#import <AVFoundation/AVVideoSettings.h>
#import <AVFoundation/AVAssetImageGenerator.h>
#import <AVFoundation/AVTime.h>
#import <CoreMedia/CMSampleBuffer.h>
#import <QuartzCore/CATransaction.h>


#import <CoreVideo/CVPixelBuffer.h>
#import <CoreVideo/CVPixelBufferIOSurface.h>


@implementation MovieWriterAVFRaw

- (id)init
{
    self = [super init];
    if (self != nil) {
        // Initialization code here.
    }
    
    return self;
}



#pragma mark Diagnostic Hacks




- (BOOL)startReadingAndWritingReturningError:(NSError **)outError writer:(AVAssetWriter *)assetWriter
{
	BOOL success = YES;
	NSError *localError = nil;
    
	// Instruct the asset reader and asset writer to get ready to do work
    success = [assetWriter startWriting];
    if (!success) {
        localError = [assetWriter error];
	}
	
    /*
	if (success)
	{
		[assetWriter startSessionAtSourceTime:[self timeRange].start];
    }
    */
	
    
    BOOL finalSuccess = YES;
    NSError *finalError = nil;

    if (finalSuccess)
    {
        finalSuccess = [assetWriter finishWriting];
        if (!finalSuccess)
            finalError = [assetWriter error];
    }

    
    
	if (outError)
		*outError = localError;
	
	return success;
}


-(CMSampleBufferRef) copyNextSampleBuffer
{
    
    
}


//- (BOOL)setUpReaderAndWriterReturningError:(NSError **)outError
- (BOOL)writeSampleBufferRef:(CMSampleBufferRef)cmSampleBufferRef outputUrl:(NSURL *)localOutputURL returningError:(NSError **)outError
{
    
//    CMSampleBufferRef cmSampleBufferRefTester = [cmsamp
    
    
    
    
    
    AVAssetWriter				*assetWriter;
// ----------------------
    
    
    
    
	BOOL success = YES;
	NSError *localError = nil;
//	AVAsset *localAsset =     nil;//                 [self asset];
//	NSURL *localOutputURL = [self outputURL];
	
	// Create asset writer
    assetWriter = [[AVAssetWriter alloc] initWithURL:localOutputURL fileType:AVFileTypeQuickTimeMovie error:&localError];
    success = (assetWriter != nil);
	
    
	// Create asset writer inputs
    AVAssetWriterInput *assetWriterInput = nil;
	if (success)
	{
		AVAssetTrack *videoTrack = nil;
        
        // Create track dimensions for video settings
        CGSize trackDimensions = {
            .width = 32.0,
            .height = 4.0,
        };
        
        
        // Compress to H.264 with the asset writer
        NSMutableDictionary *videoSettings = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                                              AVVideoCodecH264, AVVideoCodecKey,
                                              [NSNumber numberWithDouble:trackDimensions.width], AVVideoWidthKey,
                                              [NSNumber numberWithDouble:trackDimensions.height], AVVideoHeightKey,
                                              nil];
        
        
        assetWriterInput = [AVAssetWriterInput assetWriterInputWithMediaType:[videoTrack mediaType] outputSettings:videoSettings];
        [assetWriter addInput:assetWriterInput];
        
		
	}
	
    
   
    int currFrame = 0;
    int totFrames = 1;
    
    BOOL completedOrFailed = NO;
    
    // Read samples in a loop as long as the asset writer input is ready
    while (currFrame < totFrames && !completedOrFailed)
    {
        CMSampleBufferRef sampleBuffer = cmSampleBufferRef;  // [self copyNextSampleBuffer];                        
        if (sampleBuffer != NULL)
        {
            //
            // CVR: this is an example of a "Push" source.
            // See WWDC11 Session 415 for an example of a "Pull" source, which basically 
            // appends immediately w/o the callback.
            //
            BOOL success = [assetWriterInput appendSampleBuffer:sampleBuffer];
            CFRelease(sampleBuffer);
            sampleBuffer = NULL;
            
            completedOrFailed = !success;
        }
        else
        {
            completedOrFailed = YES;
        }
    }
    
    
//    if (completedOrFailed)
  //      [self callCompletionHandlerIfNecessary];
    
    
    
    
	assetWriter = nil;

    
	if (outError)
		*outError = localError;
	
	return success;
}


//
// Sample from a forum posting.  2nd to last i.e. working post.  may or may not be 100%
// http://www.cocos2d-iphone.org/forum/topic/10178/page/2
//
-(void) saveScreenshotMovieWithSize:(CGSize)imageSize andFilePath:(NSString*)path {	
    
	int imageWidth = imageSize.width;
	int imageHeight = imageSize.height;
    
	int bitsPerComponent = 8;
	int bitsPerPixel = 32;
	int bytesPerPixel = bitsPerPixel / 8;
	int bytesPerRow = bytesPerPixel * imageWidth;
	NSInteger myDataLength	= bytesPerRow * imageHeight;
    
	GLubyte *buffer = malloc(sizeof(GLubyte)*myDataLength);
    
	//Read Pixels from OpenGL
//	glReadPixels(0, 0, imageWidth, imageHeight, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
    
    
    // draw it up buttercup,  ;)
    int numComponents = 4; // R G B & A
    int numRows = imageSize.height;
    int numCols = imageSize.width;
    int row, col;
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            GLubyte colorValue = col;
            /*
            buffer[(row*numCols) + (col*4) + 0] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 1] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 2] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 3] = (GLubyte)255; 
            */
            
            buffer[(row*numCols) + (col*4) + 0] = (GLubyte)128;            
            buffer[(row*numCols) + (col*4) + 1] = (GLubyte)255;
            buffer[(row*numCols) + (col*4) + 2] = (GLubyte)128;
            buffer[(row*numCols) + (col*4) + 3] = (GLubyte)128;
        }
    }

    
    NSDictionary *options = [NSDictionary dictionaryWithObjectsAndKeys:
                             [NSNumber numberWithBool:YES], kCVPixelBufferCGImageCompatibilityKey,
                             [NSNumber numberWithBool:YES], kCVPixelBufferCGBitmapContextCompatibilityKey, nil];

    
    
    CFDataRef imageDataRef = CFDataCreate(kCFAllocatorDefault, buffer, myDataLength);
    
    
    
	CVPixelBufferRef pixel_buffer = NULL;
//    CVReturn ret = CVPixelBufferCreateWithBytes(kCFAllocatorDefault, imageWidth, imageHeight, kCVPixelFormatType_32ARGB,
//                                                (void*)CFDataGetBytePtr(imageDataRef), bytesPerRow,
//                                                NULL, 0, (CFDictionaryRef)options, &pixel_buffer);
//    CVReturn ret = CVPixelBufferCreateWithBytes(kCFAllocatorDefault, imageWidth, imageHeight, kCVPixelFormatType_32ARGB,
//                                                buffer, bytesPerRow,
//                                                NULL, 0, NULL, &pixel_buffer);

    /*
    NSDictionary *options = [NSDictionary dictionaryWithObjectsAndKeys:
                             [NSNumber numberWithBool:YES], kCVPixelBufferCGImageCompatibilityKey,
                             [NSNumber numberWithBool:YES], kCVPixelBufferCGBitmapContextCompatibilityKey, nil];
*/
    CVReturn ret = CVPixelBufferCreate(kCFAllocatorDefault, imageWidth, imageHeight, kCVPixelFormatType_32ARGB, // helloNurse edit kCVPixelFormatType_32ARGB
                                       (__bridge CFDictionaryRef) options, &pixel_buffer);

    
    NSLog(@"CVReturn from CVPixelBufferCreateWithBytes = %d", ret);
    
    

    
    CVPixelBufferLockBaseAddress(pixel_buffer, 0);
    GLubyte *pxdata = CVPixelBufferGetBaseAddress(pixel_buffer);
    NSParameterAssert(pxdata != NULL);
    buffer = pxdata;
    
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            GLubyte colorValue = col;
            /*
             buffer[(row*numCols) + (col*4) + 0] = (GLubyte)colorValue;
             buffer[(row*numCols) + (col*4) + 1] = (GLubyte)colorValue;
             buffer[(row*numCols) + (col*4) + 2] = (GLubyte)colorValue;
             buffer[(row*numCols) + (col*4) + 3] = (GLubyte)255; 
             */
            
            buffer[(row*numCols) + (col*4) + 0] = (GLubyte)128;            
            buffer[(row*numCols) + (col*4) + 1] = (GLubyte)255;
            buffer[(row*numCols) + (col*4) + 2] = (GLubyte)128;
            buffer[(row*numCols) + (col*4) + 3] = (GLubyte)128;
        }
    }
    
    CVPixelBufferUnlockBaseAddress(pixel_buffer, 0);
    
    
    
    
    
    
    
    
    
    
    
    
	NSError *error = nil;
	AVAssetWriter *videoWriter = [[AVAssetWriter alloc] initWithURL:
                                  [NSURL fileURLWithPath:path] fileType:AVFileTypeQuickTimeMovie error:&error];
    
	NSParameterAssert(videoWriter);
    
	NSDictionary *videoSettings = [NSDictionary dictionaryWithObjectsAndKeys:
                                   AVVideoCodecH264, AVVideoCodecKey,
                                   [NSNumber numberWithInt:imageWidth], AVVideoWidthKey,
                                   [NSNumber numberWithInt:imageHeight], AVVideoHeightKey,
                                   nil];
    
	AVAssetWriterInput* writerInput = [AVAssetWriterInput
                                       assetWriterInputWithMediaType:AVMediaTypeVideo
                                       outputSettings:videoSettings];
    
	writerInput.expectsMediaDataInRealTime = YES;	
    
	NSParameterAssert(writerInput);
	NSParameterAssert([videoWriter canAddInput:writerInput]);
    
	[videoWriter addInput:writerInput];
    
    NSDictionary *sourcePixelBufferAttributesDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
                                                           [NSNumber numberWithInt:kCVPixelFormatType_32ARGB], kCVPixelBufferPixelFormatTypeKey, nil];

	AVAssetWriterInputPixelBufferAdaptor *adaptor = [AVAssetWriterInputPixelBufferAdaptor
                                                     assetWriterInputPixelBufferAdaptorWithAssetWriterInput:writerInput
                                                     sourcePixelBufferAttributes:sourcePixelBufferAttributesDictionary];
    NSParameterAssert(adaptor != NULL);
    
	//Start a session:
	[videoWriter startWriting];
	[videoWriter startSessionAtSourceTime:kCMTimeZero];
    
//	CVPixelBufferPoolRef bufferPool = adaptor.pixelBufferPool;
//	NSParameterAssert(bufferPool != NULL); //null until startWriting is called according to docs
    
	//CVPixelBufferRef pixie = NULL;
	//pixie = [self pixelBufferFromCGImage:[[array objectAtIndex:0] CGImage]];
	//[adaptor appendPixelBuffer:buffer withPresentationTime:kCMTimeZero];
	//NSLog(@"isAccessibilityElement = %d", sizeof(pixel_buffer));
    
//	CVPixelBufferPoolCreatePixelBuffer (NULL, adaptor.pixelBufferPool, &pixel_buffer);
    
// rem pool	[adaptor appendPixelBuffer:pixel_buffer withPresentationTime:kCMTimeZero];
    
    int iFrameNo;
    for(iFrameNo = 0; iFrameNo < 5; iFrameNo){
        if ([writerInput isReadyForMoreMediaData]) {
            BOOL didAppend = [adaptor appendPixelBuffer:pixel_buffer withPresentationTime:CMTimeMake(iFrameNo, 5)];        
            iFrameNo++;
        }
    }
    
    
    
	//Finish the session:
	[writerInput markAsFinished];
	[videoWriter finishWriting];	
    
//	CVPixelBufferPoolRelease(adaptor.pixelBufferPool);
    
	free(buffer);
}


/*
 
 put on hold to test capture code above
 
- (CGImageRef) createGradientCMSampleBufferWithImageSize:(CGSize)imageSize
{
    int numComponents = 4; // R G B & A
    int numRows = imageSize.height;
    int numCols = imageSize.width;
    
    // http://www.iphonedevsdk.com/forum/iphone-sdk-development/23525-cgimagecreate-alpha.html
    //
    GLubyte *buffer = (GLubyte *) malloc(imageSize.width * imageSize.height * numComponents);
    // buffer contains unsigned bytes 'width' X 'height' X 4 bytes per pixel
    
    // draw it up buttercup,  ;)
    int row, col;
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            GLubyte colorValue = col;
            buffer[(row*numCols) + (col*4) + 0] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 1] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 2] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 3] = (GLubyte)255;            
        }
    }
    
    
    // 
    CVPixelBufferRef cvPixelBuffer = CVPixelBufferCreateWithBytes(
    
    
    
    
    // make data provider from buffer
    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, buffer, (64 * 64 * 4), NULL);
    
    // set up for CGImage creation
    bool shouldInterpolate = NO;
    int bitsPerComponent = 8;
    int bitsPerPixel = 32;
    int bytesPerRow = numComponents * imageSize.width;
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    CGBitmapInfo bitmapInfo = kCGBitmapByteOrderDefault;
    CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;
    CGImageRef imageRef = CGImageCreate(imageSize.width, imageSize.height, bitsPerComponent, bitsPerPixel, bytesPerRow, 
                                        colorSpaceRef, bitmapInfo, provider, NULL, shouldInterpolate, renderingIntent);
    
    // test for alpha
    //    info = CGImageGetAlphaInfo(imageRef); // Note: Returns “kCGImageAlphaNone”
    
    
    return imageRef;
}
*/












- (NSBitmapImageRep *) createGradientNSBitmapImageRepWithRows:(int)numRows cols:(int)numCols
{
    
//    int numRows = 4;
//    int numCols = 32;
    int bitsPerComponent = 8;
    int MaxVals = pow(2, bitsPerComponent);
    
    NSBitmapImageRep *bitmap = [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:NULL
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                                                       pixelsWide:numCols
                                                                       pixelsHigh:numRows
                                                                    bitsPerSample:bitsPerComponent
                                                                  samplesPerPixel:4
                                                                         hasAlpha:YES
                                                                         isPlanar:NO
                                                                   colorSpaceName:NSCalibratedRGBColorSpace
                                                                     bitmapFormat:NSAlphaFirstBitmapFormat   //           NSAlphaNonpremultipliedBitmapFormat
                                                                      bytesPerRow:4*numCols
                                                                     bitsPerPixel:8*4
                                ];
    // create the image
    int row, col;
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            CGFloat colorValue = (CGFloat)(col + 1)/ MaxVals;
            NSColor *currColor = [NSColor colorWithCalibratedRed:(CGFloat)colorValue green:(CGFloat)colorValue blue:(CGFloat)colorValue alpha:(CGFloat)0.6];
            [bitmap setColor:currColor atX:col y:row];
        }
    }
    
    return bitmap;
}


- (CGImageRef) helloNurseWithRows:(int)numRows cols:(int)numCols
{
    int numComponents = 4; // R G B & A
//    int numRows = 4;
//    int numCols = 32;
    CGSize imageSize = CGSizeMake(numCols, numRows);

    // http://www.iphonedevsdk.com/forum/iphone-sdk-development/23525-cgimagecreate-alpha.html
    //
    GLubyte *buffer = (GLubyte *) malloc(imageSize.width * imageSize.height * numComponents);
    // buffer contains unsigned bytes 'width' X 'height' X 4 bytes per pixel
    
    // draw it up buttercup,  ;)
    int row, col;
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            GLubyte colorValue = col;
            buffer[(row*numCols) + (col*4) + 0] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 1] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 2] = (GLubyte)colorValue;
            buffer[(row*numCols) + (col*4) + 3] = (GLubyte)255;            
        }
    }

    
    // make data provider from buffer
    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, buffer, (64 * 64 * 4), NULL);
    
    // set up for CGImage creation
    bool shouldInterpolate = NO;
    int bitsPerComponent = 8;
    int bitsPerPixel = 32;
    int bytesPerRow = numComponents * imageSize.width;
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    CGBitmapInfo bitmapInfo = kCGBitmapByteOrderDefault;
    CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;
    CGImageRef imageRef = CGImageCreate(imageSize.width, imageSize.height, bitsPerComponent, bitsPerPixel, bytesPerRow, 
                                        colorSpaceRef, bitmapInfo, provider, NULL, shouldInterpolate, renderingIntent);
    
    // test for alpha
//    info = CGImageGetAlphaInfo(imageRef); // Note: Returns “kCGImageAlphaNone”
    

    return imageRef;
}



// ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== 
// ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== 
// begin 
// Here is the sample code link: git@github.com:RudyAramayo/AVAssetWriterInputPixelBufferAdaptorSample.git


void dataProviderFreeData(void *info, const void *data, size_t size);


// This function exists to free the malloced data when the CGDataProviderRef is
// eventually freed.
void dataProviderFreeData(void *info, const void *data, size_t size){
    free((void *)data);
}

// Returns an autoreleased CGImageRef.
- (CGImageRef) createGradientCGImageWithRows:(int)numRows cols:(int)numCols
{
    NSBitmapImageRep *bitmap = [self createGradientNSBitmapImageRepWithRows:numRows cols:numCols];

    return [bitmap CGImage];
    
/*

    CGImageRef newImage = NULL;
    
    // Read the pixels out of the framebuffer
    //void *data = malloc(numCols * numRows * 4);
    unsigned char * dataPointa = malloc(numCols * numRows * 4);//data;
    
    
    
    
    
    
    // create the image
    int row, col;
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            unsigned char colorValue = col;
            dataPointa[(row*numCols) + (col*4) + 0] = (unsigned char)255;//colorValue;
            dataPointa[(row*numCols) + (col*4) + 1] = (unsigned char)255;//colorValue;
            dataPointa[(row*numCols) + (col*4) + 2] = (unsigned char)255;//colorValue;
            dataPointa[(row*numCols) + (col*4) + 3] = (unsigned char)255;            
        }
    }

    
    
    
    
    
    
    
    // Convert the data to a CGImageRef. Note that CGDataProviderRef takes
    // ownership of our malloced data buffer, and the CGImageRef internally
    // retains the CGDataProviderRef. Hence the callback above, to free the data
    // buffer when the provider is finally released.
    CGDataProviderRef dataProvider = CGDataProviderCreateWithData(NULL, dataPointa, numCols * numRows * 4, dataProviderFreeData);
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    newImage = CGImageCreate(numCols, numRows, 8, 32, numCols*4, colorspace, kCGBitmapByteOrder32Big | kCGImageAlphaPremultipliedLast, dataProvider, NULL, true, kCGRenderingIntentDefault);
//    newImage = CGImageCreate(numCols, numRows, 8, 32, numCols*4, colorspace, kCGImageAlphaPremultipliedFirst, dataProvider, NULL, true, kCGRenderingIntentDefault);
    CFRelease(dataProvider);
    CGColorSpaceRelease(colorspace);
    
    // Autorelease the CGImageRef
    newImage = (CGImageRef)[NSMakeCollectable(newImage) autorelease];

        
    return newImage;
*/
}

// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 



- (CVPixelBufferRef )pixelBufferFromCGImage:(CGImageRef)image size:(CGSize)size
{
    NSDictionary *options = [NSDictionary dictionaryWithObjectsAndKeys:
                             [NSNumber numberWithBool:YES], kCVPixelBufferCGImageCompatibilityKey,
                             [NSNumber numberWithBool:YES], kCVPixelBufferCGBitmapContextCompatibilityKey, nil];
    CVPixelBufferRef pxbuffer = NULL;
    CVReturn status = CVPixelBufferCreate(kCFAllocatorDefault, size.width, size.height, kCVPixelFormatType_32ARGB /* helloNurse edit kCVPixelFormatType_32ARGB*/, (__bridge CFDictionaryRef) options, &pxbuffer);
    // CVReturn status = CVPixelBufferPoolCreatePixelBuffer(NULL, adaptor.pixelBufferPool, &pxbuffer);
    
    NSParameterAssert(status == kCVReturnSuccess && pxbuffer != NULL);
    
    CVPixelBufferLockBaseAddress(pxbuffer, 0);
    void *pxdata = CVPixelBufferGetBaseAddress(pxbuffer);
    NSParameterAssert(pxdata != NULL);
    
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
    CGBitmapInfo bitmapInfo = kCGImageAlphaPremultipliedFirst;  /* helloNurse edit kCGImageAlphaPremultipliedFirst, kCGBitmapByteOrderDefault */
    CGContextRef context = CGBitmapContextCreate(pxdata, size.width, size.height, 8, 4*size.width, rgbColorSpace, bitmapInfo);
    NSParameterAssert(context);
    
    CGContextDrawImage(context, CGRectMake(0, 0, CGImageGetWidth(image), CGImageGetHeight(image)), image);
    
    CGColorSpaceRelease(rgbColorSpace);
    CGContextRelease(context);
    
    CVPixelBufferUnlockBaseAddress(pxbuffer, 0);
    
    return pxbuffer;
}


-(int) randomColor
{
    return arc4random()%4;
    /*
     int min = 1;
     int max = 4;
     
     return (arc4random() % (max - 1)) + min;
     */
}

-(int) randomDirection
{
    int direction = arc4random()%2;
    if (direction==1) {
        return 1;
    }
    else {
        return -1;
    }
}


- (void )createRandomRampsIntoDataBuffer:(GLubyte **)dataBuffer WithSize:(CGSize)size numComponents:(int)numComponents numFrames:(int)numFrames
{    
    *dataBuffer = (GLubyte *) malloc(numFrames * size.width * size.height * numComponents);
    // buffer contains unsigned bytes 'width' X 'height' X 4 bytes per pixel
    
    // draw it up buttercup,  ;)
    int numRows = size.height;
    int numCols = size.width;
    int frame, row, col;  
    GLubyte *buffer = *dataBuffer;
    for (frame = 0; frame < numFrames; frame++) {        
        
        int colorToDo = [self randomColor]; 
        int direction = [self randomDirection];
        NSLog(@"color = %d, direction = %d\n", colorToDo, direction);

        for (row = 0; row < numRows; row++) {
            
            for (col = 0; col < numCols; col++) {
                GLubyte redColorValue = (GLubyte)0;
                GLubyte greenColorValue = (GLubyte)0;
                GLubyte blueColorValue = (GLubyte)0;
                
                GLubyte colorValue = (GLubyte)((direction * col) % 256);//(col>128)? 0: 255;
                
                if (colorToDo == 0 || colorToDo == 3) {
                    redColorValue = colorValue;
                }
                if (colorToDo == 1 || colorToDo == 3) {
                    greenColorValue = colorValue;
                }
                if (colorToDo == 2 || colorToDo == 3) {
                    blueColorValue = colorValue;
                }
                
                int frameOffset = frame * (numRows * numCols * numComponents);
                int rowOffset = row * (numCols * numComponents);
                int colOffset = col * (numComponents);
                int pixelOffset = frameOffset + rowOffset + colOffset;
                
                
                if (numComponents==1) {
                    buffer[pixelOffset + 0] = colorValue;
                }
                else if (numComponents==3) {
                    buffer[pixelOffset + 0] = redColorValue;
                    buffer[pixelOffset + 1] = greenColorValue;
                    buffer[pixelOffset + 2] = blueColorValue;
                }
                else if (numComponents==4) {
                    buffer[pixelOffset + 0] = (GLubyte)0;
                    buffer[pixelOffset + 1] = redColorValue;
                    buffer[pixelOffset + 2] = greenColorValue;
                    buffer[pixelOffset + 3] = blueColorValue;
                }
            }
        }
    }
}


-(CGImageRef)grabCGImageRefWithFilename:(NSString *)fileName
{
    NSImage *pImage = [[NSImage alloc] initWithContentsOfFile:fileName];
    
    if( pImage )
    {
        NSBitmapImageRep *pImageRep = [[NSBitmapImageRep alloc] initWithData:[pImage TIFFRepresentation]];
        
        if( pImageRep )
        {
            CGImageRef pImageRef = [pImageRep CGImage];
            return pImageRef;
        }  
    }
    return NULL;
}



- (void) testCreatingMovieOfGradientCGImageWithFileName:(NSString *)fileName imageSize:(CGSize)imageSize numComponents:(int)numComponents
{
    NSError *error = nil;
    
    unlink([fileName UTF8String]);
    
    //----initialize compression engine
    AVAssetWriter *videoWriter = [[AVAssetWriter alloc] initWithURL:[NSURL fileURLWithPath:fileName]
                                                           fileType:AVFileTypeQuickTimeMovie
                                                              error:&error];
    NSParameterAssert(videoWriter);
    if(error)
        NSLog(@"error = %@", [error localizedDescription]);
    
//    NSDictionary *videoSettings = [NSDictionary dictionaryWithObjectsAndKeys:AVVideoCodecH264, AVVideoCodecKey,
//                                   [NSNumber numberWithInt:imageSize.width], AVVideoWidthKey,
//                                   [NSNumber numberWithInt:imageSize.height], AVVideoHeightKey, nil];
    NSDictionary *videoSettings = [NSDictionary dictionaryWithObjectsAndKeys:[NSNumber numberWithInt:kCVPixelFormatType_32ARGB], kCVPixelBufferPixelFormatTypeKey,
                                   [NSNumber numberWithInt:imageSize.width], kCVPixelBufferWidthKey,
                                   [NSNumber numberWithInt:imageSize.height], kCVPixelBufferHeightKey, nil];
    
    
//    AVAssetWriterInput *writerInput = [AVAssetWriterInput assetWriterInputWithMediaType:AVMediaTypeVideo outputSettings:videoSettings];
    AVAssetWriterInput *writerInput = [AVAssetWriterInput assetWriterInputWithMediaType:AVMediaTypeVideo outputSettings:nil];
    
    NSDictionary *sourcePixelBufferAttributesDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
                                                          [NSNumber numberWithInt:kCVPixelFormatType_32ARGB], kCVPixelBufferPixelFormatTypeKey, nil];
    
//    AVAssetWriterInputPixelBufferAdaptor *adaptor = [AVAssetWriterInputPixelBufferAdaptor assetWriterInputPixelBufferAdaptorWithAssetWriterInput:writerInput
//                                                                                                                     sourcePixelBufferAttributes:sourcePixelBufferAttributesDictionary];
// using nil cuz not using pool.  use pool later when working...
    AVAssetWriterInputPixelBufferAdaptor *adaptor = [AVAssetWriterInputPixelBufferAdaptor assetWriterInputPixelBufferAdaptorWithAssetWriterInput:writerInput
                                                                                                                     sourcePixelBufferAttributes:nil];
    NSParameterAssert(writerInput);
    NSParameterAssert([videoWriter canAddInput:writerInput]);
    
    if ([videoWriter canAddInput:writerInput])
        NSLog(@"I can add this input");
    else
        NSLog(@"i can't add this input");
    
    [videoWriter addInput:writerInput];
    
    [videoWriter startWriting];
    [videoWriter startSessionAtSourceTime:kCMTimeZero];
    
    
    
    //---
    
    /* no queuing
    
    dispatch_queue_t dispatchQueue = dispatch_queue_create("mediaInputQueue", NULL);
    int __block frame = 0;
    
    [writerInput requestMediaDataWhenReadyOnQueue:dispatchQueue usingBlock:^{
        while ([writerInput isReadyForMoreMediaData])
        {
            if(++frame >= 5)
            {
                [writerInput markAsFinished];
                [videoWriter finishWriting];
                [videoWriter release];
                break;
            }
            
            CVPixelBufferRef buffer = (CVPixelBufferRef)[self pixelBufferFromCGImage:theImage size:imageSize];
            if (buffer)
            {
                if(![adaptor appendPixelBuffer:buffer withPresentationTime:CMTimeMake(frame, 20)])
                    NSLog(@"FAIL");
                else
                    NSLog(@"Success:%d", frame);
                CFRelease(buffer);
            }
        }
    }];
     
     */
    
    // kCVPixelFormatType_8IndexedGray_WhiteIsZero, kCVPixelFormatType_32ARGB, kCVPixelFormatType_24RGB
    OSType pixelFormatType;
    switch (numComponents) {
        case 1:
            pixelFormatType = kCVPixelFormatType_8IndexedGray_WhiteIsZero;
            break;
        case 3:
            pixelFormatType = kCVPixelFormatType_24RGB;
            break;

        case 4:
            pixelFormatType = kCVPixelFormatType_32ARGB;
            break;

        default:  // cvr*err  cvr*crit
            NSLog(@"Holy crap!! number components per pixel = %d, EXITING!!!", numComponents);
            exit(0);
            break;
    }
    
    
    int totFrames = 30;
    GLubyte *pointa;
    [self createRandomRampsIntoDataBuffer:&pointa WithSize:imageSize numComponents:numComponents numFrames:totFrames];
    
    int bytesPerFrame = (int)imageSize.width * (int)imageSize.height * numComponents;
    int frame = 0;
    while (frame < totFrames)
    {
        if ([writerInput isReadyForMoreMediaData]) {
            GLubyte *ptrToCurrFrame = &pointa[frame * bytesPerFrame];
            CVPixelBufferRef buffer = (CVPixelBufferRef)[self pixelBufferWithSize:imageSize frameData:ptrToCurrFrame 
                                                                    numComponents:numComponents pixelFormatType:pixelFormatType];
            
            if (buffer)
            {
                
                if(![adaptor appendPixelBuffer:buffer withPresentationTime:CMTimeMake(frame, 5)])
                    NSLog(@"FAIL");
                else
                    NSLog(@"Success:%d", frame);
                CFRelease(buffer);

                frame++;
                
                [NSThread sleepForTimeInterval:0.2];
            }
        }
    }

    [NSThread sleepForTimeInterval:0.5];
    [writerInput markAsFinished];
    [videoWriter finishWriting];
    NSLog(@"did finish writing");

    
    /*  SAVE
    while ([writerInput isReadyForMoreMediaData])
    {
        if(++frame >= 20)
        {
            [writerInput markAsFinished];
            [videoWriter finishWriting];
            [videoWriter release];
            NSLog(@"did finish writing");
            
            break;
        }
        
        CVPixelBufferRef buffer = (CVPixelBufferRef)[self pixelBufferFromCGImage:theImage size:imageSize];
        if (buffer)
        {
            if(![adaptor appendPixelBuffer:buffer withPresentationTime:CMTimeMake(frame, 20)])
                NSLog(@"FAIL");
            else
                NSLog(@"Success:%d", frame);
            CFRelease(buffer);
        }
    }
     */


    
    NSLog(@"outside for loop");
    
}


// kCVPixelFormatType_8IndexedGray_WhiteIsZero, kCVPixelFormatType_32ARGB, kCVPixelFormatType_24RGB
- (CVPixelBufferRef )pixelBufferWithSize:(CGSize)size frameData:(GLubyte *)dataBuffer numComponents:(int)numComponents pixelFormatType:(OSType)pixelFormatType
{

    NSDictionary *options = [NSDictionary dictionaryWithObjectsAndKeys:
            [NSNumber numberWithBool:YES], kCVPixelBufferCGImageCompatibilityKey,
            [NSNumber numberWithBool:YES], kCVPixelBufferCGBitmapContextCompatibilityKey,
            [NSDictionary dictionary], kCVPixelBufferIOSurfacePropertiesKey,
                    nil];
    CVPixelBufferRef pxbuffer = NULL;
//    CVReturn ret = CVPixelBufferCreate(kCFAllocatorDefault, size.width, size.height, kCVPixelFormatType_32ARGB /* helloNurse edit kCVPixelFormatType_32ARGB*/, (CFDictionaryRef) options, &pxbuffer);


//    CFDataRef imageDataRef = CFDataCreate(kCFAllocatorDefault, buffer, myDataLength);

//    int bytesPerRow = numComponents * size.width;

//    CVReturn ret = CVPixelBufferCreateWithBytes(kCFAllocatorDefault, size.width, size.height, kCVPixelFormatType_32ARGB,
//                                                (void*)dataBuffer, bytesPerRow, // (void*)CFDataGetBytePtr(imageDataRef), bytesPerRow,
//                                                NULL, 0, (CFDictionaryRef)options, &pxbuffer);




    CVReturn ret = CVPixelBufferCreate(kCFAllocatorDefault, size.width, size.height, pixelFormatType,
            (__bridge CFDictionaryRef)options, &pxbuffer);

    IOSurfaceRef ioSurfaceRef = CVPixelBufferGetIOSurface(pxbuffer);
    NSLog(@"IOSurfaceRef = %@", ioSurfaceRef);

    char *ioSurfaceBaseAddy = IOSurfaceGetBaseAddress(ioSurfaceRef);
    memcpy(ioSurfaceBaseAddy, dataBuffer, size.width * size.height * numComponents);



    NSParameterAssert(ret == kCVReturnSuccess && pxbuffer != NULL);

    return pxbuffer;
}




// end 
// Here is the sample code link: git@github.com:RudyAramayo/AVAssetWriterInputPixelBufferAdaptorSample.git
// ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== 
// ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== 













//    NSString* movieName = [NSString stringWithFormat:@"%dRow%dColGradient", numRows, numCols];

-(void) createGradientTestMoviesWith:(NSString *)movieName numComponents:(int)numComponents
{
    int numRows = 50;
    int numCols = 256;
    CGSize imageSize = CGSizeMake(numCols, numRows);
    NSLog(@"movieName = %@\n", movieName);
    
    [self testCreatingMovieOfGradientCGImageWithFileName:movieName imageSize:imageSize numComponents:numComponents];
    
/*    
    // do diagnostic printout
    //
    fileName = GenerateFilenameForMovieDiagnosticsWithTypeAndDateTimeStamp(movieName, @"TextureRef", @"txt");
    NSLog(@"fileName = %@\n", fileName);
    BitmapDiagnostics *bitmapDiagnostic = [[BitmapDiagnostics alloc] initWithNSBitmapImageRep:bitmap error:nil];
    [bitmapDiagnostic writeToTexfile:fileName];

    NSLog(@"bitmap = %ld\n", (long)bitmap);
    //[bitmap release];
*/
}


@end
