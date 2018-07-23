#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests the adventurer card
int main(){
  //initialize the game
  struct gameState * gs = newGame();
  int * kingdomCards = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(2,kingdomCards,1,gs);
  int coin_bonus = 0;
  state->numActions = 0;
  int beforesize = numHandCards(gs);
  gs->hand[0][0]= adventurer;
  cardEffect(adventurer, 0, 0, 0, gs, 0, &coin_bonus);
  int aftersize = numHandCards(gs);
  //check if # of cards in hand is correct
  if (aftersize != beforesize + 1){
    printf("# of cards incorrect. current hand size: %d\n", aftersize);
  }
  else{
    printf("# of cards correct.\n");
  }
  //check if last two cards are treasures
  if (gs->hand[0][numHandCards(gs)-1] > 6 || gs->hand[0][numHandCards(gs)-1] < 4){
    printf("First card drawn NOT a treasure, card is: %d\0", gs->hand[0][numHandCards(gs)-1]);
  }
  else{
    printf("First card drawn IS a treasure.")
  }
  if (gs->hand[0][numHandCards(gs)-2] > 6 || gs->hand[0][numHandCards(gs)-2] < 4){
    printf("Second card drawn NOT a treasure, card is: %d\0", gs->hand[0][numHandCards(gs)-2]);
  }
  else{
    printf("Second card drawn IS a treasure.")
  }
  //check if it was discarded
  if(gs->hand[0][0] == adventurer){
    printf("adventurer was NOT discarded properly.\n");
  }
  else{
    printf("adventurer WAS discarded properly.\n");
  }

  return 0;
}
