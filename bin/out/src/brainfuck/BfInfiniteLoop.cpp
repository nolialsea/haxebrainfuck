#include <hxcpp.h>

#ifndef INCLUDED_brainfuck_BfInfiniteLoop
#include <brainfuck/BfInfiniteLoop.h>
#endif
namespace brainfuck{

Void BfInfiniteLoop_obj::__construct()
{
HX_STACK_FRAME("brainfuck.BfInfiniteLoop","new",0x6239b2af,"brainfuck.BfInfiniteLoop.new","brainfuck/CPU.hx",543,0xa331a858)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//BfInfiniteLoop_obj::~BfInfiniteLoop_obj() { }

Dynamic BfInfiniteLoop_obj::__CreateEmpty() { return  new BfInfiniteLoop_obj; }
hx::ObjectPtr< BfInfiniteLoop_obj > BfInfiniteLoop_obj::__new()
{  hx::ObjectPtr< BfInfiniteLoop_obj > _result_ = new BfInfiniteLoop_obj();
	_result_->__construct();
	return _result_;}

Dynamic BfInfiniteLoop_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BfInfiniteLoop_obj > _result_ = new BfInfiniteLoop_obj();
	_result_->__construct();
	return _result_;}

::String BfInfiniteLoop_obj::toString( ){
	HX_STACK_FRAME("brainfuck.BfInfiniteLoop","toString",0x16272ffd,"brainfuck.BfInfiniteLoop.toString","brainfuck/CPU.hx",548,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_LINE(548)
	return HX_HCSTRING("BF_INFINITE_LOOP","\xf4","\xdb","\xf3","\x09");
}


HX_DEFINE_DYNAMIC_FUNC0(BfInfiniteLoop_obj,toString,return )


BfInfiniteLoop_obj::BfInfiniteLoop_obj()
{
}

Dynamic BfInfiniteLoop_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
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
	HX_MARK_MEMBER_NAME(BfInfiniteLoop_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BfInfiniteLoop_obj::__mClass,"__mClass");
};

#endif

hx::Class BfInfiniteLoop_obj::__mClass;

void BfInfiniteLoop_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.BfInfiniteLoop","\x3d","\x2f","\x49","\xf6");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< BfInfiniteLoop_obj >;
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
