# haxebrainfuck
Brainfuck interpreter with extended types in haxe

Don't mind the CPU thing, I intended to run multiple "threads" on the same memory alternatively, but it was for another project.  
Just consider it's a single core and it will be fine.  
I will rewrite this part, if I feel I need to, maybe, one day. Maybe never.  

####Example  
```haxe
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
```haxe
trace(bf.execute("[.>]@Hello World!", 0).getOutput());
```
Note that this does nothing interesting since it is Extended III code, running with vanilla Brainfuck rules  

####Types
  0 : Vanilla Brainfuck  
  1 : Extended Type I  
  2 : Extended Type II  
  3 : Extended Type III (missing)

I'm currently working on the Genetic Algorithm, which will be used to generate brainfuck programs.
In theory, you can produce ANY program. But here is the catch... You have to ask the right thing.

####What the f*ck is a CPU ?
Basically, I intended to create a simplified [Avida] (https://en.wikipedia.org/wiki/Avida) like program.  
Each "creature" would be a cpu, running a brainfuck program (which would be part of its DNA) on a shared memory.  
Brainfuck seemed one of the best choices for the programming langage, since it is crazy simple, and can be extended indefinitively.
The ability to self modify its code at run time was not necessary, but is a HUGE plus.  
This Avida like program required to extend the commands with new simulation related one, so i choosed not to do it on this project and reuse this one when the time come. *And it will come*.


##TODO
- [ ] Rewrite the switch that reads the instructions  
  Make it a static map ! This will allow to easily append new commands  
  Maybe a Map<String, Brainfuck ->  Void>
- [ ] Implement missing commands (parentheses)  
  This require to implement how locks are handled when the memory size changes  
  If a byte is removed or added somewhere, all the locks should have their position updated
- [ ] Finish the CPU thing  
  This will cause conflict with Extended Type II
  If the type is 2 or superior, the way memory is handled change completely to allow the Brainfuck program to modify its own code during the execution ( how f*cking neat is that ? )
  
