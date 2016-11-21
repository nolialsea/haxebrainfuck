#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_brainfuck_Brainfuck
#include <brainfuck/Brainfuck.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_ArrayBufferViewImpl
#include <haxe/io/ArrayBufferViewImpl.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif

Void Main_obj::__construct()
{
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > _result_ = new Main_obj();
	_result_->__construct();
	return _result_;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > _result_ = new Main_obj();
	_result_->__construct();
	return _result_;}

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",17,0x087e5c05)
		HX_STACK_LINE(29)
		::brainfuck::Brainfuck tmp = ::brainfuck::Brainfuck_obj::__new(null(),null(),null(),null(),null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(29)
		::brainfuck::Brainfuck bf = tmp;		HX_STACK_VAR(bf,"bf");
		HX_STACK_LINE(31)
		::brainfuck::Brainfuck tmp1 = bf->execute(HX_HCSTRING("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.","\x1e","\x08","\x5e","\x49"),null());		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(31)
		::String tmp2 = tmp1->getOutput();		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(31)
		Dynamic tmp3 = hx::SourceInfo(HX_HCSTRING("Main.hx","\x05","\x5c","\x7e","\x08"),31,HX_HCSTRING("Main","\x59","\x64","\x2f","\x33"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(31)
		::haxe::Log_obj::trace(tmp2,tmp3);
		HX_STACK_LINE(32)
		::brainfuck::Brainfuck tmp4 = bf->execute(HX_HCSTRING("++++{+{{{.$>-}}^>++{{{++$<^.$>[-]++{{+^..$>+++|.>++{{{{.<<<<$>>>>>-}}}^.<<.+++.<.<-.>>>+.@","\xb5","\x54","\x7e","\x81"),null());		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(32)
		::String tmp5 = tmp4->getOutput();		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(32)
		Dynamic tmp6 = hx::SourceInfo(HX_HCSTRING("Main.hx","\x05","\x5c","\x7e","\x08"),32,HX_HCSTRING("Main","\x59","\x64","\x2f","\x33"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(32)
		::haxe::Log_obj::trace(tmp5,tmp6);
		HX_STACK_LINE(33)
		::brainfuck::Brainfuck tmp7 = bf->execute(HX_HCSTRING(">++{{$+*.>!++$*+.>!*=--..$>!+++.>++{${*.>++$</$>![<]!-$>=.>>>.+++.<.<-.<<=+++.@","\xdc","\xce","\x5f","\xfd"),null());		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(33)
		::String tmp8 = tmp7->getOutput();		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(33)
		Dynamic tmp9 = hx::SourceInfo(HX_HCSTRING("Main.hx","\x05","\x5c","\x7e","\x08"),33,HX_HCSTRING("Main","\x59","\x64","\x2f","\x33"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(33)
		::haxe::Log_obj::trace(tmp8,tmp9);
		HX_STACK_LINE(34)
		::brainfuck::Brainfuck tmp10 = bf->execute(HX_HCSTRING("[.>]@Hello World!","\x8b","\x21","\xf6","\x05"),null());		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(34)
		::String tmp11 = tmp10->getOutput();		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(34)
		Dynamic tmp12 = hx::SourceInfo(HX_HCSTRING("Main.hx","\x05","\x5c","\x7e","\x08"),34,HX_HCSTRING("Main","\x59","\x64","\x2f","\x33"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(tmp12,"tmp12");
		HX_STACK_LINE(34)
		::haxe::Log_obj::trace(tmp11,tmp12);
		HX_STACK_LINE(35)
		::brainfuck::Brainfuck tmp13 = bf->execute(HX_HCSTRING(">5--------.7-----------.+++++++..+++.<2.5+++++++.>.+++.------.--------.2+.","\x95","\xef","\xb0","\x87"),null());		HX_STACK_VAR(tmp13,"tmp13");
		HX_STACK_LINE(35)
		::String tmp14 = tmp13->getOutput();		HX_STACK_VAR(tmp14,"tmp14");
		HX_STACK_LINE(35)
		Dynamic tmp15 = hx::SourceInfo(HX_HCSTRING("Main.hx","\x05","\x5c","\x7e","\x08"),35,HX_HCSTRING("Main","\x59","\x64","\x2f","\x33"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(tmp15,"tmp15");
		HX_STACK_LINE(35)
		::haxe::Log_obj::trace(tmp14,tmp15);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

bool Main_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { outValue = main_dyn(); return true;  }
	}
	return false;
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

hx::Class Main_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("main","\x39","\x38","\x56","\x48"),
	::String(null()) };

void Main_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("Main","\x59","\x64","\x2f","\x33");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Main_obj::__GetStatic;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< Main_obj >;
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

