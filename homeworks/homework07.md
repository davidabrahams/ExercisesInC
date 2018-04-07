## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/davidabrahams/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

I thought only the OS could modify the PC? Segfault?

2) What is the fundamental problem caches are meant to solve?

It solves the "memory bottleneck", that is, the CPU is much faster than the memory it tries to modify.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

For 50%:

```
T = h*T_h + m*T_m
  = .5 * (1 ns) + 0.5 * (10 ns)
  = 5.5 ns
```

For 10%:

```
T = h*T_h + m*T_m
  = .9 * (1 ns) + 0.1 * (10 ns)
  = 1.9 ns
```

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

Related to loops: Often you see loops do something like:

```
while (datastructure.notEmpty()) {
    // do stuff
}
```

This notEmpty() call might access some variable in the datastructure, which would get cached as it is accessed at the start of each loop iteration (temporal locality). For spatial locality, I believe structs are often stored contiguously in memory, so if you access one part of a struct, then access to the rest of it will be fast (as the struct, or parts of it, will be cached).

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

Depends...If you optimize for temporal locality, you might not need to code for specific hardware. The same can also be said for spatial locality (ie, looping over an array once and doing all operations in one loop rather than several in-series loops_ will be faster on pretty much any hardware). However, if you start using the size of your cache as part of how you design your code, it is cache-aware.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.


Uhhh. Merp. I looked around at different CPUs and couldn't really find two that were identical but with different cache sizes. (Perhaps when this is graded, could I have a link to a pair).

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

The OS handles things at the top, and this is generlaly to optimize for program execution speed. This can be simple, and is often close to an LRU-policy. At the bottom, the user must decide which large-chunks of data (ie, files, programs) they would like "cached" (loaded into RAM, for example).

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Perhaps when thrashing happens, give the user a choice of a process to kill? I assume that detecting thrashing would also be difficult. You could keep track of how many times a program's pages are overwritten and then fetched again, and have some metric which quantifies when this is too much?
