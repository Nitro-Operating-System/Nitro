#include "headers/welcome.h"
#include "headers/kernel.h"
#include "headers/panic.h"

void run_welcome()
{
	term_init(11,0);
	kprint("Nitro OS\n");
	kprint(">_\n");
	onPanic("end welcome...");
}
