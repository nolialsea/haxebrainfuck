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
	public static var bf:Brainfuck = new Brainfuck();
	
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
		
		
		
		/*for (i in 0...1000){
			var s = "";
			for (j in 0...100){
				s += GeneticAlgorithm.getRandomGene();
			}
			bf.execute(s);
		}*/
		
		var ga : GeneticAlgorithm = new GeneticAlgorithm(10, function (bf: Brainfuck, indi:Individual) : Float{
			var fitness: Float = 0;
			//trace(indi.dna);
			bf.execute(indi.dna);
			return fitness;
		});

		ga.evaluateFirstPopulation(bf);
		
		//trace("FITNESS " + ga.population[0][0].fitness);
		
		//trace(ga.getRandomIndividualFromPopulation());
	}
}