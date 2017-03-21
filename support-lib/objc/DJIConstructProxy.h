//
//  DJIConstructProxy.h
//  TextSort
//
//  Created by ragnarok on 2017/3/21.
//  Copyright © 2017年 Dropbox, Inc. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

#import "DJIConstructProxy.h"

@interface DJIConstructProxy : NSObject

+ (void)proxyDefaultConstructor:(NSString*)_classname interfaceName:(NSString*)_interfaceName;

@end
