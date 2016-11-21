#ifndef INCLUDED_brainfuck_BfEndAt
#define INCLUDED_brainfuck_BfEndAt

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,BfEndAt)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  BfEndAt_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BfEndAt_obj OBJ_;
		BfEndAt_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="brainfuck.BfEndAt")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< BfEndAt_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BfEndAt_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("BfEndAt","\x2a","\x05","\x97","\x84"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_BfEndAt */ 
