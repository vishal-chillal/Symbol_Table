exe : FileHandling.o addEntry.o print_table.o text_entry.o optable.o prnt_opcd.o oP_Tab_main.o literal.o litTable.o
	 gcc -o exe FileHandling.o addEntry.o print_table.o text_entry.o optable.o prnt_opcd.o oP_Tab_main.o literal.o litTable.o

litTable.o : litTable.c
	gcc -Wall -g -c litTable.c
oP_Tab_main.o : oP_Tab_main.c
	gcc -Wall -g -c oP_Tab_main.c
print_table.o : print_table.c
	gcc -Wall -g -c print_table.c
literal.o : literal.c
	gcc -Wall -g -c literal.c
addEntry.o : addEntry.c
	gcc -Wall -g -c addEntry.c
optable.o : optable.c
	gcc -Wall -g -c optable.c
prnt_opcd.o : prnt_opcd.c
	gcc -Wall -g -c prnt_opcd.c
text_entry.o : text_entry.c
	gcc -Wall -g -c text_entry.c
FileHandling.o : FileHandling.c
	gcc -Wall -g -c FileHandling.c 

clear :
	rm *~ *.o  exe


