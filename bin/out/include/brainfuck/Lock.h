#ifndef INCLUDED_brainfuck_Lock
#define INCLUDED_brainfuck_Lock

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,Lock)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  Lock_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Lock_obj OBJ_;
		Lock_obj();
		Void __construct(int position,Float owner);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="brainfuck.Lock")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Lock_obj > __new(int position,Float owner);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Lock_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Lock","\x0b","\xc8","\x90","\x32"); }

		int position;
		Float owner;
};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_Lock */ 
