#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests the numHandCards function
int main(){
  //initialize the game
  struct gameState * gs = newGame();
  int * cardsList = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(1,cardsList,1,gs);
  int i;
  endTurn(gs);
  //numHandCards should be 5 at the start of the game
  printf("starting numHandCards\n");
  if (numHandCards(gs)!= 5){
    printf("numHandCards failed: returned %d\n", numHandCards(gs));
  }
  else {
    printf("numHandCards Succeeded\n");
  }
  return 0;
}
