# Linux_Course_Assignments
gcc Assignment_1.c #to compile program
./a.out #to excute program

#assignment 2 commands
  #static linking
  gcc -c rand.c fact.c fib.c
  ar -rs libyoussif.a rand.o fact.o fib.o
  gcc -c Assignment_2.c
  gcc Assignment_2.o -o myexe -lyoussif -L .
  ./myexe
  #dynamic linking
  gcc -c -fPIC rand.c fib.c fact.c
  gcc -shared rand.o fib.o fact.o -o libyoussifDynamic.so
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/youssif
  ./myexe2

