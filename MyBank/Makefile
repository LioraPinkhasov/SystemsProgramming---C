
main: main.c libOurBank.a
	gcc -Wall -o main main.c libOurBank.a 
libOurBank.a : myBank.c
	gcc -Wall -c myBank.c -o myBank.o
	ar rcs libOurBank.a myBank.o
clean:
	rm -f main *.o *.a
  
all: main