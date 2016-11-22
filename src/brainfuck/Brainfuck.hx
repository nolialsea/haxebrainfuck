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
	public var memorySize:UInt = 30000;
	public var memory:UInt8Array;
	public var input:Input;
	public var output:Output;
	public var lock: Array<Lock> = new Array<Lock>();
	public var cpu: Array<CPU> = new Array<CPU>();
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
		cpu.push(new CPU(program, type, this.input, this.output, this));
		
		return this;
	}
	
	public function reset(?program:String = "", ?type:Null<Int>, ?input:Input, ?output:Output, ?memory:UInt8Array):Brainfuck {
		this.input = input == null ? new StringInput("") : input;
		this.output = output == null ? new BytesOutput() : output;
		this.memory = memory == null ? new UInt8Array(memorySize) : memory;
		
		cpu[0].init(program, type, this.input, this.output, this);
		
		return this;
	}
	
	public function run(): Brainfuck {
		while (true){
			var allDead = true;
			for (c in 0...cpu.length){
				if (cpu[c].alive){
					allDead = false;
					try{
						cpu[c].step();
					}catch (e:Dynamic){
						error = e;
					}
				}
			}
			if (allDead) break;
		}

		return this;
	}
	
	public function isLocked (pointer:UInt) : Bool{
		for (l in 0...lock.length){
			if (lock[l].position == pointer){
				return true;
			}
		}
		return false;
	}
	
	public function lockCell (pointer:UInt, id: Float) : Bool{
		for (l in 0...lock.length){
			if (lock[l].position == pointer){
				return false;
			}
		}
		lock.push(new Lock(pointer, id));
		return true;
	}
	
	public function unlockCell (pointer:UInt, id: Float){
		for (l in 0...lock.length){
			if (lock[l].position == pointer && lock[l].owner == id){
				lock.remove(lock[l]);
				break;
			}
		}
	}
	
	public function isLockOwner (pointer:UInt, id: Float) : Bool{
		for (l in 0...lock.length){
			if (lock[l].position == pointer && lock[l].owner == id){
				return true;
			}
		}
		return false;
	}
	
	public function increment(pointer:UInt, id: Float): Void {
		if (!isLocked(pointer)){
			try {
				memory.set(pointer, Std.int(memory.get(pointer) + 1));
			} catch (e:Dynamic) {
				throw new InvalidMemoryAccessError();
			}
		}
	}
	
	public function decrement(pointer:UInt, id: Float): Void {
		if (!isLocked(pointer)){
			try {
				memory.set(pointer,Std.int(memory.get(pointer)-1));
			} catch (e:Dynamic) {
				throw new InvalidMemoryAccessError();
			}
		}
	}
	
	public function assign(pointer:UInt, id: Float, value: Int): Void {
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