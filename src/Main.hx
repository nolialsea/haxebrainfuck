package;

import genetic.GeneticAlgorithm;
import genetic.Individual;
import brainfuck.Brainfuck;
import haxe.io.StringInput;
import haxe.io.BytesOutput;
import haxe.io.UInt8Array;

/**
* ...
* @author Hugo Diranzo
*/
class Main {
	private static var bf:Brainfuck = new Brainfuck();
	
	private static function onFinish(x:Dynamic):Void{
		trace(x);
	}
	
	static function main() {
		/*
		//Parallel processing is planned, but it is for a bit later.
		var threadPool:ThreadPool = new ThreadPool(8);
		for (i in 0...8){
			threadPool.addTask(function(x:Dynamic):String {
				var bf:Brainfuck = new Brainfuck();
				return "i[" + x + "] : " + bf.execute("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.").getOutput();
			}, i, onFinish);
		}
		threadPool.blockRunAllTasks();
		*/
		
		/*
		//Hello world with different types
		trace(bf.execute("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.").getOutput());
		trace(bf.execute("++++{+{{{.$>-}}^>++{{{++$<^.$>[-]++{{+^..$>+++|.>++{{{{.<<<<$>>>>>-}}}^.<<.+++.<.<-.>>>+.@").getOutput());
		trace(bf.execute(">++{{$+*.>!++$*+.>!*=--..$>!+++.>++{${*.>++$</$>![<]!-$>=.>>>.+++.<.<-.<<=+++.@").getOutput());
		trace(bf.execute("[.>]@Hello World!").getOutput());
		trace(bf.execute(">5--------.7-----------.+++++++..+++.<2.5+++++++.>.+++.------.--------.2+.").getOutput());
		
		//Hello world with forced type
		//And yes, this one does nothing interesting since data initialisation is only Type II or above
		trace(bf.execute("[.>]@Hello World!", 1).getOutput());	//Forced Type I
		*/
		try{
			bf.execute("+++++[>,.<-]@", null, "test");
		}catch (e:Dynamic){
			trace(e);
			trace(bf.getOutput());
		}
		
		var ga : GeneticAlgorithm = new GeneticAlgorithm(32, function (bf: Brainfuck, indi:Individual) : Float{
			var fitness: Float = 0;
			var bfOutput : String;
			//trace(indi.dna);
			try{
				bf.execute(indi.dna, null, "12");
			}catch (e:Dynamic){}
			
			bfOutput = bf.getOutput();
			
			if (bfOutput != null && bfOutput.length > 0) {
				fitness += 256 - (Math.abs(bfOutput.charCodeAt(0) - "3".charCodeAt(0)));
			}
			
			//if (fitness != 0) trace("Fitness: "+fitness);
			return fitness;
		});

		ga.evaluateFirstPopulation(bf);
		
	}
}