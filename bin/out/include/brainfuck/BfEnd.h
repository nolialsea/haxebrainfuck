#ifndef INCLUDED_brainfuck_BfEnd
#define INCLUDED_brainfuck_BfEnd

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,BfEnd)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  BfEnd_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BfEnd_obj OBJ_;
		BfEnd_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="brainfuck.BfEnd")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< BfEnd_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BfEnd_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("BfEnd","\x57","\xc8","\x12","\x44"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_BfEnd */ 
