/*! AVFoundationUtils
 *
 * Created by Cesar V. Ramirez on 12/18/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <OcLib/OcLib.h>
#import <AVFoundation/AVFoundation.h>


@interface AVFoundationUtils : OcBaseNoInit

+ (NSString *)nameFromAVAssetReaderStatus:(AVAssetReaderStatus)status;
@end
