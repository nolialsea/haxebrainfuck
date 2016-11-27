package brainfuck;

import haxe.io.Bytes;
import haxe.io.BytesOutput;
import haxe.io.Input;
import haxe.io.Output;
import haxe.io.StringInput;
import haxe.io.Eof;
import haxe.io.UInt8Array;

/**
* ...
* @author Hugo Diranzo
*/

class Brainfuck {
	public var memorySize:UInt = 256;
	public var memory:UInt8Array;
	public var input:Input;
	public var output:Output;
	public var lock: Array<UInt> = new Array<UInt>();
	public var cpu: CPU;
	public var error: Null<Dynamic> = null;
	
	public function execute (bfCode: String, ?type:Null<Int> = null) : Brainfuck{
		init(bfCode, type);
		run();
		return this;
	}
	
	public function getOutput() : String {
		return cast(output, BytesOutput).getBytes().toString();
	}

	public function new(?program:String = "", ?type:Null<Int>, ?input:Input, ?output:Output, ?memory:UInt8Array):Void {
		init(program, type, input, output, memory);
	}
	
	public function init(?program:String = "", ?type:Null<Int>, ?input:Input, ?output:Output, ?memory:UInt8Array):Brainfuck {
		this.input = input == null ? new StringInput("") : input;
		this.output = output == null ? new BytesOutput() : output;
		this.memory = memory == null ? new UInt8Array(memorySize) : memory;
		lock.splice(0, lock.length);
		error = null;
		cpu = new CPU(program, type, this.input, this.output, this);
		
		return this;
	}
	
	public function reset(?program:String = "", ?type:Null<Int>, ?input:Input, ?output:Output, ?memory:UInt8Array):Brainfuck {
		this.input = input == null ? new StringInput("") : input;
		this.output = output == null ? new BytesOutput() : output;
		this.memory = memory == null ? new UInt8Array(memorySize) : memory;
		
		cpu.init(program, type, this.input, this.output, this);
		
		return this;
	}
	
	public function run(): Brainfuck {
		while (true){
			if (cpu.alive){
				try{
					cpu.step();
				}catch (e:Dynamic){
					trace(e);
					error = e;
				}
			}else{
				break;
			}
		}

		return this;
	}
	
	public function isLocked (pointer:UInt) : Bool{
		for (l in 0...lock.length){
			if (lock[l] == pointer){
				return true;
			}
		}
		return false;
	}
	
	public function lockCell (pointer:UInt) : Bool{
		for (l in 0...lock.length){
			if (lock[l] == pointer){
				return false;
			}
		}
		lock.push(pointer);
		return true;
	}
	
	public function unlockCell (pointer:UInt){
		for (l in 0...lock.length){
			if (lock[l] == pointer){
				lock.remove(lock[l]);
				break;
			}
		}
	}
	
	public function increment(pointer:UInt): Void {
		if (!isLocked(pointer)){
			try {
				memory.set(pointer, Std.int(memory.get(pointer) + 1));
			} catch (e:Dynamic) {
				throw new InvalidMemoryAccessError();
			}
		}
	}
	
	public function decrement(pointer:UInt): Void {
		if (!isLocked(pointer)){
			try {
				memory.set(pointer,Std.int(memory.get(pointer)-1));
			} catch (e:Dynamic) {
				throw new InvalidMemoryAccessError();
			}
		}
	}
	
	public function assign(pointer:UInt, value: Int): Void {
		if (!isLocked(pointer)){
			try {
				memory.set(pointer, value);
			} catch (e:Dynamic) {
				throw new InvalidMemoryAccessError();
			}
		}
		
	}
}

class InvalidMemoryAccessError {	
	public function new():Void {
		
	}
	
	public function toString():String {
		return "Invalid memory access";
	}
}