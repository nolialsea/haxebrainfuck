#include <hxcpp.h>

#ifndef INCLUDED_brainfuck_InvalidMemoryAccessError
#include <brainfuck/InvalidMemoryAccessError.h>
#endif
namespace brainfuck{

Void InvalidMemoryAccessError_obj::__construct()
{
HX_STACK_FRAME("brainfuck.InvalidMemoryAccessError","new",0xf1c6b7bf,"brainfuck.InvalidMemoryAccessError.new","brainfuck/Brainfuck.hx",148,0xf6222cb3)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//InvalidMemoryAccessError_obj::~InvalidMemoryAccessError_obj() { }

Dynamic InvalidMemoryAccessError_obj::__CreateEmpty() { return  new InvalidMemoryAccessError_obj; }
hx::ObjectPtr< InvalidMemoryAccessError_obj > InvalidMemoryAccessError_obj::__new()
{  hx::ObjectPtr< InvalidMemoryAccessError_obj > _result_ = new InvalidMemoryAccessError_obj();
	_result_->__construct();
	return _result_;}

Dynamic InvalidMemoryAccessError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InvalidMemoryAccessError_obj > _result_ = new InvalidMemoryAccessError_obj();
	_result_->__construct();
	return _result_;}

::String InvalidMemoryAccessError_obj::toString( ){
	HX_STACK_FRAME("brainfuck.InvalidMemoryAccessError","toString",0x35fdd0ed,"brainfuck.InvalidMemoryAccessError.toString","brainfuck/Brainfuck.hx",153,0xf6222cb3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(153)
	return HX_HCSTRING("Invalid memory access","\xda","\x8d","\x1d","\x07");
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidMemoryAccessError_obj,toString,return )


InvalidMemoryAccessError_obj::InvalidMemoryAccessError_obj()
{
}

Dynamic InvalidMemoryAccessError_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("toString","\xac","\xd0","\x6e","\x38"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InvalidMemoryAccessError_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InvalidMemoryAccessError_obj::__mClass,"__mClass");
};

#endif

hx::Class InvalidMemoryAccessError_obj::__mClass;

void InvalidMemoryAccessError_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.InvalidMemoryAccessError","\x4d","\x6c","\x8a","\xa9");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< InvalidMemoryAccessError_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = sStaticStorageInfo;
#endif
	hx::RegisterClass(__mClass->mName, __mClass);
}

} // end namespace brainfuck
