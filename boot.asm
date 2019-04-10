BITS 16
cli
start:
; Assigns memory to bootloader
	mov ax, 07C0h
	add ax, 288
	mov ss, ax
	mov sp, 4096

	mov ax, 07C0h
	mov ds, ax
	
; ------------ Print Handler
	mov si, text_string	
	call print_string
	mov si, test_string			
	mov si, msg
; ------------ Print Data
	text_string db 'Nitro', 0x0D, 0x0A
	test_string db 'By ec621', 0x0D, 0x0A
	msg db 'This is currently all the OS does...', 0
 print_string:			
	mov ah, 0Eh; print character command
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
; 0x0D and 0x0A (Carriage Return and Line Feed)
