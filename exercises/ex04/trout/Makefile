trout: trout.o main.o util.o
	gcc -Wall trout.o main.o util.o -o trout

trout.o: trout.c trout.h
	gcc -c -Wall trout.c -o trout.o

main.o: main.c trout.h util.h
	gcc -c -Wall main.c -o main.o

util.o: util.c util.h
	gcc -c -Wall util.c -o util.o
