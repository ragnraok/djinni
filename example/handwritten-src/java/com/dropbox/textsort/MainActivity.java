package com.dropbox.textsort;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import com.djinni.ConstructProxy;

import java.util.ArrayList;
import java.util.Arrays;

import static com.dropbox.textsort.Util.TAG;

public class MainActivity extends Activity {

    private EditText text;
    private SortItems sortItemsInterface;
    private TextboxListener textboxListener;

    static {
        System.loadLibrary("textsort_jni");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ConstructProxy.proxyDefaultConstructor(TextboxListenerImpl.class.getName().replace(".", "/"), "textbox_listener");

        text = (EditText) findViewById(R.id.editText);
        textboxListener = new TextboxListenerImpl(text);
        // Call JNI to initiate the SortItems object from the given textboxListener and translate to Java
        sortItemsInterface = SortItems.createWithListener(textboxListener);
    }

    public void sort(SortOrder order) {
        String str = text.getText().toString();
        ArrayList<String> items = new ArrayList<String>(Arrays.asList(str.split("\n")));
        ItemList itemList = new ItemList(items);
        sortItemsInterface.sort(order, itemList);
    }

    public void sortAsc(View view) {
        Log.i(TAG, "sort asc");
        this.sort(SortOrder.ASCENDING);
    }

    public void sortDesc(View view) {
        Log.i(TAG, "sortDesc");
        this.sort(SortOrder.DESCENDING);
    }

    public void sortRandom(View view) {
        Log.i(TAG, "sortRandom");
        this.sort(SortOrder.RANDOM);
    }
}
