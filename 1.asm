section .data
	msg1 dd 65,55
	msg db "Addition is %d",9,0
	Temp db "djdkjfd",10,0
	NumA dd 12,12,929
	NumB db "hello"
	NumC dd 12,11
section .bss
	twelve resd 12
	three resw 3
	four resb 4
	one resd 5
	two resd 15
	
section .text
	global main
	extern printf,scanf
	
main:
	
l9:	mov eax,ebx	
	mov eax,eax		;reg32,reg32
	add ecx,edx
kk1:
	mov al,byte[one]	;reg8,mem8
	add al,al 		;reg8,reg8
	add ax,ax		;reg16,reg16
	add eax,eax		;reg32,reg32

	add byte[one],10	;mem8,imm8
	add word[two],23	;mem16,imm16
p223:	add dword[four],111	;mem32,imm32

	mov eax,32
	
	push two
	push four
	mov al,al 		;reg8,reg8
	
	sub al,byte[one]	;reg8,mem8

	mov eax,_abc
	mov al,'a'
l1:     mov eax,20232
	mov ax,2023
	mov al,2011

_abc: 	ret					
	
