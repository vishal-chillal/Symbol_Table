%macro add2 2
	mov eax, %1
	mov ebx, %2
	add eax, ebx
%endm

%macro add3 3
	add2 %1, %2
	add2 eax, %3
%endm

section .data
	msg db "The sum is: %d", 10, 0

section .text
	global main
	extern printf

main:
	add3 10 , 20 , 30

	push eax
	push msg
	call printf
	add esp, 8

	ret	
