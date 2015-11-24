%macro fibbonacci 1
	mov ecx, %1
	cmp ecx, 1
	jl %%done

	mov eax, 0
	pushad
	push eax
	push msg1
	call printf
	add esp, 8
	popad

	cmp ecx, 2
	jl %%done

	mov ebx, 1
	pushad
	push ebx
	push msg1
	call printf
	add esp, 8	
	popad
	sub ecx, 2

	%%loop:
		cmp ecx, 0
		je %%done

		xchg eax, ebx
		add ebx, eax

		pushad
		push ebx
		push msg1
		call printf
		add esp, 8	
		popad
	
		dec ecx
		jmp %%loop
		
	%%done:
%endm

section .data
	msg db "First %d numbers of fibbonacci series are: ", 10, 0
	msg1 db "%d  ", 0
	newline db 10

section .bss
	abc resd 33
	pqr resd 2
	lmn resd 233

section .text
	global main
	extern printf

main:
	push 8
	push msg
	call printf
	add esp, 8
	fibbonacci 8
	push newline
	call printf
	add esp, 4	
	
	push 10
	push msg
	call printf
	add esp, 8
	fibbonacci 10
	push newline
	call printf
	add esp, 4	
	
	ret