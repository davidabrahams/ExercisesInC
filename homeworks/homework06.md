## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

The value you read is nonsense (I think this is most common. A segfault is possible as well).

b) Writing to unallocated memory.

You might write to some memory you're not using (in which case your data is stored somewhere you probably don't have access to), or you might override some other program data, or segfault.

c) Reading from a freed chunk.

I don't believe segfault is possible here, since your pointer still points to the heap (I'm not sure about this). The data you get might be nonsense though.

d) Writing to a freed chunk.

Seg fault!

e) Failing to free a chunk that is no longer needed.

Memory leaks. (Ie, program inefficiency...maybe eventually you run out of memory, but probably not).


3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

kthreadd, kworker, mm_percpu_wq, ksoftirqd/0, rcu_sched...Not sure what these are?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

You end up with bits of unused memory between the chunks?

You could write your program to stoe memory in blocks (maybe utilizing structs).

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
