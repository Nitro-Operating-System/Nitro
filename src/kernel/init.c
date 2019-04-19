#include "kernel.h"
void initalize_kernel()
{
 text_color = 15;
 term_init();
 kprint("Nitro");
 cls();
 kprint("Initalizing at 0x01000\n");
 kprint("C initalized.. Code: 0x0a");
 cls();
 
}
