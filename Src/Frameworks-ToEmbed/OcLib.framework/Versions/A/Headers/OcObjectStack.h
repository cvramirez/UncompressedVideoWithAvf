/*! ObjectStack
 *
 * Created by Cesar V. Ramirez on 9/19/13.
 * Copyright (c) 2013 Cesar V. Ramirez. All rights reserved.
 *
 */


#import <Foundation/Foundation.h>


@interface OcObjectStack : NSObject <NSFastEnumeration> {
    @private
    NSMutableArray* _objects;
}

- (id)initWithArray:(NSArray*)array;

@property (nonatomic, assign, readonly) NSUInteger count;
- (void)pushObject:(id)object;
- (void)pushObjects:(NSArray*)objects;
- (id)popObject;
- (id)peekObject;

@end