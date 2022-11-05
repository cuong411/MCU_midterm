/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Cuong
 */

#include "software_timer.h"

int timer0_flag = 0;
int timer1_flag = 0;

int timer0_counter = 1000 / TICK;
int timer1_counter = 0;

void set_timer1(int duration)
{
	timer1_counter = duration / TICK;
	timer1_flag = 0;
}

void timer_run()
{
	// control red led, lock at 1 second
	if(timer0_counter > 0)
	{
		timer0_counter--;
		if(timer0_counter <= 0)
		{
			timer0_flag = 1;
			timer0_counter = 1000 / TICK;
		}
	}

	if(timer1_counter > 0)
	{
		timer1_counter--;
		if(timer1_counter <= 0)
		{
			timer1_flag = 1;
		}
	}
}
