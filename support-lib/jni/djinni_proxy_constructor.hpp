#pragma once

#include "djinni_support.hpp"
#include <android/log.h>
#include <string>

namespace djinni {

class JavaWeakRef;

class ProxyConstructorMap {
public:
    static ProxyConstructorMap* get() {
        // if (instance == NULL) {
        //     instance = new ProxyConstructorMap();
        // }
        return instance;
    }

    void mapConstructor(const char* classname, const char* interfaceName);
    jobject createObject(const char* interfaceName);
private:
    std::unordered_map<std::string, std::pair<jclass, jmethodID>> constructorMap; // interfaceName->(class, creatorMethod)
    ProxyConstructorMap() {}
    ~ProxyConstructorMap() {
        __android_log_print(ANDROID_LOG_INFO, "TextSort", "ProxyConstructorMap destroy");
        constructorMap.clear();
    }

    static ProxyConstructorMap* instance;
};

static void map_interface_default_constructor(JNIEnv *env, jclass , jstring classname, jstring interface) {
    const char* _classname = env->GetStringUTFChars(classname, JNI_FALSE);
    const char* _interface = env->GetStringUTFChars(interface, JNI_FALSE);
    ProxyConstructorMap::get()->mapConstructor(_classname, _interface);
    env->ReleaseStringUTFChars(classname, _classname);
    env->ReleaseStringUTFChars(interface, _interface);
}


static void register_constructor_proxy_method() {
    jclass cls = jniGetThreadEnv()->FindClass("com/djinni/ConstructProxy");
    const JNINativeMethod sMethods[] = {
        {"proxyDefaultConstructor", "(Ljava/lang/String;Ljava/lang/String;)V",
            (void*)map_interface_default_constructor}
    };
    if (cls) {
        jniGetThreadEnv()->RegisterNatives(cls, sMethods, 1);
    }
}

template <typename CppType, typename JniProxyType>
static std::shared_ptr<CppType> proxyCreateJavaObject(const char* interfaceName) {
    jobject obj = ProxyConstructorMap::get()->createObject(interfaceName);
    if (obj) {
        return JniClass<JniProxyType>::get()._fromJava(jniGetThreadEnv(), obj);
    }
    return NULL;

}

}