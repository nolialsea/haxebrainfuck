#include <hxcpp.h>

#ifndef INCLUDED_brainfuck_BfEnd
#include <brainfuck/BfEnd.h>
#endif
namespace brainfuck{

Void BfEnd_obj::__construct()
{
HX_STACK_FRAME("brainfuck.BfEnd","new",0xcddb6c88,"brainfuck.BfEnd.new","brainfuck/CPU.hx",523,0xa331a858)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//BfEnd_obj::~BfEnd_obj() { }

Dynamic BfEnd_obj::__CreateEmpty() { return  new BfEnd_obj; }
hx::ObjectPtr< BfEnd_obj > BfEnd_obj::__new()
{  hx::ObjectPtr< BfEnd_obj > _result_ = new BfEnd_obj();
	_result_->__construct();
	return _result_;}

Dynamic BfEnd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BfEnd_obj > _result_ = new BfEnd_obj();
	_result_->__construct();
	return _result_;}

::String BfEnd_obj::toString( ){
	HX_STACK_FRAME("brainfuck.BfEnd","toString",0xac182384,"brainfuck.BfEnd.toString","brainfuck/CPU.hx",528,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_LINE(528)
	return HX_HCSTRING("BF_END","\x80","\x50","\x9a","\xf0");
}


HX_DEFINE_DYNAMIC_FUNC0(BfEnd_obj,toString,return )


BfEnd_obj::BfEnd_obj()
{
}

Dynamic BfEnd_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
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
	HX_MARK_MEMBER_NAME(BfEnd_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BfEnd_obj::__mClass,"__mClass");
};

#endif

hx::Class BfEnd_obj::__mClass;

void BfEnd_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.BfEnd","\x96","\xc8","\x00","\xad");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< BfEnd_obj >;
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
