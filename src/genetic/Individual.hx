package genetic;

/**
* ...
* @author Hugo Diranzo
*/
class Individual {
	public var dna: String;
	public var fitness: Float;
	public var x: UInt;
	public var y: UInt;
	public var z: UInt;

	public function new(position: Array<UInt>, ?dna: String, ?fitness: Float) {
		init(dna, fitness);
	}
	
	public function init(?dna: String, ?fitness: Float) {
		this.dna = dna == null ? "" : dna;
		this.fitness = fitness == null ? 0 : fitness;
	}
}