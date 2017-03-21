package com.dropbox.textsort;

/**
 * Created by foreverzeus on 17/3/20.
 */

public class DviewHelperImp implements DviewHelper {

    @Override
    public DTextView createDTextView() {
        return new DTextViewImp();
    }
}
