#ifndef INCLUDED_brainfuck_EndOfInputError
#define INCLUDED_brainfuck_EndOfInputError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,EndOfInputError)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  EndOfInputError_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EndOfInputError_obj OBJ_;
		EndOfInputError_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="brainfuck.EndOfInputError")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< EndOfInputError_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EndOfInputError_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("EndOfInputError","\xb0","\x0f","\x44","\x98"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_EndOfInputError */ 
