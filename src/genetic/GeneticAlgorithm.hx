package genetic;
import brainfuck.Brainfuck;

/**
* ...
* @author Hugo Diranzo
*/
class GeneticAlgorithm {
	public var population: Array<Individual> = new Array<Individual>();
	public var populationSize: UInt;
	public var fitnessFunction: Dynamic -> Dynamic;
	public var bigArray:Array<Array<Individual>> = [for (x in 0...10) [for (y in 0...10) new Individual()]];

	public function new(?populationSize:UInt = 100) {
		init(populationSize);
	}
	
	public function init(?populationSize:UInt) : GeneticAlgorithm{
		this.populationSize = populationSize != null ? populationSize : 100;
		
		population.splice(0, population.length);
		
		return this;
	}
	
	//Create a brand new random individual
	public static function getRandomIndividual(?dnaLength:UInt = 64) : Individual{
		var indi : Individual = new Individual();
		for (i in 0...dnaLength){
			indi.dna += String.fromCharCode(Std.int(Math.random()*256));
		}
		return indi;
	}
	
	//Create a new individual by selection/
	public function getNewIndividual() : Individual {
		
		return new Individual();
	}
	
	public function pushIndividual(indi: Individual) : Void {
		fitnessFunction(indi);
	}
	
	public function bfToIndividual() : Individual {
		return new Individual();
	}
	
	public function getFitness(bf: Brainfuck) : Float {
		
		return 0;
	}
	
	public function cross() : Individual {
		
		return new Individual();
	}
	
	public function mutate(indi: Individual) : Individual {
		
		return new Individual();
	}
	
}