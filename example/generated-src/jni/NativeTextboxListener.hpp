// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from example.djinni

#pragma once

#include "djinni_support.hpp"
#include "textbox_listener.hpp"

namespace djinni_generated {

class NativeTextboxListener final : ::djinni::JniInterface<::textsort::TextboxListener, NativeTextboxListener> {
public:
    using CppType = std::shared_ptr<::textsort::TextboxListener>;
    using CppOptType = std::shared_ptr<::textsort::TextboxListener>;
    using JniType = jobject;

    using Boxed = NativeTextboxListener;

    ~NativeTextboxListener();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeTextboxListener>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeTextboxListener>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeTextboxListener();
    friend ::djinni::JniClass<NativeTextboxListener>;
    friend ::djinni::JniInterface<::textsort::TextboxListener, NativeTextboxListener>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::textsort::TextboxListener
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void updateNew(const ::textsort::ItemList & items) override;
        void updateSuper() override;
        void update(const ::textsort::ItemList & items) override;

    private:
        friend ::djinni::JniInterface<::textsort::TextboxListener, ::djinni_generated::NativeTextboxListener>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/dropbox/textsort/TextboxListener") };
    const jmethodID method_updateNew { ::djinni::jniGetMethodID(clazz.get(), "updateNew", "(Lcom/dropbox/textsort/ItemList;)V") };
    const jmethodID method_updateSuper { ::djinni::jniGetMethodID(clazz.get(), "updateSuper", "()V") };
    const jmethodID method_update { ::djinni::jniGetMethodID(clazz.get(), "update", "(Lcom/dropbox/textsort/ItemList;)V") };
};

}  // namespace djinni_generated
