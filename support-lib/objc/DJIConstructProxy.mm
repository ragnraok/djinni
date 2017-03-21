//
//  DJIConstructProxy.m
//  TextSort
//
//  Created by ragnarok on 2017/3/21.
//  Copyright © 2017年 Dropbox, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DJIConstructProxy.h"
#import "DJIProxyConstructorImpl.hpp"

@implementation DJIConstructProxy

+ (void)proxyDefaultConstructor:(NSString*)_classname interfaceName:(NSString*)_interfaceName {
    [[DJIProxyConstructorMap get] mapConstructor:_classname interface:_interfaceName];
}

@end
