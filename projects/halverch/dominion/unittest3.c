#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//this tests the getCost function
int main(){
  //test each input result we want
  int i;
  int j;
  int cardvals [28] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,-1};
  printf("Starting getCost\n");
  for (i = 0; i < 28; i++){
    j = getCost(i);
    if (j != cardvals[i]){
      printf("Card %d failed, returned %d\n", i, j);
    }
    else{
      printf("Card %d succeeded\n");
    }
  }
  return 0;
}
