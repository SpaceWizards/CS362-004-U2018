#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests the playCard function
int main(){
  //initialize the game
  struct gameState * gs = newGame();
  int * kingdomCards = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(1,kingdomCards,1,gs);
  if (numHandCards(gs)!= 5){
    printf("numHandCards failed: returned %d\n", numHandCards(gs));
  }
  printf("numHandCards Succeeded\n");
  return 0;
}
