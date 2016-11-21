#include <hxcpp.h>

#ifndef INCLUDED_brainfuck_EndOfInputError
#include <brainfuck/EndOfInputError.h>
#endif
namespace brainfuck{

Void EndOfInputError_obj::__construct()
{
HX_STACK_FRAME("brainfuck.EndOfInputError","new",0x19939921,"brainfuck.EndOfInputError.new","brainfuck/CPU.hx",513,0xa331a858)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//EndOfInputError_obj::~EndOfInputError_obj() { }

Dynamic EndOfInputError_obj::__CreateEmpty() { return  new EndOfInputError_obj; }
hx::ObjectPtr< EndOfInputError_obj > EndOfInputError_obj::__new()
{  hx::ObjectPtr< EndOfInputError_obj > _result_ = new EndOfInputError_obj();
	_result_->__construct();
	return _result_;}

Dynamic EndOfInputError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EndOfInputError_obj > _result_ = new EndOfInputError_obj();
	_result_->__construct();
	return _result_;}

::String EndOfInputError_obj::toString( ){
	HX_STACK_FRAME("brainfuck.EndOfInputError","toString",0xc5daac4b,"brainfuck.EndOfInputError.toString","brainfuck/CPU.hx",518,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_LINE(518)
	return HX_HCSTRING("End of input reached","\xb8","\xa5","\x86","\x3f");
}


HX_DEFINE_DYNAMIC_FUNC0(EndOfInputError_obj,toString,return )


EndOfInputError_obj::EndOfInputError_obj()
{
}

Dynamic EndOfInputError_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
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
	HX_MARK_MEMBER_NAME(EndOfInputError_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EndOfInputError_obj::__mClass,"__mClass");
};

#endif

hx::Class EndOfInputError_obj::__mClass;

void EndOfInputError_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.EndOfInputError","\xaf","\x74","\x6e","\x6d");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< EndOfInputError_obj >;
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
