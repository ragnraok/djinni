//
//  TXSTextboxListenerCreator.h
//  TextSort
//
//  Created by ragnarok on 2017/3/21.
//  Copyright © 2017年 Dropbox, Inc. All rights reserved.
//

#pragma once

#include <memory>

#include "textbox_listener.hpp"

std::shared_ptr<::textsort::TextboxListener> createTextboxListener();
