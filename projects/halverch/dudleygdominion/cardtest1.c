#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests the Smithy card
int main(){
  //initialize the game
  struct gameState * gs = newGame();
  int * cardsList = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(1,cardsList,1,gs);
  int coin_bonus = 0;
  int i;
  endTurn(gs);
  int beforesize = numHandCards(gs);
  gs->hand[0][0]= smithy;
  cardEffect(smithy, 0, 0, 0, gs, 0, &coin_bonus);
  int aftersize = numHandCards(gs);
  //check if # of cards in hand is correct
  if (aftersize != beforesize + 2){
    printf("# of cards incorrect. current hand size: %d\n", aftersize);
  }
  else{
    printf("# of cards correct.\n");
  }
  //check if card was discarded
  if(gs->hand[0][0] == smithy){
    printf("Smithy was NOT discarded properly\n");
  }
  else{
    printf("Smithy WAS discarded properly\n");
  }

  return 0;
}
