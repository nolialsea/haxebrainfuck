package genetic;
import brainfuck.Brainfuck;

/**
* ...
* @author Hugo Diranzo
*/
class GeneticAlgorithm {
	public var populationSize: UInt;	//per array
	public var population: Array<Array<Individual>>;
	public var fitnessFunction: Brainfuck -> Individual -> Float;
	
	public function new(?populationSize:UInt = 100) {
		init(populationSize);
	}
	
	public function init(?populationSize:UInt) : GeneticAlgorithm{
		this.populationSize = populationSize != null ? populationSize : 100;
		population = [for (x in 0...populationSize) [for (y in 0...populationSize) getRandomIndividual(64, [x, y])]];
		
		return this;
	}
	
	//Returns random char
	public static function getRandomGene() : String{
		/*
		//Restricted number of charCode : more readable dna and bf code
		var min:UInt = 11;
		var max:UInt =  127;
		return String.fromCharCode(Std.int(Math.floor(Math.random()*(max-min)+min)));
		*/
		return String.fromCharCode(Std.int(Math.floor(Math.random()*256)));
	}
	
	//Create a brand new random individual
	public static function getRandomIndividual(?dnaLength:UInt = 64, ?position:Array<UInt>) : Individual{
		var indi : Individual = new Individual(position);
		for (i in 0...(dnaLength-1)){
			indi.dna += getRandomGene();
		}
		indi.dna += "@";
		return indi;
	}
	
	public function getRandomIndividualFromPopulation() : Individual{
		return population[Math.floor(Math.random()*populationSize)][Math.floor(Math.random()*populationSize)];
	}
	
	//Create a new individual by selection/cloning
	public function getNewIndividual() : Individual {
		return new Individual();
	}
	
	public function pushIndividual(indi: Individual) : Void {
		//indi.fitness = fitnessFunction(indi);
	}
	
	public function evaluateFirstPopulation(bf: Brainfuck) : Void {
		for (i in 0...populationSize){
			for (j in 0...populationSize){
				population[i][j].fitness = calculateFitness(bf, population[i][j]);
			}
		}
	}
	
	public function step(iteration: UInt = 1) : Void {
		
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

	public function calculateFitness(bf: Brainfuck, indi:Individual) : Float{
		return fitnessFunction(bf, indi);
	}
	
}