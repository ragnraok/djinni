////
////  DJIProxyConstructorImpl.cpp
////  TextSort
////
////  Created by ragnarok on 2017/3/21.
////  Copyright © 2017年 Dropbox, Inc. All rights reserved.
////

#import "DJIProxyConstructorImpl.h"

@implementation DJIProxyConstructorMap

static DJIProxyConstructorMap* instance = nil;

+(instancetype)get {
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        instance = [[self alloc] init];
    });
    return instance;
}

-(id)init {
    self = [super init];

    self.interfaceClassMapping = [NSMapTable mapTableWithKeyOptions:NSMapTableCopyIn valueOptions:NSMapTableStrongMemory];
    lockToken = [[NSObject alloc] init];

    return self;
}

-(void) mapConstructor:(NSString*)classname interface:(NSString*)interfaceName {
    if (classname == nil || interfaceName == nil || [classname length] == 0 || [interfaceName length] == 0) {
        return;
    }
    @synchronized (lockToken) {
        Class cls = NSClassFromString(classname);
        if (cls != nil) {
            [self.interfaceClassMapping setObject:cls forKey:interfaceName];
        }
    }
}

-(id) createObject:(NSString*)interfaceName {
    @synchronized (lockToken) {
        Class clz = [self.interfaceClassMapping objectForKey:interfaceName];
        if (clz != nil) {
            return [[clz alloc] init];
        }
    }
    return nil;
}

@end
