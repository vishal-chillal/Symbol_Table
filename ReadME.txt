input: (github)
	myInput.txt -> source opcode table
	<asm File> -> user input as a command line argument

How to Run:
	
	extract source code form tar file.
	cd to /path/to/assembler
	make
	run :
		./exe <asm file>
output:
	generation of :
		text file of symbol table
		text file of literal table
		text file of output opcode (instructions of type Reg to Reg, literals)
		source opCode table

valiadtions Handled:
	
	1. repeatations of symbols

remaining work:
	
	1. error table
	2. Remaining instruction handling

This assignment is done by:
	14109 Vishal Chillal
	14142 Varad Padhye
	14132 Saurabh Kukade
	14144 Snehal Pitrubhakta
	
