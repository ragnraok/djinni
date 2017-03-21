package com.dropbox.textsort;

import android.util.Log;
import android.widget.EditText;

import java.util.ArrayList;

import static com.dropbox.textsort.Util.TAG;

public class TextboxListenerImpl extends SuperTextboxListenerImpl implements TextboxListener {

    private EditText mTextArea;

    public TextboxListenerImpl() {
        Log.i(TAG, "create TextboxListenerImpl");
    }

    public TextboxListenerImpl(EditText textArea) {
        this.mTextArea = textArea;
    }

//    @Override
//    public void update(ItemList items) {
//        Log.i(TAG, "update " + items.getItems().toString());
//        ArrayList<String> list = items.getItems();
//        StringBuilder builder = new StringBuilder();
//        for (String str : list) {
//            builder.append(str);
//            builder.append("\n");
//        }
//        mTextArea.setText(builder);
//    }

    @Override
    public void updateNew(ItemList items) {
        Log.i(TAG, "updateNew" + items.getItems().toString());
    }
}
