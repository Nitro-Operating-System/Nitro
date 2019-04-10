[ORG 0x0000]
BITS 16

_start:
; Assigns memory to bootloader
	mov ax, 07C0h
	add ax, 288
	mov ss, ax
	mov sp, 4096

	mov ax, 07C0h
	mov ds, ax
	call cls
	
; ------------ Print Handler
	mov si, text_string	
	call print_string
	mov si, loading
; ------------ Print Data
	
	jmp $
	text_string db 'Nitro',0x0d,0x0a
	loading db 'Loading OS....',0
cls:
  pusha
  mov ah, 0x00
  mov al, 0x03  ; text mode 80x25 16 colours
  int 0x10
  popa
  ret

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
