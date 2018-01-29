
#include <stdio.h>
#include <stdlib.h>

/* Prompts user for a card name, and stores it in the input char* arr.
 * Input is truncated to first 2 characters
 *
 * arr: a pointer to a character array to store the users input in
 */
void user_input(char* arr)
{
  puts("Enter the card_name: ");
  scanf("%2s", arr);
}


/* Given a card name, return its value in the game of blackjack
 *
 * card_name: a pointer to a character array storing a card name
 */
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

/* Given a card value and a pointer to a count variable, updates the running
 * "count" for the purpose of counting cards.
 */
void update_count(int* count, int val) {
  if (val == 0) return;
  if ((val > 2) && (val < 7)) (*count)++;
  else if (val == 10) (*count)--;
}



int main()
{
  char card_name[3];
  int count = 0;
  while (card_name[0] != 'x') {
    int val;
    char card_name[3];
    user_input(card_name);
    val = eval_card(card_name);
    update_count(&count, val);
    printf("Current count: %i\n", count);
  }
  return 0;
}

