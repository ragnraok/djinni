// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from example.djinni

#pragma once

#include "super_listtener.hpp"
#include <memory>

namespace textsort {

class SuperListtener;
struct ItemList;

class TextboxListener : public SuperListtener {
public:
    TextboxListener() {}
    virtual ~TextboxListener() {
        this->objPtr.reset();
    }

    /**update(items: item_list); */
    virtual void updateNew(const ItemList & items) {
        if (this->objPtr) {
            this->objPtr->updateNew(items);
        }
    }

    static TextboxListener create() {
        return TextboxListener(true);
    }
private:
    void init();
    std::shared_ptr<TextboxListener> objPtr;
    TextboxListener(bool fromNative) {
        if (fromNative) {
            init();
        }
    }
};

}  // namespace textsort
