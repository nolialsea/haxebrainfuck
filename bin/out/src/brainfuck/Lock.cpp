#include <hxcpp.h>

#ifndef INCLUDED_brainfuck_Lock
#include <brainfuck/Lock.h>
#endif
namespace brainfuck{

Void Lock_obj::__construct(int position,Float owner)
{
HX_STACK_FRAME("brainfuck.Lock","new",0xdc2f3b9e,"brainfuck.Lock.new","brainfuck/Lock.hx",12,0x3b5513b1)
HX_STACK_THIS(this)
HX_STACK_ARG(position,"position")
HX_STACK_ARG(owner,"owner")
{
	HX_STACK_LINE(13)
	this->position = position;
	HX_STACK_LINE(14)
	this->owner = owner;
}
;
	return null();
}

//Lock_obj::~Lock_obj() { }

Dynamic Lock_obj::__CreateEmpty() { return  new Lock_obj; }
hx::ObjectPtr< Lock_obj > Lock_obj::__new(int position,Float owner)
{  hx::ObjectPtr< Lock_obj > _result_ = new Lock_obj();
	_result_->__construct(position,owner);
	return _result_;}

Dynamic Lock_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lock_obj > _result_ = new Lock_obj();
	_result_->__construct(inArgs[0],inArgs[1]);
	return _result_;}


Lock_obj::Lock_obj()
{
}

Dynamic Lock_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"owner") ) { return owner; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Lock_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"owner") ) { owner=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Lock_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("position","\xa9","\xa0","\xfa","\xca"));
	outFields->push(HX_HCSTRING("owner","\x33","\x98","\x76","\x38"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Lock_obj,position),HX_HCSTRING("position","\xa9","\xa0","\xfa","\xca")},
	{hx::fsFloat,(int)offsetof(Lock_obj,owner),HX_HCSTRING("owner","\x33","\x98","\x76","\x38")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("position","\xa9","\xa0","\xfa","\xca"),
	HX_HCSTRING("owner","\x33","\x98","\x76","\x38"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lock_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Lock_obj::__mClass,"__mClass");
};

#endif

hx::Class Lock_obj::__mClass;

void Lock_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.Lock","\xac","\xd4","\x0d","\xb7");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Lock_obj >;
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
