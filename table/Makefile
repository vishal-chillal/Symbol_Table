exe : main.o optable.o prnt_opcd.o
	 gcc -o exe  main.o optable.o prnt_opcd.o

main.o : main.c
	gcc -Wall -g -c main.c
optable.o : optable.c
	gcc -Wall -g -c optable.c
prnt_opcd.o : prnt_opcd.c
	gcc -Wall -g -c prnt_opcd.c
clear :
	rm *~ *.o  exe
