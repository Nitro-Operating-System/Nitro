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
	kprint("  _   _ _ _                ____   _____ \n");
	kprint(" | \\ | (_) |              / __ \\ / ____|\n");
	kprint(" |  \\| |_| |_ _ __ ___   | |  | | (___  \n");
	kprint(" | . ` | | __| '__/ _ \\  | |  | |\\___ \\ \n");
	kprint(" | |\\  | | |_| | | (_) | | |__| |____| |\n");	
	kprint(" |_| \\_|_|\\__|_|  \\___/   \\____/|_____/ \n");
	kprint("[Bootloader] Opening Kernel\n");
	kprint("[Kernel] Boot Running\n");
	kprint("[Kernel] Debug Mode Active\n");
	onPanic("End of Kernel");        
}
