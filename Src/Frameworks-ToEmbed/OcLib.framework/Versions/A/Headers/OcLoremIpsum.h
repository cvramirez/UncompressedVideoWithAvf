//
//  OcLoremIpsum.h
//
//  Created by dav on 12/24/10.
//  Public domain where appropriate; free for everyone, for all usages, elsewhere.
//

#import <Foundation/Foundation.h>

@interface OcLoremIpsum : NSObject {
  NSArray* _words;
}

- (NSString*) words:(NSUInteger)count;

- (NSString *)sentences:(NSUInteger)count minWords:(NSUInteger)minWords maxWords:(NSUInteger)maxWords;

@end
