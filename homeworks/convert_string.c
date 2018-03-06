#include <stdio.h>

void toCaps(char* string) {
  char *c = string;
  while (*c) {
    *c ^= (1 << 5);
    c++;
  }
}

int main(int argc, const char* argv[]) {
  char s[] = "helloDavid";
  toCaps(s);
  printf("%s", s);
}
