BITS 16
cli
start:
	mov ax, 07C0h
	add ax, 288
	mov ss, ax
	mov sp, 4096

	mov ax, 07C0h
	mov ds, ax
	

	mov si, text_string	
	call print_string
	mov si, test_string			
	
	text_string db 'Nitro', 0xa
	test_string db 'By ec621', 0
print_string:			
	mov ah, 0Eh 		; print character command
.rep:
	lodsb	
	cmp al, 0
	je .fin 
	int 10h			
	jmp .rep

.fin:    
	ret
	times 510-($-$$) db 0
	dw 0xAA55

