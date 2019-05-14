#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../drivers/sound.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include "../cpu/timer.h"
#include "terminal.h"
#include "../drivers/stdin.h"

//codes
int prevtick = 0;
int login = 1;
int passin = 0;
int state = 0;
int uinlen = 0;
int prompttype = 0;
char* last_input;
void main() {
	stdin_init();
	isr_install();
	irq_install();
	init_timer(1);
	clear_screen();
	prevtick = tick;
	clear_screen();
	kprint("NitroOS 0.0012 (Based on DripOS)\n"); //Version
        kprint("Type help for commands\nType shutdown to shutdown\n>");
	run_startup_sound();
}
void run_startup_sound() {
	play_sound(600, 60);
	play_sound(400, 60);
}

void user_input(char *input) {
	if(strcmp(input,"last")) {
		execute_command(input);
	}else{
		last_input = input;
		execute_command(input);
	}
}

void halt() {
	asm volatile("hlt");
}

void shutdown() {
	kprint("System shutdown");
	state = 1;
}

void panic() {
	state = 2;
}

int getstate() {
	return state;
}

void memory() {
	/* Lesson 22: Code to test kmalloc, the rest is unchanged */
        uint32_t phys_addr;
        uint32_t page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        kprint(", physical address: ");
        kprint(phys_str);
        kprint("\n");
}
