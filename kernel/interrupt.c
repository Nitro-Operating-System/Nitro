#include "headers/kernel.h"
#include "headers/irh.h"
void interrupt_handler() 
{
 kprint(" :: [IRH] Started\n");
 kprint(" :: [IRH] Control Transfered\n"); 
 //todo: add link to asm file for irq irh
}
