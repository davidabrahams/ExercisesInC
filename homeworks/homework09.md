## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/davidabrahams/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

So they can use/modify variables without worrying about if another thread has changed them to an unexpected value.

2) What does the gcc flag `-lpthread` do?

It links the pthread library to the executable

3) What does the argument of `pthread_exit` do?

It makes whatever it points to available to any successful join with the thread that terminated.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

AFAIK nothing strange? `pthread_join` is basically a "wait for this thread to finish" function. So any thread should be able to wait for any other thread?

5) What goes wrong if several threads try to increment a shared integer at the same time?

I believe something like `i = i + 1` is actually a few register operations. We need to load `i`, we need to add `1`, and we need to store the result in `i`. Therefore if two threads do this, they may both read the same value of i, both increment it, and then both store `i + 1` (which might not be what we're trying to do).

6) What does it mean to "lock a mutex"?

It means if another thread tries to lock the mutex, they can't because it is already locked. That thread will have to wait until the first thread has unlocked the mutex to proceed.
