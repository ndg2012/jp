CFLAGS=-Wall -g -lm

pretty: test.o
	gcc test.o -o pretty

pretty.o: test.c
	gcc -c test.c

clean:
	rm -f pretty *~ *.o