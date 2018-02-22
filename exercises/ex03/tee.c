#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

/*
 * Tutorialspoint page was super helpful:
 * https://www.tutorialspoint.com/cprogramming/c_input_output.htm, and their
 * page on writing/reading files. It was helpful to write this program
 * incrementally. Initially, I just wrote a program which printed user input
 * right back to them. Then, I had it write to a hard-coded file. Then I added
 * support for the "-a" flag, and finally for a custom filename.
 *
 * The main difference between my implementation and the real ones is robust
 * error checking, and more customization. I supported the -a flag, that's it.
 * I have checks for making sure the correct # of args are supplied, and that if
 * there are 2, one of them is "-a". There are no error messages though, and the
 * user could do a lot of illegal things (for example, passing an illegal
 * file-name in).
 */

int main(int argc, char *argv[]) {
  char *mode = "w"; // default to write mode
  char *fn;
  bool fnProvided = false;
  assert(argc == 2 || argc == 3); // accept either 1 o 2 args
  for (int i = 1; i < argc; i++) {
    // if the -a flag is provided, set mode to append
    if (strcmp(argv[i], "-a") == 0) mode = "a";
    // set the filename to the current argument if it wasn't a "-a"
    else { 
      fn = argv[i];
      fnProvided = !fnProvided;
    }
  }
  assert(fnProvided);

  // Read from stdin, and write to both file and stdout
  FILE *fp;
  fp = fopen(fn, mode);
  char c;
  while ((c = getchar()) != EOF) {
    fputc(c, fp);
    putchar(c);
  }
  fclose(fp);
}
