all: main

run: main
	./main

main: hash.o main.o
	gcc hash.o main.o -o main

main.o: main.c
	gcc main.c -c

hash.o: hash.c
	gcc hash.c -c