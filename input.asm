section .data
	msg db "Addition is %d",10,0
	msg1 db "%d %d"
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
	push two
	push one
	push msg1
	call printf
	add esp,16
	
	mov eax,32

	
	mov al,al 		;reg8,reg8
	mov ax,ax		;reg16,reg16
	mov eax,eax		;reg32,reg32

	;; mov al,byte[one]	;reg8,mem8
	;; mov ah,byte[one]	;reg8,mem8
	;; mov bl,byte[one]	;reg8,mem8
	;; mov bh,byte[one]	;reg8,mem8
	;; mov cl,byte[one]	;reg8,mem8
	;; mov ch,byte[one]	;reg8,mem8
	;; mov dl,byte[one]	;reg8,mem8
	;; mov ah,byte[one]	;reg8,mem8

	;; mov ax,word[two]	;reg16,mem16
	;; mov bx,word[two]	;reg16,mem16
	;; mov cx,word[two]	;reg16,mem16
	;; mov dx,word[two]	;reg16,mem16
	;; mov si,word[two]	;reg16,mem16
	;; mov di,word[two]	;reg16,mem16
	;; mov sp,word[two]	;reg16,mem16
	;; mov bp,word[two]	;reg16,mem16

	mov eax,12
	push eax
	push msg
	call printf
	add esp,8
	ret


	
	mov eax,dword[four]	;reg32,mem32
	mov ebx,dword[four]	;reg32,mem32
	mov ecx,dword[four]	;reg32,mem32
	mov edx,dword[four]	;reg32,mem32
	mov esi,dword[four]	;reg32,mem32
	mov edi,dword[four]	;reg32,mem32
	mov esp,dword[four]	;reg32,mem32
	mov ebp,dword[four]	;reg32,mem32

	mov byte[one],al	;mem8,reg8
	mov byte[one],ah	;mem8,reg8
	mov byte[one],bl	;mem8,reg8
	mov byte[one],bh	;mem8,reg8
	mov byte[one],cl	;mem8,reg8
	mov byte[one],ch	;mem8,reg8
	mov byte[one],dl	;mem8,reg8
	mov byte[one],dh	;mem8,reg8
	
	mov word[two],ax	;mem16,reg16
	mov word[two],bx	;mem16,reg16
	mov word[two],cx	;mem16,reg16
	mov word[two],dx	;mem16,reg16
	mov word[two],si	;mem16,reg16
	mov word[two],di	;mem16,reg16
	mov word[two],sp	;mem16,reg16
	mov word[two],bp	;mem16,reg16
	
	mov dword[four],eax	;mem32,reg32
	mov dword[four],ebx	;mem32,reg32
	mov dword[four],ecx	;mem32,reg32
	mov dword[four],edx	;mem32,reg32
	mov dword[four],esi	;mem32,reg32
	mov dword[four],edi	;mem32,reg32
	mov dword[four],esp	;mem32,reg32
	mov dword[four],ebp	;mem32,reg32
	
	mov al,10		;reg8,imm8
	mov ah,10		;reg8,imm8
	mov bl,10		;reg8,imm8
	mov bh,10		;reg8,imm8
	mov cl,10		;reg8,imm8
	mov ch,10		;reg8,imm8
	mov dl,10		;reg8,imm8
	mov dh,10		;reg8,imm8

	mov ax,10		;reg16,imm16
	mov bx,10		;reg16,imm16
	mov cx,10		;reg16,imm16
	mov dx,10		;reg16,imm16
	mov si,10		;reg16,imm16
	mov di,10		;reg16,imm16
	mov sp,10		;reg16,imm16
	mov bp,10		;reg16,imm16

	mov eax,10		;reg32,imm32
	mov ebx,10		;reg32,imm32
	mov ecx,10		;reg32,imm32
	mov edx,10		;reg32,imm32
	mov esi,10		;reg32,imm32
	mov edi,10		;reg32,imm32
	mov esp,10		;reg32,imm32
	mov ebp,10		;reg32,imm32

	mov byte[one],10	;mem8,imm8
	mov word[two],10	;mem16,imm16
	mov dword[four],10	;mem32,imm32

	
	add al,al 		;reg8,reg8
	add ax,ax		;reg16,reg16
	add eax,eax		;reg32,reg32

	add al,byte[one]	;reg8,mem8
	add ah,byte[one]	;reg8,mem8
	add bl,byte[one]	;reg8,mem8
	add bh,byte[one]	;reg8,mem8
	add cl,byte[one]	;reg8,mem8
	add ch,byte[one]	;reg8,mem8
	add dl,byte[one]	;reg8,mem8
	add ah,byte[one]	;reg8,mem8

	add ax,word[two]	;reg16,mem16
	add bx,word[two]	;reg16,mem16
	add cx,word[two]	;reg16,mem16
	add dx,word[two]	;reg16,mem16
	add si,word[two]	;reg16,mem16
	add di,word[two]	;reg16,mem16
	add sp,word[two]	;reg16,mem16
	add bp,word[two]	;reg16,mem16

	add eax,dword[four]	;reg32,mem32
	add ebx,dword[four]	;reg32,mem32
	add ecx,dword[four]	;reg32,mem32
	add edx,dword[four]	;reg32,mem32
	add esi,dword[four]	;reg32,mem32
	add edi,dword[four]	;reg32,mem32
	add esp,dword[four]	;reg32,mem32
	add ebp,dword[four]	;reg32,mem32

	add byte[one],al	;mem8,reg8
	add byte[one],ah	;mem8,reg8
	add byte[one],bl	;mem8,reg8
	add byte[one],bh	;mem8,reg8
	add byte[one],cl	;mem8,reg8
	add byte[one],ch	;mem8,reg8
	add byte[one],dl	;mem8,reg8
	add byte[one],dh	;mem8,reg8
	
	add word[two],ax	;mem16,reg16
	add word[two],bx	;mem16,reg16
	add word[two],cx	;mem16,reg16
	add word[two],dx	;mem16,reg16
	add word[two],si	;mem16,reg16
	add word[two],di	;mem16,reg16
	add word[two],sp	;mem16,reg16
	add word[two],bp	;mem16,reg16
	
	add dword[four],eax	;mem32,reg32
	add dword[four],ebx	;mem32,reg32
	add dword[four],ecx	;mem32,reg32
	add dword[four],edx	;mem32,reg32
	add dword[four],esi	;mem32,reg32
	add dword[four],edi	;mem32,reg32
	add dword[four],esp	;mem32,reg32
	add dword[four],ebp	;mem32,reg32
	
	add al,10		;reg8,imm8
	add ah,10		;reg8,imm8
	add bl,10		;reg8,imm8
	add bh,10		;reg8,imm8
	add cl,10		;reg8,imm8
	add ch,10		;reg8,imm8
	add dl,10		;reg8,imm8
	add dh,10		;reg8,imm8

	add ax,10		;reg16,imm16
	add bx,10		;reg16,imm16
	add cx,10		;reg16,imm16
	add dx,10		;reg16,imm16
	add si,10		;reg16,imm16
	add di,10		;reg16,imm16
	add sp,10		;reg16,imm16
	add bp,10		;reg16,imm16

	add eax,10		;reg32,imm32
	add ebx,10		;reg32,imm32
	add ecx,10		;reg32,imm32
	add edx,10		;reg32,imm32
	add esi,10		;reg32,imm32
	add edi,10		;reg32,imm32
	add esp,10		;reg32,imm32
	add ebp,10		;reg32,imm32

	add byte[one],10	;mem8,imm8
	add word[two],10	;mem16,imm16
	add dword[four],10	;mem32,imm32

	
	sub al,al 		;reg8,reg8
	sub ax,ax		;reg16,reg16
	sub eax,eax		;reg32,reg32
	sub al,byte[one]	;reg8,mem8
	sub ax,word[two]	;reg16,mem16
	sub eax,dword[four]	;reg32,mem32
	sub byte[one],al	;mem8,reg8
	sub word[two],ax	;mem16,reg16
	sub dword[four],eax	;mem32,reg32
	sub al,10		;reg8,imm8
	sub ax,10		;reg16,imm16
	sub eax,10		;reg32,imm32
	sub byte[one],10	;mem8,imm8
	sub word[two],10	;mem16,imm16
	sub dword[four],10	;mem32,imm32

	
	xor al,al 		;reg8,reg8
	xor ax,ax		;reg16,reg16
	xor eax,eax		;reg32,reg32
	xor al,byte[one]	;reg8,mem8
	xor ax,word[two]	;reg16,mem16
	xor eax,dword[four]	;reg32,mem32
	xor byte[one],al	;mem8,reg8
	xor word[two],ax	;mem16,reg16
	xor dword[four],eax	;mem32,reg32
	xor al,10		;reg8,imm8
	xor ax,10		;reg16,imm16
	xor eax,10		;reg32,imm32
	xor byte[one],10	;mem8,imm8
	xor word[two],10	;mem16,imm16
	xor dword[four],10	;mem32,imm32

	or al,al 		;reg8,reg8
	or ax,ax		;reg16,reg16
	or eax,eax		;reg32,reg32
	or al,byte[one]		;reg8,mem8
	or ax,word[two]		;reg16,mem16
	or eax,dword[four]	;reg32,mem32
	or byte[one],al		;mem8,reg8
	or word[two],ax		;mem16,reg16
	or dword[four],eax	;mem32,reg32
	or al,10		;reg8,imm8
	or ax,10		;reg16,imm16
	or eax,10		;reg32,imm32
	or byte[one],10		;mem8,imm8
	or word[two],10		;mem16,imm16
	or dword[four],10	;mem32,imm32

	
	and al,al 		;reg8,reg8
	and ax,ax		;reg16,reg16
	and eax,eax		;reg32,reg32
	and al,byte[one]	;reg8,mem8
	and ax,word[two]	;reg16,mem16
	and eax,dword[four]	;reg32,mem32
	and byte[one],al	;mem8,reg8
	and word[two],ax	;mem16,reg16
	and dword[four],eax	;mem32,reg32
	and al,10		;reg8,imm8
	and ax,10		;reg16,imm16
	and eax,10		;reg32,imm32
	and byte[one],10	;mem8,imm8
	and word[two],10	;mem16,imm16
	and dword[four],10	;mem32,imm32


	cmp al,al 		;reg8,reg8
	cmp ax,ax		;reg16,reg16
	cmp eax,eax		;reg32,reg32
	cmp al,byte[one]	;reg8,mem8
	cmp ax,word[two]	;reg16,mem16
	cmp eax,dword[four]	;reg32,mem32
	cmp byte[one],al	;mem8,reg8
	cmp word[two],ax	;mem16,reg16
	cmp dword[four],eax	;mem32,reg32
	cmp al,10		;reg8,imm8
	cmp ax,10		;reg16,imm16
	cmp eax,10		;reg32,imm32
	cmp byte[one],10	;mem8,imm8
	cmp word[two],10	;mem16,imm16
	cmp dword[four],10	;mem32,imm32


	mul al			;reg8
	mul ax			;reg16
	mul eax			;reg32
	mul bl			;reg8
	mul bx			;reg16
	mul ebx			;reg32
	mul cl			;reg8
	mul cx			;reg16
	mul ecx			;reg32

	mul byte[one]		;mem8
	mul word[two]		;mem16
	mul dword[four]		;mem32

	
	div al			;reg8
	div ax			;reg16
	div eax			;reg32
	div byte[one]		;mem8
	div word[two]		;mem16
	div dword[four]		;mem32

	neg al			;reg8
	neg ax			;reg16
	neg eax			;reg32
	neg byte[one]		;mem8
	neg word[two]		;mem16
	neg dword[four]		;mem32


	not al			;reg8
	not ax			;reg16
	not eax			;reg32
	not byte[one]		;mem8
	not word[two]		;mem16
	not dword[four]		;mem32


	inc al			;reg8
	inc ax			;reg16
	inc eax			;reg32
	inc byte[one]		;mem8
	inc word[two]		;mem16
	inc dword[four]		;mem32


	dec al			;reg8
	dec ax			;reg16
	dec eax			;reg32
	dec byte[one]		;mem8
	dec word[two]		;mem16
	dec dword[four]		;mem32


