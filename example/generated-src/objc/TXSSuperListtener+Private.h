// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from example.djinni

#include "super_listtener.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class TXSSuperListtener;

namespace djinni_generated {

class SuperListtener
{
public:
    using CppType = std::shared_ptr<::textsort::SuperListtener>;
    using CppOptType = std::shared_ptr<::textsort::SuperListtener>;
    using ObjcType = TXSSuperListtener*;

    using Boxed = SuperListtener;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

