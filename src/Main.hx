package;

import genetic.GeneticAlgorithm;
import genetic.Individual;
import haxe.io.StringInput;
import haxe.io.BytesOutput;
import brainfuck.Brainfuck;
import haxe.io.UInt8Array;

/**
* ...
* @author Hugo Diranzo
*/
class Main {
	public var bf:Brainfuck = new Brainfuck();
	
	private static function onFinish(x:Dynamic):Void{
		trace(x);
	}
	
	static function main() {
		/*var threadPool:ThreadPool = new ThreadPool(8);
		for (i in 0...8){
			threadPool.addTask(function(x:Dynamic):String {
				var bf:Brainfuck = new Brainfuck();
				return "i[" + x + "] : " + bf.execute("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.").getOutput();
			}, i, onFinish);
		}
		threadPool.blockRunAllTasks();*/
		
		/*trace(bf.execute("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.").getOutput());
		trace(bf.execute("++++{+{{{.$>-}}^>++{{{++$<^.$>[-]++{{+^..$>+++|.>++{{{{.<<<<$>>>>>-}}}^.<<.+++.<.<-.>>>+.@").getOutput());
		trace(bf.execute(">++{{$+*.>!++$*+.>!*=--..$>!+++.>++{${*.>++$</$>![<]!-$>=.>>>.+++.<.<-.<<=+++.@").getOutput());
		trace(bf.execute("[.>]@Hello World!").getOutput());
		trace(bf.execute(">5--------.7-----------.+++++++..+++.<2.5+++++++.>.+++.------.--------.2+.").getOutput());*/
		
		var ga : GeneticAlgorithm = new GeneticAlgorithm(100);
		
	}
}