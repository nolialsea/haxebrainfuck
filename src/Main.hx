package;

import haxe.io.StringInput;
import haxe.io.BytesOutput;
import neko.Lib;
import brainfuck.Brainfuck;
import haxe.io.UInt8Array;

/**
* ...
* @author Hugo Diranzo
*/
class Main {
	private static function onFinish(x:Dynamic):Void{
		trace(x);
	}
	
	static function main() {
		/*var threadPool:ThreadPool = new ThreadPool(8);
		for (i in 1...2){
			threadPool.addTask(function(x:Dynamic):String {
				var bf = new Brainfuck(
					"++++++++[>+++++++++<]>.<+++++[>++++++<]>.+++++++..+++.<++++++++[>>++++<<]>>.<<++++[><]>.<++++[>++++++<]>.+++...>+.",
					new StringInput(i+"+"+(i*2))).run();
				return cast(bf[0].output, BytesOutput).getBytes().toString();
			}, null, onFinish);
		}
		threadPool.blockRunAllTasks();*/
		
		var bf:Brainfuck = new Brainfuck();
		
		trace(bf.execute("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.").getOutput());
		trace(bf.execute("++++{+{{{.$>-}}^>++{{{++$<^.$>[-]++{{+^..$>+++|.>++{{{{.<<<<$>>>>>-}}}^.<<.+++.<.<-.>>>+.@").getOutput());
		trace(bf.execute(">++{{$+*.>!++$*+.>!*=--..$>!+++.>++{${*.>++$</$>![<]!-$>=.>>>.+++.<.<-.<<=+++.@").getOutput());
		trace(bf.execute("[.>]@Hello World!").getOutput());
		trace(bf.execute(">5--------.7-----------.+++++++..+++.<2.5+++++++.>.+++.------.--------.2+.").getOutput());
	}
}