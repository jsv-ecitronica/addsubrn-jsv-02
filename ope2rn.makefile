CFLAGS=-Wall
LIBS=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit

all: ope2rn

ope2rn: main.o addsubrn.o
	gcc -o ope2rn main.o addsubrn.o

main.o: main.c addsubrn.h
	gcc $(CFLAGS) -c main.c

addsubrn.o: addsubrn.c addsubrn.h
	gcc $(CFLAGS) -c addsubrn.c

test: ope2rn-test
	./ope2rn-test

ope2rn-test: addsubrn-test.o addsubrn.o
	gcc -o ope2rn-test addsubrn.o addsubrn-test.o $(LIBS)

addsubrn-test.o: addsubrn-test.c addsubrn.h
	gcc $(CFLAGS) -c addsubrn-test.c

addsubrn-test.c: addsubrn-test.check
	checkmk addsubrn-test.check >addsubrn-test.c
