#ifndef TERMINAL_H
#define TERMINAL_H

//turns out these aren't standard lib functions, these are called "free-standing"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define VGA_NUM_ROWS 25
#define VGA_NUM_COLS 80

/* Hardware text mode color constants */
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);
uint16_t vga_entry(unsigned char uc, uint8_t color);
size_t strlen(const char* str);

void terminal_initialize(void);
void terminal_setcolor(uint8_t color);
void terminal_scroll_down(void);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);

/* Test functions written in test_terminal.c */
void terminal_test_1();
void terminal_test_2();
void terminal_test_3();
void terminal_test_4();
void terminal_test_5();

#endif /* TERMINAL_H */
