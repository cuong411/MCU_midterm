/*
 * led_display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Cuong
 */

#include "led_display.h"

void display7SEG(int num)
{
	if(num < 0 || num > 9) return;
	if(num == 1 || num == 4) HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
	if(num == 5 || num == 6) HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
	if(num == 2) HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 4 || num == 7) HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
	if(num % 2 == 1 || num == 4) HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 2 || num == 3 || num == 7) HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
	if(num == 0 || num == 1 || num == 7) HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
}

void displayRedLed()
{
	if(timer0_flag == 1)
	{
		timer0_flag = 0;
		HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
	}
}
