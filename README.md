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
Deep Thought was asked the answer to life the universe and everything, and it takes 7,500,000 years to give the answer 42.  
You will face the same kind of problems if you don't know how to ask the machine.  

The Genetic Algorithm itself is no rocket science, the GA keeps a population, a Thread asks the GA for something to execute, so it gives it a brainfuck code, freshly generated from the population. Once the Thread have finished its work, it gives the result back to the GA, which define the fitness of the brainfuck code (how well it did at what you think you asked to, but haven't), and push it in the population pool if it is good enough.

A conventionnal way to store the population would be a one dimensional array, with parents randomly selected among the population (possibly with tournaments), but here I choose to make the population a multi dimensional array.  
Not even because I think this will improve anything, more by curiosity to be honest.  
Of course, if you still select randomly the parents across all the population, it's pretty much doing the same thing, so I explain this a bit later. Now.  

When the GA is asked a BF code, several things happens :
  - It selects a random cell in the multi dimensional population array, the individual at this position is the first parent
  - A new, void individual is created, let's call him **Sim**on
  - Parents are selected, it's either :
    - The first parent plus one close individual (adjacent cells, selected by tournament, this is why more dimensions are interesting)
    - Only the first parent, in this case, the new individual will be a (mutated) clone
  - Simon is injected with it(s) parents(s) DNA (which is the BF code to execute), by simple cloning or crossing
  - Simon and its position are given to a Thread (multithreads are not implemented yet, but it's planned)
  
When Simon is given to a Thread :
  - The Thread create a Brainfuck object, and inject Simon's DNA (bf code) and position
  - The Brainfuck object runs the program, storing several data at the same time (memory, number of ticks, error, ...)
  - The Thread returns the Brainfuck object and Simon's position to the GA
  
When the GA is given the Brainfuck object (and Simon's position) :
  - It evaluate its fitness : this is where the magic really happens
  - The worst individual at Simon's location (his position adjacent cells) is compared to Simon :
    If Simon is stronger, he... Kill the opponent, and take his place in the population
    If Simon is weaker, there is still a chance that he survive and take the place of the opponent

Handling population can be hard, you can't always keep only the bests due to the local maximum problem.  
If the entire population takes a bad turn in the evolution, it can be stuck and the fitness will stagnate.  
To ensure a durable and efficient evolution, you can either make a bigger population, or, like here, avoid the population from mating with other individuals that are "far". This method, i hope, will create different "families" across the population, rather than a big one.  
In general, the bigger the population, the better, but here is the catch : the evolution will be slower too. If you have more individuals, you'll have to do more calculation to make one "generation" live.

###What the f*ck is a CPU ?
Don't mind the CPU thing, I intended to run multiple "threads" on the same memory alternatively, but it was for another project.  
Just consider it's a single core and it will be fine.  
I will rewrite this part, if I feel I need to, maybe, one day. Maybe never.  
Basically, I intended to create a simplified [Avida] (https://en.wikipedia.org/wiki/Avida) like program.  
Each "creature" would be a cpu, running a brainfuck program (which would be part of its DNA) on a shared memory.  
Brainfuck seemed one of the best choices for the programming langage, since it is crazy simple, and can be extended indefinitively.
The ability to self modify its code at run time was not necessary, but is a HUGE plus.  
This Avida like program required to extend the commands with new simulation related one, so i choosed not to do it on this project and reuse this one when the time come. *And it will come*.


##TODO
- [ ] Finish the genetic algorithm  
  - [x] Function to kill part of the population  
  - [ ] Function to refill the population (using nearest best parents)