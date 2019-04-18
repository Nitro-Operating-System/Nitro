#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/io.h>
#include <stdio.h>
#include "kernel.h"
  /*
  	Modified version of OSDEV's Barebones tutorial Kernel
  */
extern void initalize_kernel(void);
int text_color = 4;
int cls_buffer = 58;

enum vga_color 
{
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_WHITE = 15
};
static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}
 
size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;
 
void term_init(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(text_color, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) 
{
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}
 
void terminal_write(const char data[], size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
void check_newline(const char space[])
{
  for (int i = 0; i < strlen(space); i++)
  {
     if(space[i] == '\n') 
     {
//For whatever reason this code detects random new lines at the beginning of kprint
    	cls();
     }
  }  
}
void kprint(const char* data) 
{
	//OS's defacto print statement
	check_newline(data);
	terminal_write(data, strlen(data));
}
void cls() 
{
 //my bullshit diy attempt to deal with \n issues
  for(int i=0; i < cls_buffer; i++) {
	terminal_putchar(' ');
  }
}
void run_init() 
{
//sets color and runs other file
 text_color = 15;
 term_init();
 initalize_kernel();
}
