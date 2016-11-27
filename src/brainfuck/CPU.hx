package brainfuck;

import brainfuck.Brainfuck.InvalidMemoryAccessError;
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
class CPU {
	public var id: Float;
	public var maxStep: UInt;
	public var pointer:Int;
	public var storage:UInt8Array;
	public var storagePointer: Null<UInt>;
	public var program:String;
	public var programPosition:Int;
	public var programType:Null<UInt>;
	public var jump: Array<UInt>;
	public var comment:Bool;
	public var ticks: UInt;
	public var xReturn: Array<UInt>;
	public var input: Input;
	public var output: Output;
	public var memory: UInt8Array;
	public var initialData: String;
	public var bf: Brainfuck;
	public var alive: Bool;
	public var error: Dynamic;
	
	public function new(?program:String = "", ?type:Null<Int>, ?input: Input, ?output:Output, ?bf:Brainfuck) {
		init(program,type, input,output,bf);
	}
	
	public function getProgramType(program: String) : UInt{
		programType = 0;
		if (~/[#0-9A-FlLmMxX]/.match(program)){
			programType = 3;
		}else if (~/[%_=\/*\(\)?]/.match(program)){
			programType = 2;
		}else if (~/[@|&\^~{}!\$]/.match(program)){
			programType = 1;
		}
        return programType;
	}
	
	public static function getProgramString(program:String, programType: Int) : String {
		var prog = "";
        var commentTemp = false;

        for (i in 0...program.length){
            prog += program.charAt(i);
            if (programType >= 3 && program.charAt(i) == "#"){
                commentTemp = !commentTemp;
            }else if(programType >= 1 && program.charAt(i) == "@" && !commentTemp){
                break;
            }
        }

        return prog;
	}
	
	public static function getInitialData(program: String, programType: Int) : String {
		var data:String = "";
        var commentTemp = false;

        for (i in 0...program.length){
            if (program.charAt(i) == "#"){
                commentTemp = !commentTemp;
            }else if(program.charAt(i) == "@" && !commentTemp){
                data = program.substr(i+1);
            }
        }

        return data;
	}
	
	public function setInitialData(program: String, initialData: String) : Void {
		if (programType >= 2){
			for (i in 0...program.length){
				memory.set(i + 1, program.charCodeAt(i));
			}
		}
	}
	
	public function init(?program:String = "", ?type:Null<Int>, ?input: Input, ?output:Output, ?bf:Brainfuck) {
		error = null;
		id = Math.random();
		maxStep = 12000;
		programType = type == null ? getProgramType(program) : type;
		storage = new UInt8Array(1);
		storagePointer = null;
		this.program = getProgramString(program, programType);
		initialData = getInitialData(program, programType);
		pointer = programType > 1 ? this.program.length+1 : 0;
		programPosition = programType > 1 ? 1 : 0;
		jump = new Array<UInt>();
		comment = false;
		ticks = 0;
		xReturn = new Array<UInt>();
		this.input = input == null ? new StringInput("") : input;
		this.output = output == null ? new BytesOutput() : output;
		this.bf = bf;
		this.memory = bf.memory;
		setInitialData(program, initialData);
		alive = true;
	}

	public function run(): CPU {
		try{
			while (ticks <= maxStep){
				if (!step()){
					break;
				}
			}
		}catch (e:Dynamic){
			error = e;
			throw e;
		}

		return this;
	}
	
	public function step() : Bool{
		if (alive){
			try{
				if (ticks >= maxStep){
					throw new BfInfiniteLoop();
				}
				
				if (programPosition >= (programType < 2 ? program.length : memory.length)){
					throw new BfEnd();
				}

				if (runCommand(programType < 2 ? program.charAt(programPosition) : String.fromCharCode(memory.get(programPosition)))){
					ticks++;
				}
			}catch (e:Dynamic){
				alive = false;
				error = e;
				throw e;
			}
		}
		return alive;
	}
	
	private function moveToNextCommand():String {
		++programPosition;
		return programType < 2 ?
			programPosition < program.length ? program.charAt(programPosition) : null
			:
			programPosition < memory.length ? String.fromCharCode(memory.get(programPosition)) : null;
	}
	
	private function moveToPrevCommand():String {
		--programPosition;
		return programType < 2 ?
			(programPosition < 0) ? null : program.charAt(programPosition)
			:
			(programPosition < 0) ? null : String.fromCharCode(memory.get(programPosition));
	}
	
	private function runCommand(command:String):Bool {
		switch (command) {
			case '>': //Increment the pointer.
				if (!comment){
					pointer++;
				}
				moveToNextCommand();
				
			case '<': //Decrement the pointer.
				if (!comment){
					pointer--;
					if (pointer < 0){
						pointer = 0;
					}
				}
				moveToNextCommand();
				
			case '+': //Increment the byte at the pointer.
				if (!comment){
					bf.increment(pointer);
				}
				moveToNextCommand();
				
			case '-': //Decrement the byte at the pointer.
				if (!comment){
					bf.decrement(pointer);
				}
				moveToNextCommand();
				
			case '.': //Output the byte at the pointer.
				try {
					output.writeByte(memory.get(pointer));
				} catch (e:Dynamic) {
					throw new InvalidMemoryAccessError();
				}
				moveToNextCommand();
				
			case ',': //Input a byte and store it in the byte at the pointer.
				var val;
				try {
					val = input.readByte();
					try {
						memory.set(pointer,val);
					} catch (e:Dynamic) {
						throw new InvalidMemoryAccessError();
					}
				} catch (e:Eof) {
					//Fails silently
					//throw new EndOfInputError();
				}
				
				moveToNextCommand();
				
			case '[': //Jump forward past the matching ] if the byte at the pointer is zero.
				if (!comment){
					var val;
					var temp = programPosition;
					var commentTemp = false;
					try {
						val = memory.get(pointer);
					} catch (e:Dynamic) {
						throw new InvalidMemoryAccessError();
					}
					if (val == 0){
						var count = 1;
						var c = moveToNextCommand();
						while (true){
							if (c == '[' && !commentTemp){
								++count;
							}
							else if (c == ']' && !commentTemp){
								--count;
							}
							else if (programType >= 1 && c == '@' && !commentTemp){
								count = 0;
								programPosition = temp;
							}else if (programType >=3 && c == '#'){
								commentTemp = !commentTemp;
							}
							if (count == 0){
								moveToNextCommand();
								break;
							}
							
							c = moveToNextCommand();
							if (c == null) {
								throw new EndOfProgramError();
							}
						}
					} else {
						moveToNextCommand();
					}
				}else{
					moveToNextCommand();
				}
				
			case ']': //Jump backward to the matching [ unless the byte at the pointer is zero.
				if (!comment){
					var val;
					var commentTemp = false;
					try {
						val = memory.get(pointer);
					} catch (e:Dynamic) {
						throw new InvalidMemoryAccessError();
					}
					
					if (val > 0){
						var count = 1;
						var c = moveToPrevCommand();
						while (true){
							if (c == '[' && !commentTemp){
								--count;
							}else if (c == ']' && !commentTemp){
								++count;
							}else if (programType >=3 && c == '#'){
								commentTemp = !commentTemp;
							}
							if (count == 0){
								break;
							}
							c = moveToPrevCommand();
							if (c == null) {
								throw new EndOfProgramError();
							}
						}
					} else {
						moveToNextCommand();
					}
				}else{
					moveToNextCommand();
				}
				
			case '@': //End the program
				if (programType >= 1 && !comment){
					throw new BfEndAt();
				}
				moveToNextCommand();
				
			case '$': //Overwrites the byte in storage with the byte at the pointer.
				if (programType >= 1 && !comment){
					if (storagePointer == null){
						if (programType > 1){
							bf.assign(0, memory.get(pointer));
						}else{
							storage.set(0, memory.get(pointer));
						}
					}else{
						bf.assign(storagePointer, memory.get(pointer));
					}
				}
				moveToNextCommand();
				
			case '!': //Overwrites the byte at the pointer with the byte in storage.
				if (programType >= 1 && !comment){
					if (storagePointer == null){
						if (programType > 1){
							bf.assign(pointer, memory.get(0));
						}else{
							bf.assign(pointer, storage.get(0));
						}
					}else{
						bf.assign(pointer, memory.get(storagePointer));
					}
				}
				moveToNextCommand();
				
			case '^': //Performs a bitwise XOR operation on the byte at the pointer and the byte in storage,  storing its result in the byte at the pointer.
				if (programType >= 1 && !comment){
					if (storagePointer == null){
						if (programType > 1){
							bf.assign(pointer, memory.get(pointer) ^ memory.get(0));
						}else{
							bf.assign(pointer, memory.get(pointer) ^ storage.get(0));
						}
					}else{
						bf.assign(pointer, memory.get(pointer) ^ memory.get(storagePointer));
					}
				}
				moveToNextCommand();
			case '&': //Performs a bitwise AND operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
				if (programType >= 1 && !comment){
					if (storagePointer == null){
						if (programType > 1){
							bf.assign(pointer, memory.get(pointer) & memory.get(0));
						}else{
							bf.assign(pointer, memory.get(pointer) & storage.get(0));
						}
					}else{
						bf.assign(pointer, memory.get(pointer) & memory.get(storagePointer));
					}
				}
				moveToNextCommand();
			case '|': //Performs a bitwise OR operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
				if (programType >= 1 && !comment){
					if (storagePointer == null){
						if (programType > 1){
							bf.assign(pointer, memory.get(pointer) | memory.get(0));
						}else{
							bf.assign(pointer, memory.get(pointer) | storage.get(0));
						}
					}else{
						bf.assign(pointer, memory.get(pointer) | memory.get(storagePointer));
					}
				}
				moveToNextCommand();
			case '{': //Performs a single left logical shift of the byte at the pointer.
				if (programType >= 1 && !comment){
					bf.assign(pointer, memory.get(pointer) << 1);
				}
				moveToNextCommand();
			case '}': //Performs a single right logical shift of the byte at the pointer.
				if (programType >= 1 && !comment){
					bf.assign(pointer, memory.get(pointer) >> 1);
				}
				moveToNextCommand();
			case '~': //Performs a bitwise NOT operation on the byte at the pointer (all 1's and 0's are swapped).
				if (programType >= 1 && !comment){
					bf.assign(pointer, ~memory.get(pointer));
				}
				moveToNextCommand();
			case '?': //Sets the current point of execution to the location of the pointer.
				if (programType >= 2 && !comment){
					programPosition = pointer;
				}
				moveToNextCommand();
			case '*': //Multiplies the byte at the pointer with the byte in storage, storing its result in the byte at the pointer.
				if (programType >= 2 && !comment){
					if (storagePointer == null){
						bf.assign(pointer, memory.get(pointer) * memory.get(0));
					}else{
						bf.assign(pointer, memory.get(pointer) * memory.get(storagePointer));
					}
				}
				moveToNextCommand();
			case '/': //Divides the byte at the pointer with the byte in storage, storing its result in the byte at the pointer.
				if (programType >= 2 && !comment){
					if (storagePointer == null){
						bf.assign(pointer, Std.int(memory.get(pointer) / (memory.get(0) == 0 ? 1 : memory.get(0))));
					}else{
						bf.assign(pointer, Std.int(memory.get(pointer) / (memory.get(storagePointer) == 0 ? 1 : memory.get(storagePointer))));
					}
				}
				moveToNextCommand();
			case '=': //Adds the byte at the pointer with the byte in storage, storing its result in the byte at the pointer.
				if (programType >= 2 && !comment){
					if (storagePointer == null){
						bf.assign(pointer, memory.get(pointer) + memory.get(0));
					}else{
						bf.assign(pointer, memory.get(pointer) + memory.get(storagePointer));
					}
				}
				moveToNextCommand();
			case '_': //Subtracts the byte at the pointer with the byte in storage, storing its result in the byte at the pointer.
				if (programType >= 2 && !comment){
					if (storagePointer == null){
						bf.assign(pointer, memory.get(pointer) - memory.get(0));
					}else{
						bf.assign(pointer, memory.get(pointer) - memory.get(storagePointer));
					}
				}
				moveToNextCommand();
			case '%': //Preforms a Modulo operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
				if (programType >= 2 && !comment){
					if (storagePointer == null){
						bf.assign(pointer, memory.get(pointer) % (memory.get(0) == 0 ? 1 : memory.get(0)));
					}else{
						bf.assign(pointer, memory.get(pointer) % (memory.get(storagePointer) == 0 ? 1 : memory.get(storagePointer)));
					}
				}
				moveToNextCommand();
			case ':': //Moves the pointer forward or back by the signed number at the current cell. 
			//So a cell value of 5, moves the pointer ahead 5 places, where as 251 (signed -5) 
			//would move the pointer back 5 places. 
			//This is useful for simple variable determining pointer movement.
				if (programType >= 3 && !comment){
					pointer += 128 - memory.get(pointer);
					if (pointer < 0){
						pointer = 0;
					}
				}
				moveToNextCommand();
			case 'x': //This command returns the pointer it was pointing to prior to the last call to X, 
			//if X has not been called, it resets it to its initial position (cell 0). 
			//If x has been called to return from X, it returns it to the cell it would have returned to.
				if (programType >= 3 && !comment){
					var xRet = xReturn.pop();
					pointer = xRet != null ? xRet : program.length+1;
				}
				moveToNextCommand();
			case 'X': //This command moves the pointer to the cell containing currently executing command. (That is this command)
				if (programType >= 3 && !comment){
					xReturn.push(pointer);
					pointer = programPosition;
				}
				moveToNextCommand();
			case 'm': //Resets the storage cell to the initial storage cell.
				if (programType >= 3 && !comment){
					storagePointer = null;
				}
				moveToNextCommand();
			case 'M': //Marks the current cell as the cell to use as the 'storage' cell defined in extended type I.
				if (programType >= 3 && !comment){
					storagePointer = pointer;
				}
				moveToNextCommand();
			case 'l': //Unlocks a previously locked cell and allows it to be edited again.
			//Calling this on a already unlocked cell does nothing.
				if (programType >= 3 && !comment){
					bf.unlockCell(pointer);
				}
				moveToNextCommand();
			case 'L': //Locks a cell and prevents it from being changed. 
			//Any attempt to change it silently fails. (This includes deleting it)
				if (programType >= 3 && !comment){
					bf.lockCell(pointer);
				}
				moveToNextCommand();
			case '#': //All following characters between this and the next # are ignored (unless they are in the data area).
			//Comments can be changed to become uncommented due to the nature of self modifying code.
				if (programType >= 3){
					comment = !comment;
				}
				moveToNextCommand();
			default:
				//Fast Cell Initializer Commands: 0 1 2 3 4 5 6 7 8 9 A B C D E F
				//Turns values 0 to F to their hex equivalents and initializes the cell to be the value of these multiplied by 16 or 0x10.
				//So F would change the value of the cell to (15*16) 240 or 0xF0, where as 5 changes it to (5*16) 80 or 0x50.
				if (programType >= 3 && ~/[0-9A-F]/.match(command)){
					bf.assign(pointer, "0123456789ABCDEF".indexOf(command)*16);
				}
				moveToNextCommand();
				return false;
		}
		return true;
	}
}

class EndOfProgramError {	
	public function new():Void {
		
	}
	
	public function toString():String {
		return "End of program reached";
	}
}

class EndOfInputError {	
	public function new():Void {
		
	}
	
	public function toString():String {
		return "End of input reached";
	}
}

class BfEnd {
	public function new():Void {
		
	}
	
	public function toString():String {
		return "BF_END";
	}
}

class BfEndAt {
	public function new():Void {
		
	}
	
	public function toString():String {
		return "BF_END_COMMAND";
	}
}

class BfInfiniteLoop {
	public function new():Void {
		
	}
	
	public function toString():String {
		return "BF_INFINITE_LOOP";
	}
}