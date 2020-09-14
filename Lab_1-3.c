/*
 * Lab_1-3.c
 *
 *  Created on: Sep 10, 2020
 *      Author: waltea2
 */

//------------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------------
#include "stm32f769xx.h"
#include "hello.h"
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>

//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
int main(void)
{
    Sys_Init(); // This always goes at the top of main (defined in init.c)
    // Need to enable clock for peripheral bus on GPIO Ports A,C,D,F,J
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOFEN| RCC_AHB1ENR_GPIOJEN;

    // set output pins
    GPIOA->MODER |= GPIO_MODER_MODER12_0;
    GPIOD->MODER |= GPIO_MODER_MODER4_0;
    GPIOJ->MODER |= GPIO_MODER_MODER5_0 | GPIO_MODER_MODER13_0;

    // Set input pull-up registers
    GPIOC->PUPDR |= GPIO_PUPDR_PUPDR6_1 | GPIO_PUPDR_PUPDR7_1;
    GPIOF->PUPDR |= GPIO_PUPDR_PUPDR6_1;
    GPIOJ->PUPDR |= GPIO_PUPDR_PUPDR1_1;

    while(1){
    	//Turn on and off LEDs based on Switch inputs (LD1-LD4 corresponds to D0-D3)
    	if (GPIOC->IDR & GPIO_PIN_7) { // If D0 is on
    		GPIOJ->BSRR = (uint16_t)GPIO_PIN_13; // Turn on LED1
    	}
    	else {
    		GPIOJ->BSRR = (uint32_t)GPIO_PIN_13 << 16; // Turn off LED1
    	}
    	if (GPIOC->IDR & GPIO_PIN_6) { // If D1 is on
    		GPIOJ->BSRR = (uint16_t)GPIO_PIN_5; // Turn on LED2
    	}
    	else {
    		GPIOJ->BSRR = (uint32_t)GPIO_PIN_5 << 16; // Turn off LED2
    	}
    	if (GPIOJ->IDR & GPIO_PIN_1) { // If D2 is on
    		GPIOA->BSRR = (uint16_t)GPIO_PIN_12; // Turn on LED3
    	}
    	else {
    		GPIOA->BSRR = (uint32_t)GPIO_PIN_12 << 16; // Turn off LED3
    	}
    	if (GPIOF->IDR & GPIO_PIN_6) { // If D3 is on
    		GPIOD->BSRR = (uint32_t)GPIO_PIN_4 << 16; // Turn on LED4
    	}
    	else {
    		GPIOD->BSRR = (uint16_t)GPIO_PIN_4; // Turn off LED4
    	}
    }
}

