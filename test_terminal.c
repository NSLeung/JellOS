#include "terminal.h"

void terminal_test_1(){
	for(int i = 0; i < VGA_NUM_ROWS; i++){
		/* We don't support printf directives yet.. */
		terminal_writestring("Hello, kernel world!\n");
	}
}
void terminal_test_2(){
	terminal_writestring("Overwriting first line!\n");
	for(int i = 0; i < VGA_NUM_ROWS - 1; i++){
		/* We don't support printf directives yet.. */
		terminal_writestring("Hello, kernel world after first line!\n");
	}
	terminal_writestring("Overwriting number 2!");
}
void terminal_test_3(){
	terminal_writestring("0SqINIxCeH7cAW0dTljnuVMrZauC3WmfQssHOJHcoCOkfByQmOrFKqITbv7j2aHA2R5kw6f32IEILWRX");

}
void terminal_test_4(){
	for(int i = 0; i < VGA_NUM_ROWS-1; i++){
		terminal_writestring("0SqINIxCeH7cAW0dTljnuVMrZauC3WmfQssHOJHcoCOkfByQmOrFKqITbv7j2aHA2R5kw6f32IEILWRX");
	}
	terminal_writestring("TCoXeqAPLBhGRxOPEKZWxZvegtPcPkzgiSFZthsEywyf6sRiqlaL7cWSRItHgGKgeKu1xE4iiFjCPeI");

}
void terminal_test_5(){
	for(int i = 0; i < VGA_NUM_ROWS-1; i++){
		terminal_writestring("0SqINIxCeH7cAW0dTljnuVMrZauC3WmfQssHOJHcoCOkfByQmOrFKqITbv7j2aHA2R5kw6f32IEILWRX");
	}
	terminal_writestring("TCoXeqAPLBhGRxOPEKZWxZvegtPcPkzgiSFZthsEywyf6sRiqlaL7cWSRItHgGKgeKu1xE4iiFjCPeIp");

}