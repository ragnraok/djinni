#include "djinni_proxy_constructor.hpp"

namespace djinni {
    ProxyConstructorMap* ProxyConstructorMap::instance = NULL;

    void ProxyConstructorMap::mapConstructor(const char* classname, const char* interfaceName) {
        if (!classname || !interfaceName) {
            return;
        }
        __android_log_print(ANDROID_LOG_INFO, "TextSort", "mapConstructor, classname: %s, interfaceName: %s",
            classname, interfaceName);
        jclass obj_class = jniGetThreadEnv()->FindClass(classname);
        // GlobalRef<jclass> obj_class(jniGetThreadEnv(), LocalRef<jclass>(jniGetThreadEnv(), jniGetThreadEnv()->FindClass(classname)).get());
        if (obj_class) {
            obj_class = (jclass)jniGetThreadEnv()->NewGlobalRef(obj_class);
            __android_log_print(ANDROID_LOG_INFO, "TextSort", "obj_class find success");
        }
        jmethodID construction_method = jniGetMethodID(obj_class, "<init>", "()V");
        if (construction_method) {
            __android_log_print(ANDROID_LOG_INFO, "TextSort", "finish insert interface mapping");
            constructorMap.insert(std::make_pair(std::string(interfaceName), std::make_pair(obj_class, construction_method)));
        }
    }

    jobject ProxyConstructorMap::createObject(const char* interfaceName) {
        auto it = constructorMap.find(std::string(interfaceName));
        __android_log_print(ANDROID_LOG_INFO, "TextSort", "try to create object: %s", interfaceName);
        if (it != constructorMap.end()) {
            __android_log_print(ANDROID_LOG_INFO, "TextSort", "find mapping!!");
            jclass obj_class = it->second.first;
            jmethodID constructor_method = it->second.second;
            jobject obj = jniGetThreadEnv()->NewObject(obj_class, constructor_method);
            return obj;
        } else {
            __android_log_print(ANDROID_LOG_INFO, "TextSort", "find interface name failed");
            return NULL;
        }
    }
}