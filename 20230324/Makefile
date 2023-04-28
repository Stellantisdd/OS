all: 07_4.o sum.o
	gcc -o test 07_4.o sum.o
	./test

07_4.o: 07_4.c
	gcc -c 07_4.c

sum.o: sum.c
	gcc -c sum.c

clean:
	rm *.o test