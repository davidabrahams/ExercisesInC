## Homework 8

### C Exercises

Modify the link below so it points to the `ex08` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/davidabrahams/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

Handling interrupts

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The program counter, and all the registers.

3) What is the difference between an interrupt and a context switch?

An interrupt stops current execution to handle the interrupt, and then returns to the original program. A context switch means switching to a different program and loading its state (this state is more than just registers).

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

If a file is read, the process must wait for that file to be read and for the data to be retrieved.

5) Why might a scheduler want to give higher priority to an I/O bound process?

They are really slow, so they can make the IO request, and then other programs can execute while the IO happens.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

Unclear if this makes actually good french toast, but here goes:

The idea is cook all the first-sides first, and then all the second sides second. We will cook in 5 minute windows:

1. Cook 8 slice's first sides
2. Cook 4 slices first sides, and 4 slices 2nd sides
3. Cook 8 slices second sides

Yummy! (Note that after step 2, 4 pieces of french toast are done, so they may get cold :(  )
