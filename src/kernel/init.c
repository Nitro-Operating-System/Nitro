#include "kernel.h"
void initalize_kernel()
{
 text_color = 15;
 term_init();
 kprint("Nitro");
 cls();
 int* adres = &text_color; 
 char* printad = adres + '0';
 terminal_putchar(printad);
}
