//
//  DJIProxyConstructorImpl.hpp
//  TextSort
//
//  Created by ragnarok on 2017/3/21.
//  Copyright © 2017年 Dropbox, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

//#import "DJIProxyConstructorSupport.hpp"

@interface DJIProxyConstructorMap : NSObject

@property NSMapTable* interfaceClassMapping;

-(void) mapConstructor:(NSString*)classname interface:(NSString*)interfaceName;

-(id) createObject:(NSString*)interfaceName;

+(instancetype)get;

@end
