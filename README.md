# haxebrainfuck
Brainfuck interpreter with extended types in haxe

###Example  
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
Here the type of the brainfuck is assumed based on chars used  
If you put only chars with vanilla instructions, it will be type 0

###But I want vanilla Brainfuck with comments !
Woah, calm the f*ck down, you can pass a second argument to enforce the type :  
```haxe
trace(bf.execute("[.>]@Hello World!", 0).getOutput());
```
Note that this does nothing interesting since it is Extended III code, running with vanilla Brainfuck rules  

Keep in mind that type 2 and above heavily change how the memory is handled, and what it contains (check [Extended Brainfuck] (https://esolangs.org/wiki/Extended_Brainfuck))  
Type 2 memory system is what **allows self-modifying brainfuck**

###Types
  0 : Vanilla Brainfuck  
  1 : Extended Type I  
  2 : Extended Type II  
  3 : Extended Type III

###Genetic Algorithm
I'm currently working on the Genetic Algorithm, which will be used to generate brainfuck programs (it's far from finished yet).
In theory, you can produce ANY program. But here is the catch... You have to ask the right thing.  

The Genetic Algorithm itself is no rocket science, the GA keeps a population, a Thread asks the GA for something to execute, 
so it gives it a brainfuck code, freshly generated from the population. Once the Thread have finished its work, 
it gives the result back to the GA, which define the fitness of the brainfuck code (how well it did at what you think you asked to, 
but haven't), and push it back in the population pool if it is good enough.

A conventionnal way to store the population would be a one dimensional array, with parents randomly selected among the population 
(possibly with tournaments), but here I choose to make the population a multi dimensional array.  
Not even because I think this will improve anything, more by curiosity to be honest.  
Of course, if you still select randomly the parents across all the population, it's pretty much doing the same thing, 
so here only the nearest individuals can mate.  

Handling population can be hard, you can't always keep only the bests due to the local maximum problem.  
If the entire population takes a bad turn in the evolution, it can be stuck and the fitness will stagnate.  
To ensure a durable and efficient evolution, you can either make a bigger population, or, like here, avoid the population from mating with 
other individuals that are "far". This method, i hope, will create different "families" across the population, rather than a big one.  
Since children are placed near to their parents, families can grow in space, or dissapear if they are not fit enough.  
In general, the bigger the population, the better, but here is the catch : the evolution will be slower too. 
If you have more individuals, you'll have to do more calculation to make one "generation" live.

###What the f*ck is a CPU ?
Don't mind the CPU thing, I intended to run multiple "threads" on the same memory alternatively, but it was for another project.  
Just consider it's a single core and it will be fine.  
Basically, I intended to create a simplified [Avida] (https://en.wikipedia.org/wiki/Avida) like program.  
Each "creature" would be a cpu, running a brainfuck program (which would be part of its DNA) on a shared memory.  
Brainfuck seemed one of the best choices for the programming langage, since it is crazy simple, and can be extended indefinitively.
The ability to self modify its code at run time was not necessary, but is a HUGE plus.  
This Avida like program required to extend the commands with new simulation related one, so i choosed not to do it on this project and reuse this one when the time come. *And it will come*.


##TODO
- [ ] Finish the genetic algorithm  
  - [x] Function to kill part of the population  
  - [ ] Function to refill the population (using nearest best parents)