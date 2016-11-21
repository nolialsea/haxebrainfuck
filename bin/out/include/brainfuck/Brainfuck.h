#ifndef INCLUDED_brainfuck_Brainfuck
#define INCLUDED_brainfuck_Brainfuck

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,Brainfuck)
HX_DECLARE_CLASS1(brainfuck,CPU)
HX_DECLARE_CLASS1(brainfuck,Lock)
HX_DECLARE_CLASS2(haxe,io,ArrayBufferViewImpl)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  Brainfuck_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Brainfuck_obj OBJ_;
		Brainfuck_obj();
		Void __construct(::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::haxe::io::ArrayBufferViewImpl memory);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="brainfuck.Brainfuck")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Brainfuck_obj > __new(::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::haxe::io::ArrayBufferViewImpl memory);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Brainfuck_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Brainfuck","\x4d","\x77","\xa7","\x31"); }

		int memorySize;
		::haxe::io::ArrayBufferViewImpl memory;
		::haxe::io::Input input;
		::haxe::io::Output output;
		Array< ::Dynamic > lock;
		Array< ::Dynamic > cpu;
		virtual ::brainfuck::Brainfuck execute( ::String bfCode,Dynamic type);
		Dynamic execute_dyn();

		virtual ::String getOutput( );
		Dynamic getOutput_dyn();

		virtual ::brainfuck::Brainfuck init( ::String program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::haxe::io::ArrayBufferViewImpl memory);
		Dynamic init_dyn();

		virtual ::brainfuck::Brainfuck run( );
		Dynamic run_dyn();

		virtual bool isLocked( int pointer);
		Dynamic isLocked_dyn();

		virtual bool lockCell( int pointer,Float id);
		Dynamic lockCell_dyn();

		virtual Void unlockCell( int pointer,Float id);
		Dynamic unlockCell_dyn();

		virtual Void increment( int pointer,Float id);
		Dynamic increment_dyn();

		virtual Void decrement( int pointer,Float id);
		Dynamic decrement_dyn();

		virtual Void assign( int pointer,Float id,int value);
		Dynamic assign_dyn();

};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_Brainfuck */ 
