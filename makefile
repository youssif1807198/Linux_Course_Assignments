#makefile for dynamic linking

myexe2 : Assignment_2.o fact.o rand.o fib.o
	gcc -c Assignment_2.c
	gcc -c -fPIC rand.c fib.c fact.c
	gcc -shared rand.o fib.o fact.o -o libyoussifDynamic.so
	gcc Assignment_2.o -o myexe2 -lyoussifDynamic -L .


Assignment_2.o : Assignment_2.c
	gcc -c Assignment_2.c
	gcc Assignment_2.o -o myexe -lyoussif -L .
	

#makefile for static linking

myexe : Assignment_2.o fact.o rand.o fib.o
	gcc -c Assignment_2.c  fib.c rand.c fact.c
	ar -rs libyoussif.a fib.o fact.o rand.o
	gcc Assignment_2.o -o myexe -lyoussif -L .

Assignment_2.o : Assignment_2.c
	gcc -c Assignment_2.c
	gcc Assignment_2.o -o myexe -lyoussif -L .
	
libyoussif.a : fact.o rand.o fib.o
	gcc -c fib.c rand.c fact.c
	ar -rs libyoussif.a fib.o fact.o rand.o
	gcc Assignment_2.o -o myexe -lyoussif -L .
	
