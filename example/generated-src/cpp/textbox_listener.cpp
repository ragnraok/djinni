#include "NativeTextboxListener.hpp"
#include <android/log.h>
#include "djinni_proxy_constructor.hpp"

using namespace djinni_generated;
using namespace djinni;

namespace textsort {

void TextboxListener::init() {
    jobject obj = ProxyConstructorMap::get()->createObject("textbox_listener");
    if (obj) {
        __android_log_print(ANDROID_LOG_INFO, "TextSort", "create TextboxListener java obj");
        this->objPtr = NativeTextboxListener::toCpp(jniGetThreadEnv(), obj);
        __android_log_print(ANDROID_LOG_INFO, "TextSort", "create TextboxListener shared_ptr");
    }
}

}