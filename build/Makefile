CC=gcc
CFLAGS=-I ../include -Wall -pedantic
DEPS=main.o fonctions.o

gameOfLife: $(DEPS) 
	$(CC) -o main $(DEPS)

main.o:
	$(CC) -c -o main.o $(CFLAGS) ../src/main.c 

fonctions.o:
	$(CC) -c -o fonctions.o ../src/fonctions.c $(CFLAGS) 

cleanObj:
	rm *.o

clean:
	rm *.o main