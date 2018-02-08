#include "utils.h"
void setMotorSpeed(int pin, float speed) {
	if(speed > 127) {
		speed = 127;
	}
	else if(speed < -127) {
		speed = -127;
	}

	int speed_multiplied = (int)(speed * motor_multiplier[pin]);

	motorSet(pin + 1, speed_multiplied * (motor_flipped[pin]? -1 : 1));
}

float float_abs(float a) {
	if(a < 0) {
		return a * -1;
	}
	return a;
}
