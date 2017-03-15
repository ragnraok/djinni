// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from example.djinni

package com.dropbox.textsort;

import java.util.concurrent.atomic.AtomicBoolean;

/*package*/ abstract class SortItems {
    /** For the iOS / Android demo */
    public abstract void sort(SortOrder order, ItemList items);

    public static native SortItems createWithListener(TextboxListener listener);

    /** For the localhost / command-line demo */
    public static native ItemList runSort(ItemList items);

    private static final class CppProxy extends SortItems
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public void sort(SortOrder order, ItemList items)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_sort(this.nativeRef, order, items);
        }
        private native void native_sort(long _nativeRef, SortOrder order, ItemList items);
    }
}
