section .text
global run

extern interrupt_handler
run:
        call interrupt_handler
        ret

