#ifndef CONSTANTS_H_
#include <stdbool.h>
#define CONSTANTS_H_

extern bool motor_flipped[];
extern float motor_multiplier[];
extern int JOYSTICK_DEAD_ZONE;
/*
	motors:
		2: leftWheels
		3: leftLift
		4: intake
		5: chainbar
		6: claw
		7:
		8: rightLift
		9: rightWheels

	sensors:
		1: leftWheelsEncoder
		3: rightWheelsEncoder
		5: liftEncoder
		7: chainBarPotentiometer
*/
#endif
