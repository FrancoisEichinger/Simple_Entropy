run: entropy

entropy.o : entropy.c
	gcc -Wall -std=c99 -c entropy.c -lm

utils.o : utils.c utils.h
	gcc -Wall -std=c99 -c utils.c -lm

entropy: utils.o entropy.o
	gcc utils.o entropy.o -o entropy -lm

clean :
	rm *.o entropy
	# All .o files have been removed.
