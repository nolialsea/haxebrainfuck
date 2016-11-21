#include <hxcpp.h>

#include "hxMath.h"
#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_brainfuck_BfEnd
#include <brainfuck/BfEnd.h>
#endif
#ifndef INCLUDED_brainfuck_BfEndAt
#include <brainfuck/BfEndAt.h>
#endif
#ifndef INCLUDED_brainfuck_BfInfiniteLoop
#include <brainfuck/BfInfiniteLoop.h>
#endif
#ifndef INCLUDED_brainfuck_Brainfuck
#include <brainfuck/Brainfuck.h>
#endif
#ifndef INCLUDED_brainfuck_CPU
#include <brainfuck/CPU.h>
#endif
#ifndef INCLUDED_brainfuck_EndOfInputError
#include <brainfuck/EndOfInputError.h>
#endif
#ifndef INCLUDED_brainfuck_EndOfProgramError
#include <brainfuck/EndOfProgramError.h>
#endif
#ifndef INCLUDED_brainfuck_InvalidMemoryAccessError
#include <brainfuck/InvalidMemoryAccessError.h>
#endif
#ifndef INCLUDED_haxe_io_ArrayBufferViewImpl
#include <haxe/io/ArrayBufferViewImpl.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_BytesOutput
#include <haxe/io/BytesOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxe_io_StringInput
#include <haxe/io/StringInput.h>
#endif
namespace brainfuck{

Void CPU_obj::__construct(::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::brainfuck::Brainfuck bf)
{
HX_STACK_FRAME("brainfuck.CPU","new",0xef13aff9,"brainfuck.CPU.new","brainfuck/CPU.hx",37,0xa331a858)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_program,"program")
HX_STACK_ARG(type,"type")
HX_STACK_ARG(input,"input")
HX_STACK_ARG(output,"output")
HX_STACK_ARG(bf,"bf")
::String program = __o_program.Default(HX_HCSTRING("","\x00","\x00","\x00","\x00"));
{
	HX_STACK_LINE(38)
	::String tmp = program;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(38)
	Dynamic tmp1 = type;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(38)
	::haxe::io::Input tmp2 = input;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(38)
	::haxe::io::Output tmp3 = output;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(38)
	::brainfuck::Brainfuck tmp4 = bf;		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(38)
	this->init(tmp,tmp1,tmp2,tmp3,tmp4);
}
;
	return null();
}

//CPU_obj::~CPU_obj() { }

Dynamic CPU_obj::__CreateEmpty() { return  new CPU_obj; }
hx::ObjectPtr< CPU_obj > CPU_obj::__new(::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::brainfuck::Brainfuck bf)
{  hx::ObjectPtr< CPU_obj > _result_ = new CPU_obj();
	_result_->__construct(__o_program,type,input,output,bf);
	return _result_;}

Dynamic CPU_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CPU_obj > _result_ = new CPU_obj();
	_result_->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return _result_;}

int CPU_obj::getProgramType( ::String program){
	HX_STACK_FRAME("brainfuck.CPU","getProgramType",0xf352536f,"brainfuck.CPU.getProgramType","brainfuck/CPU.hx",41,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_ARG(program,"program")
	HX_STACK_LINE(42)
	this->programType = (int)0;
	HX_STACK_LINE(43)
	::EReg tmp = ::EReg_obj::__new(HX_HCSTRING("[#0-9A-FlLmMxX]","\x57","\x81","\xa6","\x56"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(43)
	::String tmp1 = program;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(43)
	bool tmp2 = tmp->match(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(43)
	if ((tmp2)){
		HX_STACK_LINE(44)
		this->programType = (int)3;
	}
	else{
		HX_STACK_LINE(45)
		::EReg tmp3 = ::EReg_obj::__new(HX_HCSTRING("[%_=/*\\(\\)?]","\x5a","\xc3","\xed","\xfe"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(45)
		::String tmp4 = program;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(45)
		bool tmp5 = tmp3->match(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(45)
		if ((tmp5)){
			HX_STACK_LINE(46)
			this->programType = (int)2;
		}
		else{
			HX_STACK_LINE(47)
			::EReg tmp6 = ::EReg_obj::__new(HX_HCSTRING("[@|&\\^~{}!\\$]","\x23","\xb8","\xfb","\xb5"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(47)
			::String tmp7 = program;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(47)
			bool tmp8 = tmp6->match(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(47)
			if ((tmp8)){
				HX_STACK_LINE(48)
				this->programType = (int)1;
			}
		}
	}
	HX_STACK_LINE(50)
	Dynamic tmp3 = this->programType;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(50)
	return tmp3;
}


HX_DEFINE_DYNAMIC_FUNC1(CPU_obj,getProgramType,return )

Void CPU_obj::setInitialData( ::String program,::String initialData){
{
		HX_STACK_FRAME("brainfuck.CPU","setInitialData",0x6dcd6553,"brainfuck.CPU.setInitialData","brainfuck/CPU.hx",84,0xa331a858)
		HX_STACK_THIS(this)
		HX_STACK_ARG(program,"program")
		HX_STACK_ARG(initialData,"initialData")
		HX_STACK_LINE(85)
		bool tmp;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(85)
		{
			HX_STACK_LINE(85)
			Dynamic tmp1 = this->programType;		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(85)
			int a = tmp1;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(85)
			bool tmp2 = (a < (int)0);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(85)
			bool aNeg = tmp2;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(85)
			bool tmp3 = ((int)2 < (int)0);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(85)
			bool bNeg = tmp3;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(85)
			bool tmp4 = (aNeg != bNeg);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(85)
			if ((tmp4)){
				HX_STACK_LINE(85)
				tmp = aNeg;
			}
			else{
				HX_STACK_LINE(85)
				tmp = (a >= (int)2);
			}
		}
		HX_STACK_LINE(85)
		if ((tmp)){
			HX_STACK_LINE(86)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(86)
			int _g = program.length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(86)
			while((true)){
				HX_STACK_LINE(86)
				bool tmp1 = (_g1 < _g);		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(86)
				bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(86)
				if ((tmp2)){
					HX_STACK_LINE(86)
					break;
				}
				HX_STACK_LINE(86)
				int tmp3 = (_g1)++;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(86)
				int i = tmp3;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(87)
				{
					HX_STACK_LINE(87)
					::haxe::io::ArrayBufferViewImpl tmp4 = this->memory;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(87)
					::haxe::io::ArrayBufferViewImpl this1 = tmp4;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(87)
					int tmp5 = (i + (int)1);		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(87)
					int index = tmp5;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(87)
					int tmp6 = i;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(87)
					Dynamic tmp7 = program.charCodeAt(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(87)
					int value = tmp7;		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(87)
					bool tmp8 = (index >= (int)0);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(87)
					bool tmp9;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(87)
					if ((tmp8)){
						HX_STACK_LINE(87)
						int tmp10 = index;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(87)
						int tmp11 = this1->byteLength;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(87)
						int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(87)
						tmp9 = (tmp10 < tmp12);
					}
					else{
						HX_STACK_LINE(87)
						tmp9 = false;
					}
					HX_STACK_LINE(87)
					if ((tmp9)){
						HX_STACK_LINE(87)
						{
							HX_STACK_LINE(87)
							::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
							HX_STACK_LINE(87)
							int tmp11 = index;		HX_STACK_VAR(tmp11,"tmp11");
							HX_STACK_LINE(87)
							int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
							HX_STACK_LINE(87)
							int tmp13 = (tmp11 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
							HX_STACK_LINE(87)
							int tmp14 = value;		HX_STACK_VAR(tmp14,"tmp14");
							HX_STACK_LINE(87)
							tmp10->b[tmp13] = tmp14;
						}
						HX_STACK_LINE(87)
						value;
					}
					else{
						HX_STACK_LINE(87)
						(int)0;
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(CPU_obj,setInitialData,(void))

Void CPU_obj::init( ::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::brainfuck::Brainfuck bf){
::String program = __o_program.Default(HX_HCSTRING("","\x00","\x00","\x00","\x00"));
	HX_STACK_FRAME("brainfuck.CPU","init",0x3edf0157,"brainfuck.CPU.init","brainfuck/CPU.hx",92,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_ARG(program,"program")
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(input,"input")
	HX_STACK_ARG(output,"output")
	HX_STACK_ARG(bf,"bf")
{
		HX_STACK_LINE(93)
		Float tmp = ::Math_obj::random();		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(93)
		this->id = tmp;
		HX_STACK_LINE(94)
		this->maxStep = (int)42000;
		HX_STACK_LINE(95)
		bool tmp1 = (type == null());		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(95)
		Dynamic tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(95)
		if ((tmp1)){
			HX_STACK_LINE(95)
			::String tmp3 = program;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(95)
			tmp2 = this->getProgramType(tmp3);
		}
		else{
			HX_STACK_LINE(95)
			tmp2 = type;
		}
		HX_STACK_LINE(95)
		this->programType = tmp2;
		HX_STACK_LINE(96)
		::haxe::io::ArrayBufferViewImpl tmp3;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(96)
		{
			HX_STACK_LINE(96)
			::haxe::io::ArrayBufferViewImpl this1;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(96)
			::haxe::io::ArrayBufferViewImpl tmp4;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(96)
			{
				HX_STACK_LINE(96)
				::haxe::io::ArrayBufferViewImpl tmp5;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(96)
				{
					HX_STACK_LINE(96)
					::haxe::io::ArrayBufferViewImpl this2;		HX_STACK_VAR(this2,"this2");
					HX_STACK_LINE(96)
					::haxe::io::Bytes tmp6 = ::haxe::io::Bytes_obj::alloc((int)1);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(96)
					::haxe::io::ArrayBufferViewImpl tmp7 = ::haxe::io::ArrayBufferViewImpl_obj::__new(tmp6,(int)0,(int)1);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(96)
					this2 = tmp7;
					HX_STACK_LINE(96)
					tmp5 = this2;
				}
				HX_STACK_LINE(96)
				::haxe::io::ArrayBufferViewImpl this2 = tmp5;		HX_STACK_VAR(this2,"this2");
				HX_STACK_LINE(96)
				tmp4 = this2;
			}
			HX_STACK_LINE(96)
			this1 = tmp4;
			HX_STACK_LINE(96)
			tmp3 = this1;
		}
		HX_STACK_LINE(96)
		this->storage = tmp3;
		HX_STACK_LINE(97)
		this->storagePointer = null();
		HX_STACK_LINE(98)
		::String tmp4 = program;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(98)
		Dynamic tmp5 = this->programType;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(98)
		::String tmp6 = ::brainfuck::CPU_obj::getProgramString(tmp4,tmp5);		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(98)
		this->program = tmp6;
		HX_STACK_LINE(99)
		::String tmp7 = program;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(99)
		Dynamic tmp8 = this->programType;		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(99)
		::String tmp9 = ::brainfuck::CPU_obj::getInitialData(tmp7,tmp8);		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(99)
		this->initialData = tmp9;
		HX_STACK_LINE(100)
		bool tmp10;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(100)
		{
			HX_STACK_LINE(100)
			Dynamic tmp11 = this->programType;		HX_STACK_VAR(tmp11,"tmp11");
			HX_STACK_LINE(100)
			int a = tmp11;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(100)
			bool tmp12 = (a < (int)0);		HX_STACK_VAR(tmp12,"tmp12");
			HX_STACK_LINE(100)
			bool aNeg = tmp12;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(100)
			bool tmp13 = ((int)1 < (int)0);		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(100)
			bool bNeg = tmp13;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(100)
			bool tmp14 = (aNeg != bNeg);		HX_STACK_VAR(tmp14,"tmp14");
			HX_STACK_LINE(100)
			if ((tmp14)){
				HX_STACK_LINE(100)
				tmp10 = aNeg;
			}
			else{
				HX_STACK_LINE(100)
				tmp10 = (a > (int)1);
			}
		}
		HX_STACK_LINE(100)
		int tmp11;		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(100)
		if ((tmp10)){
			HX_STACK_LINE(100)
			::String tmp12 = this->program;		HX_STACK_VAR(tmp12,"tmp12");
			HX_STACK_LINE(100)
			int tmp13 = tmp12.length;		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(100)
			tmp11 = (tmp13 + (int)1);
		}
		else{
			HX_STACK_LINE(100)
			tmp11 = (int)0;
		}
		HX_STACK_LINE(100)
		this->pointer = tmp11;
		HX_STACK_LINE(101)
		bool tmp12;		HX_STACK_VAR(tmp12,"tmp12");
		HX_STACK_LINE(101)
		{
			HX_STACK_LINE(101)
			Dynamic tmp13 = this->programType;		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(101)
			int a = tmp13;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(101)
			bool tmp14 = (a < (int)0);		HX_STACK_VAR(tmp14,"tmp14");
			HX_STACK_LINE(101)
			bool aNeg = tmp14;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(101)
			bool tmp15 = ((int)1 < (int)0);		HX_STACK_VAR(tmp15,"tmp15");
			HX_STACK_LINE(101)
			bool bNeg = tmp15;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(101)
			bool tmp16 = (aNeg != bNeg);		HX_STACK_VAR(tmp16,"tmp16");
			HX_STACK_LINE(101)
			if ((tmp16)){
				HX_STACK_LINE(101)
				tmp12 = aNeg;
			}
			else{
				HX_STACK_LINE(101)
				tmp12 = (a > (int)1);
			}
		}
		HX_STACK_LINE(101)
		int tmp13;		HX_STACK_VAR(tmp13,"tmp13");
		HX_STACK_LINE(101)
		if ((tmp12)){
			HX_STACK_LINE(101)
			tmp13 = (int)1;
		}
		else{
			HX_STACK_LINE(101)
			tmp13 = (int)0;
		}
		HX_STACK_LINE(101)
		this->programPosition = tmp13;
		HX_STACK_LINE(102)
		this->jump = Array_obj< int >::__new();
		HX_STACK_LINE(103)
		this->comment = false;
		HX_STACK_LINE(104)
		this->ticks = (int)0;
		HX_STACK_LINE(105)
		this->xReturn = Array_obj< int >::__new();
		HX_STACK_LINE(106)
		bool tmp14 = (input == null());		HX_STACK_VAR(tmp14,"tmp14");
		HX_STACK_LINE(106)
		::haxe::io::Input tmp15;		HX_STACK_VAR(tmp15,"tmp15");
		HX_STACK_LINE(106)
		if ((tmp14)){
			HX_STACK_LINE(106)
			tmp15 = ::haxe::io::StringInput_obj::__new(HX_HCSTRING("","\x00","\x00","\x00","\x00"));
		}
		else{
			HX_STACK_LINE(106)
			tmp15 = input;
		}
		HX_STACK_LINE(106)
		this->input = tmp15;
		HX_STACK_LINE(107)
		bool tmp16 = (output == null());		HX_STACK_VAR(tmp16,"tmp16");
		HX_STACK_LINE(107)
		::haxe::io::Output tmp17;		HX_STACK_VAR(tmp17,"tmp17");
		HX_STACK_LINE(107)
		if ((tmp16)){
			HX_STACK_LINE(107)
			tmp17 = ::haxe::io::BytesOutput_obj::__new();
		}
		else{
			HX_STACK_LINE(107)
			tmp17 = output;
		}
		HX_STACK_LINE(107)
		this->output = tmp17;
		HX_STACK_LINE(108)
		this->bf = bf;
		HX_STACK_LINE(109)
		this->memory = bf->memory;
		HX_STACK_LINE(110)
		::String tmp18 = program;		HX_STACK_VAR(tmp18,"tmp18");
		HX_STACK_LINE(110)
		::String tmp19 = this->initialData;		HX_STACK_VAR(tmp19,"tmp19");
		HX_STACK_LINE(110)
		this->setInitialData(tmp18,tmp19);
		HX_STACK_LINE(111)
		this->alive = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(CPU_obj,init,(void))

bool CPU_obj::step( ){
	HX_STACK_FRAME("brainfuck.CPU","step",0x457fad93,"brainfuck.CPU.step","brainfuck/CPU.hx",128,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_LINE(129)
	bool tmp = this->alive;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(129)
	if ((tmp)){
		HX_STACK_LINE(130)
		int tmp1 = (this->ticks)++;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(130)
		tmp1;
		HX_STACK_LINE(131)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(132)
			bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(132)
			{
				HX_STACK_LINE(132)
				int tmp3 = this->ticks;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(132)
				int a = tmp3;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(132)
				int tmp4 = this->maxStep;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(132)
				int b = tmp4;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(132)
				bool tmp5 = (a < (int)0);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(132)
				bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
				HX_STACK_LINE(132)
				bool tmp6 = (b < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(132)
				bool bNeg = tmp6;		HX_STACK_VAR(bNeg,"bNeg");
				HX_STACK_LINE(132)
				bool tmp7 = (aNeg != bNeg);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(132)
				if ((tmp7)){
					HX_STACK_LINE(132)
					tmp2 = aNeg;
				}
				else{
					HX_STACK_LINE(132)
					tmp2 = (a >= b);
				}
			}
			HX_STACK_LINE(132)
			if ((tmp2)){
				HX_STACK_LINE(133)
				::brainfuck::BfInfiniteLoop tmp3 = ::brainfuck::BfInfiniteLoop_obj::__new();		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(133)
				HX_STACK_DO_THROW(tmp3);
			}
			HX_STACK_LINE(136)
			int tmp3 = this->programPosition;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(136)
			bool tmp4;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(136)
			{
				HX_STACK_LINE(136)
				Dynamic tmp5 = this->programType;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(136)
				int a = tmp5;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(136)
				{
					HX_STACK_LINE(136)
					bool tmp6 = ((int)2 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(136)
					bool aNeg = tmp6;		HX_STACK_VAR(aNeg,"aNeg");
					HX_STACK_LINE(136)
					bool tmp7 = (a < (int)0);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(136)
					bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
					HX_STACK_LINE(136)
					bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(136)
					if ((tmp8)){
						HX_STACK_LINE(136)
						tmp4 = aNeg;
					}
					else{
						HX_STACK_LINE(136)
						tmp4 = ((int)2 > a);
					}
				}
			}
			HX_STACK_LINE(136)
			int tmp5;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(136)
			if ((tmp4)){
				HX_STACK_LINE(136)
				::String tmp6 = this->program;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(136)
				tmp5 = tmp6.length;
			}
			else{
				HX_STACK_LINE(136)
				::haxe::io::ArrayBufferViewImpl tmp6 = this->memory;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(136)
				tmp5 = tmp6->byteLength;
			}
			HX_STACK_LINE(136)
			bool tmp6 = (tmp3 >= tmp5);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(136)
			if ((tmp6)){
				HX_STACK_LINE(137)
				::brainfuck::BfEnd tmp7 = ::brainfuck::BfEnd_obj::__new();		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(137)
				HX_STACK_DO_THROW(tmp7);
			}
			HX_STACK_LINE(140)
			bool tmp7;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(140)
			{
				HX_STACK_LINE(140)
				Dynamic tmp8 = this->programType;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(140)
				int a = tmp8;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(140)
				{
					HX_STACK_LINE(140)
					bool tmp9 = ((int)2 < (int)0);		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(140)
					bool aNeg = tmp9;		HX_STACK_VAR(aNeg,"aNeg");
					HX_STACK_LINE(140)
					bool tmp10 = (a < (int)0);		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(140)
					bool bNeg = tmp10;		HX_STACK_VAR(bNeg,"bNeg");
					HX_STACK_LINE(140)
					bool tmp11 = (aNeg != bNeg);		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(140)
					if ((tmp11)){
						HX_STACK_LINE(140)
						tmp7 = aNeg;
					}
					else{
						HX_STACK_LINE(140)
						tmp7 = ((int)2 > a);
					}
				}
			}
			HX_STACK_LINE(140)
			::String tmp8;		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(140)
			if ((tmp7)){
				HX_STACK_LINE(140)
				::String tmp9 = this->program;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(140)
				int tmp10 = this->programPosition;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(140)
				tmp8 = tmp9.charAt(tmp10);
			}
			else{
				HX_STACK_LINE(140)
				int tmp9;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(140)
				{
					HX_STACK_LINE(140)
					::haxe::io::ArrayBufferViewImpl tmp10 = this->memory;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(140)
					::haxe::io::ArrayBufferViewImpl this1 = tmp10;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(140)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(140)
					int tmp12 = this->programPosition;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(140)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(140)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(140)
					tmp9 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(140)
				tmp8 = ::String::fromCharCode(tmp9);
			}
			HX_STACK_LINE(140)
			bool tmp9 = this->runCommand(tmp8);		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(140)
			if ((tmp9)){
			}
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(144)
					this->alive = false;
					HX_STACK_LINE(145)
					Dynamic tmp2 = e;		HX_STACK_VAR(tmp2,"tmp2");
					HX_STACK_LINE(145)
					HX_STACK_DO_THROW(tmp2);
				}
			}
		}
	}
	HX_STACK_LINE(148)
	bool tmp1 = this->alive;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(148)
	return tmp1;
}


HX_DEFINE_DYNAMIC_FUNC0(CPU_obj,step,return )

::String CPU_obj::moveToNextCommand( ){
	HX_STACK_FRAME("brainfuck.CPU","moveToNextCommand",0x14ad9665,"brainfuck.CPU.moveToNextCommand","brainfuck/CPU.hx",151,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_LINE(152)
	++(this->programPosition);
	HX_STACK_LINE(153)
	bool tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(153)
	{
		HX_STACK_LINE(153)
		Dynamic tmp1 = this->programType;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(153)
		int a = tmp1;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(153)
		{
			HX_STACK_LINE(153)
			bool tmp2 = ((int)2 < (int)0);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(153)
			bool aNeg = tmp2;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(153)
			bool tmp3 = (a < (int)0);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(153)
			bool bNeg = tmp3;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(153)
			bool tmp4 = (aNeg != bNeg);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(153)
			if ((tmp4)){
				HX_STACK_LINE(153)
				tmp = aNeg;
			}
			else{
				HX_STACK_LINE(153)
				tmp = ((int)2 > a);
			}
		}
	}
	HX_STACK_LINE(153)
	::String tmp1;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(153)
	if ((tmp)){
		HX_STACK_LINE(154)
		int tmp2 = this->programPosition;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(154)
		::String tmp3 = this->program;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(154)
		int tmp4 = tmp3.length;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(154)
		bool tmp5 = (tmp2 < tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(154)
		if ((tmp5)){
			HX_STACK_LINE(154)
			::String tmp6 = this->program;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(154)
			int tmp7 = this->programPosition;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(154)
			tmp1 = tmp6.charAt(tmp7);
		}
		else{
			HX_STACK_LINE(154)
			tmp1 = null();
		}
	}
	else{
		HX_STACK_LINE(156)
		int tmp2 = this->programPosition;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(156)
		::haxe::io::ArrayBufferViewImpl tmp3 = this->memory;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(156)
		int tmp4 = tmp3->byteLength;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(156)
		bool tmp5 = (tmp2 < tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(156)
		if ((tmp5)){
			HX_STACK_LINE(156)
			int tmp6;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(156)
			{
				HX_STACK_LINE(156)
				::haxe::io::ArrayBufferViewImpl tmp7 = this->memory;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(156)
				::haxe::io::ArrayBufferViewImpl this1 = tmp7;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(156)
				::haxe::io::Bytes tmp8 = this1->bytes;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(156)
				int tmp9 = this->programPosition;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(156)
				int tmp10 = this1->byteOffset;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(156)
				int tmp11 = (tmp9 + tmp10);		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(156)
				tmp6 = tmp8->b->__get(tmp11);
			}
			HX_STACK_LINE(156)
			tmp1 = ::String::fromCharCode(tmp6);
		}
		else{
			HX_STACK_LINE(156)
			tmp1 = null();
		}
	}
	HX_STACK_LINE(153)
	return tmp1;
}


HX_DEFINE_DYNAMIC_FUNC0(CPU_obj,moveToNextCommand,return )

::String CPU_obj::moveToPrevCommand( ){
	HX_STACK_FRAME("brainfuck.CPU","moveToPrevCommand",0xa4ac9c65,"brainfuck.CPU.moveToPrevCommand","brainfuck/CPU.hx",159,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_LINE(160)
	--(this->programPosition);
	HX_STACK_LINE(161)
	bool tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(161)
	{
		HX_STACK_LINE(161)
		Dynamic tmp1 = this->programType;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(161)
		int a = tmp1;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(161)
		{
			HX_STACK_LINE(161)
			bool tmp2 = ((int)2 < (int)0);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(161)
			bool aNeg = tmp2;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(161)
			bool tmp3 = (a < (int)0);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(161)
			bool bNeg = tmp3;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(161)
			bool tmp4 = (aNeg != bNeg);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(161)
			if ((tmp4)){
				HX_STACK_LINE(161)
				tmp = aNeg;
			}
			else{
				HX_STACK_LINE(161)
				tmp = ((int)2 > a);
			}
		}
	}
	HX_STACK_LINE(161)
	::String tmp1;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(161)
	if ((tmp)){
		HX_STACK_LINE(162)
		int tmp2 = this->programPosition;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(162)
		bool tmp3 = (tmp2 < (int)0);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(162)
		if ((tmp3)){
			HX_STACK_LINE(162)
			tmp1 = null();
		}
		else{
			HX_STACK_LINE(162)
			::String tmp4 = this->program;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(162)
			int tmp5 = this->programPosition;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(162)
			tmp1 = tmp4.charAt(tmp5);
		}
	}
	else{
		HX_STACK_LINE(164)
		int tmp2 = this->programPosition;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(164)
		bool tmp3 = (tmp2 < (int)0);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(164)
		if ((tmp3)){
			HX_STACK_LINE(164)
			tmp1 = null();
		}
		else{
			HX_STACK_LINE(164)
			int tmp4;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(164)
			{
				HX_STACK_LINE(164)
				::haxe::io::ArrayBufferViewImpl tmp5 = this->memory;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(164)
				::haxe::io::ArrayBufferViewImpl this1 = tmp5;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(164)
				::haxe::io::Bytes tmp6 = this1->bytes;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(164)
				int tmp7 = this->programPosition;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(164)
				int tmp8 = this1->byteOffset;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(164)
				int tmp9 = (tmp7 + tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(164)
				tmp4 = tmp6->b->__get(tmp9);
			}
			HX_STACK_LINE(164)
			tmp1 = ::String::fromCharCode(tmp4);
		}
	}
	HX_STACK_LINE(161)
	return tmp1;
}


HX_DEFINE_DYNAMIC_FUNC0(CPU_obj,moveToPrevCommand,return )

bool CPU_obj::runCommand( ::String command){
	HX_STACK_FRAME("brainfuck.CPU","runCommand",0x039a36c7,"brainfuck.CPU.runCommand","brainfuck/CPU.hx",167,0xa331a858)
	HX_STACK_THIS(this)
	HX_STACK_ARG(command,"command")
	HX_STACK_LINE(168)
	::String tmp = command;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(168)
	::String _switch_1 = (tmp);
	if (  ( _switch_1==HX_HCSTRING(">","\x3e","\x00","\x00","\x00"))){
		HX_STACK_LINE(170)
		bool tmp1 = this->comment;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(170)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(170)
		if ((tmp2)){
			HX_STACK_LINE(171)
			(this->pointer)++;
		}
		HX_STACK_LINE(173)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("<","\x3c","\x00","\x00","\x00"))){
		HX_STACK_LINE(176)
		bool tmp1 = this->comment;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(176)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(176)
		if ((tmp2)){
			HX_STACK_LINE(177)
			(this->pointer)--;
			HX_STACK_LINE(178)
			int tmp3 = this->pointer;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(178)
			bool tmp4 = (tmp3 < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(178)
			if ((tmp4)){
				HX_STACK_LINE(179)
				this->pointer = (int)0;
			}
		}
		HX_STACK_LINE(182)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("+","\x2b","\x00","\x00","\x00"))){
		HX_STACK_LINE(185)
		bool tmp1 = this->comment;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(185)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(185)
		if ((tmp2)){
			HX_STACK_LINE(186)
			::brainfuck::Brainfuck tmp3 = this->bf;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(186)
			int tmp4 = this->pointer;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(186)
			Float tmp5 = this->id;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(186)
			tmp3->increment(tmp4,tmp5);
		}
		HX_STACK_LINE(188)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("-","\x2d","\x00","\x00","\x00"))){
		HX_STACK_LINE(191)
		bool tmp1 = this->comment;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(191)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(191)
		if ((tmp2)){
			HX_STACK_LINE(192)
			::brainfuck::Brainfuck tmp3 = this->bf;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(192)
			int tmp4 = this->pointer;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(192)
			Float tmp5 = this->id;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(192)
			tmp3->decrement(tmp4,tmp5);
		}
		HX_STACK_LINE(194)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING(".","\x2e","\x00","\x00","\x00"))){
		HX_STACK_LINE(197)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(198)
			::haxe::io::Output tmp1 = this->output;		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(198)
			int tmp2;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(198)
			{
				HX_STACK_LINE(198)
				::haxe::io::ArrayBufferViewImpl tmp3 = this->memory;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(198)
				::haxe::io::ArrayBufferViewImpl this1 = tmp3;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(198)
				::haxe::io::Bytes tmp4 = this1->bytes;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(198)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(198)
				int tmp6 = this1->byteOffset;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(198)
				int tmp7 = (tmp5 + tmp6);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(198)
				tmp2 = tmp4->b->__get(tmp7);
			}
			HX_STACK_LINE(198)
			tmp1->writeByte(tmp2);
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(200)
					::brainfuck::InvalidMemoryAccessError tmp1 = ::brainfuck::InvalidMemoryAccessError_obj::__new();		HX_STACK_VAR(tmp1,"tmp1");
					HX_STACK_LINE(200)
					HX_STACK_DO_THROW(tmp1);
				}
			}
		}
		HX_STACK_LINE(202)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING(",","\x2c","\x00","\x00","\x00"))){
		HX_STACK_LINE(205)
		int val;		HX_STACK_VAR(val,"val");
		HX_STACK_LINE(206)
		try
		{
		HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
		{
			HX_STACK_LINE(207)
			::haxe::io::Input tmp1 = this->input;		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(207)
			int tmp2 = tmp1->readByte();		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(207)
			val = tmp2;
		}
		}
		catch(Dynamic __e){
			if (__e.IsClass< ::haxe::io::Eof >() ){
				HX_STACK_BEGIN_CATCH
				::haxe::io::Eof e = __e;{
					HX_STACK_LINE(209)
					::brainfuck::EndOfInputError tmp1 = ::brainfuck::EndOfInputError_obj::__new();		HX_STACK_VAR(tmp1,"tmp1");
					HX_STACK_LINE(209)
					HX_STACK_DO_THROW(tmp1);
				}
			}
			else {
			    HX_STACK_DO_THROW(__e);
			}
		}
		HX_STACK_LINE(211)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(212)
			::haxe::io::ArrayBufferViewImpl tmp1 = this->memory;		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(212)
			::haxe::io::ArrayBufferViewImpl this1 = tmp1;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(212)
			int tmp2 = this->pointer;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(212)
			int index = tmp2;		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(212)
			bool tmp3 = (index >= (int)0);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(212)
			bool tmp4;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(212)
			if ((tmp3)){
				HX_STACK_LINE(212)
				int tmp5 = index;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(212)
				int tmp6 = this1->byteLength;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(212)
				int tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(212)
				tmp4 = (tmp5 < tmp7);
			}
			else{
				HX_STACK_LINE(212)
				tmp4 = false;
			}
			HX_STACK_LINE(212)
			if ((tmp4)){
				HX_STACK_LINE(212)
				{
					HX_STACK_LINE(212)
					::haxe::io::Bytes tmp5 = this1->bytes;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(212)
					int tmp6 = index;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(212)
					int tmp7 = this1->byteOffset;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(212)
					int tmp8 = (tmp6 + tmp7);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(212)
					int tmp9 = val;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(212)
					tmp5->b[tmp8] = tmp9;
				}
				HX_STACK_LINE(212)
				val;
			}
			else{
				HX_STACK_LINE(212)
				(int)0;
			}
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(214)
					::brainfuck::InvalidMemoryAccessError tmp1 = ::brainfuck::InvalidMemoryAccessError_obj::__new();		HX_STACK_VAR(tmp1,"tmp1");
					HX_STACK_LINE(214)
					HX_STACK_DO_THROW(tmp1);
				}
			}
		}
		HX_STACK_LINE(216)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("[","\x5b","\x00","\x00","\x00"))){
		HX_STACK_LINE(219)
		bool tmp1 = this->comment;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(219)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(219)
		if ((tmp2)){
			HX_STACK_LINE(220)
			int val;		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(221)
			int tmp3 = this->programPosition;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(221)
			int temp = tmp3;		HX_STACK_VAR(temp,"temp");
			HX_STACK_LINE(222)
			bool commentTemp = false;		HX_STACK_VAR(commentTemp,"commentTemp");
			HX_STACK_LINE(223)
			try
			{
			HX_STACK_CATCHABLE(Dynamic, 0);
			{
				HX_STACK_LINE(224)
				int tmp4;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(224)
				{
					HX_STACK_LINE(224)
					::haxe::io::ArrayBufferViewImpl tmp5 = this->memory;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(224)
					::haxe::io::ArrayBufferViewImpl this1 = tmp5;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(224)
					::haxe::io::Bytes tmp6 = this1->bytes;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(224)
					int tmp7 = this->pointer;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(224)
					int tmp8 = this1->byteOffset;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(224)
					int tmp9 = (tmp7 + tmp8);		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(224)
					tmp4 = tmp6->b->__get(tmp9);
				}
				HX_STACK_LINE(224)
				val = tmp4;
			}
			}
			catch(Dynamic __e){
				{
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(226)
						::brainfuck::InvalidMemoryAccessError tmp4 = ::brainfuck::InvalidMemoryAccessError_obj::__new();		HX_STACK_VAR(tmp4,"tmp4");
						HX_STACK_LINE(226)
						HX_STACK_DO_THROW(tmp4);
					}
				}
			}
			HX_STACK_LINE(228)
			bool tmp4 = (val == (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(228)
			if ((tmp4)){
				HX_STACK_LINE(229)
				int count = (int)1;		HX_STACK_VAR(count,"count");
				HX_STACK_LINE(230)
				::String tmp5 = this->moveToNextCommand();		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(230)
				::String c = tmp5;		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(231)
				while((true)){
					HX_STACK_LINE(232)
					bool tmp6 = (c == HX_HCSTRING("[","\x5b","\x00","\x00","\x00"));		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(232)
					bool tmp7;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(232)
					if ((tmp6)){
						HX_STACK_LINE(232)
						bool tmp8 = commentTemp;		HX_STACK_VAR(tmp8,"tmp8");
						HX_STACK_LINE(232)
						bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(232)
						tmp7 = !(tmp9);
					}
					else{
						HX_STACK_LINE(232)
						tmp7 = false;
					}
					HX_STACK_LINE(232)
					if ((tmp7)){
						HX_STACK_LINE(233)
						++(count);
					}
					else{
						HX_STACK_LINE(235)
						bool tmp8 = (c == HX_HCSTRING("]","\x5d","\x00","\x00","\x00"));		HX_STACK_VAR(tmp8,"tmp8");
						HX_STACK_LINE(235)
						bool tmp9;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(235)
						if ((tmp8)){
							HX_STACK_LINE(235)
							bool tmp10 = commentTemp;		HX_STACK_VAR(tmp10,"tmp10");
							HX_STACK_LINE(235)
							bool tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
							HX_STACK_LINE(235)
							tmp9 = !(tmp11);
						}
						else{
							HX_STACK_LINE(235)
							tmp9 = false;
						}
						HX_STACK_LINE(235)
						if ((tmp9)){
							HX_STACK_LINE(236)
							--(count);
						}
						else{
							HX_STACK_LINE(238)
							bool tmp10;		HX_STACK_VAR(tmp10,"tmp10");
							HX_STACK_LINE(238)
							{
								HX_STACK_LINE(238)
								Dynamic tmp11 = this->programType;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(238)
								Dynamic tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(238)
								int a = tmp12;		HX_STACK_VAR(a,"a");
								HX_STACK_LINE(238)
								bool tmp13 = (a < (int)0);		HX_STACK_VAR(tmp13,"tmp13");
								HX_STACK_LINE(238)
								bool tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
								HX_STACK_LINE(238)
								bool aNeg = tmp14;		HX_STACK_VAR(aNeg,"aNeg");
								HX_STACK_LINE(238)
								bool tmp15 = ((int)1 < (int)0);		HX_STACK_VAR(tmp15,"tmp15");
								HX_STACK_LINE(238)
								bool tmp16 = tmp15;		HX_STACK_VAR(tmp16,"tmp16");
								HX_STACK_LINE(238)
								bool bNeg = tmp16;		HX_STACK_VAR(bNeg,"bNeg");
								HX_STACK_LINE(238)
								bool tmp17 = (aNeg != bNeg);		HX_STACK_VAR(tmp17,"tmp17");
								HX_STACK_LINE(238)
								bool tmp18 = tmp17;		HX_STACK_VAR(tmp18,"tmp18");
								HX_STACK_LINE(238)
								bool tmp19 = tmp18;		HX_STACK_VAR(tmp19,"tmp19");
								HX_STACK_LINE(238)
								if ((tmp19)){
									HX_STACK_LINE(238)
									tmp10 = aNeg;
								}
								else{
									HX_STACK_LINE(238)
									tmp10 = (a >= (int)1);
								}
							}
							HX_STACK_LINE(238)
							bool tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
							HX_STACK_LINE(238)
							bool tmp12;		HX_STACK_VAR(tmp12,"tmp12");
							HX_STACK_LINE(238)
							if ((tmp11)){
								HX_STACK_LINE(238)
								tmp12 = (c == HX_HCSTRING("@","\x40","\x00","\x00","\x00"));
							}
							else{
								HX_STACK_LINE(238)
								tmp12 = false;
							}
							HX_STACK_LINE(238)
							bool tmp13;		HX_STACK_VAR(tmp13,"tmp13");
							HX_STACK_LINE(238)
							if ((tmp12)){
								HX_STACK_LINE(238)
								bool tmp14 = commentTemp;		HX_STACK_VAR(tmp14,"tmp14");
								HX_STACK_LINE(238)
								bool tmp15 = tmp14;		HX_STACK_VAR(tmp15,"tmp15");
								HX_STACK_LINE(238)
								tmp13 = !(tmp15);
							}
							else{
								HX_STACK_LINE(238)
								tmp13 = false;
							}
							HX_STACK_LINE(238)
							if ((tmp13)){
								HX_STACK_LINE(239)
								count = (int)0;
								HX_STACK_LINE(240)
								this->programPosition = temp;
							}
							else{
								HX_STACK_LINE(241)
								bool tmp14;		HX_STACK_VAR(tmp14,"tmp14");
								HX_STACK_LINE(241)
								{
									HX_STACK_LINE(241)
									Dynamic tmp15 = this->programType;		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(241)
									Dynamic tmp16 = tmp15;		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(241)
									int a = tmp16;		HX_STACK_VAR(a,"a");
									HX_STACK_LINE(241)
									bool tmp17 = (a < (int)0);		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(241)
									bool tmp18 = tmp17;		HX_STACK_VAR(tmp18,"tmp18");
									HX_STACK_LINE(241)
									bool aNeg = tmp18;		HX_STACK_VAR(aNeg,"aNeg");
									HX_STACK_LINE(241)
									bool tmp19 = ((int)3 < (int)0);		HX_STACK_VAR(tmp19,"tmp19");
									HX_STACK_LINE(241)
									bool tmp20 = tmp19;		HX_STACK_VAR(tmp20,"tmp20");
									HX_STACK_LINE(241)
									bool bNeg = tmp20;		HX_STACK_VAR(bNeg,"bNeg");
									HX_STACK_LINE(241)
									bool tmp21 = (aNeg != bNeg);		HX_STACK_VAR(tmp21,"tmp21");
									HX_STACK_LINE(241)
									bool tmp22 = tmp21;		HX_STACK_VAR(tmp22,"tmp22");
									HX_STACK_LINE(241)
									bool tmp23 = tmp22;		HX_STACK_VAR(tmp23,"tmp23");
									HX_STACK_LINE(241)
									if ((tmp23)){
										HX_STACK_LINE(241)
										tmp14 = aNeg;
									}
									else{
										HX_STACK_LINE(241)
										tmp14 = (a >= (int)3);
									}
								}
								HX_STACK_LINE(241)
								bool tmp15;		HX_STACK_VAR(tmp15,"tmp15");
								HX_STACK_LINE(241)
								if ((tmp14)){
									HX_STACK_LINE(241)
									tmp15 = (c == HX_HCSTRING("#","\x23","\x00","\x00","\x00"));
								}
								else{
									HX_STACK_LINE(241)
									tmp15 = false;
								}
								HX_STACK_LINE(241)
								if ((tmp15)){
									HX_STACK_LINE(242)
									bool tmp16 = commentTemp;		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(242)
									bool tmp17 = !(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(242)
									commentTemp = tmp17;
								}
							}
						}
					}
					HX_STACK_LINE(244)
					bool tmp8 = (count == (int)0);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(244)
					if ((tmp8)){
						HX_STACK_LINE(245)
						this->moveToNextCommand();
						HX_STACK_LINE(246)
						break;
					}
					HX_STACK_LINE(249)
					::String tmp9 = this->moveToNextCommand();		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(249)
					c = tmp9;
					HX_STACK_LINE(250)
					bool tmp10 = (c == null());		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(250)
					if ((tmp10)){
						HX_STACK_LINE(251)
						::brainfuck::EndOfProgramError tmp11 = ::brainfuck::EndOfProgramError_obj::__new();		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(251)
						HX_STACK_DO_THROW(tmp11);
					}
				}
			}
			else{
				HX_STACK_LINE(255)
				this->moveToNextCommand();
			}
		}
		else{
			HX_STACK_LINE(258)
			this->moveToNextCommand();
		}
	}
	else if (  ( _switch_1==HX_HCSTRING("]","\x5d","\x00","\x00","\x00"))){
		HX_STACK_LINE(262)
		bool tmp1 = this->comment;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(262)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(262)
		if ((tmp2)){
			HX_STACK_LINE(263)
			int val;		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(264)
			bool commentTemp = false;		HX_STACK_VAR(commentTemp,"commentTemp");
			HX_STACK_LINE(265)
			try
			{
			HX_STACK_CATCHABLE(Dynamic, 0);
			{
				HX_STACK_LINE(266)
				int tmp3;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(266)
				{
					HX_STACK_LINE(266)
					::haxe::io::ArrayBufferViewImpl tmp4 = this->memory;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(266)
					::haxe::io::ArrayBufferViewImpl this1 = tmp4;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(266)
					::haxe::io::Bytes tmp5 = this1->bytes;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(266)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(266)
					int tmp7 = this1->byteOffset;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(266)
					int tmp8 = (tmp6 + tmp7);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(266)
					tmp3 = tmp5->b->__get(tmp8);
				}
				HX_STACK_LINE(266)
				val = tmp3;
			}
			}
			catch(Dynamic __e){
				{
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(268)
						::brainfuck::InvalidMemoryAccessError tmp3 = ::brainfuck::InvalidMemoryAccessError_obj::__new();		HX_STACK_VAR(tmp3,"tmp3");
						HX_STACK_LINE(268)
						HX_STACK_DO_THROW(tmp3);
					}
				}
			}
			HX_STACK_LINE(271)
			bool tmp3 = (val > (int)0);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(271)
			if ((tmp3)){
				HX_STACK_LINE(272)
				int count = (int)1;		HX_STACK_VAR(count,"count");
				HX_STACK_LINE(273)
				::String tmp4 = this->moveToPrevCommand();		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(273)
				::String c = tmp4;		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(274)
				while((true)){
					HX_STACK_LINE(275)
					bool tmp5 = (c == HX_HCSTRING("[","\x5b","\x00","\x00","\x00"));		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(275)
					bool tmp6;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(275)
					if ((tmp5)){
						HX_STACK_LINE(275)
						bool tmp7 = commentTemp;		HX_STACK_VAR(tmp7,"tmp7");
						HX_STACK_LINE(275)
						bool tmp8 = tmp7;		HX_STACK_VAR(tmp8,"tmp8");
						HX_STACK_LINE(275)
						tmp6 = !(tmp8);
					}
					else{
						HX_STACK_LINE(275)
						tmp6 = false;
					}
					HX_STACK_LINE(275)
					if ((tmp6)){
						HX_STACK_LINE(276)
						--(count);
					}
					else{
						HX_STACK_LINE(277)
						bool tmp7 = (c == HX_HCSTRING("]","\x5d","\x00","\x00","\x00"));		HX_STACK_VAR(tmp7,"tmp7");
						HX_STACK_LINE(277)
						bool tmp8;		HX_STACK_VAR(tmp8,"tmp8");
						HX_STACK_LINE(277)
						if ((tmp7)){
							HX_STACK_LINE(277)
							bool tmp9 = commentTemp;		HX_STACK_VAR(tmp9,"tmp9");
							HX_STACK_LINE(277)
							bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
							HX_STACK_LINE(277)
							tmp8 = !(tmp10);
						}
						else{
							HX_STACK_LINE(277)
							tmp8 = false;
						}
						HX_STACK_LINE(277)
						if ((tmp8)){
							HX_STACK_LINE(278)
							++(count);
						}
						else{
							HX_STACK_LINE(279)
							bool tmp9;		HX_STACK_VAR(tmp9,"tmp9");
							HX_STACK_LINE(279)
							{
								HX_STACK_LINE(279)
								Dynamic tmp10 = this->programType;		HX_STACK_VAR(tmp10,"tmp10");
								HX_STACK_LINE(279)
								Dynamic tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(279)
								int a = tmp11;		HX_STACK_VAR(a,"a");
								HX_STACK_LINE(279)
								bool tmp12 = (a < (int)0);		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(279)
								bool tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
								HX_STACK_LINE(279)
								bool aNeg = tmp13;		HX_STACK_VAR(aNeg,"aNeg");
								HX_STACK_LINE(279)
								bool tmp14 = ((int)3 < (int)0);		HX_STACK_VAR(tmp14,"tmp14");
								HX_STACK_LINE(279)
								bool tmp15 = tmp14;		HX_STACK_VAR(tmp15,"tmp15");
								HX_STACK_LINE(279)
								bool bNeg = tmp15;		HX_STACK_VAR(bNeg,"bNeg");
								HX_STACK_LINE(279)
								bool tmp16 = (aNeg != bNeg);		HX_STACK_VAR(tmp16,"tmp16");
								HX_STACK_LINE(279)
								bool tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
								HX_STACK_LINE(279)
								bool tmp18 = tmp17;		HX_STACK_VAR(tmp18,"tmp18");
								HX_STACK_LINE(279)
								if ((tmp18)){
									HX_STACK_LINE(279)
									tmp9 = aNeg;
								}
								else{
									HX_STACK_LINE(279)
									tmp9 = (a >= (int)3);
								}
							}
							HX_STACK_LINE(279)
							bool tmp10;		HX_STACK_VAR(tmp10,"tmp10");
							HX_STACK_LINE(279)
							if ((tmp9)){
								HX_STACK_LINE(279)
								tmp10 = (c == HX_HCSTRING("#","\x23","\x00","\x00","\x00"));
							}
							else{
								HX_STACK_LINE(279)
								tmp10 = false;
							}
							HX_STACK_LINE(279)
							if ((tmp10)){
								HX_STACK_LINE(280)
								bool tmp11 = commentTemp;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(280)
								bool tmp12 = !(tmp11);		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(280)
								commentTemp = tmp12;
							}
						}
					}
					HX_STACK_LINE(282)
					bool tmp7 = (count == (int)0);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(282)
					if ((tmp7)){
						HX_STACK_LINE(283)
						break;
					}
					HX_STACK_LINE(285)
					::String tmp8 = this->moveToPrevCommand();		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(285)
					c = tmp8;
					HX_STACK_LINE(286)
					bool tmp9 = (c == null());		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(286)
					if ((tmp9)){
						HX_STACK_LINE(287)
						::brainfuck::EndOfProgramError tmp10 = ::brainfuck::EndOfProgramError_obj::__new();		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(287)
						HX_STACK_DO_THROW(tmp10);
					}
				}
			}
			else{
				HX_STACK_LINE(291)
				this->moveToNextCommand();
			}
		}
		else{
			HX_STACK_LINE(294)
			this->moveToNextCommand();
		}
	}
	else if (  ( _switch_1==HX_HCSTRING("@","\x40","\x00","\x00","\x00"))){
		HX_STACK_LINE(298)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(298)
		{
			HX_STACK_LINE(298)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(298)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(298)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(298)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(298)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(298)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(298)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(298)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(298)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(298)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(298)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(298)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(298)
			if ((tmp10)){
				HX_STACK_LINE(298)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(298)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(298)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(298)
		if ((tmp1)){
			HX_STACK_LINE(298)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(298)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(298)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(298)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(298)
			tmp2 = false;
		}
		HX_STACK_LINE(298)
		if ((tmp2)){
			HX_STACK_LINE(299)
			::brainfuck::BfEndAt tmp3 = ::brainfuck::BfEndAt_obj::__new();		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(299)
			HX_STACK_DO_THROW(tmp3);
		}
		HX_STACK_LINE(301)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("$","\x24","\x00","\x00","\x00"))){
		HX_STACK_LINE(304)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(304)
		{
			HX_STACK_LINE(304)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(304)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(304)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(304)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(304)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(304)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(304)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(304)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(304)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(304)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(304)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(304)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(304)
			if ((tmp10)){
				HX_STACK_LINE(304)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(304)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(304)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(304)
		if ((tmp1)){
			HX_STACK_LINE(304)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(304)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(304)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(304)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(304)
			tmp2 = false;
		}
		HX_STACK_LINE(304)
		if ((tmp2)){
			HX_STACK_LINE(305)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(305)
			{
				HX_STACK_LINE(305)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(305)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(305)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(305)
			if ((tmp3)){
				HX_STACK_LINE(306)
				bool tmp4;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(306)
				{
					HX_STACK_LINE(306)
					Dynamic tmp5 = this->programType;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(306)
					int a = tmp5;		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(306)
					bool tmp6 = (a < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(306)
					bool aNeg = tmp6;		HX_STACK_VAR(aNeg,"aNeg");
					HX_STACK_LINE(306)
					bool tmp7 = ((int)1 < (int)0);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(306)
					bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
					HX_STACK_LINE(306)
					bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(306)
					if ((tmp8)){
						HX_STACK_LINE(306)
						tmp4 = aNeg;
					}
					else{
						HX_STACK_LINE(306)
						tmp4 = (a > (int)1);
					}
				}
				HX_STACK_LINE(306)
				if ((tmp4)){
					HX_STACK_LINE(307)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(307)
					Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(307)
					int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(307)
					{
						HX_STACK_LINE(307)
						::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
						HX_STACK_LINE(307)
						::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(307)
						::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(307)
						int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(307)
						int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(307)
						int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(307)
						tmp7 = tmp9->b->__get(tmp12);
					}
					HX_STACK_LINE(307)
					tmp5->assign((int)0,tmp6,tmp7);
				}
				else{
					HX_STACK_LINE(309)
					::haxe::io::ArrayBufferViewImpl tmp5 = this->storage;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(309)
					::haxe::io::ArrayBufferViewImpl this1 = tmp5;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(309)
					int tmp6;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(309)
					{
						HX_STACK_LINE(309)
						::haxe::io::ArrayBufferViewImpl tmp7 = this->memory;		HX_STACK_VAR(tmp7,"tmp7");
						HX_STACK_LINE(309)
						::haxe::io::ArrayBufferViewImpl this2 = tmp7;		HX_STACK_VAR(this2,"this2");
						HX_STACK_LINE(309)
						::haxe::io::Bytes tmp8 = this2->bytes;		HX_STACK_VAR(tmp8,"tmp8");
						HX_STACK_LINE(309)
						int tmp9 = this->pointer;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(309)
						int tmp10 = this2->byteOffset;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(309)
						int tmp11 = (tmp9 + tmp10);		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(309)
						tmp6 = tmp8->b->__get(tmp11);
					}
					HX_STACK_LINE(309)
					int value = tmp6;		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(309)
					bool tmp7 = true;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(309)
					bool tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(309)
					if ((tmp7)){
						HX_STACK_LINE(309)
						int tmp9 = this1->byteLength;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(309)
						int tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(309)
						tmp8 = ((int)0 < tmp10);
					}
					else{
						HX_STACK_LINE(309)
						tmp8 = false;
					}
					HX_STACK_LINE(309)
					if ((tmp8)){
						HX_STACK_LINE(309)
						{
							HX_STACK_LINE(309)
							::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
							HX_STACK_LINE(309)
							int tmp10 = this1->byteOffset;		HX_STACK_VAR(tmp10,"tmp10");
							HX_STACK_LINE(309)
							int tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
							HX_STACK_LINE(309)
							int tmp12 = value;		HX_STACK_VAR(tmp12,"tmp12");
							HX_STACK_LINE(309)
							tmp9->b[tmp11] = tmp12;
						}
						HX_STACK_LINE(309)
						value;
					}
					else{
						HX_STACK_LINE(309)
						(int)0;
					}
				}
			}
			else{
				HX_STACK_LINE(312)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(312)
				Dynamic tmp5 = this->storagePointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(312)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(312)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(312)
				{
					HX_STACK_LINE(312)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(312)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(312)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(312)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(312)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(312)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(312)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(312)
				tmp4->assign(tmp5,tmp6,tmp7);
			}
		}
		HX_STACK_LINE(315)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("!","\x21","\x00","\x00","\x00"))){
		HX_STACK_LINE(318)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(318)
		{
			HX_STACK_LINE(318)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(318)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(318)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(318)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(318)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(318)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(318)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(318)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(318)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(318)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(318)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(318)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(318)
			if ((tmp10)){
				HX_STACK_LINE(318)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(318)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(318)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(318)
		if ((tmp1)){
			HX_STACK_LINE(318)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(318)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(318)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(318)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(318)
			tmp2 = false;
		}
		HX_STACK_LINE(318)
		if ((tmp2)){
			HX_STACK_LINE(319)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(319)
			{
				HX_STACK_LINE(319)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(319)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(319)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(319)
			if ((tmp3)){
				HX_STACK_LINE(320)
				bool tmp4;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(320)
				{
					HX_STACK_LINE(320)
					Dynamic tmp5 = this->programType;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(320)
					int a = tmp5;		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(320)
					bool tmp6 = (a < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(320)
					bool aNeg = tmp6;		HX_STACK_VAR(aNeg,"aNeg");
					HX_STACK_LINE(320)
					bool tmp7 = ((int)1 < (int)0);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(320)
					bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
					HX_STACK_LINE(320)
					bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(320)
					if ((tmp8)){
						HX_STACK_LINE(320)
						tmp4 = aNeg;
					}
					else{
						HX_STACK_LINE(320)
						tmp4 = (a > (int)1);
					}
				}
				HX_STACK_LINE(320)
				if ((tmp4)){
					HX_STACK_LINE(321)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(321)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(321)
					Float tmp7 = this->id;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(321)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(321)
					{
						HX_STACK_LINE(321)
						::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(321)
						::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(321)
						::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(321)
						int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(321)
						int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(321)
						tmp8 = tmp10->b->__get(tmp12);
					}
					HX_STACK_LINE(321)
					tmp5->assign(tmp6,tmp7,tmp8);
				}
				else{
					HX_STACK_LINE(323)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(323)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(323)
					Float tmp7 = this->id;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(323)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(323)
					{
						HX_STACK_LINE(323)
						::haxe::io::ArrayBufferViewImpl tmp9 = this->storage;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(323)
						::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(323)
						::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(323)
						int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(323)
						int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(323)
						tmp8 = tmp10->b->__get(tmp12);
					}
					HX_STACK_LINE(323)
					tmp5->assign(tmp6,tmp7,tmp8);
				}
			}
			else{
				HX_STACK_LINE(326)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(326)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(326)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(326)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(326)
				{
					HX_STACK_LINE(326)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(326)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(326)
					Dynamic tmp9 = this->storagePointer;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(326)
					int index = tmp9;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(326)
					::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(326)
					int tmp11 = index;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(326)
					int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(326)
					int tmp13 = (tmp11 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(326)
					tmp7 = tmp10->b->__get(tmp13);
				}
				HX_STACK_LINE(326)
				tmp4->assign(tmp5,tmp6,tmp7);
			}
		}
		HX_STACK_LINE(329)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("^","\x5e","\x00","\x00","\x00"))){
		HX_STACK_LINE(332)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(332)
		{
			HX_STACK_LINE(332)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(332)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(332)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(332)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(332)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(332)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(332)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(332)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(332)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(332)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(332)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(332)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(332)
			if ((tmp10)){
				HX_STACK_LINE(332)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(332)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(332)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(332)
		if ((tmp1)){
			HX_STACK_LINE(332)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(332)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(332)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(332)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(332)
			tmp2 = false;
		}
		HX_STACK_LINE(332)
		if ((tmp2)){
			HX_STACK_LINE(333)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(333)
			{
				HX_STACK_LINE(333)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(333)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(333)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(333)
			if ((tmp3)){
				HX_STACK_LINE(334)
				bool tmp4;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(334)
				{
					HX_STACK_LINE(334)
					Dynamic tmp5 = this->programType;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(334)
					int a = tmp5;		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(334)
					bool tmp6 = (a < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(334)
					bool aNeg = tmp6;		HX_STACK_VAR(aNeg,"aNeg");
					HX_STACK_LINE(334)
					bool tmp7 = ((int)1 < (int)0);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(334)
					bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
					HX_STACK_LINE(334)
					bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(334)
					if ((tmp8)){
						HX_STACK_LINE(334)
						tmp4 = aNeg;
					}
					else{
						HX_STACK_LINE(334)
						tmp4 = (a > (int)1);
					}
				}
				HX_STACK_LINE(334)
				if ((tmp4)){
					HX_STACK_LINE(335)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(335)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(335)
					Float tmp7 = this->id;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(335)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(335)
					{
						HX_STACK_LINE(335)
						::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(335)
						::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(335)
						::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(335)
						int tmp11 = this->pointer;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(335)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(335)
						int tmp13 = (tmp11 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(335)
						tmp8 = tmp10->b->__get(tmp13);
					}
					HX_STACK_LINE(335)
					int tmp9;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(335)
					{
						HX_STACK_LINE(335)
						::haxe::io::ArrayBufferViewImpl tmp10 = this->memory;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(335)
						::haxe::io::ArrayBufferViewImpl this1 = tmp10;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(335)
						::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(335)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(335)
						int tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(335)
						tmp9 = tmp11->b->__get(tmp13);
					}
					HX_STACK_LINE(335)
					int tmp10 = (int(tmp8) ^ int(tmp9));		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(335)
					tmp5->assign(tmp6,tmp7,tmp10);
				}
				else{
					HX_STACK_LINE(337)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(337)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(337)
					Float tmp7 = this->id;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(337)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(337)
					{
						HX_STACK_LINE(337)
						::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(337)
						::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(337)
						::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(337)
						int tmp11 = this->pointer;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(337)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(337)
						int tmp13 = (tmp11 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(337)
						tmp8 = tmp10->b->__get(tmp13);
					}
					HX_STACK_LINE(337)
					int tmp9;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(337)
					{
						HX_STACK_LINE(337)
						::haxe::io::ArrayBufferViewImpl tmp10 = this->storage;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(337)
						::haxe::io::ArrayBufferViewImpl this1 = tmp10;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(337)
						::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(337)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(337)
						int tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(337)
						tmp9 = tmp11->b->__get(tmp13);
					}
					HX_STACK_LINE(337)
					int tmp10 = (int(tmp8) ^ int(tmp9));		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(337)
					tmp5->assign(tmp6,tmp7,tmp10);
				}
			}
			else{
				HX_STACK_LINE(340)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(340)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(340)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(340)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(340)
				{
					HX_STACK_LINE(340)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(340)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(340)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(340)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(340)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(340)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(340)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(340)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(340)
				{
					HX_STACK_LINE(340)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(340)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(340)
					Dynamic tmp10 = this->storagePointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(340)
					int index = tmp10;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(340)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(340)
					int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(340)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(340)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(340)
					tmp8 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(340)
				int tmp9 = (int(tmp7) ^ int(tmp8));		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(340)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
		}
		HX_STACK_LINE(343)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("&","\x26","\x00","\x00","\x00"))){
		HX_STACK_LINE(345)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(345)
		{
			HX_STACK_LINE(345)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(345)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(345)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(345)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(345)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(345)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(345)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(345)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(345)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(345)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(345)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(345)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(345)
			if ((tmp10)){
				HX_STACK_LINE(345)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(345)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(345)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(345)
		if ((tmp1)){
			HX_STACK_LINE(345)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(345)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(345)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(345)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(345)
			tmp2 = false;
		}
		HX_STACK_LINE(345)
		if ((tmp2)){
			HX_STACK_LINE(346)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(346)
			{
				HX_STACK_LINE(346)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(346)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(346)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(346)
			if ((tmp3)){
				HX_STACK_LINE(347)
				bool tmp4;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(347)
				{
					HX_STACK_LINE(347)
					Dynamic tmp5 = this->programType;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(347)
					int a = tmp5;		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(347)
					bool tmp6 = (a < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(347)
					bool aNeg = tmp6;		HX_STACK_VAR(aNeg,"aNeg");
					HX_STACK_LINE(347)
					bool tmp7 = ((int)1 < (int)0);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(347)
					bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
					HX_STACK_LINE(347)
					bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(347)
					if ((tmp8)){
						HX_STACK_LINE(347)
						tmp4 = aNeg;
					}
					else{
						HX_STACK_LINE(347)
						tmp4 = (a > (int)1);
					}
				}
				HX_STACK_LINE(347)
				if ((tmp4)){
					HX_STACK_LINE(348)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(348)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(348)
					Float tmp7 = this->id;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(348)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(348)
					{
						HX_STACK_LINE(348)
						::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(348)
						::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(348)
						::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(348)
						int tmp11 = this->pointer;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(348)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(348)
						int tmp13 = (tmp11 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(348)
						tmp8 = tmp10->b->__get(tmp13);
					}
					HX_STACK_LINE(348)
					int tmp9;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(348)
					{
						HX_STACK_LINE(348)
						::haxe::io::ArrayBufferViewImpl tmp10 = this->memory;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(348)
						::haxe::io::ArrayBufferViewImpl this1 = tmp10;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(348)
						::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(348)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(348)
						int tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(348)
						tmp9 = tmp11->b->__get(tmp13);
					}
					HX_STACK_LINE(348)
					int tmp10 = (int(tmp8) & int(tmp9));		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(348)
					tmp5->assign(tmp6,tmp7,tmp10);
				}
				else{
					HX_STACK_LINE(350)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(350)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(350)
					Float tmp7 = this->id;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(350)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(350)
					{
						HX_STACK_LINE(350)
						::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(350)
						::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(350)
						::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(350)
						int tmp11 = this->pointer;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(350)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(350)
						int tmp13 = (tmp11 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(350)
						tmp8 = tmp10->b->__get(tmp13);
					}
					HX_STACK_LINE(350)
					int tmp9;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(350)
					{
						HX_STACK_LINE(350)
						::haxe::io::ArrayBufferViewImpl tmp10 = this->storage;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(350)
						::haxe::io::ArrayBufferViewImpl this1 = tmp10;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(350)
						::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(350)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(350)
						int tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(350)
						tmp9 = tmp11->b->__get(tmp13);
					}
					HX_STACK_LINE(350)
					int tmp10 = (int(tmp8) & int(tmp9));		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(350)
					tmp5->assign(tmp6,tmp7,tmp10);
				}
			}
			else{
				HX_STACK_LINE(353)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(353)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(353)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(353)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(353)
				{
					HX_STACK_LINE(353)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(353)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(353)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(353)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(353)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(353)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(353)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(353)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(353)
				{
					HX_STACK_LINE(353)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(353)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(353)
					Dynamic tmp10 = this->storagePointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(353)
					int index = tmp10;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(353)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(353)
					int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(353)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(353)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(353)
					tmp8 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(353)
				int tmp9 = (int(tmp7) & int(tmp8));		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(353)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
		}
		HX_STACK_LINE(356)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("|","\x7c","\x00","\x00","\x00"))){
		HX_STACK_LINE(358)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(358)
		{
			HX_STACK_LINE(358)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(358)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(358)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(358)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(358)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(358)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(358)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(358)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(358)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(358)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(358)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(358)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(358)
			if ((tmp10)){
				HX_STACK_LINE(358)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(358)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(358)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(358)
		if ((tmp1)){
			HX_STACK_LINE(358)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(358)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(358)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(358)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(358)
			tmp2 = false;
		}
		HX_STACK_LINE(358)
		if ((tmp2)){
			HX_STACK_LINE(359)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(359)
			{
				HX_STACK_LINE(359)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(359)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(359)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(359)
			if ((tmp3)){
				HX_STACK_LINE(360)
				bool tmp4;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(360)
				{
					HX_STACK_LINE(360)
					Dynamic tmp5 = this->programType;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(360)
					int a = tmp5;		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(360)
					bool tmp6 = (a < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(360)
					bool aNeg = tmp6;		HX_STACK_VAR(aNeg,"aNeg");
					HX_STACK_LINE(360)
					bool tmp7 = ((int)1 < (int)0);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(360)
					bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
					HX_STACK_LINE(360)
					bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(360)
					if ((tmp8)){
						HX_STACK_LINE(360)
						tmp4 = aNeg;
					}
					else{
						HX_STACK_LINE(360)
						tmp4 = (a > (int)1);
					}
				}
				HX_STACK_LINE(360)
				if ((tmp4)){
					HX_STACK_LINE(361)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(361)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(361)
					Float tmp7 = this->id;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(361)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(361)
					{
						HX_STACK_LINE(361)
						::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(361)
						::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(361)
						::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(361)
						int tmp11 = this->pointer;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(361)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(361)
						int tmp13 = (tmp11 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(361)
						tmp8 = tmp10->b->__get(tmp13);
					}
					HX_STACK_LINE(361)
					int tmp9;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(361)
					{
						HX_STACK_LINE(361)
						::haxe::io::ArrayBufferViewImpl tmp10 = this->memory;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(361)
						::haxe::io::ArrayBufferViewImpl this1 = tmp10;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(361)
						::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(361)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(361)
						int tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(361)
						tmp9 = tmp11->b->__get(tmp13);
					}
					HX_STACK_LINE(361)
					int tmp10 = (int(tmp8) | int(tmp9));		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(361)
					tmp5->assign(tmp6,tmp7,tmp10);
				}
				else{
					HX_STACK_LINE(363)
					::brainfuck::Brainfuck tmp5 = this->bf;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(363)
					int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(363)
					Float tmp7 = this->id;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(363)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(363)
					{
						HX_STACK_LINE(363)
						::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(363)
						::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(363)
						::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(363)
						int tmp11 = this->pointer;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(363)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(363)
						int tmp13 = (tmp11 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(363)
						tmp8 = tmp10->b->__get(tmp13);
					}
					HX_STACK_LINE(363)
					int tmp9;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(363)
					{
						HX_STACK_LINE(363)
						::haxe::io::ArrayBufferViewImpl tmp10 = this->storage;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(363)
						::haxe::io::ArrayBufferViewImpl this1 = tmp10;		HX_STACK_VAR(this1,"this1");
						HX_STACK_LINE(363)
						::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(363)
						int tmp12 = this1->byteOffset;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(363)
						int tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(363)
						tmp9 = tmp11->b->__get(tmp13);
					}
					HX_STACK_LINE(363)
					int tmp10 = (int(tmp8) | int(tmp9));		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(363)
					tmp5->assign(tmp6,tmp7,tmp10);
				}
			}
			else{
				HX_STACK_LINE(366)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(366)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(366)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(366)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(366)
				{
					HX_STACK_LINE(366)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(366)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(366)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(366)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(366)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(366)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(366)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(366)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(366)
				{
					HX_STACK_LINE(366)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(366)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(366)
					Dynamic tmp10 = this->storagePointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(366)
					int index = tmp10;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(366)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(366)
					int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(366)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(366)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(366)
					tmp8 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(366)
				int tmp9 = (int(tmp7) | int(tmp8));		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(366)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
		}
		HX_STACK_LINE(369)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("{","\x7b","\x00","\x00","\x00"))){
		HX_STACK_LINE(371)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(371)
		{
			HX_STACK_LINE(371)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(371)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(371)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(371)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(371)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(371)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(371)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(371)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(371)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(371)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(371)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(371)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(371)
			if ((tmp10)){
				HX_STACK_LINE(371)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(371)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(371)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(371)
		if ((tmp1)){
			HX_STACK_LINE(371)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(371)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(371)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(371)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(371)
			tmp2 = false;
		}
		HX_STACK_LINE(371)
		if ((tmp2)){
			HX_STACK_LINE(372)
			::brainfuck::Brainfuck tmp3 = this->bf;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(372)
			int tmp4 = this->pointer;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(372)
			Float tmp5 = this->id;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(372)
			int tmp6;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(372)
			{
				HX_STACK_LINE(372)
				::haxe::io::ArrayBufferViewImpl tmp7 = this->memory;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(372)
				::haxe::io::ArrayBufferViewImpl this1 = tmp7;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(372)
				::haxe::io::Bytes tmp8 = this1->bytes;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(372)
				int tmp9 = this->pointer;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(372)
				int tmp10 = this1->byteOffset;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(372)
				int tmp11 = (tmp9 + tmp10);		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(372)
				tmp6 = tmp8->b->__get(tmp11);
			}
			HX_STACK_LINE(372)
			int tmp7 = (int(tmp6) << int((int)1));		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(372)
			tmp3->assign(tmp4,tmp5,tmp7);
		}
		HX_STACK_LINE(374)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("}","\x7d","\x00","\x00","\x00"))){
		HX_STACK_LINE(376)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(376)
		{
			HX_STACK_LINE(376)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(376)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(376)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(376)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(376)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(376)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(376)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(376)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(376)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(376)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(376)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(376)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(376)
			if ((tmp10)){
				HX_STACK_LINE(376)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(376)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(376)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(376)
		if ((tmp1)){
			HX_STACK_LINE(376)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(376)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(376)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(376)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(376)
			tmp2 = false;
		}
		HX_STACK_LINE(376)
		if ((tmp2)){
			HX_STACK_LINE(377)
			::brainfuck::Brainfuck tmp3 = this->bf;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(377)
			int tmp4 = this->pointer;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(377)
			Float tmp5 = this->id;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(377)
			int tmp6;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(377)
			{
				HX_STACK_LINE(377)
				::haxe::io::ArrayBufferViewImpl tmp7 = this->memory;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(377)
				::haxe::io::ArrayBufferViewImpl this1 = tmp7;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(377)
				::haxe::io::Bytes tmp8 = this1->bytes;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(377)
				int tmp9 = this->pointer;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(377)
				int tmp10 = this1->byteOffset;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(377)
				int tmp11 = (tmp9 + tmp10);		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(377)
				tmp6 = tmp8->b->__get(tmp11);
			}
			HX_STACK_LINE(377)
			int tmp7 = (int(tmp6) >> int((int)1));		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(377)
			tmp3->assign(tmp4,tmp5,tmp7);
		}
		HX_STACK_LINE(379)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("~","\x7e","\x00","\x00","\x00"))){
		HX_STACK_LINE(381)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(381)
		{
			HX_STACK_LINE(381)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(381)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(381)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(381)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(381)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(381)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(381)
			bool tmp6 = ((int)1 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(381)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(381)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(381)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(381)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(381)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(381)
			if ((tmp10)){
				HX_STACK_LINE(381)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(381)
				tmp1 = (a >= (int)1);
			}
		}
		HX_STACK_LINE(381)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(381)
		if ((tmp1)){
			HX_STACK_LINE(381)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(381)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(381)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(381)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(381)
			tmp2 = false;
		}
		HX_STACK_LINE(381)
		if ((tmp2)){
			HX_STACK_LINE(382)
			::brainfuck::Brainfuck tmp3 = this->bf;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(382)
			int tmp4 = this->pointer;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(382)
			Float tmp5 = this->id;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(382)
			int tmp6;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(382)
			{
				HX_STACK_LINE(382)
				::haxe::io::ArrayBufferViewImpl tmp7 = this->memory;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(382)
				::haxe::io::ArrayBufferViewImpl this1 = tmp7;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(382)
				::haxe::io::Bytes tmp8 = this1->bytes;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(382)
				int tmp9 = this->pointer;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(382)
				int tmp10 = this1->byteOffset;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(382)
				int tmp11 = (tmp9 + tmp10);		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(382)
				tmp6 = tmp8->b->__get(tmp11);
			}
			HX_STACK_LINE(382)
			int tmp7 = ~(int)(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(382)
			tmp3->assign(tmp4,tmp5,tmp7);
		}
		HX_STACK_LINE(384)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("?","\x3f","\x00","\x00","\x00"))){
		HX_STACK_LINE(386)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(386)
		{
			HX_STACK_LINE(386)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(386)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(386)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(386)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(386)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(386)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(386)
			bool tmp6 = ((int)2 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(386)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(386)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(386)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(386)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(386)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(386)
			if ((tmp10)){
				HX_STACK_LINE(386)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(386)
				tmp1 = (a >= (int)2);
			}
		}
		HX_STACK_LINE(386)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(386)
		if ((tmp1)){
			HX_STACK_LINE(386)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(386)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(386)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(386)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(386)
			tmp2 = false;
		}
		HX_STACK_LINE(386)
		if ((tmp2)){
			HX_STACK_LINE(387)
			int tmp3 = this->pointer;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(387)
			this->programPosition = tmp3;
		}
		HX_STACK_LINE(389)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("*","\x2a","\x00","\x00","\x00"))){
		HX_STACK_LINE(391)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(391)
		{
			HX_STACK_LINE(391)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(391)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(391)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(391)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(391)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(391)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(391)
			bool tmp6 = ((int)2 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(391)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(391)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(391)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(391)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(391)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(391)
			if ((tmp10)){
				HX_STACK_LINE(391)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(391)
				tmp1 = (a >= (int)2);
			}
		}
		HX_STACK_LINE(391)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(391)
		if ((tmp1)){
			HX_STACK_LINE(391)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(391)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(391)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(391)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(391)
			tmp2 = false;
		}
		HX_STACK_LINE(391)
		if ((tmp2)){
			HX_STACK_LINE(392)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(392)
			{
				HX_STACK_LINE(392)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(392)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(392)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(392)
			if ((tmp3)){
				HX_STACK_LINE(393)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(393)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(393)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(393)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(393)
				{
					HX_STACK_LINE(393)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(393)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(393)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(393)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(393)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(393)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(393)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(393)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(393)
				{
					HX_STACK_LINE(393)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(393)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(393)
					::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(393)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(393)
					int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(393)
					tmp8 = tmp10->b->__get(tmp12);
				}
				HX_STACK_LINE(393)
				int tmp9 = (tmp7 * tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(393)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
			else{
				HX_STACK_LINE(395)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(395)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(395)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(395)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(395)
				{
					HX_STACK_LINE(395)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(395)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(395)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(395)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(395)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(395)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(395)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(395)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(395)
				{
					HX_STACK_LINE(395)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(395)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(395)
					Dynamic tmp10 = this->storagePointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(395)
					int index = tmp10;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(395)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(395)
					int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(395)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(395)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(395)
					tmp8 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(395)
				int tmp9 = (tmp7 * tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(395)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
		}
		HX_STACK_LINE(398)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("/","\x2f","\x00","\x00","\x00"))){
		HX_STACK_LINE(400)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(400)
		{
			HX_STACK_LINE(400)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(400)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(400)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(400)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(400)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(400)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(400)
			bool tmp6 = ((int)2 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(400)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(400)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(400)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(400)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(400)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(400)
			if ((tmp10)){
				HX_STACK_LINE(400)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(400)
				tmp1 = (a >= (int)2);
			}
		}
		HX_STACK_LINE(400)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(400)
		if ((tmp1)){
			HX_STACK_LINE(400)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(400)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(400)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(400)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(400)
			tmp2 = false;
		}
		HX_STACK_LINE(400)
		if ((tmp2)){
			HX_STACK_LINE(401)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(401)
			{
				HX_STACK_LINE(401)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(401)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(401)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(401)
			if ((tmp3)){
				HX_STACK_LINE(402)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(402)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(402)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(402)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(402)
				{
					HX_STACK_LINE(402)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(402)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(402)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(402)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(402)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(402)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(402)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(402)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(402)
				{
					HX_STACK_LINE(402)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(402)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(402)
					::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(402)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(402)
					int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(402)
					tmp8 = tmp10->b->__get(tmp12);
				}
				HX_STACK_LINE(402)
				Float tmp9 = (Float(tmp7) / Float(tmp8));		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(402)
				int tmp10 = ::Std_obj::_int(tmp9);		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(402)
				tmp4->assign(tmp5,tmp6,tmp10);
			}
			else{
				HX_STACK_LINE(404)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(404)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(404)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(404)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(404)
				{
					HX_STACK_LINE(404)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(404)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(404)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(404)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(404)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(404)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(404)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(404)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(404)
				{
					HX_STACK_LINE(404)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(404)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(404)
					Dynamic tmp10 = this->storagePointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(404)
					int index = tmp10;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(404)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(404)
					int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(404)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(404)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(404)
					tmp8 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(404)
				Float tmp9 = (Float(tmp7) / Float(tmp8));		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(404)
				int tmp10 = ::Std_obj::_int(tmp9);		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(404)
				tmp4->assign(tmp5,tmp6,tmp10);
			}
		}
		HX_STACK_LINE(407)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("=","\x3d","\x00","\x00","\x00"))){
		HX_STACK_LINE(409)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(409)
		{
			HX_STACK_LINE(409)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(409)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(409)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(409)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(409)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(409)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(409)
			bool tmp6 = ((int)2 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(409)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(409)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(409)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(409)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(409)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(409)
			if ((tmp10)){
				HX_STACK_LINE(409)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(409)
				tmp1 = (a >= (int)2);
			}
		}
		HX_STACK_LINE(409)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(409)
		if ((tmp1)){
			HX_STACK_LINE(409)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(409)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(409)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(409)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(409)
			tmp2 = false;
		}
		HX_STACK_LINE(409)
		if ((tmp2)){
			HX_STACK_LINE(410)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(410)
			{
				HX_STACK_LINE(410)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(410)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(410)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(410)
			if ((tmp3)){
				HX_STACK_LINE(411)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(411)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(411)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(411)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(411)
				{
					HX_STACK_LINE(411)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(411)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(411)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(411)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(411)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(411)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(411)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(411)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(411)
				{
					HX_STACK_LINE(411)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(411)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(411)
					::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(411)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(411)
					int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(411)
					tmp8 = tmp10->b->__get(tmp12);
				}
				HX_STACK_LINE(411)
				int tmp9 = (tmp7 + tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(411)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
			else{
				HX_STACK_LINE(413)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(413)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(413)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(413)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(413)
				{
					HX_STACK_LINE(413)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(413)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(413)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(413)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(413)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(413)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(413)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(413)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(413)
				{
					HX_STACK_LINE(413)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(413)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(413)
					Dynamic tmp10 = this->storagePointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(413)
					int index = tmp10;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(413)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(413)
					int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(413)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(413)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(413)
					tmp8 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(413)
				int tmp9 = (tmp7 + tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(413)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
		}
		HX_STACK_LINE(416)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("_","\x5f","\x00","\x00","\x00"))){
		HX_STACK_LINE(418)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(418)
		{
			HX_STACK_LINE(418)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(418)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(418)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(418)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(418)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(418)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(418)
			bool tmp6 = ((int)2 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(418)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(418)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(418)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(418)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(418)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(418)
			if ((tmp10)){
				HX_STACK_LINE(418)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(418)
				tmp1 = (a >= (int)2);
			}
		}
		HX_STACK_LINE(418)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(418)
		if ((tmp1)){
			HX_STACK_LINE(418)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(418)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(418)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(418)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(418)
			tmp2 = false;
		}
		HX_STACK_LINE(418)
		if ((tmp2)){
			HX_STACK_LINE(419)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(419)
			{
				HX_STACK_LINE(419)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(419)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(419)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(419)
			if ((tmp3)){
				HX_STACK_LINE(420)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(420)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(420)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(420)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(420)
				{
					HX_STACK_LINE(420)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(420)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(420)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(420)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(420)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(420)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(420)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(420)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(420)
				{
					HX_STACK_LINE(420)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(420)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(420)
					::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(420)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(420)
					int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(420)
					tmp8 = tmp10->b->__get(tmp12);
				}
				HX_STACK_LINE(420)
				int tmp9 = (tmp7 - tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(420)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
			else{
				HX_STACK_LINE(422)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(422)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(422)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(422)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(422)
				{
					HX_STACK_LINE(422)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(422)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(422)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(422)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(422)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(422)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(422)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(422)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(422)
				{
					HX_STACK_LINE(422)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(422)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(422)
					Dynamic tmp10 = this->storagePointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(422)
					int index = tmp10;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(422)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(422)
					int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(422)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(422)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(422)
					tmp8 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(422)
				int tmp9 = (tmp7 - tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(422)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
		}
		HX_STACK_LINE(425)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("%","\x25","\x00","\x00","\x00"))){
		HX_STACK_LINE(427)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(427)
		{
			HX_STACK_LINE(427)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(427)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(427)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(427)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(427)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(427)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(427)
			bool tmp6 = ((int)2 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(427)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(427)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(427)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(427)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(427)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(427)
			if ((tmp10)){
				HX_STACK_LINE(427)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(427)
				tmp1 = (a >= (int)2);
			}
		}
		HX_STACK_LINE(427)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(427)
		if ((tmp1)){
			HX_STACK_LINE(427)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(427)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(427)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(427)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(427)
			tmp2 = false;
		}
		HX_STACK_LINE(427)
		if ((tmp2)){
			HX_STACK_LINE(428)
			bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(428)
			{
				HX_STACK_LINE(428)
				Dynamic tmp4 = this->storagePointer;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(428)
				int a = tmp4;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(428)
				tmp3 = (a == null());
			}
			HX_STACK_LINE(428)
			if ((tmp3)){
				HX_STACK_LINE(429)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(429)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(429)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(429)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(429)
				{
					HX_STACK_LINE(429)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(429)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(429)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(429)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(429)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(429)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(429)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(429)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(429)
				{
					HX_STACK_LINE(429)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(429)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(429)
					::haxe::io::Bytes tmp10 = this1->bytes;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(429)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(429)
					int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(429)
					tmp8 = tmp10->b->__get(tmp12);
				}
				HX_STACK_LINE(429)
				int tmp9 = hx::Mod(tmp7,tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(429)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
			else{
				HX_STACK_LINE(431)
				::brainfuck::Brainfuck tmp4 = this->bf;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(431)
				int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(431)
				Float tmp6 = this->id;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(431)
				int tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(431)
				{
					HX_STACK_LINE(431)
					::haxe::io::ArrayBufferViewImpl tmp8 = this->memory;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(431)
					::haxe::io::ArrayBufferViewImpl this1 = tmp8;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(431)
					::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(431)
					int tmp10 = this->pointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(431)
					int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(431)
					int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(431)
					tmp7 = tmp9->b->__get(tmp12);
				}
				HX_STACK_LINE(431)
				int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(431)
				{
					HX_STACK_LINE(431)
					::haxe::io::ArrayBufferViewImpl tmp9 = this->memory;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(431)
					::haxe::io::ArrayBufferViewImpl this1 = tmp9;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(431)
					Dynamic tmp10 = this->storagePointer;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(431)
					int index = tmp10;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(431)
					::haxe::io::Bytes tmp11 = this1->bytes;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(431)
					int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(431)
					int tmp13 = this1->byteOffset;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(431)
					int tmp14 = (tmp12 + tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(431)
					tmp8 = tmp11->b->__get(tmp14);
				}
				HX_STACK_LINE(431)
				int tmp9 = hx::Mod(tmp7,tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(431)
				tmp4->assign(tmp5,tmp6,tmp9);
			}
		}
		HX_STACK_LINE(434)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING(":","\x3a","\x00","\x00","\x00"))){
		HX_STACK_LINE(439)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(439)
		{
			HX_STACK_LINE(439)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(439)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(439)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(439)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(439)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(439)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(439)
			bool tmp6 = ((int)3 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(439)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(439)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(439)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(439)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(439)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(439)
			if ((tmp10)){
				HX_STACK_LINE(439)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(439)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(439)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(439)
		if ((tmp1)){
			HX_STACK_LINE(439)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(439)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(439)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(439)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(439)
			tmp2 = false;
		}
		HX_STACK_LINE(439)
		if ((tmp2)){
			HX_STACK_LINE(440)
			int tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(440)
			{
				HX_STACK_LINE(440)
				::haxe::io::ArrayBufferViewImpl tmp4 = this->memory;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(440)
				::haxe::io::ArrayBufferViewImpl this1 = tmp4;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(440)
				::haxe::io::Bytes tmp5 = this1->bytes;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(440)
				int tmp6 = this->pointer;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(440)
				int tmp7 = this1->byteOffset;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(440)
				int tmp8 = (tmp6 + tmp7);		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(440)
				tmp3 = tmp5->b->__get(tmp8);
			}
			HX_STACK_LINE(440)
			int tmp4 = ((int)128 - tmp3);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(440)
			hx::AddEq(this->pointer,tmp4);
			HX_STACK_LINE(441)
			int tmp5 = this->pointer;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(441)
			bool tmp6 = (tmp5 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(441)
			if ((tmp6)){
				HX_STACK_LINE(442)
				this->pointer = (int)0;
			}
		}
		HX_STACK_LINE(445)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("x","\x78","\x00","\x00","\x00"))){
		HX_STACK_LINE(449)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(449)
		{
			HX_STACK_LINE(449)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(449)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(449)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(449)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(449)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(449)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(449)
			bool tmp6 = ((int)3 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(449)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(449)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(449)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(449)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(449)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(449)
			if ((tmp10)){
				HX_STACK_LINE(449)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(449)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(449)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(449)
		if ((tmp1)){
			HX_STACK_LINE(449)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(449)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(449)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(449)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(449)
			tmp2 = false;
		}
		HX_STACK_LINE(449)
		if ((tmp2)){
			HX_STACK_LINE(450)
			Dynamic tmp3 = this->xReturn->pop();		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(450)
			Dynamic xRet = tmp3;		HX_STACK_VAR(xRet,"xRet");
			HX_STACK_LINE(451)
			bool tmp4;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(451)
			{
				HX_STACK_LINE(451)
				int a = xRet;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(451)
				tmp4 = (a != null());
			}
			HX_STACK_LINE(451)
			int tmp5;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(451)
			if ((tmp4)){
				HX_STACK_LINE(451)
				tmp5 = xRet;
			}
			else{
				HX_STACK_LINE(451)
				::String tmp6 = this->program;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(451)
				int tmp7 = tmp6.length;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(451)
				tmp5 = (tmp7 + (int)1);
			}
			HX_STACK_LINE(451)
			this->pointer = tmp5;
		}
		HX_STACK_LINE(453)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("X","\x58","\x00","\x00","\x00"))){
		HX_STACK_LINE(455)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(455)
		{
			HX_STACK_LINE(455)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(455)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(455)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(455)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(455)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(455)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(455)
			bool tmp6 = ((int)3 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(455)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(455)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(455)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(455)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(455)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(455)
			if ((tmp10)){
				HX_STACK_LINE(455)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(455)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(455)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(455)
		if ((tmp1)){
			HX_STACK_LINE(455)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(455)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(455)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(455)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(455)
			tmp2 = false;
		}
		HX_STACK_LINE(455)
		if ((tmp2)){
			HX_STACK_LINE(456)
			int tmp3 = this->pointer;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(456)
			this->xReturn->push(tmp3);
			HX_STACK_LINE(457)
			int tmp4 = this->programPosition;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(457)
			this->pointer = tmp4;
		}
		HX_STACK_LINE(459)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("m","\x6d","\x00","\x00","\x00"))){
		HX_STACK_LINE(461)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(461)
		{
			HX_STACK_LINE(461)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(461)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(461)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(461)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(461)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(461)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(461)
			bool tmp6 = ((int)3 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(461)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(461)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(461)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(461)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(461)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(461)
			if ((tmp10)){
				HX_STACK_LINE(461)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(461)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(461)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(461)
		if ((tmp1)){
			HX_STACK_LINE(461)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(461)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(461)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(461)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(461)
			tmp2 = false;
		}
		HX_STACK_LINE(461)
		if ((tmp2)){
			HX_STACK_LINE(462)
			this->storagePointer = null();
		}
		HX_STACK_LINE(464)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("M","\x4d","\x00","\x00","\x00"))){
		HX_STACK_LINE(466)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(466)
		{
			HX_STACK_LINE(466)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(466)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(466)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(466)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(466)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(466)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(466)
			bool tmp6 = ((int)3 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(466)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(466)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(466)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(466)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(466)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(466)
			if ((tmp10)){
				HX_STACK_LINE(466)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(466)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(466)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(466)
		if ((tmp1)){
			HX_STACK_LINE(466)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(466)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(466)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(466)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(466)
			tmp2 = false;
		}
		HX_STACK_LINE(466)
		if ((tmp2)){
			HX_STACK_LINE(467)
			int tmp3 = this->pointer;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(467)
			this->storagePointer = tmp3;
		}
		HX_STACK_LINE(469)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("l","\x6c","\x00","\x00","\x00"))){
		HX_STACK_LINE(472)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(472)
		{
			HX_STACK_LINE(472)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(472)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(472)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(472)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(472)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(472)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(472)
			bool tmp6 = ((int)3 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(472)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(472)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(472)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(472)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(472)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(472)
			if ((tmp10)){
				HX_STACK_LINE(472)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(472)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(472)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(472)
		if ((tmp1)){
			HX_STACK_LINE(472)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(472)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(472)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(472)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(472)
			tmp2 = false;
		}
		HX_STACK_LINE(472)
		if ((tmp2)){
			HX_STACK_LINE(473)
			::brainfuck::Brainfuck tmp3 = this->bf;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(473)
			int tmp4 = this->pointer;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(473)
			Float tmp5 = this->id;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(473)
			tmp3->unlockCell(tmp4,tmp5);
		}
		HX_STACK_LINE(475)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("L","\x4c","\x00","\x00","\x00"))){
		HX_STACK_LINE(478)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(478)
		{
			HX_STACK_LINE(478)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(478)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(478)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(478)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(478)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(478)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(478)
			bool tmp6 = ((int)3 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(478)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(478)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(478)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(478)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(478)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(478)
			if ((tmp10)){
				HX_STACK_LINE(478)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(478)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(478)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(478)
		if ((tmp1)){
			HX_STACK_LINE(478)
			bool tmp3 = this->comment;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(478)
			bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(478)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(478)
			tmp2 = !(tmp5);
		}
		else{
			HX_STACK_LINE(478)
			tmp2 = false;
		}
		HX_STACK_LINE(478)
		if ((tmp2)){
			HX_STACK_LINE(479)
			::brainfuck::Brainfuck tmp3 = this->bf;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(479)
			int tmp4 = this->pointer;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(479)
			Float tmp5 = this->id;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(479)
			tmp3->lockCell(tmp4,tmp5);
		}
		HX_STACK_LINE(481)
		this->moveToNextCommand();
	}
	else if (  ( _switch_1==HX_HCSTRING("#","\x23","\x00","\x00","\x00"))){
		HX_STACK_LINE(484)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(484)
		{
			HX_STACK_LINE(484)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(484)
			int a = tmp2;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(484)
			bool tmp3 = (a < (int)0);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(484)
			bool aNeg = tmp3;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(484)
			bool tmp4 = ((int)3 < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(484)
			bool bNeg = tmp4;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(484)
			bool tmp5 = (aNeg != bNeg);		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(484)
			if ((tmp5)){
				HX_STACK_LINE(484)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(484)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(484)
		if ((tmp1)){
			HX_STACK_LINE(485)
			bool tmp2 = this->comment;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(485)
			bool tmp3 = !(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(485)
			this->comment = tmp3;
		}
		HX_STACK_LINE(487)
		this->moveToNextCommand();
	}
	else  {
		HX_STACK_LINE(492)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(492)
		{
			HX_STACK_LINE(492)
			Dynamic tmp2 = this->programType;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(492)
			Dynamic tmp3 = tmp2;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(492)
			int a = tmp3;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(492)
			bool tmp4 = (a < (int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(492)
			bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(492)
			bool aNeg = tmp5;		HX_STACK_VAR(aNeg,"aNeg");
			HX_STACK_LINE(492)
			bool tmp6 = ((int)3 < (int)0);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(492)
			bool tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(492)
			bool bNeg = tmp7;		HX_STACK_VAR(bNeg,"bNeg");
			HX_STACK_LINE(492)
			bool tmp8 = (aNeg != bNeg);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(492)
			bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(492)
			bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(492)
			if ((tmp10)){
				HX_STACK_LINE(492)
				tmp1 = aNeg;
			}
			else{
				HX_STACK_LINE(492)
				tmp1 = (a >= (int)3);
			}
		}
		HX_STACK_LINE(492)
		bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(492)
		if ((tmp1)){
			HX_STACK_LINE(492)
			::EReg tmp3 = ::EReg_obj::__new(HX_HCSTRING("[0-9A-F]","\xc4","\x63","\xf4","\x1b"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(492)
			::EReg tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(492)
			::String tmp5 = command;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(492)
			::String tmp6 = tmp5;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(492)
			tmp2 = tmp4->match(tmp6);
		}
		else{
			HX_STACK_LINE(492)
			tmp2 = false;
		}
		HX_STACK_LINE(492)
		if ((tmp2)){
			HX_STACK_LINE(493)
			::brainfuck::Brainfuck tmp3 = this->bf;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(493)
			int tmp4 = this->pointer;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(493)
			Float tmp5 = this->id;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(493)
			::String tmp6 = command;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(493)
			int tmp7 = HX_HCSTRING("0123456789ABCDEF","\x68","\x2a","\x58","\xa2").indexOf(tmp6,null());		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(493)
			int tmp8 = (tmp7 * (int)16);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(493)
			tmp3->assign(tmp4,tmp5,tmp8);
		}
		HX_STACK_LINE(495)
		this->moveToNextCommand();
		HX_STACK_LINE(496)
		return false;
	}
;
;
	HX_STACK_LINE(498)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(CPU_obj,runCommand,return )

::String CPU_obj::getProgramString( ::String program,int programType){
	HX_STACK_FRAME("brainfuck.CPU","getProgramString",0xe51ae0c6,"brainfuck.CPU.getProgramString","brainfuck/CPU.hx",53,0xa331a858)
	HX_STACK_ARG(program,"program")
	HX_STACK_ARG(programType,"programType")
	HX_STACK_LINE(54)
	::String prog = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(prog,"prog");
	HX_STACK_LINE(55)
	bool commentTemp = false;		HX_STACK_VAR(commentTemp,"commentTemp");
	HX_STACK_LINE(57)
	{
		HX_STACK_LINE(57)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(57)
		int _g = program.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		while((true)){
			HX_STACK_LINE(57)
			bool tmp = (_g1 < _g);		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(57)
			bool tmp1 = !(tmp);		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(57)
			if ((tmp1)){
				HX_STACK_LINE(57)
				break;
			}
			HX_STACK_LINE(57)
			int tmp2 = (_g1)++;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(57)
			int i = tmp2;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(58)
			int tmp3 = i;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(58)
			::String tmp4 = program.charAt(tmp3);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(58)
			hx::AddEq(prog,tmp4);
			HX_STACK_LINE(59)
			bool tmp5 = (programType >= (int)3);		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(59)
			bool tmp6;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(59)
			if ((tmp5)){
				HX_STACK_LINE(59)
				int tmp7 = i;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(59)
				int tmp8 = tmp7;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(59)
				::String tmp9 = program.charAt(tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(59)
				::String tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(59)
				tmp6 = (tmp10 == HX_HCSTRING("#","\x23","\x00","\x00","\x00"));
			}
			else{
				HX_STACK_LINE(59)
				tmp6 = false;
			}
			HX_STACK_LINE(59)
			if ((tmp6)){
				HX_STACK_LINE(60)
				bool tmp7 = commentTemp;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(60)
				bool tmp8 = !(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(60)
				commentTemp = tmp8;
			}
			else{
				HX_STACK_LINE(61)
				bool tmp7 = (programType >= (int)1);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(61)
				bool tmp8 = tmp7;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(61)
				bool tmp9;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(61)
				if ((tmp8)){
					HX_STACK_LINE(61)
					int tmp10 = i;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(61)
					int tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(61)
					int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(61)
					::String tmp13 = program.charAt(tmp12);		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(61)
					::String tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(61)
					::String tmp15 = tmp14;		HX_STACK_VAR(tmp15,"tmp15");
					HX_STACK_LINE(61)
					tmp9 = (tmp15 == HX_HCSTRING("@","\x40","\x00","\x00","\x00"));
				}
				else{
					HX_STACK_LINE(61)
					tmp9 = false;
				}
				HX_STACK_LINE(61)
				bool tmp10;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(61)
				if ((tmp9)){
					HX_STACK_LINE(61)
					bool tmp11 = commentTemp;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(61)
					bool tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(61)
					tmp10 = !(tmp12);
				}
				else{
					HX_STACK_LINE(61)
					tmp10 = false;
				}
				HX_STACK_LINE(61)
				if ((tmp10)){
					HX_STACK_LINE(62)
					break;
				}
			}
		}
	}
	HX_STACK_LINE(66)
	::String tmp = prog;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(66)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CPU_obj,getProgramString,return )

::String CPU_obj::getInitialData( ::String program,int programType){
	HX_STACK_FRAME("brainfuck.CPU","getInitialData",0x4dad7cdf,"brainfuck.CPU.getInitialData","brainfuck/CPU.hx",69,0xa331a858)
	HX_STACK_ARG(program,"program")
	HX_STACK_ARG(programType,"programType")
	HX_STACK_LINE(70)
	::String data = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(71)
	bool commentTemp = false;		HX_STACK_VAR(commentTemp,"commentTemp");
	HX_STACK_LINE(73)
	{
		HX_STACK_LINE(73)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(73)
		int _g = program.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(73)
		while((true)){
			HX_STACK_LINE(73)
			bool tmp = (_g1 < _g);		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(73)
			bool tmp1 = !(tmp);		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(73)
			if ((tmp1)){
				HX_STACK_LINE(73)
				break;
			}
			HX_STACK_LINE(73)
			int tmp2 = (_g1)++;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(73)
			int i = tmp2;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(74)
			int tmp3 = i;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(74)
			::String tmp4 = program.charAt(tmp3);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(74)
			bool tmp5 = (tmp4 == HX_HCSTRING("#","\x23","\x00","\x00","\x00"));		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(74)
			if ((tmp5)){
				HX_STACK_LINE(75)
				bool tmp6 = commentTemp;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(75)
				bool tmp7 = !(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(75)
				commentTemp = tmp7;
			}
			else{
				HX_STACK_LINE(76)
				int tmp6 = i;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(76)
				::String tmp7 = program.charAt(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(76)
				bool tmp8 = (tmp7 == HX_HCSTRING("@","\x40","\x00","\x00","\x00"));		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(76)
				bool tmp9;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(76)
				if ((tmp8)){
					HX_STACK_LINE(76)
					bool tmp10 = commentTemp;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(76)
					bool tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(76)
					tmp9 = !(tmp11);
				}
				else{
					HX_STACK_LINE(76)
					tmp9 = false;
				}
				HX_STACK_LINE(76)
				if ((tmp9)){
					HX_STACK_LINE(77)
					int tmp10 = (i + (int)1);		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(77)
					::String tmp11 = program.substr(tmp10,null());		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(77)
					data = tmp11;
				}
			}
		}
	}
	HX_STACK_LINE(81)
	::String tmp = data;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(81)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CPU_obj,getInitialData,return )


CPU_obj::CPU_obj()
{
}

void CPU_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CPU);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(maxStep,"maxStep");
	HX_MARK_MEMBER_NAME(pointer,"pointer");
	HX_MARK_MEMBER_NAME(storage,"storage");
	HX_MARK_MEMBER_NAME(storagePointer,"storagePointer");
	HX_MARK_MEMBER_NAME(program,"program");
	HX_MARK_MEMBER_NAME(programPosition,"programPosition");
	HX_MARK_MEMBER_NAME(programType,"programType");
	HX_MARK_MEMBER_NAME(jump,"jump");
	HX_MARK_MEMBER_NAME(comment,"comment");
	HX_MARK_MEMBER_NAME(ticks,"ticks");
	HX_MARK_MEMBER_NAME(xReturn,"xReturn");
	HX_MARK_MEMBER_NAME(input,"input");
	HX_MARK_MEMBER_NAME(output,"output");
	HX_MARK_MEMBER_NAME(memory,"memory");
	HX_MARK_MEMBER_NAME(initialData,"initialData");
	HX_MARK_MEMBER_NAME(bf,"bf");
	HX_MARK_MEMBER_NAME(alive,"alive");
	HX_MARK_END_CLASS();
}

void CPU_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(maxStep,"maxStep");
	HX_VISIT_MEMBER_NAME(pointer,"pointer");
	HX_VISIT_MEMBER_NAME(storage,"storage");
	HX_VISIT_MEMBER_NAME(storagePointer,"storagePointer");
	HX_VISIT_MEMBER_NAME(program,"program");
	HX_VISIT_MEMBER_NAME(programPosition,"programPosition");
	HX_VISIT_MEMBER_NAME(programType,"programType");
	HX_VISIT_MEMBER_NAME(jump,"jump");
	HX_VISIT_MEMBER_NAME(comment,"comment");
	HX_VISIT_MEMBER_NAME(ticks,"ticks");
	HX_VISIT_MEMBER_NAME(xReturn,"xReturn");
	HX_VISIT_MEMBER_NAME(input,"input");
	HX_VISIT_MEMBER_NAME(output,"output");
	HX_VISIT_MEMBER_NAME(memory,"memory");
	HX_VISIT_MEMBER_NAME(initialData,"initialData");
	HX_VISIT_MEMBER_NAME(bf,"bf");
	HX_VISIT_MEMBER_NAME(alive,"alive");
}

Dynamic CPU_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		if (HX_FIELD_EQ(inName,"bf") ) { return bf; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"jump") ) { return jump; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ticks") ) { return ticks; }
		if (HX_FIELD_EQ(inName,"input") ) { return input; }
		if (HX_FIELD_EQ(inName,"alive") ) { return alive; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { return output; }
		if (HX_FIELD_EQ(inName,"memory") ) { return memory; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"maxStep") ) { return maxStep; }
		if (HX_FIELD_EQ(inName,"pointer") ) { return pointer; }
		if (HX_FIELD_EQ(inName,"storage") ) { return storage; }
		if (HX_FIELD_EQ(inName,"program") ) { return program; }
		if (HX_FIELD_EQ(inName,"comment") ) { return comment; }
		if (HX_FIELD_EQ(inName,"xReturn") ) { return xReturn; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"runCommand") ) { return runCommand_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"programType") ) { return programType; }
		if (HX_FIELD_EQ(inName,"initialData") ) { return initialData; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"storagePointer") ) { return storagePointer; }
		if (HX_FIELD_EQ(inName,"getProgramType") ) { return getProgramType_dyn(); }
		if (HX_FIELD_EQ(inName,"setInitialData") ) { return setInitialData_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"programPosition") ) { return programPosition; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"moveToNextCommand") ) { return moveToNextCommand_dyn(); }
		if (HX_FIELD_EQ(inName,"moveToPrevCommand") ) { return moveToPrevCommand_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

bool CPU_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"getInitialData") ) { outValue = getInitialData_dyn(); return true;  }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getProgramString") ) { outValue = getProgramString_dyn(); return true;  }
	}
	return false;
}

Dynamic CPU_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bf") ) { bf=inValue.Cast< ::brainfuck::Brainfuck >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"jump") ) { jump=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ticks") ) { ticks=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"input") ) { input=inValue.Cast< ::haxe::io::Input >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alive") ) { alive=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { output=inValue.Cast< ::haxe::io::Output >(); return inValue; }
		if (HX_FIELD_EQ(inName,"memory") ) { memory=inValue.Cast< ::haxe::io::ArrayBufferViewImpl >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"maxStep") ) { maxStep=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pointer") ) { pointer=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"storage") ) { storage=inValue.Cast< ::haxe::io::ArrayBufferViewImpl >(); return inValue; }
		if (HX_FIELD_EQ(inName,"program") ) { program=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"comment") ) { comment=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xReturn") ) { xReturn=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"programType") ) { programType=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initialData") ) { initialData=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"storagePointer") ) { storagePointer=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"programPosition") ) { programPosition=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CPU_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("id","\xdb","\x5b","\x00","\x00"));
	outFields->push(HX_HCSTRING("maxStep","\x10","\x40","\x8c","\xcc"));
	outFields->push(HX_HCSTRING("pointer","\xbd","\xc0","\x21","\x51"));
	outFields->push(HX_HCSTRING("storage","\x3b","\xdf","\xa8","\x44"));
	outFields->push(HX_HCSTRING("storagePointer","\xc2","\x36","\xd4","\x5e"));
	outFields->push(HX_HCSTRING("program","\x84","\x4a","\xf9","\xf3"));
	outFields->push(HX_HCSTRING("programPosition","\x4d","\xcb","\x79","\x46"));
	outFields->push(HX_HCSTRING("programType","\x5e","\xfb","\x2c","\xc4"));
	outFields->push(HX_HCSTRING("jump","\xee","\xc4","\x69","\x46"));
	outFields->push(HX_HCSTRING("comment","\x5f","\x7a","\x70","\x81"));
	outFields->push(HX_HCSTRING("ticks","\x76","\x2e","\x2e","\x10"));
	outFields->push(HX_HCSTRING("xReturn","\x48","\xc3","\xd1","\xbb"));
	outFields->push(HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"));
	outFields->push(HX_HCSTRING("output","\x01","\x0f","\x81","\x0c"));
	outFields->push(HX_HCSTRING("memory","\x01","\xcb","\xbf","\x04"));
	outFields->push(HX_HCSTRING("initialData","\xce","\x24","\x88","\x1e"));
	outFields->push(HX_HCSTRING("bf","\xc4","\x55","\x00","\x00"));
	outFields->push(HX_HCSTRING("alive","\xcd","\x63","\x91","\x21"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(CPU_obj,id),HX_HCSTRING("id","\xdb","\x5b","\x00","\x00")},
	{hx::fsInt,(int)offsetof(CPU_obj,maxStep),HX_HCSTRING("maxStep","\x10","\x40","\x8c","\xcc")},
	{hx::fsInt,(int)offsetof(CPU_obj,pointer),HX_HCSTRING("pointer","\xbd","\xc0","\x21","\x51")},
	{hx::fsObject /*::haxe::io::ArrayBufferViewImpl*/ ,(int)offsetof(CPU_obj,storage),HX_HCSTRING("storage","\x3b","\xdf","\xa8","\x44")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CPU_obj,storagePointer),HX_HCSTRING("storagePointer","\xc2","\x36","\xd4","\x5e")},
	{hx::fsString,(int)offsetof(CPU_obj,program),HX_HCSTRING("program","\x84","\x4a","\xf9","\xf3")},
	{hx::fsInt,(int)offsetof(CPU_obj,programPosition),HX_HCSTRING("programPosition","\x4d","\xcb","\x79","\x46")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CPU_obj,programType),HX_HCSTRING("programType","\x5e","\xfb","\x2c","\xc4")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(CPU_obj,jump),HX_HCSTRING("jump","\xee","\xc4","\x69","\x46")},
	{hx::fsBool,(int)offsetof(CPU_obj,comment),HX_HCSTRING("comment","\x5f","\x7a","\x70","\x81")},
	{hx::fsInt,(int)offsetof(CPU_obj,ticks),HX_HCSTRING("ticks","\x76","\x2e","\x2e","\x10")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(CPU_obj,xReturn),HX_HCSTRING("xReturn","\x48","\xc3","\xd1","\xbb")},
	{hx::fsObject /*::haxe::io::Input*/ ,(int)offsetof(CPU_obj,input),HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe")},
	{hx::fsObject /*::haxe::io::Output*/ ,(int)offsetof(CPU_obj,output),HX_HCSTRING("output","\x01","\x0f","\x81","\x0c")},
	{hx::fsObject /*::haxe::io::ArrayBufferViewImpl*/ ,(int)offsetof(CPU_obj,memory),HX_HCSTRING("memory","\x01","\xcb","\xbf","\x04")},
	{hx::fsString,(int)offsetof(CPU_obj,initialData),HX_HCSTRING("initialData","\xce","\x24","\x88","\x1e")},
	{hx::fsObject /*::brainfuck::Brainfuck*/ ,(int)offsetof(CPU_obj,bf),HX_HCSTRING("bf","\xc4","\x55","\x00","\x00")},
	{hx::fsBool,(int)offsetof(CPU_obj,alive),HX_HCSTRING("alive","\xcd","\x63","\x91","\x21")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("id","\xdb","\x5b","\x00","\x00"),
	HX_HCSTRING("maxStep","\x10","\x40","\x8c","\xcc"),
	HX_HCSTRING("pointer","\xbd","\xc0","\x21","\x51"),
	HX_HCSTRING("storage","\x3b","\xdf","\xa8","\x44"),
	HX_HCSTRING("storagePointer","\xc2","\x36","\xd4","\x5e"),
	HX_HCSTRING("program","\x84","\x4a","\xf9","\xf3"),
	HX_HCSTRING("programPosition","\x4d","\xcb","\x79","\x46"),
	HX_HCSTRING("programType","\x5e","\xfb","\x2c","\xc4"),
	HX_HCSTRING("jump","\xee","\xc4","\x69","\x46"),
	HX_HCSTRING("comment","\x5f","\x7a","\x70","\x81"),
	HX_HCSTRING("ticks","\x76","\x2e","\x2e","\x10"),
	HX_HCSTRING("xReturn","\x48","\xc3","\xd1","\xbb"),
	HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"),
	HX_HCSTRING("output","\x01","\x0f","\x81","\x0c"),
	HX_HCSTRING("memory","\x01","\xcb","\xbf","\x04"),
	HX_HCSTRING("initialData","\xce","\x24","\x88","\x1e"),
	HX_HCSTRING("bf","\xc4","\x55","\x00","\x00"),
	HX_HCSTRING("alive","\xcd","\x63","\x91","\x21"),
	HX_HCSTRING("getProgramType","\x68","\x4e","\xcb","\x4b"),
	HX_HCSTRING("setInitialData","\x4c","\x60","\x46","\xc6"),
	HX_HCSTRING("init","\x10","\x3b","\xbb","\x45"),
	HX_HCSTRING("step","\x4c","\xe7","\x5b","\x4c"),
	HX_HCSTRING("moveToNextCommand","\x0c","\xfd","\x22","\x3b"),
	HX_HCSTRING("moveToPrevCommand","\x0c","\x03","\x22","\xcb"),
	HX_HCSTRING("runCommand","\x40","\x01","\xea","\xeb"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CPU_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CPU_obj::__mClass,"__mClass");
};

#endif

hx::Class CPU_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("getProgramString","\xff","\x4b","\x03","\x0a"),
	HX_HCSTRING("getInitialData","\xd8","\x77","\x26","\xa6"),
	::String(null()) };

void CPU_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.CPU","\x87","\x3f","\xb4","\x6c");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &CPU_obj::__GetStatic;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< CPU_obj >;
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

} // end namespace brainfuck
