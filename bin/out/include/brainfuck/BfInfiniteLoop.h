#ifndef INCLUDED_brainfuck_BfInfiniteLoop
#define INCLUDED_brainfuck_BfInfiniteLoop

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,BfInfiniteLoop)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  BfInfiniteLoop_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BfInfiniteLoop_obj OBJ_;
		BfInfiniteLoop_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="brainfuck.BfInfiniteLoop")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< BfInfiniteLoop_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BfInfiniteLoop_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("BfInfiniteLoop","\x5c","\xaf","\xa3","\x9a"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_BfInfiniteLoop */ 
