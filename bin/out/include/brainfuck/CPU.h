#ifndef INCLUDED_brainfuck_CPU
#define INCLUDED_brainfuck_CPU

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(brainfuck,Brainfuck)
HX_DECLARE_CLASS1(brainfuck,CPU)
HX_DECLARE_CLASS2(haxe,io,ArrayBufferViewImpl)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace brainfuck{


class HXCPP_CLASS_ATTRIBUTES  CPU_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CPU_obj OBJ_;
		CPU_obj();
		Void __construct(::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::brainfuck::Brainfuck bf);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="brainfuck.CPU")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< CPU_obj > __new(::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::brainfuck::Brainfuck bf);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CPU_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("CPU","\x08","\x1d","\x33","\x00"); }

		static ::String getProgramString( ::String program,int programType);
		static Dynamic getProgramString_dyn();

		static ::String getInitialData( ::String program,int programType);
		static Dynamic getInitialData_dyn();

		Float id;
		int maxStep;
		int pointer;
		::haxe::io::ArrayBufferViewImpl storage;
		Dynamic storagePointer;
		::String program;
		int programPosition;
		Dynamic programType;
		Array< int > jump;
		bool comment;
		int ticks;
		Array< int > xReturn;
		::haxe::io::Input input;
		::haxe::io::Output output;
		::haxe::io::ArrayBufferViewImpl memory;
		::String initialData;
		::brainfuck::Brainfuck bf;
		bool alive;
		virtual int getProgramType( ::String program);
		Dynamic getProgramType_dyn();

		virtual Void setInitialData( ::String program,::String initialData);
		Dynamic setInitialData_dyn();

		virtual Void init( ::String program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::brainfuck::Brainfuck bf);
		Dynamic init_dyn();

		virtual bool step( );
		Dynamic step_dyn();

		virtual ::String moveToNextCommand( );
		Dynamic moveToNextCommand_dyn();

		virtual ::String moveToPrevCommand( );
		Dynamic moveToPrevCommand_dyn();

		virtual bool runCommand( ::String command);
		Dynamic runCommand_dyn();

};

} // end namespace brainfuck

#endif /* INCLUDED_brainfuck_CPU */ 
