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
	public var fitnessFunction: Individual -> Float;
	public var cloningChance : Float = 0.9;
	public var bf : Brainfuck;
	public var bestIndividual : Individual = new Individual();
	public var debug : Bool = false;
	public var nbGene : UInt = 48;
	
	public function new(?populationSize:UInt = 100, bf: Brainfuck, fitnessFunction: Individual -> Float) {
		init(populationSize, bf, fitnessFunction);
	}
	
	public function init(?populationSize:UInt, bf: Brainfuck, fitnessFunction: Individual -> Float) : GeneticAlgorithm{
		this.bf = bf;
		this.populationSize = populationSize != null ? populationSize : 100;
		population = [for (x in 0...populationSize) [for (y in 0...populationSize) getRandomIndividual(nbGene, [x, y])]];
		this.fitnessFunction = fitnessFunction;
		
		return this;
	}
	
	//Returns random char
	public static function getRandomGene() : String{
		return Math.random() > 0.5 ? Brainfuck.sLegalChars.charAt(Math.floor(Math.random()*Brainfuck.sLegalChars.length))
		: String.fromCharCode(Std.int(Math.floor(Math.random()*256)));
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
	
	public function evaluateFirstPopulation(bf: Brainfuck) : Void {
		if (this.bf == null) this.bf = bf;
		for (i in 0...populationSize){
			for (j in 0...populationSize){
				population[i][j].fitness = getFitness(population[i][j]);
			}
		}
	}
	
	public function getFitness(indi: Individual) : Float{
		var fitness = fitnessFunction(indi);
		if (fitness > bestIndividual.fitness) {
			bestIndividual.dna = indi.dna;
			bestIndividual.fitness = fitness;
			bestIndividual.position = new Array<UInt>();
			bestIndividual.position.push(indi.position[0]);
			bestIndividual.position.push(indi.position[1]);
			#if cpp
				bf.execute(indi.dna,null,"Hello world !");
				Sys.println("\nNew Best ! ");
				Sys.println("Best DNA        : " + indi.dna);
				Sys.println("Best DNA length : " + indi.dna.length);
				Sys.println("Best fitness    : " + fitness);
				Sys.println("Best output     : " + bf.getOutput());
			#end
		}
		
		return fitness;
	}
	
	//Kills 1/4 of the population
	public function makeDarwinDoHisJob() : Void {	//TODO: find a better name ?
		var nbIndividualKilled : UInt = 0;
		loop(0, populationSize, 2, function(i:Int){
			loop(0, populationSize, 2, function(j:Int){
				var tournamentPlayers : Array<Individual> = new Array<Individual>();
				tournamentPlayers.push(population[i][j]);
				tournamentPlayers.push(population[i][j+1]);
				tournamentPlayers.push(population[i+1][j]);
				tournamentPlayers.push(population[i+1][j+1]);
				
				//Sort from worst to best
				tournamentPlayers.sort(function(indi1 : Individual, indi2 : Individual) : Int{
					return indi1.fitness < indi2.fitness ? -1 : indi2.fitness < indi1.fitness ? 1 : 0;
				});
				
				//Worst have 1/2 chance of dying, second worst have 1/4, third 1/8, fourth 1/16, else nobody dies
				//Only one can die
				for (k in 0...tournamentPlayers.length){
					var rand : Float = Math.random();
					if (rand < 0.5){
						population[tournamentPlayers[k].position[0]][tournamentPlayers[k].position[1]] = null;
						nbIndividualKilled ++;
						break;
					}
				}
			});
		});
		//trace("Number of individual killed : " + nbIndividualKilled);
	}
	
	//Fills the holes in the population
	public function repopulate() : Void {
		var nbIndividualBorn : UInt = 0;
		for (i in 0...population.length){
			for (j in 0...population[i].length){
				if (population[i][j] == null) {
					var nearest : Array<Individual> = new Array<Individual>();
					var indi: Individual = new Individual();
					
					//find the nearest individuals
					for (k in -1...2){
						for (l in -1...2){
							if (k == 0 && l == 0){
								continue;
							}
							if ( i + k >= 0 && i + k < population.length && j + l >= 0 && j + l < population.length){
								if (population[i + k][j + l] != null){
									nearest.push(population[i + k][j + l]);
								}
							}
						}
					}
					
					if (nearest.length > 1){
						//Random parents among nearests
						shuffleArray(nearest);
						if (Math.random() < cloningChance){
							indi = mutate(nearest[0]);
						}else{
							cross(nearest[0], nearest[1]);
						}
					}else if (nearest.length == 1){
						indi = mutate(nearest[0]);
					}else{
						throw new NotEnoughParentsError();
					}
					
					if (Math.random()*10000 < 1){
						indi.dna = "[.>]@Hello World!";
					}
					
					indi.position = [i,j];
					indi.fitness = getFitness(indi);
					population[i][j] = indi;
					nbIndividualBorn ++;
				}
			}
		}
		//trace("Number of individual born : " + nbIndividualBorn);
	}
	
	public function cross(parent1: Individual, parent2: Individual) : Individual {
		var indi: Individual = new Individual();
		
		if (debug) trace("");
		
		if (Math.random() < 0.1){
			indi = crossPoint(parent1, parent2);
		}else{
			indi = crossMix(parent1, parent2);
		}
		
		if (debug) trace("DNA child   : " + bf.escape(indi.dna));
		
		indi = mutate(indi);
		
		return indi;
	}
	
	//Each gene have 50/50 chances of being from parent1/parent2
	public function crossMix (parent1: Individual, parent2: Individual) : Individual{
		var indi: Individual = new Individual();
		
		if (debug) trace("Cross Mix");
		if (debug) trace("DNA parent1 : " + bf.escape(parent1.dna));
		if (debug) trace("DNA parent2 : " + bf.escape(parent2.dna));
		
		for (i in 0...parent1.dna.length){
			if (parent2.dna.length <= i){
				indi.dna += parent1.dna.charAt(i);
			}else{
				indi.dna += Math.random() < 0.5 ? parent1.dna.charAt(i) : parent2.dna.charAt(i);
			}
		}
		
		return indi;
	}
	
	//Child get one part of parent1 DNA, the other from parent2
	public function crossPoint (parent1: Individual, parent2: Individual) : Individual{
		var indi = new Individual();
		
		if (debug) trace("Cross Point");
		if (debug) trace("DNA parent1 : " + bf.escape(parent1.dna));
		if (debug) trace("DNA parent2 : " + bf.escape(parent2.dna));
		
		var point : UInt = Std.int(Math.floor(Math.random()*Math.min(parent1.dna.length, parent2.dna.length)));
		for (i in 0...parent2.dna.length){
			if (point < i){
				indi.dna += parent1.dna.charAt(i);
			}else{
				indi.dna += parent2.dna.charAt(i);
			}
		}
		return indi;
	}
	
	public function mutate(parent: Individual) : Individual {
		var indi = new Individual();
		
		for (i in 0...parent.dna.length){
			indi.dna += parent.dna.charAt(i);
		}
		
		if (debug) trace("");
		
		var b:UInt = 1;
		while (b-- == 0 || Math.random()<0.5){
			var rand = Math.random();
			if (rand < 0.5){
				mutationGeneChange(indi);
			}else if (rand < 0.75){
				mutationGeneAdd(indi);
			}else{
				mutationGeneRemove(indi);
			}
		}
		
		if (debug) trace("DNA child  : " + bf.escape(indi.dna));
		
		return indi;
	}
	
	//Adds a random gene at a random location
	public function mutationGeneAdd(indi: Individual) : Individual {
		var newDna : String = "";
		var indice : UInt = Math.floor(Math.random() * indi.dna.length);
		
		if (debug) trace("Mutation Gene Add");
		if (debug) trace("DNA parent : " + bf.escape(indi.dna));
		
		for (i in 0...indi.dna.length+1){
			if (i < indice){
				newDna += indi.dna.charAt(i);
			}else if (i == indice){
				newDna += getRandomGene();
			}else{
				newDna += indi.dna.charAt(i-1);
			}
		}
		indi.dna = newDna;
		return indi;
	}
	
	//Removes a random gene
	public function mutationGeneRemove(indi: Individual) : Individual {
		var newDna : String = "";
		var indice : UInt = Math.floor(Math.random() * indi.dna.length);
		
		if (debug) trace("Mutation Gene Remove");
		if (debug) trace("DNA parent : " + bf.escape(indi.dna));
		
		for (i in 0...indi.dna.length){
			if (i != indice){
				newDna += indi.dna.charAt(i);
			}
		}
		
		indi.dna = newDna;
		return indi;
	}
	
	//Sets a random gene by a random value
	public function mutationGeneChange(indi: Individual) : Individual {
		var newDna : String = "";
		var indice : UInt = Math.floor(Math.random() * indi.dna.length);
		
		if (debug) trace("Mutation Gene Change");
		if (debug) trace("DNA parent : " + bf.escape(indi.dna));
		
		for (i in 0...indi.dna.length){
			if (i != indice){
				newDna += indi.dna.charAt(i);
			}else if (i == indice){
				newDna += getRandomGene();
			}
		}
		
		indi.dna = newDna;
		return indi;
	}
	
	//Single point swap
	public function mutationGenesSwap(indi: Individual) : Individual {
		return indi;
	}
}

class NotEnoughParentsError {
	public function new():Void {
		
	}
	
	public function toString():String {
		return "Not Enough Parents !";
	}
}