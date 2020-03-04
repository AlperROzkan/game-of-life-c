CC=gcc
CFLAGS=-I.
DEPS=main.o fonctions.o

gameOfLife: clean $(DEPS)
	$(CC) -o main $(DEPS)

main.o:
	$(CC) -c -o main.o $(CFLAGS) ../src/main.c 

fonctions.o:
	$(CC) -c -o fonctions.o ../src/fonctions.c $(CFLAGS)

clean:
	rm -rf *.o main