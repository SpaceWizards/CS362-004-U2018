CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittestresults: dominion.o interface.o
	gcc -o test8 -g cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test7 -g cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test6 -g cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test5 -g cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test4 -g unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test3 -g unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test2 -g unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test1 -g unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

	./test8 >> unittestresults.out
	./test7 >> unittestresults.out
	./test6 >> unittestresults.out
	./test5 >> unittestresults.out
	./test4 >> unittestresults.out
	./test3 >> unittestresults.out
	./test2 >> unittestresults.out
	./test1 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestresults: dominion.o interface.o
	gcc -o test3 -g randomtestcard1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test2 -g randomtestcard2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test1 -g randomtestadventurer.c -g dominion.o rngs.o interface.o $(CFLAGS)

	./test3 >> randomtestcard1.out
	./test2 >> randomtestcard2.out
	./test1 >> randomtestadventurer.out

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
