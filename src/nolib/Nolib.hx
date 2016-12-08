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
	
	public static function getLevenshteinDistance( left:String, right:String ):Int {
        if ( left.length == 0 ) {
            return right.length;
        }
        if ( right.length == 0 ) {
            return left.length;
        }
        var matrix = [];
        var i:Int = 0;
        while ( i < right.length ) {
          matrix[ i ] = [ i ];
          i++;
        }
        var j:Int = 0;
        while ( j < left.length ) {
          matrix[ 0 ][ j ] = j;
          j++;
        }
        i = 1;
        while ( i < right.length ) {
            j = 1;
            while ( j < left.length ) {
                if ( right.charAt( i - 1) == left.charAt( j - 1 ) ) {
                    matrix[ i ][ j ] = matrix[ i - 1 ][ j - 1 ];
                } else {
                    matrix[ i ][ j ] = cast( Math.min( matrix[ i - 1][ j - 1] + 1, // substitution
                                                 Math.min( matrix[ i ][ j - 1 ] + 1, // insertion
                                                           matrix[ i - 1 ][ j ] + 1)), Int); // deletion
                }
                j++;
            }
            i++;
        }
        return matrix[ right.length - 1 ][ left.length - 1 ];
    }
}