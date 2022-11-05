/*
 * fsm_simple_buttons.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Cuong
 */

#ifndef INC_FSM_SIMPLE_BUTTONS_H_
#define INC_FSM_SIMPLE_BUTTONS_H_

#include "global.h"
#include "software_timer.h"
#include "main.h"
#include "led_display.h"
#include "button.h"

void fsm_simple_buttons_run();
void time_out_10s();

#endif /* INC_FSM_SIMPLE_BUTTONS_H_ */
