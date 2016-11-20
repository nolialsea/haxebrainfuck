package brainfuck;

/**
* ...
* @author Hugo Diranzo
*/
class Lock {
	public var position:UInt;
	public var owner:Float;
	public var closed:Bool;

	public function new(position: UInt, owner: Float) {
		this.position = position;
		this.owner = owner;
	}
}