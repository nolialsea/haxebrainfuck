#include <hxcpp.h>

#ifndef INCLUDED_brainfuck_BfEndAt
#include <brainfuck/BfEndAt.h>
#endif
namespace brainfuck{

Void BfEndAt_obj::__construct()
{
HX_STACK_FRAME("brainfuck.BfEndAt","new",0x75c3bc9b,"brainfuck.BfEndAt.new","brainfuck/CPU.hx",533,0xa331a858)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//BfEndAt_obj::~BfEndAt_obj() { }

Dynamic BfEndAt_obj::__CreateEmpty() { return  new BfEndAt_obj; }
hx::ObjectPtr< BfEndAt_obj > BfEndAt_obj::__new()
{  hx::ObjectPtr< BfEndAt_obj > _result_ = new BfEndAt_obj();
	_result_->__construct();
	return _result_;}

Dynamic BfEndAt_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BfEndAt_obj > _result_ = new BfEndAt_obj();
	_result_->__construct();
	return _result_;}

::String BfEndAt_obj::toString( ){
	HX_STACK_FRAME("brainfuck.BfEndAt","toString",0x80d5ae91,"brainfuck.BfEndAt.toString","brainfuck/CPU.hx",538,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_LINE(538)
	return HX_HCSTRING("BF_END_COMMAND","\x2c","\x6f","\x18","\x3f");
}


HX_DEFINE_DYNAMIC_FUNC0(BfEndAt_obj,toString,return )


BfEndAt_obj::BfEndAt_obj()
{
}

Dynamic BfEndAt_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
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
	HX_MARK_MEMBER_NAME(BfEndAt_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BfEndAt_obj::__mClass,"__mClass");
};

#endif

hx::Class BfEndAt_obj::__mClass;

void BfEndAt_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.BfEndAt","\x29","\xd3","\x34","\x85");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< BfEndAt_obj >;
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
