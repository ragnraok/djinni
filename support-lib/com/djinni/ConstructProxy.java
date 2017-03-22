package com.djinni;

/**
 * Created by ragnarok on 2017/3/19.
 */

public class ConstructProxy {

    public static void proxyDefaultConstructor(Class clazz, String interfaceName) {
        if (clazz != null && interfaceName != null) {
            proxyDefaultConstructor(clazz.getName().replace(".", "/"), interfaceName);
        }
    }

    private static native void proxyDefaultConstructor(String classname, String interfaceName);

}
