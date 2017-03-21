//
//  TXSTextboxListenerCreator.m
//  TextSort
//
//  Created by ragnarok on 2017/3/21.
//  Copyright © 2017年 Dropbox, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DJIProxyConstructorImpl.h"
#import "TXSTextboxListenerCreator.h"
#import "TXSTextboxListener+Private.h"

std::shared_ptr<::textsort::TextboxListener> createTextboxListener() {
    id<TXSTextboxListener> listener = [[DJIProxyConstructorMap get] createObject:@"textbox_listener"];
    return ::djinni_generated::TextboxListener::toCpp(listener);
}
