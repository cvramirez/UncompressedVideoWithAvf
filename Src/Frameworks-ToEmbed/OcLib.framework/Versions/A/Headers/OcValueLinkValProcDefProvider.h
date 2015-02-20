/*! OcValProcDefScanner
 *
 * Created by Cesar V. Ramirez on 6/19/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <OcLib/OcLib.h>


@interface OcValueLinkValProcDefProvider : OcBaseNoInit

+ (instancetype)newWithAutoScanning:(BOOL)shouldAutoScan;

@property (nonatomic, readonly, strong) NSArray *classes;
@property (nonatomic, readonly, assign) BOOL isAutoScanningEnabled;
@end