// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from example.djinni

#include "NativeSuperListtener.hpp"  // my header
#include "NativeItemList.hpp"

namespace djinni_generated {

NativeSuperListtener::NativeSuperListtener() : ::djinni::JniInterface<::textsort::SuperListtener, NativeSuperListtener>() {}

NativeSuperListtener::~NativeSuperListtener() = default;

NativeSuperListtener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeSuperListtener::JavaProxy::~JavaProxy() = default;

void NativeSuperListtener::JavaProxy::update(const ::textsort::ItemList & c_items) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeSuperListtener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_update,
                           ::djinni::get(::djinni_generated::NativeItemList::fromCpp(jniEnv, c_items)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
