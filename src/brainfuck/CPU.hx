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
	public var commands : Map<String, Void -> Void>;
	
	public function new(?program:String = "", ?type:Null<Int>, ?input: Input, ?output:Output, ?bf:Brainfuck) {
		init(program,type, input,output,bf);
	}
	
	public function init(?program:String = "", ?type:Null<Int>, ?input: Input, ?output:Output, ?bf:Brainfuck) {
		error = null;
		id = Math.random();
		
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
		maxStep = bf.maxStep;
		setInitialData(program, initialData);
		alive = true;
		initCommands();
	}
	
	public function initCommands() : Void{
		commands = new Map<String, Void -> Void>();
		
		//Vanilla Brainfuck
		commands.set(">", moveRight);
		commands.set("<", moveLeft);
		commands.set("+", increment);
		commands.set("-", decrement);
		commands.set(".", write);
		commands.set(",", read);
		commands.set("[", leftBracket);
		commands.set("]", rightBracket);
		
		//Extended Type I
		commands.set("@", endProgram);
		commands.set("$", writeStorage);
		commands.set("!", readStorage);
		commands.set("^", XOR);
		commands.set("&", AND);
		commands.set("|", OR);
		commands.set("~", NOT);
		commands.set("{", leftShift);
		commands.set("}", rightShift);
		
		//Extended Type II
		commands.set("?", goto);
		commands.set("*", mul);
		commands.set("/", div);
		commands.set("=", add);
		commands.set("_", sub);
		commands.set("%", mod);
		commands.set(")", insertCell);
		commands.set("(", removeCell);
		
		//Extended Type III
		commands.set(":", jumpCommandPointer);
		commands.set("x", returnPointer);
		commands.set("X", jumpPointer);
		commands.set("m", markCellForStorage);
		commands.set("M", resetCellForStorage);
		commands.set("l", unlock);
		commands.set("L", lock);
		commands.set("#", toggleComment);
		var hex = "0123456789ABCDEF";
		for (i in 0...hex.length){
			commands.set(hex.charAt(i), setHexa(i));
		}
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
		if (commands.exists(command)){
			commands.get(command)();
			return true;
		}
		moveToNextCommand();
		return false;
	}
	
	//Increment the pointer.
	public function moveRight() : Void {
		if (!comment){
			pointer++;
		}
		moveToNextCommand();
	}
	
	//Decrement the pointer.
	public function moveLeft () : Void {
		if (!comment){
			pointer--;
			if (pointer < 0){
				pointer = 0;
			}
		}
		moveToNextCommand();
	}
	
	//Increment the byte at the pointer.
	public function increment () : Void {
		if (!comment){
			bf.increment(pointer);
		}
		moveToNextCommand();
	}
	
	//Decrement the byte at the pointer.
	public function decrement () : Void {
		if (!comment){
			bf.decrement(pointer);
		}
		moveToNextCommand();
	}
	
	//Output the byte at the pointer.
	public function write () : Void {
		try {
			output.writeByte(memory.get(pointer));
		} catch (e:Dynamic) {
			throw new InvalidMemoryAccessError();
		}
		moveToNextCommand();
	}
	
	//Input a byte and store it in the byte at the pointer.
	public function read () : Void {
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
			memory.set(pointer,0);
			//throw new EndOfInputError();
		}
		
		moveToNextCommand();
	}
	
	//Jump forward past the matching ] if the byte at the pointer is zero.
	public function leftBracket () : Void {
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
						throw new BfEnd();
					}
				}
			} else {
				moveToNextCommand();
			}
		}else{
			moveToNextCommand();
		}
	}
	
	//Jump backward to the matching [ unless the byte at the pointer is zero.
	public function rightBracket () : Void {
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
						throw new BfEnd();
					}
				}
			} else {
				moveToNextCommand();
			}
		}else{
			moveToNextCommand();
		}
	}

	//End the program
	public function endProgram () : Void {
		if (programType >= 1 && !comment){
			throw new BfEndAt();
		}
		moveToNextCommand();
	}
	
	//Overwrites the byte in storage with the byte at the pointer.
	public function writeStorage () : Void {
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
	}
	
	//Overwrites the byte at the pointer with the byte in storage.
	public function readStorage () : Void {
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
	}
	
	//Performs a bitwise XOR operation on the byte at the pointer and the byte in storage,  storing its result in the byte at the pointer.
	public function XOR () : Void {
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
	}
	
	//Performs a bitwise AND operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
	public function AND () : Void {
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
	}
	
	//Performs a bitwise OR operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
	public function OR () : Void {
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
	}
	
	//Performs a bitwise NOT operation on the byte at the pointer (all 1's and 0's are swapped).
	public function NOT () : Void {
		if (programType >= 1 && !comment){
			bf.assign(pointer, ~memory.get(pointer));
		}
		moveToNextCommand();
	}
	
	//Performs a single left logical shift of the byte at the 
	public function leftShift () : Void {
		if (programType >= 1 && !comment){
			bf.assign(pointer, memory.get(pointer) << 1);
		}
		moveToNextCommand();
	}
	
	//Performs a single right logical shift of the byte at the 
	public function rightShift () : Void {
		if (programType >= 1 && !comment){
			bf.assign(pointer, memory.get(pointer) >> 1);
		}
		moveToNextCommand();
	}
	
	//Sets the current point of execution to the location of the pointer.
	public function goto () : Void {
		if (programType >= 2 && !comment){
			programPosition = pointer;
		}
		moveToNextCommand();
	}
	
	//Multiplies the byte at the pointer with the byte in storage, storing its result in the byte at the pointer.
	public function mul () : Void {
		if (programType >= 2 && !comment){
			if (storagePointer == null){
				bf.assign(pointer, memory.get(pointer) * memory.get(0));
			}else{
				bf.assign(pointer, memory.get(pointer) * memory.get(storagePointer));
			}
		}
		moveToNextCommand();
	}
	
	//Divides the byte at the pointer with the byte in storage, storing its result in the byte at the pointer.
	public function div () : Void {
		if (programType >= 2 && !comment){
			if (storagePointer == null){
				bf.assign(pointer, Std.int(memory.get(pointer) / (memory.get(0) == 0 ? 1 : memory.get(0))));
			}else{
				bf.assign(pointer, Std.int(memory.get(pointer) / (memory.get(storagePointer) == 0 ? 1 : memory.get(storagePointer))));
			}
		}
		moveToNextCommand();
	}
	
	//Adds the byte at the pointer with the byte in storage, storing its result in the byte at the pointer.
	public function add () : Void {
		if (programType >= 2 && !comment){
			if (storagePointer == null){
				bf.assign(pointer, memory.get(pointer) + memory.get(0));
			}else{
				bf.assign(pointer, memory.get(pointer) + memory.get(storagePointer));
			}
		}
		moveToNextCommand();
	}
	
	//Substracts the byte at the pointer with the byte in storage, storing its result in the byte at the pointer.
	public function sub () : Void {
		if (programType >= 2 && !comment){
			if (storagePointer == null){
				bf.assign(pointer, memory.get(pointer) - memory.get(0));
			}else{
				bf.assign(pointer, memory.get(pointer) - memory.get(storagePointer));
			}
		}
		moveToNextCommand();
	}
	
	//Preforms a Modulo operation on the byte at the pointer and the byte in storage, storing its result in the byte at the pointer.
	public function mod () : Void {
		if (programType >= 2 && !comment){
			if (storagePointer == null){
				bf.assign(pointer, memory.get(pointer) % (memory.get(0) == 0 ? 1 : memory.get(0)));
			}else{
				bf.assign(pointer, memory.get(pointer) % (memory.get(storagePointer) == 0 ? 1 : memory.get(storagePointer)));
			}
		}
		moveToNextCommand();
	}
	
	//Moves the pointer forward or back by the signed number at the current cell. 
	//So a cell value of 5, moves the pointer ahead 5 places, where as 251 (signed -5) 
	//would move the pointer back 5 places. 
	//This is useful for simple variable determining pointer movement.
	public function jumpCommandPointer () : Void {
		if (programType >= 3 && !comment){
			pointer += 128 - memory.get(pointer);
			if (pointer < 0){
				pointer = 0;
			}
		}
		moveToNextCommand();
	}
	
	//This command returns the pointer it was pointing to prior to the last call to X, 
	//if X has not been called, it resets it to its initial position (cell 0). 
	//If x has been called to return from X, it returns it to the cell it would have returned to.
	public function returnPointer () : Void {
		if (programType >= 3 && !comment){
			var xRet = xReturn.pop();
			pointer = xRet != null ? xRet : program.length+1;
		}
		moveToNextCommand();
	}
	
	//This command moves the pointer to the cell containing currently executing command. (That is this command)
	public function jumpPointer () : Void {
		if (programType >= 3 && !comment){
			xReturn.push(pointer);
			pointer = programPosition;
		}
		moveToNextCommand();
	}
	
	//Resets the storage cell to the initial storage cell.
	public function resetCellForStorage () : Void {
		if (programType >= 3 && !comment){
			storagePointer = null;
		}
		moveToNextCommand();
	}
	
	//Marks the current cell as the cell to use as the 'storage' cell defined in extended type I.
	public function markCellForStorage () : Void {
		if (programType >= 3 && !comment){
			storagePointer = pointer;
		}
		moveToNextCommand();
	}
	
	//Unlocks a previously locked cell and allows it to be edited again.
	public function unlock () : Void {
		if (programType >= 3 && !comment){
			bf.unlockCell(pointer);
		}
		moveToNextCommand();
	}
	
	//Locks a cell and prevents it from being changed. 
	//Any attempt to change it silently fails. (This includes deleting it)
	public function lock () : Void {
		if (programType >= 3 && !comment){
			bf.lockCell(pointer);
		}
		moveToNextCommand();
	}
	
	//All following characters between this and the next # are ignored (unless they are in the data area).
	//Comments can be changed to become uncommented due to the nature of self modifying code.
	public function toggleComment () : Void {
		if (programType >= 3){
			comment = !comment;
		}
		moveToNextCommand();
	}
	
	//Fast Cell Initializer Commands: 0 1 2 3 4 5 6 7 8 9 A B C D E F
	//Turns values 0 to F to their hex equivalents and initializes the cell to be the value of these multiplied by 16 or 0x10.
	//So F would change the value of the cell to (15*16) 240 or 0xF0, where as 5 changes it to (5*16) 80 or 0x50.
	public function setHexa (i : Int) : Void->Void {
		//commands is an Map<String, Void->Void>, so have to convert it
		var f = function() : Void{
			if (programType >= 3){
				bf.assign(pointer, i*16);
			}
			moveToNextCommand();
		};
		return f;
	}
	
	//Inserts a new cell before the current pointer, shifting all following cells to the right.
	public function insertCell () : Void {
		if (programType >= 2 && !comment){
			bf.addCell(pointer);
		}
		moveToNextCommand();
	}
	
	//Removes the cell at the current pointer, shifting all following cells to the left.
	public function removeCell () : Void {
		if (programType >= 2 && !comment){
			bf.removeCell(pointer);
		}
		moveToNextCommand();
	}
}

class EndOfInputError {	
	public function new():Void {
		
	}
	
	public function toString():String {
		return "BF_END_OF_INPUT";
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