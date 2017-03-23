#include "djinni_proxy_constructor.hpp"

namespace djinni {
    ProxyConstructorMap* ProxyConstructorMap::instance = new ProxyConstructorMap();

    void ProxyConstructorMap::mapConstructor(const char* classname, const char* interfaceName) {
        if (!classname || !interfaceName) {
            return;
        }
        std::unique_lock<std::mutex> lock(_mutex);
        jclass obj_class = jniGetThreadEnv()->FindClass(classname);
        if (obj_class) {
            obj_class = (jclass)jniGetThreadEnv()->NewGlobalRef(obj_class);
        }
        jmethodID construction_method = jniGetMethodID(obj_class, "<init>", "()V");
        if (construction_method) {
            constructorMap.insert(std::make_pair(std::string(interfaceName), std::make_pair(obj_class, construction_method)));
        }
    }

    jobject ProxyConstructorMap::createObject(const char* interfaceName) {
        std::unique_lock<std::mutex> lock(_mutex);
        auto it = constructorMap.find(std::string(interfaceName));
        if (it != constructorMap.end()) {
            jclass obj_class = it->second.first;
            jmethodID constructor_method = it->second.second;
            jobject obj = jniGetThreadEnv()->NewObject(obj_class, constructor_method);
            return obj;
        } else {
            return NULL;
        }
    }
}