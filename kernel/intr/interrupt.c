#include "../headers/kernel.h"
#include "../headers/irh.h"
void interrupt_handler() 
{
 //This is called from a seperate asm file in sys
 kprint("[IRH] Started\n");
 kprint("[IRH] Control Transfered\n");
 
}
