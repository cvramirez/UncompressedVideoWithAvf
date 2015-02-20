/*! OcObjectQueueDictionary
 *
 * Created by Cesar V. Ramirez on 9/14/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */


#import <Foundation/Foundation.h>
#import "OcBaseNoInit.h"

@class OcObjectQueue;


@interface OcObjectQueueDictionary : OcBaseNoInit

+ (OcObjectQueueDictionary *)instance;
- (OcObjectQueue *)getQueue:(NSString *)queueName;
- (void)enqueueTo:(NSString *)queueName theObject:(id)object;
- (id)dequeueFrom:(NSString *)queueName;

- (id)peekFrom:(NSString *)queueName;

- (BOOL)isEmptyQueued:(NSString *)queueName;

- (BOOL)ensureQueueCleared:(NSString *)queueName;
- (BOOL)ensureAllCleared;

- (BOOL)ensureAllClearedOrPeekedOut;
@end