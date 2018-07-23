#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests the council_room card
int main(){
  //initialize the game
  struct gameState * gs = newGame();
  int * cardsList = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(2,cardsList,1,gs);
  int coin_bonus = 0;
  int i;
  for (i = 0; i < 5; i++){
    drawCard(0, gs);
  }
  drawCard(1, gs);
  gs->numBuys = 0;
  int beforesize = numHandCards(gs);
  gs->hand[0][0]= council_room;
  cardEffect(council_room, 0, 0, 0, gs, 0, &coin_bonus);
  int aftersize = numHandCards(gs);
  if (aftersize != beforesize + 3 ){
    printf("# of cards incorrect. current hand size: %d\n", aftersize);
  }
  else{
    printf("# of cards correct.\n");
  }
  //check if card was given to other players
  if (gs->handCount[1] != 2){
    printf("Card was NOT given properly. Current hand size: %d\n", gs->handCount[1]);
  }
  else{
    printf("Card WAS given properly.\n");
  }
  //check if number of buys went up
  if (gs->numBuys != 1){
    printf("Buy was NOT added properly. Current number of buys: %d\n", gs->numBuys);
  }
  else{
    printf("Buy WAS added properly.");
  }
  //check if it was discarded
  if(gs->hand[0][0] == council_room){
    printf("Council Room was NOT discarded properly.\n");
  }
  else{
    printf("Council Room WAS discarded properly.\n");
  }

  return 0;
}
