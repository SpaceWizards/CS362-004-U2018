#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests the village card
int main(){
  //initialize the game
  struct gameState * gs = newGame();
  int * kingdomCards = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(2,kingdomCards,1,gs);
  int coin_bonus = 0;
  state->numActions = 0;
  int beforesize = numHandCards(gs);
  gs->hand[0][0]= village;
  cardEffect(village, 0, 0, 0, gs, 0, &coin_bonus);
  int aftersize = numHandCards(gs);
  //check if # of cards in hand is correct
  if (aftersize != beforesize){
    printf("# of cards incorrect. current hand size: %d\n", aftersize);
  }
  else{
    printf("# of cards correct.\n");
  }
  //check if number of actions went up
  if (state->numActions != 2){
    printf("Actions were NOT added properly. Current number of actions: %d\n", gs->numBuys);
  }
  else{
    printf("Buy WAS added properly.")
  }
  //check if it was discarded
  if(gs->hand[0][0] == village){
    printf("Village was NOT discarded properly.\n");
  }
  else{
    printf("Village WAS discarded properly.\n");
  }

  return 0;
}
