## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my repository](https://github.com/davidabrahams/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of 
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?

Stealing Allen's car idea from class (I'm not very creative, though he spoke about the steering wheel), when you press the gas in a car, it accelerates, and when you press the brake, it slows down. You get a very simplified interface, even though clearly what actually happens to move/slow down the car is quite complicated.

2. What is the difference between a program and a process?

The process is what actually runs the program. The process has all the programs resources, such as data and memory, and the program itself (in machine code sometimes).

3. What is the primary purpose of the process abstraction? 

To make it easier for programmers to write programs that interface with the operating system (which is pretty much every program). You don't have to worry about how to OS works, ie, how the OS recieves keyboard input, this is abstracted out for you. You also don't have to worry about your program being influenced by or influencing other programs.

4. What illusion does the process abstraction create?

That your program runs in its own environment/chunk of memory.

5. What is the kernel?

A core part of the OS which creates threads (TBH I'm still a bit fuzzy on this).

6. What is a daemon?

Processes that run in the background and provide OS services (this makes a bit more sense).
