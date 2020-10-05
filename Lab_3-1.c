//Autumn Walters
//Date: 10/5/2020
//Lab 3-1 Main Code

//------------------------------------
// Lab 3 - Part 1: UART - Lab03_uart.c
//------------------------------------
//

#include "init.h"

// Main Execution Loop
int main(void) {
	//Initialize the system
	Sys_Init();

	printf("Your code here!\r\n");

	// Lost? Check out uart.c!
	UART_HandleTypeDef huart1;
	UART_HandleTypeDef huart6;
	char inp1;
	char inp2;

	//Initialize GPIO configurations
	HAL_UART_MspInit(huart1);
	HAL_UART_MspInit(huart6);

	//Initialize UART configurations
	initUart(huart1, 115200, USART1);
	initUart(huart6, 9600, USART6);

	while (inp1 != 27 && inp2 != 27) {
		inp1 = uart_getchar(huart1, 1);
		uart_putchar(huart6, inp1);	// echos character to other serial port
		inp2 = uart_getchar(huart6, 1);
		uart_putchar(huart1, inp2);
	}

	uart_print(huart1, "Program Ended");

}
