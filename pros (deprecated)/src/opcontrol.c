/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "utils.h"
#include "constants.h"
#include "pid.h"
#include "operator.h"


void operatorControl() {
	//pid_encoders[0] = encoderInit(1, 2, false);
	while (true) {
		controlAll();
		updateSlewController();
		delay(1);
	}
}
