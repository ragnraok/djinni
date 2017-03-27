//
// Copyright 2014 Dropbox, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// This provides a minimal JNI_OnLoad and JNI_OnUnload implementation - include it if your
// app doesn't use JNI except through Djinni.

#include "djinni_support.hpp"
#include "djinni_proxy_constructor.hpp"

namespace djinni {
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

}

// Called when library is loaded by the first class which uses it.
CJNIEXPORT jint JNICALL JNI_OnLoad(JavaVM * jvm, void * /*reserved*/) {
    djinni::jniInit(jvm);
    djinni::register_constructor_proxy_method();

    return JNI_VERSION_1_6;
}

// (Potentially) called when library is about to be unloaded.
CJNIEXPORT void JNICALL JNI_OnUnload(JavaVM * /*jvm*/, void * /*reserved*/) {
    djinni::jniShutdown();
}
