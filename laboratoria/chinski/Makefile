CFLAGS=-D_GNU_SOURCE -Wall -lm -std=c99 -g

chiny3: chiny3.o
	$(CC) chiny3.o -o chiny3

chiny3.o: chiny3.c
	$(CC) $(CFLAGS) -c chiny3.c

chiny2: chiny2.o
	$(CC) chiny2.o -o chiny2

chiny2.o: chiny2.c
	$(CC) $(CFLAGS) -c chiny2.c

chiny: chiny.o
	$(CC) chiny.o -o chiny

chiny.o: chiny.c
	$(CC) $(CFLAGS) -c chiny.c

clean:
	rm -f *.o *~ chiny2 chiny3 chiny
