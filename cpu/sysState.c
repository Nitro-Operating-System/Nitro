#include "sysState.h"
#include "isr.h"
#include "../libc/function.h"
#include "../drivers/screen.h"
#include "../kernel/kernel.h"
#include "ports.h"
#include "timer.h"

void sys_state_manager() {
    int state = getstate();
	if (state == 1) {
		//shutdown
		
		//halt();
		port_byte_out(0xf4, 0x00);
	} else if (state == 2) {
		//Uh Oh!!!! Kernel Panic!!!! Display Error then HALT the CPU
		kprint("\n\n\n\n\n\n\n\n\n\n\n\n                  OOPS, Your System Has Crashed, Halting CPU");
		port_byte_out(0xf4, 0x00);
	}}
