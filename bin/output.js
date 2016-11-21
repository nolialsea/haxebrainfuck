(function (console, $global) { "use strict";
var $estr = function() { return js_Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var EReg = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
EReg.__name__ = true;
EReg.prototype = {
	match: function(s) {
		if(this.r.global) this.r.lastIndex = 0;
		this.r.m = this.r.exec(s);
		this.r.s = s;
		return this.r.m != null;
	}
	,__class__: EReg
};
var HxOverrides = function() { };
HxOverrides.__name__ = true;
HxOverrides.cca = function(s,index) {
	var x = s.charCodeAt(index);
	if(x != x) return undefined;
	return x;
};
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
};
HxOverrides.indexOf = function(a,obj,i) {
	var len = a.length;
	if(i < 0) {
		i += len;
		if(i < 0) i = 0;
	}
	while(i < len) {
		if(a[i] === obj) return i;
		i++;
	}
	return -1;
};
HxOverrides.remove = function(a,obj) {
	var i = HxOverrides.indexOf(a,obj,0);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
};
var Main = function() { };
Main.__name__ = true;
Main.main = function() {
	var bf = new brainfuck_Brainfuck();
	console.log(bf.execute("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.").getOutput());
	console.log(bf.execute("++++{+{{{.$>-}}^>++{{{++$<^.$>[-]++{{+^..$>+++|.>++{{{{.<<<<$>>>>>-}}}^.<<.+++.<.<-.>>>+.@").getOutput());
	console.log(bf.execute(">++{{$+*.>!++$*+.>!*=--..$>!+++.>++{${*.>++$</$>![<]!-$>=.>>>.+++.<.<-.<<=+++.@").getOutput());
	console.log(bf.execute("[.>]@Hello World!").getOutput());
	console.log(bf.execute(">5--------.7-----------.+++++++..+++.<2.5+++++++.>.+++.------.--------.2+.").getOutput());
};
Math.__name__ = true;
var Std = function() { };
Std.__name__ = true;
Std.string = function(s) {
	return js_Boot.__string_rec(s,"");
};
var StringTools = function() { };
StringTools.__name__ = true;
StringTools.fastCodeAt = function(s,index) {
	return s.charCodeAt(index);
};
var _$UInt_UInt_$Impl_$ = {};
_$UInt_UInt_$Impl_$.__name__ = true;
_$UInt_UInt_$Impl_$.gt = function(a,b) {
	var aNeg = a < 0;
	var bNeg = b < 0;
	if(aNeg != bNeg) return aNeg; else return a > b;
};
_$UInt_UInt_$Impl_$.gte = function(a,b) {
	var aNeg = a < 0;
	var bNeg = b < 0;
	if(aNeg != bNeg) return aNeg; else return a >= b;
};
var brainfuck_Brainfuck = function(program,type,input,output,memory) {
	if(program == null) program = "";
	this.cpu = [];
	this.lock = [];
	this.memorySize = 30000;
	this.init(program,type,input,output,memory);
};
brainfuck_Brainfuck.__name__ = true;
brainfuck_Brainfuck.prototype = {
	execute: function(bfCode,type) {
		this.init(bfCode,type);
		this.run();
		return this;
	}
	,getOutput: function() {
		return (js_Boot.__cast(this.output , haxe_io_BytesOutput)).getBytes().toString();
	}
	,init: function(program,type,input,output,memory) {
		if(program == null) program = "";
		if(input == null) this.input = new haxe_io_StringInput(""); else this.input = input;
		if(output == null) this.output = new haxe_io_BytesOutput(); else this.output = output;
		if(memory == null) this.memory = new Uint8Array(this.memorySize); else this.memory = memory;
		this.lock.splice(0,this.lock.length);
		this.cpu.push(new brainfuck_CPU(program,type,this.input,this.output,this));
		return this;
	}
	,run: function() {
		while(true) {
			var allDead = true;
			var _g1 = 0;
			var _g = this.cpu.length;
			while(_g1 < _g) {
				var c = _g1++;
				if(this.cpu[c].alive) {
					allDead = false;
					try {
						this.cpu[c].step();
					} catch( e ) {
						if (e instanceof js__$Boot_HaxeError) e = e.val;
					}
				}
			}
			if(allDead) break;
		}
		return this;
	}
	,isLocked: function(pointer) {
		var _g1 = 0;
		var _g = this.lock.length;
		while(_g1 < _g) {
			var l = _g1++;
			if(this.lock[l].position == pointer) return true;
		}
		return false;
	}
	,lockCell: function(pointer,id) {
		var _g1 = 0;
		var _g = this.lock.length;
		while(_g1 < _g) {
			var l = _g1++;
			if(this.lock[l].position == pointer) return false;
		}
		this.lock.push(new brainfuck_Lock(pointer,id));
		return true;
	}
	,unlockCell: function(pointer,id) {
		var _g1 = 0;
		var _g = this.lock.length;
		while(_g1 < _g) {
			var l = _g1++;
			if(this.lock[l].position == pointer && this.lock[l].owner == id) {
				HxOverrides.remove(this.lock,this.lock[l]);
				break;
			}
		}
	}
	,increment: function(pointer,id) {
		if(!this.isLocked(pointer)) try {
			this.memory[pointer] = (this.memory[pointer] + 1 | 0) & 255;
		} catch( e ) {
			if (e instanceof js__$Boot_HaxeError) e = e.val;
			throw new js__$Boot_HaxeError(new brainfuck_InvalidMemoryAccessError());
		}
	}
	,decrement: function(pointer,id) {
		if(!this.isLocked(pointer)) try {
			this.memory[pointer] = (this.memory[pointer] - 1 | 0) & 255;
		} catch( e ) {
			if (e instanceof js__$Boot_HaxeError) e = e.val;
			throw new js__$Boot_HaxeError(new brainfuck_InvalidMemoryAccessError());
		}
	}
	,assign: function(pointer,id,value) {
		if(!this.isLocked(pointer)) try {
			this.memory[pointer] = value & 255;
		} catch( e ) {
			if (e instanceof js__$Boot_HaxeError) e = e.val;
			throw new js__$Boot_HaxeError(new brainfuck_InvalidMemoryAccessError());
		}
	}
	,__class__: brainfuck_Brainfuck
};
var brainfuck_InvalidMemoryAccessError = function() {
};
brainfuck_InvalidMemoryAccessError.__name__ = true;
brainfuck_InvalidMemoryAccessError.prototype = {
	toString: function() {
		return "Invalid memory access";
	}
	,__class__: brainfuck_InvalidMemoryAccessError
};
var brainfuck_CPU = function(program,type,input,output,bf) {
	if(program == null) program = "";
	this.init(program,type,input,output,bf);
};
brainfuck_CPU.__name__ = true;
brainfuck_CPU.getProgramString = function(program,programType) {
	var prog = "";
	var commentTemp = false;
	var _g1 = 0;
	var _g = program.length;
	while(_g1 < _g) {
		var i = _g1++;
		prog += program.charAt(i);
		if(programType >= 3 && program.charAt(i) == "#") commentTemp = !commentTemp; else if(programType >= 1 && program.charAt(i) == "@" && !commentTemp) break;
	}
	return prog;
};
brainfuck_CPU.getInitialData = function(program,programType) {
	var data = "";
	var commentTemp = false;
	var _g1 = 0;
	var _g = program.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(program.charAt(i) == "#") commentTemp = !commentTemp; else if(program.charAt(i) == "@" && !commentTemp) data = HxOverrides.substr(program,i + 1,null);
	}
	return data;
};
brainfuck_CPU.prototype = {
	getProgramType: function(program) {
		this.programType = 0;
		if(new EReg("[#0-9A-FlLmMxX]","").match(program)) this.programType = 3; else if(new EReg("[%_=/*\\(\\)?]","").match(program)) this.programType = 2; else if(new EReg("[@|&\\^~{}!\\$]","").match(program)) this.programType = 1;
		return this.programType;
	}
	,setInitialData: function(program,initialData) {
		if(_$UInt_UInt_$Impl_$.gte(this.programType,2)) {
			var _g1 = 0;
			var _g = program.length;
			while(_g1 < _g) {
				var i = _g1++;
				var value = HxOverrides.cca(program,i);
				this.memory[i + 1] = value & 255;
			}
		}
	}
	,init: function(program,type,input,output,bf) {
		if(program == null) program = "";
		this.id = Math.random();
		this.maxStep = 42000;
		if(type == null) this.programType = this.getProgramType(program); else this.programType = type;
		this.storage = new Uint8Array(1);
		this.storagePointer = null;
		this.program = brainfuck_CPU.getProgramString(program,this.programType);
		this.initialData = brainfuck_CPU.getInitialData(program,this.programType);
		if(_$UInt_UInt_$Impl_$.gt(this.programType,1)) this.pointer = this.program.length + 1; else this.pointer = 0;
		if(_$UInt_UInt_$Impl_$.gt(this.programType,1)) this.programPosition = 1; else this.programPosition = 0;
		this.jump = [];
		this.comment = false;
		this.ticks = 0;
		this.xReturn = [];
		if(input == null) this.input = new haxe_io_StringInput(""); else this.input = input;
		if(output == null) this.output = new haxe_io_BytesOutput(); else this.output = output;
		this.bf = bf;
		this.memory = bf.memory;
		this.setInitialData(program,this.initialData);
		this.alive = true;
	}
	,step: function() {
		if(this.alive) {
			this.ticks++;
			try {
				if(_$UInt_UInt_$Impl_$.gte(this.ticks,this.maxStep)) throw new js__$Boot_HaxeError(new brainfuck_BfInfiniteLoop());
				if(this.programPosition >= (_$UInt_UInt_$Impl_$.gt(2,this.programType)?this.program.length:this.memory.length)) throw new js__$Boot_HaxeError(new brainfuck_BfEnd());
				if(this.runCommand(_$UInt_UInt_$Impl_$.gt(2,this.programType)?this.program.charAt(this.programPosition):String.fromCharCode(this.memory[this.programPosition]))) {
				}
			} catch( e ) {
				if (e instanceof js__$Boot_HaxeError) e = e.val;
				this.alive = false;
				throw new js__$Boot_HaxeError(e);
			}
		}
		return this.alive;
	}
	,moveToNextCommand: function() {
		++this.programPosition;
		if(_$UInt_UInt_$Impl_$.gt(2,this.programType)) {
			if(this.programPosition < this.program.length) return this.program.charAt(this.programPosition); else return null;
		} else if(this.programPosition < this.memory.length) return String.fromCharCode(this.memory[this.programPosition]); else return null;
	}
	,moveToPrevCommand: function() {
		--this.programPosition;
		if(_$UInt_UInt_$Impl_$.gt(2,this.programType)) {
			if(this.programPosition < 0) return null; else return this.program.charAt(this.programPosition);
		} else if(this.programPosition < 0) return null; else return String.fromCharCode(this.memory[this.programPosition]);
	}
	,runCommand: function(command) {
		switch(command) {
		case ">":
			if(!this.comment) this.pointer++;
			this.moveToNextCommand();
			break;
		case "<":
			if(!this.comment) {
				this.pointer--;
				if(this.pointer < 0) this.pointer = 0;
			}
			this.moveToNextCommand();
			break;
		case "+":
			if(!this.comment) this.bf.increment(this.pointer,this.id);
			this.moveToNextCommand();
			break;
		case "-":
			if(!this.comment) this.bf.decrement(this.pointer,this.id);
			this.moveToNextCommand();
			break;
		case ".":
			try {
				this.output.writeByte(this.memory[this.pointer]);
			} catch( e ) {
				if (e instanceof js__$Boot_HaxeError) e = e.val;
				throw new js__$Boot_HaxeError(new brainfuck_InvalidMemoryAccessError());
			}
			this.moveToNextCommand();
			break;
		case ",":
			var val;
			try {
				val = this.input.readByte();
			} catch( e1 ) {
				if (e1 instanceof js__$Boot_HaxeError) e1 = e1.val;
				if( js_Boot.__instanceof(e1,haxe_io_Eof) ) {
					throw new js__$Boot_HaxeError(new brainfuck_EndOfInputError());
				} else throw(e1);
			}
			try {
				this.memory[this.pointer] = val & 255;
			} catch( e2 ) {
				if (e2 instanceof js__$Boot_HaxeError) e2 = e2.val;
				throw new js__$Boot_HaxeError(new brainfuck_InvalidMemoryAccessError());
			}
			this.moveToNextCommand();
			break;
		case "[":
			if(!this.comment) {
				var val1;
				var temp = this.programPosition;
				var commentTemp = false;
				try {
					val1 = this.memory[this.pointer];
				} catch( e3 ) {
					if (e3 instanceof js__$Boot_HaxeError) e3 = e3.val;
					throw new js__$Boot_HaxeError(new brainfuck_InvalidMemoryAccessError());
				}
				if(val1 == 0) {
					var count = 1;
					var c = this.moveToNextCommand();
					while(true) {
						if(c == "[" && !commentTemp) ++count; else if(c == "]" && !commentTemp) --count; else if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && c == "@" && !commentTemp) {
							count = 0;
							this.programPosition = temp;
						} else if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && c == "#") commentTemp = !commentTemp;
						if(count == 0) {
							this.moveToNextCommand();
							break;
						}
						c = this.moveToNextCommand();
						if(c == null) throw new js__$Boot_HaxeError(new brainfuck_EndOfProgramError());
					}
				} else this.moveToNextCommand();
			} else this.moveToNextCommand();
			break;
		case "]":
			if(!this.comment) {
				var val2;
				var commentTemp1 = false;
				try {
					val2 = this.memory[this.pointer];
				} catch( e4 ) {
					if (e4 instanceof js__$Boot_HaxeError) e4 = e4.val;
					throw new js__$Boot_HaxeError(new brainfuck_InvalidMemoryAccessError());
				}
				if(val2 > 0) {
					var count1 = 1;
					var c1 = this.moveToPrevCommand();
					while(true) {
						if(c1 == "[" && !commentTemp1) --count1; else if(c1 == "]" && !commentTemp1) ++count1; else if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && c1 == "#") commentTemp1 = !commentTemp1;
						if(count1 == 0) break;
						c1 = this.moveToPrevCommand();
						if(c1 == null) throw new js__$Boot_HaxeError(new brainfuck_EndOfProgramError());
					}
				} else this.moveToNextCommand();
			} else this.moveToNextCommand();
			break;
		case "@":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) throw new js__$Boot_HaxeError(new brainfuck_BfEndAt());
			this.moveToNextCommand();
			break;
		case "$":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) {
				if(this.storagePointer == null) {
					if(_$UInt_UInt_$Impl_$.gt(this.programType,1)) this.bf.assign(0,this.id,this.memory[this.pointer]); else this.storage[0] = this.memory[this.pointer] & 255;
				} else this.bf.assign(this.storagePointer,this.id,this.memory[this.pointer]);
			}
			this.moveToNextCommand();
			break;
		case "!":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) {
				if(this.storagePointer == null) {
					if(_$UInt_UInt_$Impl_$.gt(this.programType,1)) this.bf.assign(this.pointer,this.id,this.memory[0]); else this.bf.assign(this.pointer,this.id,this.storage[0]);
				} else this.bf.assign(this.pointer,this.id,this.memory[this.storagePointer]);
			}
			this.moveToNextCommand();
			break;
		case "^":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) {
				if(this.storagePointer == null) {
					if(_$UInt_UInt_$Impl_$.gt(this.programType,1)) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] ^ this.memory[0]); else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] ^ this.storage[0]);
				} else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] ^ this.memory[this.storagePointer]);
			}
			this.moveToNextCommand();
			break;
		case "&":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) {
				if(this.storagePointer == null) {
					if(_$UInt_UInt_$Impl_$.gt(this.programType,1)) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] & this.memory[0]); else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] & this.storage[0]);
				} else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] & this.memory[this.storagePointer]);
			}
			this.moveToNextCommand();
			break;
		case "|":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) {
				if(this.storagePointer == null) {
					if(_$UInt_UInt_$Impl_$.gt(this.programType,1)) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] | this.memory[0]); else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] | this.storage[0]);
				} else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] | this.memory[this.storagePointer]);
			}
			this.moveToNextCommand();
			break;
		case "{":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] << 1);
			this.moveToNextCommand();
			break;
		case "}":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] >> 1);
			this.moveToNextCommand();
			break;
		case "~":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,1) && !this.comment) this.bf.assign(this.pointer,this.id,~this.memory[this.pointer]);
			this.moveToNextCommand();
			break;
		case "?":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,2) && !this.comment) this.programPosition = this.pointer;
			this.moveToNextCommand();
			break;
		case "*":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,2) && !this.comment) {
				if(this.storagePointer == null) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] * this.memory[0]); else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] * this.memory[this.storagePointer]);
			}
			this.moveToNextCommand();
			break;
		case "/":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,2) && !this.comment) {
				if(this.storagePointer == null) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] / this.memory[0] | 0); else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] / this.memory[this.storagePointer] | 0);
			}
			this.moveToNextCommand();
			break;
		case "=":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,2) && !this.comment) {
				if(this.storagePointer == null) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] + this.memory[0]); else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] + this.memory[this.storagePointer]);
			}
			this.moveToNextCommand();
			break;
		case "_":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,2) && !this.comment) {
				if(this.storagePointer == null) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] - this.memory[0]); else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] - this.memory[this.storagePointer]);
			}
			this.moveToNextCommand();
			break;
		case "%":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,2) && !this.comment) {
				if(this.storagePointer == null) this.bf.assign(this.pointer,this.id,this.memory[this.pointer] % this.memory[0]); else this.bf.assign(this.pointer,this.id,this.memory[this.pointer] % this.memory[this.storagePointer]);
			}
			this.moveToNextCommand();
			break;
		case ":":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && !this.comment) {
				this.pointer += 128 - this.memory[this.pointer];
				if(this.pointer < 0) this.pointer = 0;
			}
			this.moveToNextCommand();
			break;
		case "x":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && !this.comment) {
				var xRet = this.xReturn.pop();
				if(xRet != null) this.pointer = xRet; else this.pointer = this.program.length + 1;
			}
			this.moveToNextCommand();
			break;
		case "X":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && !this.comment) {
				this.xReturn.push(this.pointer);
				this.pointer = this.programPosition;
			}
			this.moveToNextCommand();
			break;
		case "m":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && !this.comment) this.storagePointer = null;
			this.moveToNextCommand();
			break;
		case "M":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && !this.comment) this.storagePointer = this.pointer;
			this.moveToNextCommand();
			break;
		case "l":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && !this.comment) this.bf.unlockCell(this.pointer,this.id);
			this.moveToNextCommand();
			break;
		case "L":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && !this.comment) this.bf.lockCell(this.pointer,this.id);
			this.moveToNextCommand();
			break;
		case "#":
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3)) this.comment = !this.comment;
			this.moveToNextCommand();
			break;
		default:
			if(_$UInt_UInt_$Impl_$.gte(this.programType,3) && new EReg("[0-9A-F]","").match(command)) this.bf.assign(this.pointer,this.id,"0123456789ABCDEF".indexOf(command) * 16);
			this.moveToNextCommand();
			return false;
		}
		return true;
	}
	,__class__: brainfuck_CPU
};
var brainfuck_EndOfProgramError = function() {
};
brainfuck_EndOfProgramError.__name__ = true;
brainfuck_EndOfProgramError.prototype = {
	toString: function() {
		return "End of program reached";
	}
	,__class__: brainfuck_EndOfProgramError
};
var brainfuck_EndOfInputError = function() {
};
brainfuck_EndOfInputError.__name__ = true;
brainfuck_EndOfInputError.prototype = {
	toString: function() {
		return "End of input reached";
	}
	,__class__: brainfuck_EndOfInputError
};
var brainfuck_BfEnd = function() {
};
brainfuck_BfEnd.__name__ = true;
brainfuck_BfEnd.prototype = {
	toString: function() {
		return "BF_END";
	}
	,__class__: brainfuck_BfEnd
};
var brainfuck_BfEndAt = function() {
};
brainfuck_BfEndAt.__name__ = true;
brainfuck_BfEndAt.prototype = {
	toString: function() {
		return "BF_END_COMMAND";
	}
	,__class__: brainfuck_BfEndAt
};
var brainfuck_BfInfiniteLoop = function() {
};
brainfuck_BfInfiniteLoop.__name__ = true;
brainfuck_BfInfiniteLoop.prototype = {
	toString: function() {
		return "BF_INFINITE_LOOP";
	}
	,__class__: brainfuck_BfInfiniteLoop
};
var brainfuck_Lock = function(position,owner) {
	this.position = position;
	this.owner = owner;
};
brainfuck_Lock.__name__ = true;
brainfuck_Lock.prototype = {
	__class__: brainfuck_Lock
};
var haxe__$Int64__$_$_$Int64 = function(high,low) {
	this.high = high;
	this.low = low;
};
haxe__$Int64__$_$_$Int64.__name__ = true;
haxe__$Int64__$_$_$Int64.prototype = {
	__class__: haxe__$Int64__$_$_$Int64
};
var haxe_io_Bytes = function(data) {
	this.length = data.byteLength;
	this.b = new Uint8Array(data);
	this.b.bufferValue = data;
	data.hxBytes = this;
	data.bytes = this.b;
};
haxe_io_Bytes.__name__ = true;
haxe_io_Bytes.ofString = function(s) {
	var a = [];
	var i = 0;
	while(i < s.length) {
		var c = StringTools.fastCodeAt(s,i++);
		if(55296 <= c && c <= 56319) c = c - 55232 << 10 | StringTools.fastCodeAt(s,i++) & 1023;
		if(c <= 127) a.push(c); else if(c <= 2047) {
			a.push(192 | c >> 6);
			a.push(128 | c & 63);
		} else if(c <= 65535) {
			a.push(224 | c >> 12);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		} else {
			a.push(240 | c >> 18);
			a.push(128 | c >> 12 & 63);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		}
	}
	return new haxe_io_Bytes(new Uint8Array(a).buffer);
};
haxe_io_Bytes.prototype = {
	getString: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
		var s = "";
		var b = this.b;
		var fcc = String.fromCharCode;
		var i = pos;
		var max = pos + len;
		while(i < max) {
			var c = b[i++];
			if(c < 128) {
				if(c == 0) break;
				s += fcc(c);
			} else if(c < 224) s += fcc((c & 63) << 6 | b[i++] & 127); else if(c < 240) {
				var c2 = b[i++];
				s += fcc((c & 31) << 12 | (c2 & 127) << 6 | b[i++] & 127);
			} else {
				var c21 = b[i++];
				var c3 = b[i++];
				var u = (c & 15) << 18 | (c21 & 127) << 12 | (c3 & 127) << 6 | b[i++] & 127;
				s += fcc((u >> 10) + 55232);
				s += fcc(u & 1023 | 56320);
			}
		}
		return s;
	}
	,toString: function() {
		return this.getString(0,this.length);
	}
	,__class__: haxe_io_Bytes
};
var haxe_io_BytesBuffer = function() {
	this.b = [];
};
haxe_io_BytesBuffer.__name__ = true;
haxe_io_BytesBuffer.prototype = {
	getBytes: function() {
		var bytes = new haxe_io_Bytes(new Uint8Array(this.b).buffer);
		this.b = null;
		return bytes;
	}
	,__class__: haxe_io_BytesBuffer
};
var haxe_io_Input = function() { };
haxe_io_Input.__name__ = true;
haxe_io_Input.prototype = {
	readByte: function() {
		throw new js__$Boot_HaxeError("Not implemented");
	}
	,__class__: haxe_io_Input
};
var haxe_io_BytesInput = function(b,pos,len) {
	if(pos == null) pos = 0;
	if(len == null) len = b.length - pos;
	if(pos < 0 || len < 0 || pos + len > b.length) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
	this.b = b.b;
	this.pos = pos;
	this.len = len;
	this.totlen = len;
};
haxe_io_BytesInput.__name__ = true;
haxe_io_BytesInput.__super__ = haxe_io_Input;
haxe_io_BytesInput.prototype = $extend(haxe_io_Input.prototype,{
	readByte: function() {
		if(this.len == 0) throw new js__$Boot_HaxeError(new haxe_io_Eof());
		this.len--;
		return this.b[this.pos++];
	}
	,__class__: haxe_io_BytesInput
});
var haxe_io_Output = function() { };
haxe_io_Output.__name__ = true;
haxe_io_Output.prototype = {
	writeByte: function(c) {
		throw new js__$Boot_HaxeError("Not implemented");
	}
	,__class__: haxe_io_Output
};
var haxe_io_BytesOutput = function() {
	this.b = new haxe_io_BytesBuffer();
};
haxe_io_BytesOutput.__name__ = true;
haxe_io_BytesOutput.__super__ = haxe_io_Output;
haxe_io_BytesOutput.prototype = $extend(haxe_io_Output.prototype,{
	writeByte: function(c) {
		this.b.b.push(c);
	}
	,getBytes: function() {
		return this.b.getBytes();
	}
	,__class__: haxe_io_BytesOutput
});
var haxe_io_Eof = function() {
};
haxe_io_Eof.__name__ = true;
haxe_io_Eof.prototype = {
	toString: function() {
		return "Eof";
	}
	,__class__: haxe_io_Eof
};
var haxe_io_Error = { __ename__ : true, __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] };
haxe_io_Error.Blocked = ["Blocked",0];
haxe_io_Error.Blocked.toString = $estr;
haxe_io_Error.Blocked.__enum__ = haxe_io_Error;
haxe_io_Error.Overflow = ["Overflow",1];
haxe_io_Error.Overflow.toString = $estr;
haxe_io_Error.Overflow.__enum__ = haxe_io_Error;
haxe_io_Error.OutsideBounds = ["OutsideBounds",2];
haxe_io_Error.OutsideBounds.toString = $estr;
haxe_io_Error.OutsideBounds.__enum__ = haxe_io_Error;
haxe_io_Error.Custom = function(e) { var $x = ["Custom",3,e]; $x.__enum__ = haxe_io_Error; $x.toString = $estr; return $x; };
var haxe_io_FPHelper = function() { };
haxe_io_FPHelper.__name__ = true;
haxe_io_FPHelper.i32ToFloat = function(i) {
	var sign = 1 - (i >>> 31 << 1);
	var exp = i >>> 23 & 255;
	var sig = i & 8388607;
	if(sig == 0 && exp == 0) return 0.0;
	return sign * (1 + Math.pow(2,-23) * sig) * Math.pow(2,exp - 127);
};
haxe_io_FPHelper.floatToI32 = function(f) {
	if(f == 0) return 0;
	var af;
	if(f < 0) af = -f; else af = f;
	var exp = Math.floor(Math.log(af) / 0.6931471805599453);
	if(exp < -127) exp = -127; else if(exp > 128) exp = 128;
	var sig = Math.round((af / Math.pow(2,exp) - 1) * 8388608) & 8388607;
	return (f < 0?-2147483648:0) | exp + 127 << 23 | sig;
};
haxe_io_FPHelper.i64ToDouble = function(low,high) {
	var sign = 1 - (high >>> 31 << 1);
	var exp = (high >> 20 & 2047) - 1023;
	var sig = (high & 1048575) * 4294967296. + (low >>> 31) * 2147483648. + (low & 2147483647);
	if(sig == 0 && exp == -1023) return 0.0;
	return sign * (1.0 + Math.pow(2,-52) * sig) * Math.pow(2,exp);
};
haxe_io_FPHelper.doubleToI64 = function(v) {
	var i64 = haxe_io_FPHelper.i64tmp;
	if(v == 0) {
		i64.low = 0;
		i64.high = 0;
	} else {
		var av;
		if(v < 0) av = -v; else av = v;
		var exp = Math.floor(Math.log(av) / 0.6931471805599453);
		var sig;
		var v1 = (av / Math.pow(2,exp) - 1) * 4503599627370496.;
		sig = Math.round(v1);
		var sig_l = sig | 0;
		var sig_h = sig / 4294967296.0 | 0;
		i64.low = sig_l;
		i64.high = (v < 0?-2147483648:0) | exp + 1023 << 20 | sig_h;
	}
	return i64;
};
var haxe_io_StringInput = function(s) {
	haxe_io_BytesInput.call(this,haxe_io_Bytes.ofString(s));
};
haxe_io_StringInput.__name__ = true;
haxe_io_StringInput.__super__ = haxe_io_BytesInput;
haxe_io_StringInput.prototype = $extend(haxe_io_BytesInput.prototype,{
	__class__: haxe_io_StringInput
});
var js__$Boot_HaxeError = function(val) {
	Error.call(this);
	this.val = val;
	this.message = String(val);
	if(Error.captureStackTrace) Error.captureStackTrace(this,js__$Boot_HaxeError);
};
js__$Boot_HaxeError.__name__ = true;
js__$Boot_HaxeError.__super__ = Error;
js__$Boot_HaxeError.prototype = $extend(Error.prototype,{
	__class__: js__$Boot_HaxeError
});
var js_Boot = function() { };
js_Boot.__name__ = true;
js_Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else {
		var cl = o.__class__;
		if(cl != null) return cl;
		var name = js_Boot.__nativeClassName(o);
		if(name != null) return js_Boot.__resolveNativeClass(name);
		return null;
	}
};
js_Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str2 = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i1 = _g1++;
					if(i1 != 2) str2 += "," + js_Boot.__string_rec(o[i1],s); else str2 += js_Boot.__string_rec(o[i1],s);
				}
				return str2 + ")";
			}
			var l = o.length;
			var i;
			var str1 = "[";
			s += "\t";
			var _g2 = 0;
			while(_g2 < l) {
				var i2 = _g2++;
				str1 += (i2 > 0?",":"") + js_Boot.__string_rec(o[i2],s);
			}
			str1 += "]";
			return str1;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			if (e instanceof js__$Boot_HaxeError) e = e.val;
			return "???";
		}
		if(tostr != null && tostr != Object.toString && typeof(tostr) == "function") {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js_Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		return str;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
};
js_Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0;
		var _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js_Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js_Boot.__interfLoop(cc.__super__,cl);
};
js_Boot.__instanceof = function(o,cl) {
	if(cl == null) return false;
	switch(cl) {
	case Int:
		return (o|0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return typeof(o) == "boolean";
	case String:
		return typeof(o) == "string";
	case Array:
		return (o instanceof Array) && o.__enum__ == null;
	case Dynamic:
		return true;
	default:
		if(o != null) {
			if(typeof(cl) == "function") {
				if(o instanceof cl) return true;
				if(js_Boot.__interfLoop(js_Boot.getClass(o),cl)) return true;
			} else if(typeof(cl) == "object" && js_Boot.__isNativeObj(cl)) {
				if(o instanceof cl) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
};
js_Boot.__cast = function(o,t) {
	if(js_Boot.__instanceof(o,t)) return o; else throw new js__$Boot_HaxeError("Cannot cast " + Std.string(o) + " to " + Std.string(t));
};
js_Boot.__nativeClassName = function(o) {
	var name = js_Boot.__toStr.call(o).slice(8,-1);
	if(name == "Object" || name == "Function" || name == "Math" || name == "JSON") return null;
	return name;
};
js_Boot.__isNativeObj = function(o) {
	return js_Boot.__nativeClassName(o) != null;
};
js_Boot.__resolveNativeClass = function(name) {
	return $global[name];
};
var js_html_compat_ArrayBuffer = function(a) {
	if((a instanceof Array) && a.__enum__ == null) {
		this.a = a;
		this.byteLength = a.length;
	} else {
		var len = a;
		this.a = [];
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			this.a[i] = 0;
		}
		this.byteLength = len;
	}
};
js_html_compat_ArrayBuffer.__name__ = true;
js_html_compat_ArrayBuffer.sliceImpl = function(begin,end) {
	var u = new Uint8Array(this,begin,end == null?null:end - begin);
	var result = new ArrayBuffer(u.byteLength);
	var resultArray = new Uint8Array(result);
	resultArray.set(u);
	return result;
};
js_html_compat_ArrayBuffer.prototype = {
	slice: function(begin,end) {
		return new js_html_compat_ArrayBuffer(this.a.slice(begin,end));
	}
	,__class__: js_html_compat_ArrayBuffer
};
var js_html_compat_DataView = function(buffer,byteOffset,byteLength) {
	this.buf = buffer;
	if(byteOffset == null) this.offset = 0; else this.offset = byteOffset;
	if(byteLength == null) this.length = buffer.byteLength - this.offset; else this.length = byteLength;
	if(this.offset < 0 || this.length < 0 || this.offset + this.length > buffer.byteLength) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
};
js_html_compat_DataView.__name__ = true;
js_html_compat_DataView.prototype = {
	getInt8: function(byteOffset) {
		var v = this.buf.a[this.offset + byteOffset];
		if(v >= 128) return v - 256; else return v;
	}
	,getUint8: function(byteOffset) {
		return this.buf.a[this.offset + byteOffset];
	}
	,getInt16: function(byteOffset,littleEndian) {
		var v = this.getUint16(byteOffset,littleEndian);
		if(v >= 32768) return v - 65536; else return v;
	}
	,getUint16: function(byteOffset,littleEndian) {
		if(littleEndian) return this.buf.a[this.offset + byteOffset] | this.buf.a[this.offset + byteOffset + 1] << 8; else return this.buf.a[this.offset + byteOffset] << 8 | this.buf.a[this.offset + byteOffset + 1];
	}
	,getInt32: function(byteOffset,littleEndian) {
		var p = this.offset + byteOffset;
		var a = this.buf.a[p++];
		var b = this.buf.a[p++];
		var c = this.buf.a[p++];
		var d = this.buf.a[p++];
		if(littleEndian) return a | b << 8 | c << 16 | d << 24; else return d | c << 8 | b << 16 | a << 24;
	}
	,getUint32: function(byteOffset,littleEndian) {
		var v = this.getInt32(byteOffset,littleEndian);
		if(v < 0) return v + 4294967296.; else return v;
	}
	,getFloat32: function(byteOffset,littleEndian) {
		return haxe_io_FPHelper.i32ToFloat(this.getInt32(byteOffset,littleEndian));
	}
	,getFloat64: function(byteOffset,littleEndian) {
		var a = this.getInt32(byteOffset,littleEndian);
		var b = this.getInt32(byteOffset + 4,littleEndian);
		return haxe_io_FPHelper.i64ToDouble(littleEndian?a:b,littleEndian?b:a);
	}
	,setInt8: function(byteOffset,value) {
		if(value < 0) this.buf.a[byteOffset + this.offset] = value + 128 & 255; else this.buf.a[byteOffset + this.offset] = value & 255;
	}
	,setUint8: function(byteOffset,value) {
		this.buf.a[byteOffset + this.offset] = value & 255;
	}
	,setInt16: function(byteOffset,value,littleEndian) {
		this.setUint16(byteOffset,value < 0?value + 65536:value,littleEndian);
	}
	,setUint16: function(byteOffset,value,littleEndian) {
		var p = byteOffset + this.offset;
		if(littleEndian) {
			this.buf.a[p] = value & 255;
			this.buf.a[p++] = value >> 8 & 255;
		} else {
			this.buf.a[p++] = value >> 8 & 255;
			this.buf.a[p] = value & 255;
		}
	}
	,setInt32: function(byteOffset,value,littleEndian) {
		this.setUint32(byteOffset,value,littleEndian);
	}
	,setUint32: function(byteOffset,value,littleEndian) {
		var p = byteOffset + this.offset;
		if(littleEndian) {
			this.buf.a[p++] = value & 255;
			this.buf.a[p++] = value >> 8 & 255;
			this.buf.a[p++] = value >> 16 & 255;
			this.buf.a[p++] = value >>> 24;
		} else {
			this.buf.a[p++] = value >>> 24;
			this.buf.a[p++] = value >> 16 & 255;
			this.buf.a[p++] = value >> 8 & 255;
			this.buf.a[p++] = value & 255;
		}
	}
	,setFloat32: function(byteOffset,value,littleEndian) {
		this.setUint32(byteOffset,haxe_io_FPHelper.floatToI32(value),littleEndian);
	}
	,setFloat64: function(byteOffset,value,littleEndian) {
		var i64 = haxe_io_FPHelper.doubleToI64(value);
		if(littleEndian) {
			this.setUint32(byteOffset,i64.low);
			this.setUint32(byteOffset,i64.high);
		} else {
			this.setUint32(byteOffset,i64.high);
			this.setUint32(byteOffset,i64.low);
		}
	}
	,__class__: js_html_compat_DataView
};
var js_html_compat_Uint8Array = function() { };
js_html_compat_Uint8Array.__name__ = true;
js_html_compat_Uint8Array._new = function(arg1,offset,length) {
	var arr;
	if(typeof(arg1) == "number") {
		arr = [];
		var _g = 0;
		while(_g < arg1) {
			var i = _g++;
			arr[i] = 0;
		}
		arr.byteLength = arr.length;
		arr.byteOffset = 0;
		arr.buffer = new js_html_compat_ArrayBuffer(arr);
	} else if(js_Boot.__instanceof(arg1,js_html_compat_ArrayBuffer)) {
		var buffer = arg1;
		if(offset == null) offset = 0;
		if(length == null) length = buffer.byteLength - offset;
		if(offset == 0) arr = buffer.a; else arr = buffer.a.slice(offset,offset + length);
		arr.byteLength = arr.length;
		arr.byteOffset = offset;
		arr.buffer = buffer;
	} else if((arg1 instanceof Array) && arg1.__enum__ == null) {
		arr = arg1.slice();
		arr.byteLength = arr.length;
		arr.byteOffset = 0;
		arr.buffer = new js_html_compat_ArrayBuffer(arr);
	} else throw new js__$Boot_HaxeError("TODO " + Std.string(arg1));
	arr.subarray = js_html_compat_Uint8Array._subarray;
	arr.set = js_html_compat_Uint8Array._set;
	return arr;
};
js_html_compat_Uint8Array._set = function(arg,offset) {
	var t = this;
	if(js_Boot.__instanceof(arg.buffer,js_html_compat_ArrayBuffer)) {
		var a = arg;
		if(arg.byteLength + offset > t.byteLength) throw new js__$Boot_HaxeError("set() outside of range");
		var _g1 = 0;
		var _g = arg.byteLength;
		while(_g1 < _g) {
			var i = _g1++;
			t[i + offset] = a[i];
		}
	} else if((arg instanceof Array) && arg.__enum__ == null) {
		var a1 = arg;
		if(a1.length + offset > t.byteLength) throw new js__$Boot_HaxeError("set() outside of range");
		var _g11 = 0;
		var _g2 = a1.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			t[i1 + offset] = a1[i1];
		}
	} else throw new js__$Boot_HaxeError("TODO");
};
js_html_compat_Uint8Array._subarray = function(start,end) {
	var t = this;
	var a = js_html_compat_Uint8Array._new(t.slice(start,end));
	a.byteOffset = start;
	return a;
};
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
String.prototype.__class__ = String;
String.__name__ = true;
Array.__name__ = true;
var Int = { __name__ : ["Int"]};
var Dynamic = { __name__ : ["Dynamic"]};
var Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = { __name__ : ["Class"]};
var Enum = { };
var ArrayBuffer = $global.ArrayBuffer || js_html_compat_ArrayBuffer;
if(ArrayBuffer.prototype.slice == null) ArrayBuffer.prototype.slice = js_html_compat_ArrayBuffer.sliceImpl;
var DataView = $global.DataView || js_html_compat_DataView;
var Uint8Array = $global.Uint8Array || js_html_compat_Uint8Array._new;
haxe_io_FPHelper.i64tmp = (function($this) {
	var $r;
	var x = new haxe__$Int64__$_$_$Int64(0,0);
	$r = x;
	return $r;
}(this));
js_Boot.__toStr = {}.toString;
js_html_compat_Uint8Array.BYTES_PER_ELEMENT = 1;
Main.main();
})(typeof console != "undefined" ? console : {log:function(){}}, typeof window != "undefined" ? window : typeof global != "undefined" ? global : typeof self != "undefined" ? self : this);
