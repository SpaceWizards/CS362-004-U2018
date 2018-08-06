#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this randomly tests the adventurer card
//This doesn't properly test based on what's in the deck, but whatever.

int main(){
  //initialize the game
  srand(time(NULL));
  struct gameState * gs = newGame();
  int * cardsList = kingdomCards(7,8,9,10,11,12,13,14,15,16);
  initializeGame(1,cardsList,1,gs);
  int coin_bonus = 0;
  gs->numActions = 0;
  int i;
  int testnum = 0;
  int successes = 0;
  int failures = 0;
  for (testnum = 0; testnum < 100; testnum++){
    //reset the parameters
    endTurn(gs);
    //get a random # of cards in hand
    int disc = rand() % 6;
    int draw = rand() % 6;
    for (i = 0; i < disc, i++){
      discardCard(0,0,gs,0);
    }
    for (i = 0; i < draw; i++){
      drawCard(0, gs);
    }
    int beforesize = numHandCards(gs);
    //pick a random number of actions
    int act = rand() % 100;
    gs->numActions = act;
    //put the card in the hand somewhere
    int loc = rand() % beforesize;
    gs->hand[0][loc] = adventurer;
    //make sure the next card isn't a adventurer to avoid weird errors
    gs->hand[0][((loc + 1) % beforesize)] = mine;
    //run the card
    adventurerEffect(0, loc, gs);
    //if something went wrong increment failure, otherwise success
    if(beforesize != (numHandCards(gs)+1)){
      failures++;
    }
    else if (gs->hand[0][loc] == adventurer){
      failures++;
    }
    else if (gs->hand[0][numHandCards(gs)-1] > 6 || gs->hand[0][numHandCards(gs)-1] < 4){
      failures++;
    }
    else if (gs->hand[0][numHandCards(gs)-2] > 6 || gs->hand[0][numHandCards(gs)-2] < 4){
      failures++;
    }
    else{
      successes++;
    }
  }
  printf("Adventurer successes/failures out of 100: %d / %d \n", successes, failures);
  return 0;
}
