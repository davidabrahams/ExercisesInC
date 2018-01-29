
#include <stdio.h>
#include <stdlib.h>

void user_input(char* arr)
{
  puts("Enter the card_name: ");
  scanf("%2s", arr);
}


int eval_card(char* card_name) {
  int val = 0;
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      val = 0;
      break;
    default:
      val = atoi(card_name);
      if ((val < 1) || (val > 10)) {
        val = 0;
        puts("I don't understand that value!");
      }
  }
  return val;
}



int main()
{
  char card_name[3];
  int count = 0;
  while (card_name[0] != 'x') {
    char card_name[3];
    user_input(card_name);
    int val = eval_card(card_name);
    if (val == 0) continue;
    if ((val > 2) && (val < 7)) {
      count++;
    } else if (val == 10) {
      count--;
    }
    printf("Current count: %i\n", count);
  }
  return 0;
}

