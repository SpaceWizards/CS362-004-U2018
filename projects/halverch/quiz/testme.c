#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    //pick a number between 32 and 127
	//if it's 127, return \0, otherwise return that ascii value
	char c;
	int i = rand() % 96 ;
	if (i == 95){
		c = '\0';
	}
	else {
		c = (char)(i + 32);
	}
    return c;
}

char *inputString()
{
    //pick five lowercase letters and put them in a malloced string
	//add a \0 at the end and return it
	int i = 6;
	int j;
	char * s = malloc (sizeof(char) * i);
	for (j = 0; j < i - 1; j++){
		s[j] = (char) ((rand() % 26) + 97);
	}
	s[i] = '\0';
    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
	//added a free here so that we don't eat all of the memory
	free (s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
