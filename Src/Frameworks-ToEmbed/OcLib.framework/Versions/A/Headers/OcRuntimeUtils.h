/*! OcRuntimeUtils
 *
 * Created by Cesar V. Ramirez on 4/18/14.
 * Copyright (c) 2014 Cesar V. Ramirez. All rights reserved.
 *
 */
#import <Foundation/Foundation.h>
#import <objc/runtime.h>


@interface OcRuntimeUtils : NSObject

+ (NSArray *)classNamesOfSubclassesForClass:(Class)targetSuperClass;

+ (NSArray *)subclassesForClass:(Class)targetSuperClass;

+ (NSArray *)getMethodSelectorsForInstance:(id)instance shouldIncludeSuperclasses:(BOOL)shouldIncludeSuperclasses shouldIncludeNSObject:(BOOL)shouldIncludeNSObject filter:(BOOL(^)(Method method))methodFilter;

+ (NSArray *)getMethodSelectorsForClass:(Class)class shouldIncludeSuperclasses:(BOOL)shouldIncludeSuperclasses shouldIncludeNSObject:(BOOL)shouldIncludeNSObject filter:(BOOL(^)(Method method))methodFilter;

+ (NSDictionary *)getMethodSelectorsDictionaryForClass:(Class)class shouldIncludeSuperclasses:(BOOL)shouldIncludeSuperclasses shouldIncludeNSObject:(BOOL)shouldIncludeNSObject filter:(BOOL(^)(Method method))methodFilter;
@end