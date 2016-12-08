package genetic;
import haxe.Int64;

/**
* ...
* @author Hugo Diranzo
*/
class Individual {
	public var dna: String;
	public var fitness: Float;
	public var position: Array<UInt>;
	public var id: Int64 = -1;
	public var type: UInt;
	public var output: Null<String>;

	public function new(?position: Array<UInt>, ?dna: String, ?fitness: Float) {
		init(position, dna, fitness);
	}
	
	public function init(?position: Array<UInt>, ?dna: String, ?fitness: Float) {
		this.position = position == null ? new Array<UInt>() : position;
		this.dna = dna == null ? "" : dna;
		this.fitness = fitness == null ? 0 : fitness;
	}
}