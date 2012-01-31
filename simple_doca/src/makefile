# Makefile for simple_doca objects and test cases

CC=g++
CFLAGS= -c -Wall
LDFLAGS= -Wall
OBJS= line.o vect.o doca.o test_doca.o

all: test_doca

line.h: point.h vect.h
vect.h: point.h
doca.h: vect.h point.h line.h

line.o: line.cpp line.h
	$(CC) $(CFLAGS) line.cpp

vect.o: vect.cpp vect.h
	$(CC) $(CFLAGS) vect.cpp

doca.o: doca.cpp doca.h
	$(CC) $(CFLAGS) doca.cpp

test_doca.o: test_doca.cpp doca.h line.h
	$(CC) $(CFLAGS) test_doca.cpp

test_doca : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test_doca

clean:
	\rm *.o test_doca