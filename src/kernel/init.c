#include "headers/kernel.h"
#include "headers/panic.h"
#include <stdio.h>	
void timeout(int delay) {
int c, d;
   
   for (c = 1; c <= delay; c++)
       for (d = 1; d <= delay; d++)
       {}
}
void initalize_kernel()
{ 
 text_color = 10;//Light green
 term_init(); 
 kprint("NOS");
// timeout(10000);
// onPanic("Application Quit!");
}
