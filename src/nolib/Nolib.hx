package nolib;

/**
* ...
* @author Hugo Diranzo
*/
class Nolib {

	public function new() {
		
	}
	
	private static inline function int(from:Int, to:Int):Int{
		return from + Math.floor(((to - from + 1) * Math.random()));
	}
	
	public static function fixedFloat(v:Float, ?precision:Int = 2):Float{
		return Math.round( v * Math.pow(10, precision) ) / Math.pow(10, precision);
	}
	
	public static function randint(from:Int, to:Int):Int{
		return from + Math.floor(((to - from) * Math.random()));
	}

	//If you know how to achieve that more efficiently, i'm willing to know
	public static function loop(start:Int, end:Int, step:Int = 1, func:Int -> Void){
		var i = start;
		while ( i < end ){
			func(i);
        i += step;
        }
	}
	
	public static function shuffleArray<T>(arr:Array<T>):Array<T>{
		if (arr!=null) {
			for (i in 0...arr.length) {
				var j = int(0, arr.length - 1);
				var a = arr[i];
				var b = arr[j];
				arr[i] = b;
				arr[j] = a;
			}
		}
		return arr;
	}
}