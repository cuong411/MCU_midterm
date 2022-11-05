/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Cuong
 */

#include "button.h"

int TimeOutForKeyPress = 0;

int buttonReset_flag = 0;
int buttonInc_flag = 0;
int buttonDec_flag = 0;

int buttonReset_count = 0;
int buttonInc_count = 0;
int buttonDec_count = 0;

void getKeyInputReset()
{
    if(HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin) == GPIO_PIN_RESET)
    {
        buttonReset_count++;
        if(buttonReset_count == (40 / TICK))
        {
            buttonReset_flag = 1;
        }
    }
    else
    {
        if(buttonReset_count < (40 / TICK))
        {
            buttonReset_flag = 0;
        }
        buttonReset_count = 0;
    }
}

void getKeyInputInc()
{
    if(HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin) == GPIO_PIN_RESET)
    {
        buttonInc_count++;
        if(buttonInc_count == (40 / TICK))
        {
            buttonInc_flag = 1;
        }
        if(buttonInc_count >= (3000 / TICK))
        {
            TimeOutForKeyPress--;
            if(TimeOutForKeyPress <= 0)
            {
                buttonInc_flag = 1;
                TimeOutForKeyPress = 1000 / TICK;
            }
        }
    }
    else
    {
        if(buttonInc_count < (40 / TICK))
        {
            buttonInc_flag = 0;
        }
        buttonInc_count = 0;
        TimeOutForKeyPress = 0;
    }
}

void getKeyInputDec()
{
    if(HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin) == GPIO_PIN_RESET)
    {
        buttonDec_count++;
        if(buttonDec_count == (40 / TICK))
        {
            buttonDec_flag = 1;
        }
        if(buttonDec_count >= (3000 / TICK))
		{
        	TimeOutForKeyPress--;
        	if(TimeOutForKeyPress <= 0)
        	{
        		buttonDec_flag = 1;
        		TimeOutForKeyPress = 1000 / TICK;
        	}
		}
    }
    else
    {
        if(buttonDec_count < (40 / TICK))
        {
            buttonDec_flag = 0;
        }
        buttonDec_count = 0;
        TimeOutForKeyPress = 0;
    }
}
