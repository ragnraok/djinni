package com.dropbox.textsort;

import android.util.Log;

import static com.dropbox.textsort.Util.TAG;

/**
 * Created by ragnarok on 2017/3/16.
 */

public class SuperTextboxListenerImpl extends SuperSuperListenerImpl implements SuperListtener {
    @Override
    public void update(ItemList items) {
        Log.i(TAG, "update " + items.getItems().toString());
    }
}
