
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"

int tests_run = 0;

static char *testicmpcode_v4_1() {
  int code = 0;
  mu_assert("test1 failed for code 0", strcmp(icmpcode_v4(code), "network unreachable") == 0);
  return NULL;
}

static char *testicmpcode_v4_2() {

  int code = 0;
  mu_assert("test1 failed for code 1", strcmp(icmpcode_v4(code), "host unreachable") == 0);
  return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
