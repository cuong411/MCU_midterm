/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Cuong
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"
#include "main.h"

#define LONG_PRESS_DURATION	3000
#define KEY_PRESS_TIME_OUT	1000

extern int buttonReset_flag;
extern int buttonInc_flag;
extern int buttonDec_flag;

void getKeyInputReset();
void getKeyInputInc();
void getKeyInputDec();

#endif /* INC_BUTTON_H_ */
