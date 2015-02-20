/*! STAssetUtils
 *
 * Created by Cesar V. Ramirez on 7/24/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <AVFoundation/AVFoundation.h>
@class OcResultSet;


@interface STAVAssetHelper : NSObject

+ (instancetype)newWithUrl:(NSURL *)movieUrl resultSet:(OcResultSet *)resultSet;
@property (atomic, readonly, strong) AVURLAsset *asset;

@end

