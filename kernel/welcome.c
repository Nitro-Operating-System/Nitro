#include "headers/welcome.h"
#include "headers/kernel.h"
#include "headers/panic.h"

void run_welcome()
{
	term_init(0,15);
	kprint("Welcome to Nitro OS\n");
	kprint("Created by ec21\n");
	onPanic("end welcome...");
}
