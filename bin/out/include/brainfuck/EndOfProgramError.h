#ifndef INCLUDED_brainfuck_EndOfProgramError
#define INCLUDED_brainfuck_EndOfProgramError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,EndOfProgramError)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  EndOfProgramError_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EndOfProgramError_obj OBJ_;
		EndOfProgramError_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="brainfuck.EndOfProgramError")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< EndOfProgramError_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EndOfProgramError_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("EndOfProgramError","\x76","\x07","\x82","\xf6"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_EndOfProgramError */ 
