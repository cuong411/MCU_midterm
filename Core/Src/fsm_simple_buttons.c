/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Cuong
 */

#include "fsm_simple_buttons.h"

int state = 0;
int isTimeOut = 0;

void fsm_simple_buttons_run()
{
	if(buttonReset_flag == 1)
	{
		buttonReset_flag = 0;
		state = 0;
	}
	if(buttonInc_flag == 1)
	{
		buttonInc_flag = 0;
		state++;
		set_timer1(9000);
	}
	if(buttonDec_flag == 1)
	{
		buttonDec_flag = 0;
		state--;
		set_timer1(9000);
	}
	if(state < 0) state = 9;
	if(state > 9) state = 0;
}

void time_out_10s()
{
	if(timer1_flag == 1)
	{
		timer1_flag = 0;
		set_timer1(1000);
		state--;
	}
	if(state == 0) set_timer1(0);
}
