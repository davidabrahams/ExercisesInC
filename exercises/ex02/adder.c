#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Return
//   0: EOF
//   1: Valid input
//   2: Input too long
int readUserInput(const char* prompt, char* into, int length) {
  printf("%s: ", prompt);
  // read the first 'length - 1' characters into 'into'
  char* result = fgets(into,length,stdin);
  if (result == NULL) return 0;
  int slen = strlen(into);
  // check if the final character is a new line
  if (into[slen - 1] == '\n') {
    // remove the new line and return true
    into[slen - 1] = '\0';
    return 1;
  }
  // read from stdin until we find the new line
  if (getchar() == '\n') return 1;
  while (getchar() != '\n') {}
  return 2;
}

int* resizeArray(int* A, int oldSize, int newSize) {
  printf("RESIZE");
  int* B = malloc(newSize * sizeof(int));
  for (int i = 0; i < oldSize; i++) {
    B[i] = A[i];
  }
  free(A);
  return B;
}

int main() {
  int capacity = 2;
  int size = 0;
  int* A = malloc(2 * sizeof(int));

  char string[11];
  int valid = 1;
  
  while (valid != 0) {
    // read user input, capping at 11 characters
    valid = readUserInput("Please enter an integer", string, 11);
    if (valid == 0) continue;
    printf("You entered: %s\n", string);
    int i = atoi(string);
    // Check if input was too long, or was not an integer
    if (valid == 2 || (i == 0 && (strlen(string) != 1 || string[0] != '0'))) {
      printf("Invalid input recieved.\n");
      continue;
    }
    if (++size > capacity) { // Check if we have to resize the array
      A = resizeArray(A, capacity, capacity * 2); // double the size
      capacity = capacity * 2;
    }
    // Store the user input in the array
    A[size - 1] = i;
  }
  // Finally, take the sum and print it
  int sum = 0;
  for (int i = 0; i < size; i++) sum += A[i];
  printf("\nSum of array: %d", sum);
}
