# haxebrainfuck
Brainfuck interpreter with extended types in haxe

Don't mind the CPU thing, I intended to run multiple "threads" on the same memory alternatively, but it was for another project.  
Just consider it's a single core and it will be fine.  
I will rewrite this part, if I feel I need to, maybe, one day. Maybe never.  

####Example  
```
var bf: Brainfuck = new Brainfuck();
bf.execute("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.");
trace(bf.getOutput());
trace(bf.programType);
trace(bf.execute("++++{+{{{.$>-}}^>++{{{++$<^.$>[-]++{{+^..$>+++|.>++{{{{.<<<<$>>>>>-}}}^.<<.+++.<.<-.>>>+.@").getOutput());
trace(bf.execute(">++{{$+*.>!++$*+.>!*=--..$>!+++.>++{${*.>++$</$>![<]!-$>=.>>>.+++.<.<-.<<=+++.@").getOutput());
trace(bf.execute("[.>]@Hello World!").getOutput());
trace(bf.execute(">5--------.7-----------.+++++++..+++.<2.5+++++++.>.+++.------.--------.2+.").getOutput());
```

You can enforce extended types  
```
trace(bf.execute("[.>]@Hello World!", 0).getOutput());
```
Note that this does nothing interesting since it is Extended III code, running with vanilla Brainfuck rules  

####Types
  0 : Vanilla Brainfuck  
  1 : Extended Type I  
  2 : Extended Type II  
  3 : Extended Type III
