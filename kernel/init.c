#include "headers/kernel.h"
#include "headers/panic.h"
#include "headers/irh.h"
#include <stdio.h>	
void timeout(int delay) {
int c, d;
   
   for (c = 1; c <= delay; c++)
       for (d = 1; d <= delay; d++)
       {}
}
void initalize_kernel()
{ 
 term_init(15, 0); 
 kprint("[Bootloader] Opening Kernel\n");
 kprint("[Kernel] Boot Running\n");
 kprint("[Kernel] Debug Mode Active\n");
 interrupt_handler();
 /*timeout(10000);
 term_init(4, 0);
 onPanic("Application Quit!");*/
}
