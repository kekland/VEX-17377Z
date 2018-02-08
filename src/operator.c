#include "headers/operator.h"

void controlBaseJoystick() {
	int leftSpeed = joystickGetAnalog(1, 3);
	int rightSpeed = joystickGetAnalog(1, 2);
	if(abs(leftSpeed) < JOYSTICK_DEAD_ZONE)
		leftSpeed = 0;
	if(abs(rightSpeed) < JOYSTICK_DEAD_ZONE)
		rightSpeed = 0;
	setMotorSpeed(2, rightSpeed);
	setMotorSpeed(7, leftSpeed);
}

void controlIntakeJoystick() {
	if(joystickGetDigital(1, 7, JOY_UP)) {
		setMotorSpeed(0, 127);
	}
	else if(joystickGetDigital(1, 7, JOY_DOWN)) {
		setMotorSpeed(0, -127);
	}
	else {
		setMotorSpeed(0, 0);
	}
}

void controlLiftJoystick() {
		if(joystickGetDigital(1, 5, JOY_UP)) {
			setMotorSpeed(4, 127);
			setMotorSpeed(6, 127);
		}
		else if(joystickGetDigital(1, 5, JOY_DOWN)) {
			setMotorSpeed(4, -127);
			setMotorSpeed(6, -127);
		}
		else {
			setMotorSpeed(4, 0);
			setMotorSpeed(6, 0);
		}
}

void controlAll() {
  controlBaseJoystick();
  controlLiftJoystick();
  controlIntakeJoystick();
  //controlChainBarJoystick();
  //controlClawJoystick();
}
