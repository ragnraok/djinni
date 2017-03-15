// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from example.djinni

#include "NativeTextboxListener.hpp"  // my header
#include "NativeItemList.hpp"

namespace djinni_generated {

NativeTextboxListener::NativeTextboxListener() : ::djinni::JniInterface<::textsort::TextboxListener, NativeTextboxListener>() {}

NativeTextboxListener::~NativeTextboxListener() = default;

NativeTextboxListener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeTextboxListener::JavaProxy::~JavaProxy() = default;

void NativeTextboxListener::JavaProxy::updateNew(const ::textsort::ItemList & c_items) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeTextboxListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_updateNew,
                           ::djinni::get(::djinni_generated::NativeItemList::fromCpp(jniEnv, c_items)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeTextboxListener::JavaProxy::update(const ::textsort::ItemList & c_items) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeTextboxListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_update,
                           ::djinni::get(::djinni_generated::NativeItemList::fromCpp(jniEnv, c_items)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
