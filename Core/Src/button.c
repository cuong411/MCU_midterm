/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Cuong
 */

#include "button.h"

int buttonReset_flag = 0;
int buttonInc_flag = 0;
int buttonDec_flag = 0;

int buttonReset_counter = 0;
int buttonInc_counter = 0;
int buttonDec_counter = 0;

void getKeyInputReset()
{
    if(HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin) == GPIO_PIN_RESET)
    {
        buttonReset_counter++;
        if(buttonReset_counter == (40 / TICK))
        {
            buttonReset_flag = 1;
        }
    }
    else
    {
        if(buttonReset_counter < (40 / TICK))
        {
            buttonReset_flag = 0;
        }
        buttonReset_counter = 0;
    }
}

void getKeyInputInc()
{
    if(HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin) == GPIO_PIN_RESET)
    {
        buttonInc_counter++;
        if(buttonInc_counter == (40 / TICK))
        {
            buttonInc_flag = 1;
        }
        if(buttonInc_counter >= (LONG_PRESS_DURATION / TICK) && buttonInc_counter % (KEY_PRESS_TIME_OUT / TICK) == 0)
        {
        	buttonInc_flag = 1;
        }
    }
    else
    {
        if(buttonInc_counter < (40 / TICK))
        {
            buttonInc_flag = 0;
        }
        buttonInc_counter = 0;
    }
}

void getKeyInputDec()
{
    if(HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin) == GPIO_PIN_RESET)
    {
        buttonDec_counter++;
        if(buttonDec_counter == (40 / TICK))
        {
            buttonDec_flag = 1;
        }
        if(buttonDec_counter >= (LONG_PRESS_DURATION / TICK) && buttonDec_counter % (KEY_PRESS_TIME_OUT / TICK) == 0)
        {
        	buttonDec_flag = 1;
        }
    }
    else
    {
        if(buttonDec_counter < (40 / TICK))
        {
            buttonDec_flag = 0;
        }
        buttonDec_counter = 0;
    }
}
