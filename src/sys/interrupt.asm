global interrupt
align   4
extern interrupt_handler
interrupt:
    pushad
    cld 
    call interrupt_handler
    popad
    iret
