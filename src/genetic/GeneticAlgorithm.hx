package genetic;
import brainfuck.Brainfuck;
import haxe.Int64;
import nolib.Nolib;
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
	public var nbGene : UInt = 64;
	private var nextId: Int64 = 0;
	
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
	
	public static function escapeString(s: String) : String{
		var newString : String = "";
		for (i in 0...s.length){
			if (s.charCodeAt(i) >= 30 || s.charCodeAt(i) == 10){
				newString += s.charAt(i);
			}
		}
		return newString;
	}
	
	public function escape(s: String) : String{
		return GeneticAlgorithm.escapeString(s);
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
				if (i % 2 == 0 && j % 2 == 0){
					//population[i][j].dna = "--------.2${|+++++.<..7-.!.X-|.7-.+++.7----.6++++.&!.+.";
				}
				
				//population[i][j].dna = ".>.>.>@Hello world !";
				
				population[i][j].fitness = getFitness(population[i][j], 0);
			}
		}
	}
	
	public function getFitness(indi: Individual, ?generation: Int) : Float{
		var fitness = fitnessFunction(indi);
		indi.id = nextId++;
		if (fitness > bestIndividual.fitness) {
			bestIndividual.id = indi.id;
			bestIndividual.dna = indi.dna;
			bestIndividual.fitness = fitness;
			bestIndividual.output = indi.output;
			bestIndividual.position = new Array<UInt>();
			bestIndividual.position.push(indi.position[0]);
			bestIndividual.position.push(indi.position[1]);
			
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
	public function repopulate(?generation : Int) : Void {
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
					
					indi.position = [i,j];
					indi.fitness = getFitness(indi, generation);
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
		
		var mutations : Array<Individual-> Void> = [
			mutationGeneChange,
			mutationGeneAdd,
			mutationGeneRemove,
			mutationGeneRemoveBlock,
			mutationGenesSwap,
			mutationGenesSwapBlock
		];
		
		var b:UInt = 1;
		while (b-- == 0 || Math.random()<0.5){
			var rand = Nolib.randint(0, mutations.length);
			mutations[rand](indi);
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
	
	//Removes a random gene block
	public function mutationGeneRemoveBlock(indi: Individual) : Individual {
		var newDna : String = "";
		var indice : UInt = Math.floor(Math.random() * indi.dna.length);
		var length : UInt = Nolib.randint(2, 16);
		if (debug) trace("Mutation Gene Remove");
		if (debug) trace("DNA parent : " + bf.escape(indi.dna));
		
		for (i in 0...indi.dna.length){
			if (i < indice){
				newDna += indi.dna.charAt(i);
			}else if (i >= indice && i < indice + length){
				//Nothing
			}else{
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
	
	//Swaps two random genes
	public function mutationGenesSwap(indi: Individual) : Individual {
		var newDna : String = "";
		var indice1 : UInt = Math.floor(Math.random() * indi.dna.length);
		var indice2 : UInt = Math.floor(Math.random() * indi.dna.length);
		
		if (debug) trace("Mutation Gene Swap");
		if (debug) trace("DNA parent : " + bf.escape(indi.dna));
		
		for (i in 0...indi.dna.length){
			if (i == indice1){
				newDna += indi.dna.charAt(indice2);
			}else if (i == indice2){
				newDna += indi.dna.charAt(indice1);
			}else{
				newDna += indi.dna.charAt(i);
			}
		}
		
		indi.dna = newDna;
		return indi;
	}
	
	//Swaps two random block of genes
	public function mutationGenesSwapBlock(indi: Individual) : Individual {
		if (indi.dna.length > 10){
			var newDna : String = "";
			var length : UInt = Nolib.randint(2,5);
			var indice1 : UInt = Math.floor(Math.random() * (indi.dna.length-length));
			var indice2 : UInt = Math.floor(Math.random() * (indi.dna.length-length));
			
			if (debug) trace("Mutation Gene Swap");
			if (debug) trace("DNA parent : " + bf.escape(indi.dna));
			
			for (i in 0...indi.dna.length){
				if (i >= indice1 && i < indice1+length){
					newDna += indi.dna.charAt(indice2+(i-indice1));
				}else if (i >= indice2 && i < indice2+length){
					newDna += indi.dna.charAt(indice1+(i-indice2));
				}else{
					newDna += indi.dna.charAt(i);
				}
			}
			
			indi.dna = newDna;
		}
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