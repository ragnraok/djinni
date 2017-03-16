// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from example.djinni

#import "TXSSuperListtener+Private.h"
#import "TXSSuperListtener.h"
#import "DJIObjcWrapperCache+Private.h"
#import "TXSItemList+Private.h"
#include <stdexcept>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class SuperListtener::ObjcProxy final
: public ::textsort::SuperListtener
, private ::djinni::ObjcProxyBase<ObjcType>
{
    friend class ::djinni_generated::SuperListtener;
public:
    using ObjcProxyBase::ObjcProxyBase;
    void update(const ::textsort::ItemList & c_items) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() update:(::djinni_generated::ItemList::fromCpp(c_items))];
        }
    }
    void updateSuper() override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() updateSuper];
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto SuperListtener::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto SuperListtener::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).djinni_private_get_proxied_objc_object();
}

}  // namespace djinni_generated