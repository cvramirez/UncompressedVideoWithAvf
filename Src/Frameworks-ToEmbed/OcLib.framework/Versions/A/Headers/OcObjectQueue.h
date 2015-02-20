#import <Foundation/Foundation.h>

// https://github.com/dominikkrejcik/Objective-C-Stack---Queue/blob/master/DKQueue.h

@interface OcObjectQueue : NSObject

- (void)enqueue:(id)element;
- (void)enqueueElementsFromArray:(NSArray*)arr;
- (void)enqueueElementsFromQueue:(OcObjectQueue*)queue;

- (id)dequeue;
- (id)peek;
- (void)clear;

- (BOOL)isEmpty;

- (BOOL)isEmptyOrPeekedOut;

- (NSInteger)numObjects;
@end
