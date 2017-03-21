////
////  DJIProxyConstructorImpl.cpp
////  TextSort
////
////  Created by ragnarok on 2017/3/21.
////  Copyright © 2017年 Dropbox, Inc. All rights reserved.
////

#import "DJIProxyConstructorImpl.h"

@implementation DJIProxyConstructorMap

+(instancetype)get {
    static DJIProxyConstructorMap* instance = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        instance = [[self alloc] init];
    });
    return instance;
}

-(id)init {
    self = [super init];
    
    self.interfaceClassMapping = [NSMapTable mapTableWithKeyOptions:NSMapTableCopyIn valueOptions:NSMapTableStrongMemory];
    
    return self;
}

-(void) mapConstructor:(NSString*)classname interface:(NSString*)interfaceName {
    if (classname == nil || interfaceName == nil || [classname length] == 0 || [interfaceName length] == 0) {
        return;
    }
    NSLog(@"mapConstructor: %@ %@", classname, interfaceName);
    Class cls = NSClassFromString(classname);
    if (cls != nil) {
        NSLog(@"find cls success!");
        [self.interfaceClassMapping setObject:cls forKey:interfaceName];
    }
}

-(id) createObject:(NSString*)interfaceName {
    Class clz = [self.interfaceClassMapping objectForKey:interfaceName];
    NSLog(@"try to find interface: %@", interfaceName);
    if (clz != nil) {
        NSLog(@"find cls success, create object");
        return [[clz alloc] init];
    }
    NSLog(@"find cls failed!");
    return nil;
}


//template<class CppType/*, typename GenCppType, typename GenCppProxyType*/>
//std::shared_ptr<CppType> createDJIOBJProxyObjectFromInterfaceName(const char* interfaceName) {
//    NSLog(@"createDJIOBJProxyObjectFromInterfaceName %s", interfaceName);
//    if (interfaceName != NULL) {
//        NSString* interfaceNameStr = [NSString stringWithUTF8String:interfaceName];
//        id obj = [[DJIProxyConstructorMap get] createObject:interfaceNameStr];
//        if (obj != nil) {
//            NSLog(@"createDJIOBJProxyObjectFromInterfaceName, success create object");
////            auto result = ::djinni::get_objc_proxy<GenCppProxyType>(obj);
//            NSLog(@"success get proxy object");
//            return result;
//        }
//    }
//}
//
//id djiCreateObjObject(const char* interfaceName) {
//    NSLog(@"djiCreateObjObject %s", interfaceName);
//    if (interfaceName != NULL) {
//        NSString* interfaceNameStr = [NSString stringWithUTF8String:interfaceName];
//        id obj = [[DJIProxyConstructorMap get] createObject:interfaceNameStr];
//        if (obj != nil) {
//            NSLog(@"createDJIOBJProxyObjectFromInterfaceName, success create object");
//            return obj;
//        }
//    }
//    return NULL;
//}

@end
