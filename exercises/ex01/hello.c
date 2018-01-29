#include <stdio.h>

int main() {
  // with this line of code and no others added, without optimization we see the
  // value 5 being stored in a register. With optimization, this doesn't happen
  // because the value is never used.
  int x = 5;

  // adding this line in forces 5 to be stored in a register so it can be
  // printed. The optimized version does look cleaner though...
  // printf("Hello, %d", x);

  // This line, without optimization, causes 5 to be placed in a register, and
  // then that register's value added with 1, and placed in another register.
  // with optimization, it just puts 6 in the register
  int y = x + 1;

  printf("Hello, %d", y);
  return 0;
}
