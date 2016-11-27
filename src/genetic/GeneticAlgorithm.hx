package genetic;
import brainfuck.Brainfuck;
import nolib.Nolib.loop;
import nolib.Nolib.shuffleArray;

/**
* ...
* @author Hugo Diranzo
*/
class GeneticAlgorithm {
	public var populationSize: UInt;	//per array
	public var population: Array<Array<Null<Individual>>>;
	public var fitnessFunction: Brainfuck -> Individual -> Float;
	public var cloningChance : Float = 0.1;
	
	public function new(?populationSize:UInt = 100, fitnessFunction: Brainfuck -> Individual -> Float) {
		init(populationSize, fitnessFunction);
	}
	
	public function init(?populationSize:UInt, fitnessFunction: Brainfuck -> Individual -> Float) : GeneticAlgorithm{
		this.populationSize = populationSize != null ? populationSize : 100;
		population = [for (x in 0...populationSize) [for (y in 0...populationSize) getRandomIndividual(64, [x, y])]];
		this.fitnessFunction = fitnessFunction;
		
		return this;
	}
	
	//Returns random char
	public static function getRandomGene() : String{
		return String.fromCharCode(Std.int(Math.floor(Math.random()*256)));
	}
	
	//Create a brand new random individual
	public static function getRandomIndividual(?dnaLength:UInt = 64, ?position:Array<UInt>) : Individual{
		var indi : Individual = new Individual(position);
		for (i in 0...(dnaLength)){
			indi.dna += getRandomGene();
		}
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
				population[i][j].fitness = fitnessFunction(bf, population[i][j]);
			}
		}
	}
	
	//Kills 1/4 of the population
	public function makeDarwinDoHisJob() : Void {	//TODO: find a better name ?
		loop(0, populationSize, 2, function(i:Int){
			loop(0, populationSize, 2, function(j:Int){
				var tournamentPlayers : Array<Individual> = new Array<Individual>();
				tournamentPlayers.push(population[i][j]);
				tournamentPlayers.push(population[i][j+1]);
				tournamentPlayers.push(population[i+1][j]);
				tournamentPlayers.push(population[i+1][j+1]);
				
				//Sort from worst to best
				tournamentPlayers.sort(function(indi1 : Individual, indi2 : Individual) : Int{
					return indi1.fitness > indi2.fitness ? -1 : indi2.fitness > indi1.fitness ? 1 : 0;
				});
				
				//Worst have 1/2 chance of dying, second worst have 1/4, third 1/8, fourth 1/16, else nobody dies
				//Only one can die
				var rand : Float = Math.random();
				for (k in 0...tournamentPlayers.length){
					if (rand < 1/(Math.pow(2,k+1)) ){
						population[tournamentPlayers[k].position[0]][tournamentPlayers[k].position[1]] = null;
						break;
					}
				}
			});
		});
	}
	
	//Fills the holes in the population
	public function repopulate() : Void {
		for (i in 0...population.length){
			for (j in 0...population[i].length){
				if (population[i][j] == null) {
					var nearest : Array<Individual> = new Array<Individual>();
					
					//find the nearest individuals
					for (k in -1...2){
						for (l in -1...2){
							if (k == 0 && l == 0){
								continue;
							}
							if ( i+k >= 0 && i+k < population.length && j+l >= 0 && j+l < population.length && population[i+k][j+l] != null){
								nearest.push(population[i][j]);
							}
						}
					}
					
					
					if (nearest.length > 1){
						shuffleArray(nearest);
						
					}else if (nearest.length == 1){
						
					}
				}
			}
		}
	}
	
	public function step(iteration: UInt = 1) : Void {
		
	}
	
	public function cross(parent1: Individual, parent2: Individual) : Individual {
		var indi = new Individual();
		for (i in 0...parent1.dna.length){
			
		}
		return indi;
	}
	
	public function mutate(indi: Individual) : Individual {
		return new Individual();
	}
	
}