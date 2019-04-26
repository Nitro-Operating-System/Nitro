#include "headers/kernel.h"
#include "headers/panic.h"
#include "headers/irh.h"
#include <stdio.h>	
#include <execinfo.h>
void initalize_kernel()
{
        term_init(15,0); 
	kprint(" :: [Bootloader] Opening Kernel\n");
	kprint(" :: [Kernel] Boot Running\n");
	kprint(" :: [Kernel] Debug Mode Active\n");
	onPanic("End of Kernel");
}
