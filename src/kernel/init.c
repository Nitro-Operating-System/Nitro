#include "headers/kernel.h"
#include "headers/panic.h"
void initalize_kernel()
{
 
 text_color = 15;
 term_init();
 kprint("> ");
 term_init();
 kprint("> ");
 term_init();
 kprint("> ");
}
