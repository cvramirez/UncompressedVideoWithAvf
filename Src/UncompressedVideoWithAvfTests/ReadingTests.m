#import <OcLib/OcLib.h>//
//  ReadingTests
//
//  Created by Cesar V. Ramirez on 2/17/15.
//  Copyright (c) 2015 Watson Lab. All rights reserved.
//
#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <OcLib/OcLib.h>
#import "STMovieDataReader.h"

@interface ReadingTests : XCTestCase
@property (nonatomic, readonly,  strong) NSURL *movieUrl;
@property (nonatomic, readonly,  strong) OcResultSet *resultSet;
@end


@implementation ReadingTests

- (void)setUp {
    [super setUp];
    _movieUrl = [NSURL fileURLWithPath:@"/Users/cvramirez/Movies/SupaDupa.mov" isDirectory:NO];
    //_movieUrl = [NSURL fileURLWithPath:@"/Users/cvramirez/Movies/AnimatedColorGradient.mov" isDirectory:NO];
    _resultSet = [OcResultSet new];
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {

    STMovieDataReader *dataReader = [STMovieDataReader newWithUrl:self.movieUrl resultSet:self.resultSet];
    XCTAssertNotNil(dataReader, @"Poop, init problem!\n%@", self.resultSet.codeList.debugDescription);

    XCTAssert(dataReader.videoDimensions.width == 256, @"Wrong width!");
    XCTAssert(dataReader.videoDimensions.height == 4, @"Wrong height!");
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
