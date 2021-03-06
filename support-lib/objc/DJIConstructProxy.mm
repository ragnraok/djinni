//
//  DJIConstructProxy.m
//  TextSort
//
//  Created by ragnarok on 2017/3/21.
//  Copyright © 2017年 Dropbox, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DJIConstructProxy.h"
#import "DJIProxyConstructorImpl.h"

@implementation DJIConstructProxy

+ (void)proxyDefaultConstructor:(Class)_class interfaceName:(NSString*)_interfaceName {
    
    
    [[DJIProxyConstructorMap get] mapConstructor:NSStringFromClass(_class) interface:_interfaceName];
}

@end
