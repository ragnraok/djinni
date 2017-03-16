// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from example.djinni

#pragma once

#include "djinni_support.hpp"
#include "super_super_listener.hpp"

namespace djinni_generated {

class NativeSuperSuperListener final : ::djinni::JniInterface<::textsort::SuperSuperListener, NativeSuperSuperListener> {
public:
    using CppType = std::shared_ptr<::textsort::SuperSuperListener>;
    using CppOptType = std::shared_ptr<::textsort::SuperSuperListener>;
    using JniType = jobject;

    using Boxed = NativeSuperSuperListener;

    ~NativeSuperSuperListener();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeSuperSuperListener>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeSuperSuperListener>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeSuperSuperListener();
    friend ::djinni::JniClass<NativeSuperSuperListener>;
    friend ::djinni::JniInterface<::textsort::SuperSuperListener, NativeSuperSuperListener>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::textsort::SuperSuperListener
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void updateSuper() override;

    private:
        friend ::djinni::JniInterface<::textsort::SuperSuperListener, ::djinni_generated::NativeSuperSuperListener>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/dropbox/textsort/SuperSuperListener") };
    const jmethodID method_updateSuper { ::djinni::jniGetMethodID(clazz.get(), "updateSuper", "()V") };
};

}  // namespace djinni_generated
