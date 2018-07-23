#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests handCard function
int main(){
  //initialize the game
  struct gameState * gs = newGame();
  int * kingdomCards = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(1,kingdomCards,1,gs);
  printf("starting HandCard\n");
  gs->hand[0][0] = 5;
  state->whoseTurn = 0;
  int i = handCard(0, gs);
  if (i != 5){
    printf("HandCard failed: returned %d\n", i);
  }
  else{
    printf("HandCard Succeeded\n");
  }
  return 0;
}
