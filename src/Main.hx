package;

import genetic.GeneticAlgorithm;
import genetic.Individual;
import brainfuck.Brainfuck;
import haxe.io.StringInput;
import haxe.io.BytesOutput;
import haxe.io.UInt8Array;
import nolib.Nolib;

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
		
		bf.maxStep = 12000;
		bf.memorySize = 128;
		
		try{
			bf.execute("+[,.]@", null, "Brainfuck yeah !");
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
			
			if (fitness != 0) trace("Fitness: "+fitness);
			return fitness;
		});
		
		#if cpp
			var t:Float = Sys.time();
		#end
		ga.evaluateFirstPopulation(bf);
		#if cpp
			trace(Nolib.fixedFloat(Sys.time() - t, 3));
		#end
		
	}
}