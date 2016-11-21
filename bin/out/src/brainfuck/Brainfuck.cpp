#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_brainfuck_Brainfuck
#include <brainfuck/Brainfuck.h>
#endif
#ifndef INCLUDED_brainfuck_CPU
#include <brainfuck/CPU.h>
#endif
#ifndef INCLUDED_brainfuck_InvalidMemoryAccessError
#include <brainfuck/InvalidMemoryAccessError.h>
#endif
#ifndef INCLUDED_brainfuck_Lock
#include <brainfuck/Lock.h>
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

Void Brainfuck_obj::__construct(::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::haxe::io::ArrayBufferViewImpl memory)
{
HX_STACK_FRAME("brainfuck.Brainfuck","new",0xa51c19fe,"brainfuck.Brainfuck.new","brainfuck/Brainfuck.hx",16,0xf6222cb3)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_program,"program")
HX_STACK_ARG(type,"type")
HX_STACK_ARG(input,"input")
HX_STACK_ARG(output,"output")
HX_STACK_ARG(memory,"memory")
::String program = __o_program.Default(HX_HCSTRING("","\x00","\x00","\x00","\x00"));
{
	HX_STACK_LINE(22)
	this->cpu = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(21)
	this->lock = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(17)
	this->memorySize = (int)30000;
	HX_STACK_LINE(36)
	::String tmp = program;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(36)
	Dynamic tmp1 = type;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(36)
	::haxe::io::Input tmp2 = input;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(36)
	::haxe::io::Output tmp3 = output;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(36)
	::haxe::io::ArrayBufferViewImpl tmp4 = memory;		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(36)
	this->init(tmp,tmp1,tmp2,tmp3,tmp4);
}
;
	return null();
}

//Brainfuck_obj::~Brainfuck_obj() { }

Dynamic Brainfuck_obj::__CreateEmpty() { return  new Brainfuck_obj; }
hx::ObjectPtr< Brainfuck_obj > Brainfuck_obj::__new(::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::haxe::io::ArrayBufferViewImpl memory)
{  hx::ObjectPtr< Brainfuck_obj > _result_ = new Brainfuck_obj();
	_result_->__construct(__o_program,type,input,output,memory);
	return _result_;}

Dynamic Brainfuck_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Brainfuck_obj > _result_ = new Brainfuck_obj();
	_result_->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return _result_;}

::brainfuck::Brainfuck Brainfuck_obj::execute( ::String bfCode,Dynamic type){
	HX_STACK_FRAME("brainfuck.Brainfuck","execute",0xae7d7ad3,"brainfuck.Brainfuck.execute","brainfuck/Brainfuck.hx",24,0xf6222cb3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bfCode,"bfCode")
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(25)
	::String tmp = bfCode;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(25)
	Dynamic tmp1 = type;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(25)
	this->init(tmp,tmp1,null(),null(),null());
	HX_STACK_LINE(26)
	this->run();
	HX_STACK_LINE(27)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Brainfuck_obj,execute,return )

::String Brainfuck_obj::getOutput( ){
	HX_STACK_FRAME("brainfuck.Brainfuck","getOutput",0x3cbbec55,"brainfuck.Brainfuck.getOutput","brainfuck/Brainfuck.hx",31,0xf6222cb3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(32)
	::haxe::io::Output tmp = this->output;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(32)
	::haxe::io::BytesOutput tmp1;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(32)
	tmp1 = hx::TCast< ::haxe::io::BytesOutput >::cast(tmp);
	HX_STACK_LINE(32)
	::haxe::io::Bytes tmp2 = tmp1->getBytes();		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(32)
	::String tmp3 = tmp2->toString();		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(32)
	return tmp3;
}


HX_DEFINE_DYNAMIC_FUNC0(Brainfuck_obj,getOutput,return )

::brainfuck::Brainfuck Brainfuck_obj::init( ::String __o_program,Dynamic type,::haxe::io::Input input,::haxe::io::Output output,::haxe::io::ArrayBufferViewImpl memory){
::String program = __o_program.Default(HX_HCSTRING("","\x00","\x00","\x00","\x00"));
	HX_STACK_FRAME("brainfuck.Brainfuck","init",0xd0335bb2,"brainfuck.Brainfuck.init","brainfuck/Brainfuck.hx",39,0xf6222cb3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(program,"program")
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(input,"input")
	HX_STACK_ARG(output,"output")
	HX_STACK_ARG(memory,"memory")
{
		HX_STACK_LINE(40)
		bool tmp = (input == null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(40)
		::haxe::io::Input tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(40)
		if ((tmp)){
			HX_STACK_LINE(40)
			tmp1 = ::haxe::io::StringInput_obj::__new(HX_HCSTRING("","\x00","\x00","\x00","\x00"));
		}
		else{
			HX_STACK_LINE(40)
			tmp1 = input;
		}
		HX_STACK_LINE(40)
		this->input = tmp1;
		HX_STACK_LINE(41)
		bool tmp2 = (output == null());		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(41)
		::haxe::io::Output tmp3;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(41)
		if ((tmp2)){
			HX_STACK_LINE(41)
			tmp3 = ::haxe::io::BytesOutput_obj::__new();
		}
		else{
			HX_STACK_LINE(41)
			tmp3 = output;
		}
		HX_STACK_LINE(41)
		this->output = tmp3;
		HX_STACK_LINE(42)
		bool tmp4 = (memory == null());		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(42)
		::haxe::io::ArrayBufferViewImpl tmp5;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(42)
		if ((tmp4)){
			HX_STACK_LINE(42)
			int tmp6 = this->memorySize;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(42)
			int elements = tmp6;		HX_STACK_VAR(elements,"elements");
			HX_STACK_LINE(42)
			::haxe::io::ArrayBufferViewImpl this1;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(42)
			::haxe::io::ArrayBufferViewImpl tmp7;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(42)
			{
				HX_STACK_LINE(42)
				::haxe::io::ArrayBufferViewImpl tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(42)
				{
					HX_STACK_LINE(42)
					::haxe::io::ArrayBufferViewImpl this2;		HX_STACK_VAR(this2,"this2");
					HX_STACK_LINE(42)
					int tmp9 = elements;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(42)
					::haxe::io::Bytes tmp10 = ::haxe::io::Bytes_obj::alloc(tmp9);		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(42)
					int tmp11 = elements;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(42)
					::haxe::io::ArrayBufferViewImpl tmp12 = ::haxe::io::ArrayBufferViewImpl_obj::__new(tmp10,(int)0,tmp11);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(42)
					this2 = tmp12;
					HX_STACK_LINE(42)
					tmp8 = this2;
				}
				HX_STACK_LINE(42)
				::haxe::io::ArrayBufferViewImpl this2 = tmp8;		HX_STACK_VAR(this2,"this2");
				HX_STACK_LINE(42)
				tmp7 = this2;
			}
			HX_STACK_LINE(42)
			this1 = tmp7;
			HX_STACK_LINE(42)
			tmp5 = this1;
		}
		else{
			HX_STACK_LINE(42)
			tmp5 = memory;
		}
		HX_STACK_LINE(42)
		this->memory = tmp5;
		HX_STACK_LINE(43)
		int tmp6 = this->lock->length;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(43)
		this->lock->splice((int)0,tmp6);
		HX_STACK_LINE(44)
		::String tmp7 = program;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(44)
		Dynamic tmp8 = type;		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(44)
		::haxe::io::Input tmp9 = this->input;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(44)
		::haxe::io::Output tmp10 = this->output;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(44)
		::brainfuck::CPU tmp11 = ::brainfuck::CPU_obj::__new(tmp7,tmp8,tmp9,tmp10,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(44)
		this->cpu->push(tmp11);
		HX_STACK_LINE(46)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC5(Brainfuck_obj,init,return )

::brainfuck::Brainfuck Brainfuck_obj::run( ){
	HX_STACK_FRAME("brainfuck.Brainfuck","run",0xa51f30e9,"brainfuck.Brainfuck.run","brainfuck/Brainfuck.hx",59,0xf6222cb3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(60)
	while((true)){
		HX_STACK_LINE(61)
		bool allDead = true;		HX_STACK_VAR(allDead,"allDead");
		HX_STACK_LINE(62)
		{
			HX_STACK_LINE(62)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(62)
			int tmp = this->cpu->length;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(62)
			int _g = tmp;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(62)
			while((true)){
				HX_STACK_LINE(62)
				bool tmp1 = (_g1 < _g);		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(62)
				bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(62)
				if ((tmp2)){
					HX_STACK_LINE(62)
					break;
				}
				HX_STACK_LINE(62)
				int tmp3 = (_g1)++;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(62)
				int c = tmp3;		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(63)
				::brainfuck::CPU tmp4 = this->cpu->__get(c).StaticCast< ::brainfuck::CPU >();		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(63)
				bool tmp5 = tmp4->alive;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(63)
				if ((tmp5)){
					HX_STACK_LINE(64)
					allDead = false;
					HX_STACK_LINE(65)
					try
					{
					HX_STACK_CATCHABLE(Dynamic, 0);
					{
						HX_STACK_LINE(66)
						::brainfuck::CPU tmp6 = this->cpu->__get(c).StaticCast< ::brainfuck::CPU >();		HX_STACK_VAR(tmp6,"tmp6");
						HX_STACK_LINE(66)
						tmp6->step();
					}
					}
					catch(Dynamic __e){
						{
							HX_STACK_BEGIN_CATCH
							Dynamic e = __e;{
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(72)
		bool tmp = allDead;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(72)
		if ((tmp)){
			HX_STACK_LINE(72)
			break;
		}
	}
	HX_STACK_LINE(75)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Brainfuck_obj,run,return )

bool Brainfuck_obj::isLocked( int pointer){
	HX_STACK_FRAME("brainfuck.Brainfuck","isLocked",0xf222ba36,"brainfuck.Brainfuck.isLocked","brainfuck/Brainfuck.hx",78,0xf6222cb3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(pointer,"pointer")
	HX_STACK_LINE(79)
	{
		HX_STACK_LINE(79)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(79)
		int tmp = this->lock->length;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(79)
		int _g = tmp;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(79)
		while((true)){
			HX_STACK_LINE(79)
			bool tmp1 = (_g1 < _g);		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(79)
			bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(79)
			if ((tmp2)){
				HX_STACK_LINE(79)
				break;
			}
			HX_STACK_LINE(79)
			int tmp3 = (_g1)++;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(79)
			int l = tmp3;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(80)
			::brainfuck::Lock tmp4 = this->lock->__get(l).StaticCast< ::brainfuck::Lock >();		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(80)
			int tmp5 = tmp4->position;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(80)
			int tmp6 = pointer;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(80)
			bool tmp7 = (tmp5 == tmp6);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(80)
			if ((tmp7)){
				HX_STACK_LINE(81)
				return true;
			}
		}
	}
	HX_STACK_LINE(84)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Brainfuck_obj,isLocked,return )

bool Brainfuck_obj::lockCell( int pointer,Float id){
	HX_STACK_FRAME("brainfuck.Brainfuck","lockCell",0xc6d3d4cf,"brainfuck.Brainfuck.lockCell","brainfuck/Brainfuck.hx",87,0xf6222cb3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(pointer,"pointer")
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(88)
	{
		HX_STACK_LINE(88)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(88)
		int tmp = this->lock->length;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(88)
		int _g = tmp;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(88)
		while((true)){
			HX_STACK_LINE(88)
			bool tmp1 = (_g1 < _g);		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(88)
			bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(88)
			if ((tmp2)){
				HX_STACK_LINE(88)
				break;
			}
			HX_STACK_LINE(88)
			int tmp3 = (_g1)++;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(88)
			int l = tmp3;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(89)
			::brainfuck::Lock tmp4 = this->lock->__get(l).StaticCast< ::brainfuck::Lock >();		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(89)
			int tmp5 = tmp4->position;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(89)
			int tmp6 = pointer;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(89)
			bool tmp7 = (tmp5 == tmp6);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(89)
			if ((tmp7)){
				HX_STACK_LINE(90)
				return false;
			}
		}
	}
	HX_STACK_LINE(93)
	::brainfuck::Lock tmp = ::brainfuck::Lock_obj::__new(pointer,id);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(93)
	this->lock->push(tmp);
	HX_STACK_LINE(94)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(Brainfuck_obj,lockCell,return )

Void Brainfuck_obj::unlockCell( int pointer,Float id){
{
		HX_STACK_FRAME("brainfuck.Brainfuck","unlockCell",0xc08ae8a8,"brainfuck.Brainfuck.unlockCell","brainfuck/Brainfuck.hx",98,0xf6222cb3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(pointer,"pointer")
		HX_STACK_ARG(id,"id")
		HX_STACK_LINE(98)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(98)
		int tmp = this->lock->length;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(98)
		int _g = tmp;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(98)
		while((true)){
			HX_STACK_LINE(98)
			bool tmp1 = (_g1 < _g);		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(98)
			bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(98)
			if ((tmp2)){
				HX_STACK_LINE(98)
				break;
			}
			HX_STACK_LINE(98)
			int tmp3 = (_g1)++;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(98)
			int l = tmp3;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(99)
			::brainfuck::Lock tmp4 = this->lock->__get(l).StaticCast< ::brainfuck::Lock >();		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(99)
			int tmp5 = tmp4->position;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(99)
			int tmp6 = pointer;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(99)
			bool tmp7 = (tmp5 == tmp6);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(99)
			bool tmp8;		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(99)
			if ((tmp7)){
				HX_STACK_LINE(99)
				::brainfuck::Lock tmp9 = this->lock->__get(l).StaticCast< ::brainfuck::Lock >();		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(99)
				::brainfuck::Lock tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(99)
				Float tmp11 = tmp10->owner;		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(99)
				Float tmp12 = id;		HX_STACK_VAR(tmp12,"tmp12");
				HX_STACK_LINE(99)
				tmp8 = (tmp11 == tmp12);
			}
			else{
				HX_STACK_LINE(99)
				tmp8 = false;
			}
			HX_STACK_LINE(99)
			if ((tmp8)){
				HX_STACK_LINE(100)
				::brainfuck::Lock tmp9 = this->lock->__get(l).StaticCast< ::brainfuck::Lock >();		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(100)
				this->lock->remove(tmp9);
				HX_STACK_LINE(101)
				break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Brainfuck_obj,unlockCell,(void))

Void Brainfuck_obj::increment( int pointer,Float id){
{
		HX_STACK_FRAME("brainfuck.Brainfuck","increment",0xe5e35a4d,"brainfuck.Brainfuck.increment","brainfuck/Brainfuck.hx",115,0xf6222cb3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(pointer,"pointer")
		HX_STACK_ARG(id,"id")
		HX_STACK_LINE(116)
		int tmp = pointer;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(116)
		bool tmp1 = this->isLocked(tmp);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(116)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(116)
		if ((tmp2)){
			HX_STACK_LINE(117)
			try
			{
			HX_STACK_CATCHABLE(Dynamic, 0);
			{
				HX_STACK_LINE(118)
				::haxe::io::ArrayBufferViewImpl tmp3 = this->memory;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(118)
				::haxe::io::ArrayBufferViewImpl this1 = tmp3;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(118)
				int tmp4;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(118)
				{
					HX_STACK_LINE(118)
					::haxe::io::ArrayBufferViewImpl tmp5 = this->memory;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(118)
					::haxe::io::ArrayBufferViewImpl this2 = tmp5;		HX_STACK_VAR(this2,"this2");
					HX_STACK_LINE(118)
					::haxe::io::Bytes tmp6 = this2->bytes;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(118)
					int tmp7 = pointer;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(118)
					int tmp8 = this2->byteOffset;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(118)
					int tmp9 = (tmp7 + tmp8);		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(118)
					tmp4 = tmp6->b->__get(tmp9);
				}
				HX_STACK_LINE(118)
				int tmp5 = (tmp4 + (int)1);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(118)
				int tmp6 = ::Std_obj::_int(tmp5);		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(118)
				int value = tmp6;		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(118)
				bool tmp7 = (pointer >= (int)0);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(118)
				bool tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(118)
				if ((tmp7)){
					HX_STACK_LINE(118)
					int tmp9 = pointer;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(118)
					int tmp10 = this1->byteLength;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(118)
					int tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(118)
					tmp8 = (tmp9 < tmp11);
				}
				else{
					HX_STACK_LINE(118)
					tmp8 = false;
				}
				HX_STACK_LINE(118)
				if ((tmp8)){
					HX_STACK_LINE(118)
					{
						HX_STACK_LINE(118)
						::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(118)
						int tmp10 = pointer;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(118)
						int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(118)
						int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(118)
						int tmp13 = value;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(118)
						tmp9->b[tmp12] = tmp13;
					}
					HX_STACK_LINE(118)
					value;
				}
				else{
					HX_STACK_LINE(118)
					(int)0;
				}
			}
			}
			catch(Dynamic __e){
				{
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(120)
						::brainfuck::InvalidMemoryAccessError tmp3 = ::brainfuck::InvalidMemoryAccessError_obj::__new();		HX_STACK_VAR(tmp3,"tmp3");
						HX_STACK_LINE(120)
						HX_STACK_DO_THROW(tmp3);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Brainfuck_obj,increment,(void))

Void Brainfuck_obj::decrement( int pointer,Float id){
{
		HX_STACK_FRAME("brainfuck.Brainfuck","decrement",0xc4664a31,"brainfuck.Brainfuck.decrement","brainfuck/Brainfuck.hx",125,0xf6222cb3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(pointer,"pointer")
		HX_STACK_ARG(id,"id")
		HX_STACK_LINE(126)
		int tmp = pointer;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(126)
		bool tmp1 = this->isLocked(tmp);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(126)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(126)
		if ((tmp2)){
			HX_STACK_LINE(127)
			try
			{
			HX_STACK_CATCHABLE(Dynamic, 0);
			{
				HX_STACK_LINE(128)
				::haxe::io::ArrayBufferViewImpl tmp3 = this->memory;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(128)
				::haxe::io::ArrayBufferViewImpl this1 = tmp3;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(128)
				int tmp4;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(128)
				{
					HX_STACK_LINE(128)
					::haxe::io::ArrayBufferViewImpl tmp5 = this->memory;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(128)
					::haxe::io::ArrayBufferViewImpl this2 = tmp5;		HX_STACK_VAR(this2,"this2");
					HX_STACK_LINE(128)
					::haxe::io::Bytes tmp6 = this2->bytes;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(128)
					int tmp7 = pointer;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(128)
					int tmp8 = this2->byteOffset;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(128)
					int tmp9 = (tmp7 + tmp8);		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(128)
					tmp4 = tmp6->b->__get(tmp9);
				}
				HX_STACK_LINE(128)
				int tmp5 = (tmp4 - (int)1);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(128)
				int tmp6 = ::Std_obj::_int(tmp5);		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(128)
				int value = tmp6;		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(128)
				bool tmp7 = (pointer >= (int)0);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(128)
				bool tmp8;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(128)
				if ((tmp7)){
					HX_STACK_LINE(128)
					int tmp9 = pointer;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(128)
					int tmp10 = this1->byteLength;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(128)
					int tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(128)
					tmp8 = (tmp9 < tmp11);
				}
				else{
					HX_STACK_LINE(128)
					tmp8 = false;
				}
				HX_STACK_LINE(128)
				if ((tmp8)){
					HX_STACK_LINE(128)
					{
						HX_STACK_LINE(128)
						::haxe::io::Bytes tmp9 = this1->bytes;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(128)
						int tmp10 = pointer;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(128)
						int tmp11 = this1->byteOffset;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(128)
						int tmp12 = (tmp10 + tmp11);		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(128)
						int tmp13 = value;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(128)
						tmp9->b[tmp12] = tmp13;
					}
					HX_STACK_LINE(128)
					value;
				}
				else{
					HX_STACK_LINE(128)
					(int)0;
				}
			}
			}
			catch(Dynamic __e){
				{
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(130)
						::brainfuck::InvalidMemoryAccessError tmp3 = ::brainfuck::InvalidMemoryAccessError_obj::__new();		HX_STACK_VAR(tmp3,"tmp3");
						HX_STACK_LINE(130)
						HX_STACK_DO_THROW(tmp3);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Brainfuck_obj,decrement,(void))

Void Brainfuck_obj::assign( int pointer,Float id,int value){
{
		HX_STACK_FRAME("brainfuck.Brainfuck","assign",0x7d415351,"brainfuck.Brainfuck.assign","brainfuck/Brainfuck.hx",135,0xf6222cb3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(pointer,"pointer")
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(136)
		int tmp = pointer;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(136)
		bool tmp1 = this->isLocked(tmp);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(136)
		bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(136)
		if ((tmp2)){
			HX_STACK_LINE(137)
			try
			{
			HX_STACK_CATCHABLE(Dynamic, 0);
			{
				HX_STACK_LINE(138)
				::haxe::io::ArrayBufferViewImpl tmp3 = this->memory;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(138)
				::haxe::io::ArrayBufferViewImpl this1 = tmp3;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(138)
				bool tmp4 = (pointer >= (int)0);		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(138)
				bool tmp5;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(138)
				if ((tmp4)){
					HX_STACK_LINE(138)
					int tmp6 = pointer;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(138)
					int tmp7 = this1->byteLength;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(138)
					int tmp8 = tmp7;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(138)
					tmp5 = (tmp6 < tmp8);
				}
				else{
					HX_STACK_LINE(138)
					tmp5 = false;
				}
				HX_STACK_LINE(138)
				if ((tmp5)){
					HX_STACK_LINE(138)
					{
						HX_STACK_LINE(138)
						::haxe::io::Bytes tmp6 = this1->bytes;		HX_STACK_VAR(tmp6,"tmp6");
						HX_STACK_LINE(138)
						int tmp7 = pointer;		HX_STACK_VAR(tmp7,"tmp7");
						HX_STACK_LINE(138)
						int tmp8 = this1->byteOffset;		HX_STACK_VAR(tmp8,"tmp8");
						HX_STACK_LINE(138)
						int tmp9 = (tmp7 + tmp8);		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(138)
						int tmp10 = value;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(138)
						tmp6->b[tmp9] = tmp10;
					}
					HX_STACK_LINE(138)
					value;
				}
				else{
					HX_STACK_LINE(138)
					(int)0;
				}
			}
			}
			catch(Dynamic __e){
				{
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(140)
						::brainfuck::InvalidMemoryAccessError tmp3 = ::brainfuck::InvalidMemoryAccessError_obj::__new();		HX_STACK_VAR(tmp3,"tmp3");
						HX_STACK_LINE(140)
						HX_STACK_DO_THROW(tmp3);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Brainfuck_obj,assign,(void))


Brainfuck_obj::Brainfuck_obj()
{
}

void Brainfuck_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Brainfuck);
	HX_MARK_MEMBER_NAME(memorySize,"memorySize");
	HX_MARK_MEMBER_NAME(memory,"memory");
	HX_MARK_MEMBER_NAME(input,"input");
	HX_MARK_MEMBER_NAME(output,"output");
	HX_MARK_MEMBER_NAME(lock,"lock");
	HX_MARK_MEMBER_NAME(cpu,"cpu");
	HX_MARK_END_CLASS();
}

void Brainfuck_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(memorySize,"memorySize");
	HX_VISIT_MEMBER_NAME(memory,"memory");
	HX_VISIT_MEMBER_NAME(input,"input");
	HX_VISIT_MEMBER_NAME(output,"output");
	HX_VISIT_MEMBER_NAME(lock,"lock");
	HX_VISIT_MEMBER_NAME(cpu,"cpu");
}

Dynamic Brainfuck_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cpu") ) { return cpu; }
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"lock") ) { return lock; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { return input; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"memory") ) { return memory; }
		if (HX_FIELD_EQ(inName,"output") ) { return output; }
		if (HX_FIELD_EQ(inName,"assign") ) { return assign_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"execute") ) { return execute_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isLocked") ) { return isLocked_dyn(); }
		if (HX_FIELD_EQ(inName,"lockCell") ) { return lockCell_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getOutput") ) { return getOutput_dyn(); }
		if (HX_FIELD_EQ(inName,"increment") ) { return increment_dyn(); }
		if (HX_FIELD_EQ(inName,"decrement") ) { return decrement_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"memorySize") ) { return memorySize; }
		if (HX_FIELD_EQ(inName,"unlockCell") ) { return unlockCell_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Brainfuck_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cpu") ) { cpu=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"lock") ) { lock=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { input=inValue.Cast< ::haxe::io::Input >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"memory") ) { memory=inValue.Cast< ::haxe::io::ArrayBufferViewImpl >(); return inValue; }
		if (HX_FIELD_EQ(inName,"output") ) { output=inValue.Cast< ::haxe::io::Output >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"memorySize") ) { memorySize=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Brainfuck_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("memorySize","\x62","\xac","\x94","\xf2"));
	outFields->push(HX_HCSTRING("memory","\x01","\xcb","\xbf","\x04"));
	outFields->push(HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"));
	outFields->push(HX_HCSTRING("output","\x01","\x0f","\x81","\x0c"));
	outFields->push(HX_HCSTRING("lock","\xeb","\x9b","\xb7","\x47"));
	outFields->push(HX_HCSTRING("cpu","\x28","\x81","\x4b","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Brainfuck_obj,memorySize),HX_HCSTRING("memorySize","\x62","\xac","\x94","\xf2")},
	{hx::fsObject /*::haxe::io::ArrayBufferViewImpl*/ ,(int)offsetof(Brainfuck_obj,memory),HX_HCSTRING("memory","\x01","\xcb","\xbf","\x04")},
	{hx::fsObject /*::haxe::io::Input*/ ,(int)offsetof(Brainfuck_obj,input),HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe")},
	{hx::fsObject /*::haxe::io::Output*/ ,(int)offsetof(Brainfuck_obj,output),HX_HCSTRING("output","\x01","\x0f","\x81","\x0c")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Brainfuck_obj,lock),HX_HCSTRING("lock","\xeb","\x9b","\xb7","\x47")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Brainfuck_obj,cpu),HX_HCSTRING("cpu","\x28","\x81","\x4b","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("memorySize","\x62","\xac","\x94","\xf2"),
	HX_HCSTRING("memory","\x01","\xcb","\xbf","\x04"),
	HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"),
	HX_HCSTRING("output","\x01","\x0f","\x81","\x0c"),
	HX_HCSTRING("lock","\xeb","\x9b","\xb7","\x47"),
	HX_HCSTRING("cpu","\x28","\x81","\x4b","\x00"),
	HX_HCSTRING("execute","\x35","\x0a","\x0d","\xcc"),
	HX_HCSTRING("getOutput","\x37","\x98","\xd7","\x88"),
	HX_HCSTRING("init","\x10","\x3b","\xbb","\x45"),
	HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),
	HX_HCSTRING("isLocked","\x94","\xa0","\x30","\xb2"),
	HX_HCSTRING("lockCell","\x2d","\xbb","\xe1","\x86"),
	HX_HCSTRING("unlockCell","\x86","\xa2","\xa5","\x0c"),
	HX_HCSTRING("increment","\x2f","\x06","\xff","\x31"),
	HX_HCSTRING("decrement","\x13","\xf6","\x81","\x10"),
	HX_HCSTRING("assign","\x2f","\x46","\x06","\x4c"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Brainfuck_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Brainfuck_obj::__mClass,"__mClass");
};

#endif

hx::Class Brainfuck_obj::__mClass;

void Brainfuck_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("brainfuck.Brainfuck","\x0c","\x03","\xd4","\xef");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Brainfuck_obj >;
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
