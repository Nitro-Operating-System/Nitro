global interrupt
align   4
extern interrupt_handler
interrupt:
    pushad
    cld /* C code following the sysV ABI requires DF to be clear on function entry */
    call interrupt_handler
    popad
    iret
