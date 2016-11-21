#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_haxe_io_StringInput
#include <haxe/io/StringInput.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_BytesOutput
#include <haxe/io/BytesOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_ArrayBufferViewImpl
#include <haxe/io/ArrayBufferViewImpl.h>
#endif
#ifndef INCLUDED_brainfuck_Lock
#include <brainfuck/Lock.h>
#endif
#ifndef INCLUDED_brainfuck_BfInfiniteLoop
#include <brainfuck/BfInfiniteLoop.h>
#endif
#ifndef INCLUDED_brainfuck_BfEndAt
#include <brainfuck/BfEndAt.h>
#endif
#ifndef INCLUDED_brainfuck_BfEnd
#include <brainfuck/BfEnd.h>
#endif
#ifndef INCLUDED_brainfuck_EndOfInputError
#include <brainfuck/EndOfInputError.h>
#endif
#ifndef INCLUDED_brainfuck_EndOfProgramError
#include <brainfuck/EndOfProgramError.h>
#endif
#ifndef INCLUDED_brainfuck_CPU
#include <brainfuck/CPU.h>
#endif
#ifndef INCLUDED_brainfuck_InvalidMemoryAccessError
#include <brainfuck/InvalidMemoryAccessError.h>
#endif
#ifndef INCLUDED_brainfuck_Brainfuck
#include <brainfuck/Brainfuck.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::haxe::io::Error_obj::__register();
::haxe::Log_obj::__register();
::EReg_obj::__register();
::haxe::io::StringInput_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesOutput_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::BytesInput_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::io::ArrayBufferViewImpl_obj::__register();
::brainfuck::Lock_obj::__register();
::brainfuck::BfInfiniteLoop_obj::__register();
::brainfuck::BfEndAt_obj::__register();
::brainfuck::BfEnd_obj::__register();
::brainfuck::EndOfInputError_obj::__register();
::brainfuck::EndOfProgramError_obj::__register();
::brainfuck::CPU_obj::__register();
::brainfuck::InvalidMemoryAccessError_obj::__register();
::brainfuck::Brainfuck_obj::__register();
::Std_obj::__register();
::Main_obj::__register();
::cpp::Lib_obj::__register();
::haxe::io::Error_obj::__boot();
::EReg_obj::__boot();
::haxe::Log_obj::__boot();
}

