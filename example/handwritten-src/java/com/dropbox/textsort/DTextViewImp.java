package com.dropbox.textsort;

import android.util.Log;

/**
 * Created by foreverzeus on 17/3/20.
 */

public class DTextViewImp implements DTextView {

    public static final String TAG = "MicroMsg.DTextViewImp";

    @Override
    public void setWidth(int w) {
        Log.i(TAG, "set Width DTextViewImp " +  w);
    }

    @Override
    public void setHeight(int h) {
        Log.i(TAG, "set setHeight DTextViewImp " + h);
    }

    @Override
    public void setText(String text) {
        Log.i(TAG, "set setText DTextViewImp" + text);
    }
}
