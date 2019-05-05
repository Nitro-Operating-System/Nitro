#include "headers/welcome.h"
#include "headers/kernel.h"
#include "headers/panic.h"

void run_welcome()
{
	term_init(0,15);
	kprint("Nitro OS\n");
	onPanic("end welcome...");
}
