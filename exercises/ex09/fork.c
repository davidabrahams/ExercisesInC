/* Example code for Exercises in C.

   Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;

int globalInt = 0;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
  struct timeval tv[1];

  gettimeofday(tv, NULL);
  return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
  sleep(i);
  printf("Hello from child %d.\n", i);
  printf("Value of global int in child: %d\n", globalInt);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
  int status;
  pid_t pid;
  double start, stop;
  int i, num_children;
  int stackInt = 0;
  int *heapInt = malloc(sizeof(int));
  *heapInt = 0;

  // the first command-line argument is the name of the executable.
  // if there is a second, it is the number of children to create.
  if (argc == 2) {
    num_children = atoi(argv[1]);
  } else {
    num_children = 1;
  }

  // get the start time
  start = get_seconds();

  for (i=0; i<num_children; i++) {

    // create a child process
    printf("Creating child %d.\n", i);
    globalInt = 0; // reset the ints when we create each child process
    stackInt = 0;
    *heapInt = 0;
    pid = fork();

    if (pid > 0) { // if we're in the parent, increase the ints
      globalInt += i;
      stackInt += i;
      *heapInt += i;
    }

    /* check for an error */
    if (pid == -1) {
      fprintf(stderr, "fork failed: %s\n", strerror(errno));
      perror(argv[0]);
      exit(1);
    }

    /* see if we're the parent or the child */
    // Children share the same global address space
    if (pid == 0) {
      child_code(i);
      printf("Value of stackInt in child: %d.\n", stackInt);
      printf("Value of heapInt in child: %d.\n", *heapInt);
      exit(i);
    }
  }

  /* parent continues */
  printf("Hello from the parent.\n");
  printf("Value of globalInt in parent: %d.\n", globalInt);
  printf("Value of stackInt in parent: %d.\n", stackInt);
  printf("Value of heapInt in parent: %d.\n", *heapInt);
  
  // value of globalInt in parent will be 2, in all children is 0. They do not
  // share same global space.
  // same for stackInt/heapInt. They do not share the same stack/heap space.
  // AFAIK, static/global space is the same, so they don't share the same stack
  // space.
  // 
  // I believe fork duplicates all memory (code also). I couldn't think of a
  // good way to test this? You could print the address of functions, but that's
  // in each program's virtual memory space, which is completely copied, right?

  for (i=0; i<num_children; i++) {
    pid = wait(&status);

    if (pid == -1) {
      fprintf(stderr, "wait failed: %s\n", strerror(errno));
      perror(argv[0]);
      exit(1);
    }

    // check the exit status of the child
    status = WEXITSTATUS(status);
    printf("Child %d exited with error code %d.\n", pid, status);
  }
  // compute the elapsed time
  stop = get_seconds();
  printf("Elapsed time = %f seconds.\n", stop - start);

  exit(0);
}
