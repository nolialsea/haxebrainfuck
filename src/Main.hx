package;

import genetic.GeneticAlgorithm;
import genetic.Individual;
import brainfuck.Brainfuck;
import haxe.io.StringInput;
import haxe.io.BytesOutput;
import haxe.io.UInt8Array;
import nolib.Nolib;
import haxe.Log;
import Sys;

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
		bf.memorySize = 256;
		var nbIndividual = 32;

		var ga : GeneticAlgorithm = new GeneticAlgorithm(nbIndividual, bf, function (indi:Individual) : Float{
			var fitness: Float = 0;
			var bfOutput : String;
			//trace(indi.dna);
			
			
			var target = "Hello world !";
			bf.execute(indi.dna, null);
			bfOutput = bf.getOutput();
			if (bfOutput != null && bfOutput.length > 0) {
				for (i in 0...target.length){
					if (i < bfOutput.length){
						fitness += 256 - (Math.abs(bfOutput.charCodeAt(i) - target.charCodeAt(i)));
					}
				}
			}
			
			if (bfOutput.length > target.length){
				fitness -= (bfOutput.length - target.length);
			}
			
			fitness -= indi.dna.length/1000;
			
			//if (fitness != 0) trace("Fitness: "+fitness);
			return fitness;
		});
		
		#if cpp
			var t:Float = Sys.time();
		#end
		ga.evaluateFirstPopulation(bf);
		#if cpp
			Sys.println("\nFirst population evaluation time : " + Nolib.fixedFloat(Sys.time() - t, 2) + 
				" seconds for " +Math.pow(ga.populationSize, 2)+ " individuals");
		#end
		
		var i:UInt = 0;
		while (++i < 999999 || true){
			#if cpp
				var t:Float = Sys.time();
			#end
			ga.makeDarwinDoHisJob();
			ga.repopulate(i);
			#if cpp
				//if (i%10 == 0) Sys.println("\nGeneration " + i +" executed in " + Nolib.fixedFloat(Sys.time() - t, 2) + " seconds");
			#else
				//trace("Generation " + i);
			#end
			
		}
	}
	
	
}