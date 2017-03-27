#pragma once

#include "djinni_support.hpp"
#include <string>

namespace djinni {

class JavaWeakRef;

class ProxyConstructorMap {
public:
    static ProxyConstructorMap* get() {
        return instance;
    }

    void mapConstructor(const char* classname, const char* interfaceName);
    jobject createObject(const char* interfaceName);
private:
    std::unordered_map<std::string, std::pair<jclass, jmethodID>> constructorMap; // interfaceName->(class, creatorMethod)
    std::mutex _mutex;

    ProxyConstructorMap() {}
    ~ProxyConstructorMap() {
        constructorMap.clear();
    }

    static ProxyConstructorMap* instance;
};

template <typename CppType, typename JniProxyType>
static std::shared_ptr<CppType> proxyCreateJavaObject(const char* interfaceName) {
    jobject obj = ProxyConstructorMap::get()->createObject(interfaceName);
    if (obj) {
        return JniClass<JniProxyType>::get()._fromJava(jniGetThreadEnv(), obj);
    }
    return NULL;

}

}