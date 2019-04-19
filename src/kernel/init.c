#include "kernel.h"
void initalize_kernel()
{
 text_color = 15;
 term_init();
 kprint("Nitro\n\0");
 //kprint("Initalizing at 0x01000");
 //kprint("C initalized.. Code: 0x0a");
 kprint("Testing");
 
}
