#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/io.h>
#include <stdio.h>
#include "headers/kernel.h"
  /*
  	Modified version of OSDEV's Barebones tutorial Kernel
  */
extern void initalize_kernel(void);
enum vga_color {
    COLOR_BLACK             = 0,
    COLOR_BLUE              = 1,
    COLOR_GREEN             = 2,
    COLOR_CYAN              = 3,
    COLOR_RED               = 4,
    COLOR_MAGENTA           = 5,
    COLOR_BROWN             = 6,
    COLOR_LIGHT_GREY        = 7,
    COLOR_DARK_GREY         = 8,
    COLOR_LIGHT_BLUE        = 9,
    COLOR_LIGHT_GREEN       = 10,
    COLOR_LIGHT_CYAN        = 11,
    COLOR_LIGHT_RED         = 12,
    COLOR_LIGHT_MAGENTA     = 13,
    COLOR_LIGHT_BROWN       = 14,
    COLOR_WHITE             = 15,
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
//function now takes fg and bg for color idet
void term_init(int fg, int bg) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(fg, bg);
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
      if (c == '\n') {
        if (terminal_row < 25) {
          terminal_row++;
          terminal_column = 0;
        }else{
          terminal_row = 0;
	  terminal_column = 0;
        }
     }else{
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;}
  }
}
 
void terminal_write(const char data[], size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
void kprint(const char* data) 
{
	terminal_write(data, strlen(data));
}
//Edited by Evan Carter for use with Nitro

