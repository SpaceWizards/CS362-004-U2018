#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests the playCard function
//this does not actually test cards working, just the shell trying to run the card
int main(){
  //initialize the game
  struct gameState * gs = newGame();
  int * kingdomCards = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(1,kingdomCards,1,gs);
  printf("starting playCard\n");
  //test being in the wrong phase
  gs->phase = 1;
  if (playCard(0,0,0,0,gs) != -1){
    printf("Wrong Phase Test Failed\n");
  }
  else {
    printf("Wrong Phase Test Succeeded\n");
  }
  //test having no more actions
  gs->phase = 0;
  gs->numActions = 0;
  if (playCard(0,0,0,0,gs) != -1){
    printf("No Actions Test Failed\n");
  }
  else{
    printf("No Actions Test Succeeded\n");
  }
  //test if card isn't an action
  gs->numActions = 2;
  gs->hand[0][0] = province;
  if (playCard(0,0,0,0,gs) != -1){
    printf("Not an Action Test Failed\n");
  }
  else{
    printf("Not an Action Test Succeeded\n");
  }
  //test if playing a normal card works
  gs->hand[0][0] = village;
  if (playCard(0,0,0,0,gs) != -1){
    printf("Card Playing Returned -1\n");
  }
  else {
    printf("Card Playing Did Not Return -1\n");
  }
  return 0;
}
