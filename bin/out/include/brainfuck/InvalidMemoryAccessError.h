#ifndef INCLUDED_brainfuck_InvalidMemoryAccessError
#define INCLUDED_brainfuck_InvalidMemoryAccessError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,InvalidMemoryAccessError)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  InvalidMemoryAccessError_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef InvalidMemoryAccessError_obj OBJ_;
		InvalidMemoryAccessError_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="brainfuck.InvalidMemoryAccessError")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< InvalidMemoryAccessError_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~InvalidMemoryAccessError_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("InvalidMemoryAccessError","\x2c","\xe9","\xf3","\xd2"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_InvalidMemoryAccessError */ 
