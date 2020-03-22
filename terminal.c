#include "terminal.h"



uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg){
	return fg | bg << 4;
}
uint16_t vga_entry(unsigned char uc, uint8_t color){
	return (uint16_t) uc | (uint16_t) color << 8;
}

/* we need to write this since we don't have C stdlib functions */
size_t strlen(const char* str){
	size_t len = 0;
	while(str[len])
		len++;
	return len;
}

// static const size_t VGA_WIDTH = 80;
// static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	/* paging hasn't been supported yet so this is hardcoded */
	terminal_buffer = (uint16_t*) 0xB8000;	

	/* initialize the entire terminal_buffer as black */
	for (size_t y = 0; y < VGA_NUM_ROWS; y++) {
		for (size_t x = 0; x < VGA_NUM_COLS; x++) {
			const size_t index = y * VGA_NUM_COLS + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}

/**
 * Description: shift screen upward (so far we don't have history implemented)
 * bounded by O(n^2) because have to reload entire screen?
 */
void terminal_scroll_down(void){
    for (size_t y = 0; y < VGA_NUM_ROWS - 1; y++){ /* only go up to one before last row */
        for (size_t x = 0; x < VGA_NUM_COLS; x++){
            const size_t curr_index = y * VGA_NUM_COLS + x;
            const size_t next_row_index = (y + 1) * VGA_NUM_COLS + x;
            terminal_buffer[curr_index] = terminal_buffer[next_row_index];
        }
    }
    /* clear entire last row */
    size_t y = VGA_NUM_ROWS - 1;
    for(size_t x = 0; x < VGA_NUM_COLS; x++){
        const size_t index = y * VGA_NUM_COLS + x;
        terminal_buffer[index] = vga_entry(' ', terminal_color);
    }
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_NUM_COLS + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) 
{
	
	if (c == '\n'){
		terminal_column = 0;
		if (++terminal_row >= VGA_NUM_ROWS){
			// terminal_row = 0;   // this should not be the intended effect, we want to scroll
            terminal_row = VGA_NUM_ROWS - 1;
            terminal_scroll_down();   //maybe later implement terminal ID like ECE 391
        }
	}
	else {
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (++terminal_column == VGA_NUM_COLS) {
			terminal_column = 0;
			if (++terminal_row >= VGA_NUM_ROWS){
				// terminal_row = 0;   // this should not be the intended effect, we want to scroll
                terminal_row = VGA_NUM_ROWS - 1;
                terminal_scroll_down();   //maybe later implement terminal ID like ECE 391
			}
		}
    }
}
 
void terminal_write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
 
void terminal_writestring(const char* data) 
{
	terminal_write(data, strlen(data));
}