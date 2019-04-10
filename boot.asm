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
	
	MOV AX,0600H    ;06 TO SCROLL & 00 FOR FULLJ SCREEN
    	MOV BH,71H    ;ATTRIBUTE 7 FOR BACKGROUND AND 1 FOR FOREGROUND
    	MOV CX,0000H    ;STARTING COORDINATES
   	MOV DX,184FH    ;ENDING COORDINATES
    	INT 10H       ;FOR VIDEO DISPLAY
    	MOV AH,4CH    ;RETURN TO DOS MODE
    	INT 21H
; ------------ Print Handler
	mov si, text_string	
	call print_string			
	mov si, msg
; ------------ Print Data
	text_string db 'Nitro', 0x0D, 0x0A
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
