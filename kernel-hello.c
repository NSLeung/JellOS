//turns out these aren't standard lib functions, these are called "free-standing"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

//test if we can define?
// #define VGA_NUM_ROWS 25
// #define VGA_NUM_COLS 80
#include "terminal.h"

/* Check if compiler thinks you are targeting wrong OS */
#if defined(__linux__)
#error "You are not using cross-compiler!!"
#endif

/* This tutorial only works for 32-bit ix86 targets */
#if !defined(__i386)
#error "This tutorial needs to be compiled with ix86-elf compiler"
#endif

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();
 
	/* TEST 1: Newline support */
	/* Newline support is left as an exercise. */
	// terminal_test_1();

	/* TEST 2: going over row bounds */
	// terminal_test_2();

	/* TEST 3: going over column bounds */
	// terminal_test_3();

	/* TEST 4: just filling entire screen (minus one character else it clears next line) */
	// terminal_test_4();

	/* TEST 5: same as Test 4 but going one more character to initiate scrolling and clear last line */
	terminal_test_5();
}
