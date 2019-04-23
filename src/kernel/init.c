#include "headers/kernel.h"
#include "headers/panic.h"
#include <stdio.h>	
void initalize_kernel()
{
 
 text_color = 15;
 term_init();
 kprint("> ");
 int cr2_var;
 asm volatile ( 
	"movq %%cr2, %%0;"
	: "=r" (cr2_var)
 );
 char *dat = "";
 sprintf(dat, cr2_var);
 kprint(dat);
}
