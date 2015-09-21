section .data
	msg db "Addition is %d",10,0
	msg1 dd 65,55,56
	Temp db"djdkjfd",10,0
	NumA dq 12,12,929
	NumB dt "hello"
	NumC dd 12,12,929
section .bss
	four resd 1
	two resw 1
	one resb 1
	
section .text
	global main
	extern printf,scanf
	xor eax,eax
	
main:	push four
	push four

mov:	mov eax,32

	mov al,al 		;reg8,reg8

	mov eax,eax		;reg32,reg32

kk1:
	mov al,byte[one]	;reg8,mem8
	add al,al 		;reg8,reg8
	add ax,ax		;reg16,reg16
	add eax,eax		;reg32,reg32

	add byte[one],10	;mem8,imm8
	add word[two],10	;mem16,imm16
p223:	add dword[four],10	;mem32,imm32

	
	sub al,byte[one]	;reg8,mem8

	mov eax,_abc
	mov al, 'a'
l1:     mov eax, 20
	mov ax, 20		
	mov al, 20

_abc: 	ret					
	
