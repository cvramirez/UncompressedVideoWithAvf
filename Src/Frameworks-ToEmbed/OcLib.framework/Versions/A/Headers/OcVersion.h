/*! @class OcVersion
 
 To use [OcVersion newWithVersionInfoFromMainBundlePlist],
   (1) in Build Phases for the selected Target, add a new Run Script
   (2) copy the script below
   (3) ensure fields described in the scripts instructions are in the <YourApplicationName>-Info.plist file
 
 
== == == == == Script BEGINS right BELOW here == == == == ==
 
 
 #!/bin/sh
 
 #  Script.sh
 #  Created by Cesar V. Ramirez on 1/17/14.
 #
 #  To use, ensure there are the following in the application {ApplicationName}-Info.plist file:
 #  (1) CFBundleVersion, if you have something called "Bundle Version" in the list, you are good.  Should be there by default.
 #  (2) add CFBundleVersionMajorMinorBaseForComposition, should be a string, something like this 1.0 to start with.
 #      It's basically "Major.Minor" and the script will append Build to make it something like 1.0.XXX, incrementing build.
 #  (3) add CFBuildDate, should be a string, leave blank, script will timestamp on each build.
 #
 
 # Get infoPlist.
 infoPlist=${PROJECT_DIR}/${INFOPLIST_FILE}
 # Add CFBuildNumber, CFBuildDate, CFBundleShortVersionString (if it doesn't exist) and CFBuildVersion to your <YourApplicationName>-Info.plist.
 
 # Get CFBuildNumber. Increment build number by 1. & update
 buildNumber=$(/usr/libexec/PlistBuddy -c "Print CFBundleVersion" $infoPlist)
 buildNumber=$(($buildNumber + 1))
 /usr/libexec/PlistBuddy -c "Set :CFBundleVersion $buildNumber" $infoPlist
 
 # Get & update BuildDate.
 buildDate=$(date)
 /usr/libexec/PlistBuddy -c "Set :CFBuildDate $buildDate" $infoPlist
 
 # Get CFBundleShortVersionString.
 majorMinorBaseString=$(/usr/libexec/PlistBuddy -c "Print CFBundleVersionMajorMinorBaseForComposition" $infoPlist)
 # Update CFBuildVersion version with CFBundleShortVersionString.CFBuildNumber.
 /usr/libexec/PlistBuddy -c "Set :CFBundleShortVersionString $majorMinorBaseString.$buildNumber" $infoPlist
 

 
== == == == == Script ENDS right ABOVE here == == == == ==
 
 
    11/3/13 - Created by Cesar V. Ramirez
 
 */
#import <Foundation/Foundation.h>
#import <OcLib/OcLib.h>

@class OcIntArray;


@interface OcVersion : OcBaseNoInit

+ (instancetype)newWithVersionInfoFromMainBundlePlist;
+ (instancetype)newWithMajor:(uint32)major minor:(uint32)minor revision:(uint32)revision date:(NSDate *)date;

@property (nonatomic, readonly, assign) uint32 major;
@property (nonatomic, readonly, assign) uint32 minor;
@property (nonatomic, readonly, assign) uint32 revision;
@property (nonatomic, readonly, copy  ) NSDate *date;
@property (nonatomic, readonly, strong) OcIntArray *numbersList;
- (NSString *)numbers;

@end