#include <hxcpp.h>

#ifndef INCLUDED_brainfuck_EndOfProgramError
#include <brainfuck/EndOfProgramError.h>
#endif
namespace brainfuck{

Void EndOfProgramError_obj::__construct()
{
HX_STACK_FRAME("brainfuck.EndOfProgramError","new",0x1c8449a7,"brainfuck.EndOfProgramError.new","brainfuck/CPU.hx",503,0xa331a858)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//EndOfProgramError_obj::~EndOfProgramError_obj() { }

Dynamic EndOfProgramError_obj::__CreateEmpty() { return  new EndOfProgramError_obj; }
hx::ObjectPtr< EndOfProgramError_obj > EndOfProgramError_obj::__new()
{  hx::ObjectPtr< EndOfProgramError_obj > _result_ = new EndOfProgramError_obj();
	_result_->__construct();
	return _result_;}

Dynamic EndOfProgramError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EndOfProgramError_obj > _result_ = new EndOfProgramError_obj();
	_result_->__construct();
	return _result_;}

::String EndOfProgramError_obj::toString( ){
	HX_STACK_FRAME("brainfuck.EndOfProgramError","toString",0x803e5605,"brainfuck.EndOfProgramError.toString","brainfuck/CPU.hx",508,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_LINE(508)
	return HX_HCSTRING("End of program reached","\x32","\xfd","\x85","\x38");
}


HX_DEFINE_DYNAMIC_FUNC0(EndOfProgramError_obj,toString,return )


EndOfProgramError_obj::EndOfProgramError_obj()
{
}

Dynamic EndOfProgramError_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
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
	HX_MARK_MEMBER_NAME(EndOfProgramError_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EndOfProgramError_obj::__mClass,"__mClass");
};

#endif

hx::Class EndOfProgramError_obj::__mClass;

void EndOfProgramError_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.EndOfProgramError","\x35","\xea","\xce","\x36");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< EndOfProgramError_obj >;
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
