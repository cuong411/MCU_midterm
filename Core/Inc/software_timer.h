/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Cuong
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

extern int timer0_flag;
extern int timer1_flag;

void set_timer1(int duration);

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
