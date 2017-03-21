#include "textbox_listener.hpp"

#ifdef __ANDROID__
#include "NativeTextboxListener.hpp"
#include "djinni_proxy_constructor.hpp"

using namespace djinni_generated;
using namespace djinni;

#define CREATE_PROXY_TEXTBOX_LISTENER_OBJ(PTR) \
    jobject obj = ProxyConstructorMap::get()->createObject("textbox_listener"); \
    if (obj) { \
        PTR = NativeTextboxListener::toCpp(jniGetThreadEnv(), obj); \
    }
#endif


#ifdef __APPLE__
#include "TXSTextboxListenerCreator.h"
#define CREATE_PROXY_TEXTBOX_LISTENER_OBJ(PTR) \
    PTR = createTextboxListener();
#endif

#ifndef CREATE_PROXY_TEXTBOX_LISTENER_OBJ
#define CREATE_PROXY_TEXTBOX_LISTENER_OBJ(PTR)
#endif


namespace textsort {

void TextboxListener::init() {
    CREATE_PROXY_TEXTBOX_LISTENER_OBJ(this->objPtr);
}

}
