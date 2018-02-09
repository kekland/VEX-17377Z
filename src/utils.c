#include "utils.h"
bool useSlewRate = true;
int motorDesiredSpeed[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void setMotorSpeed(int pin, float speed) {
	if(speed > 127) {
		speed = 127;
	}
	else if(speed < -127) {
		speed = -127;
	}

	int speed_multiplied = (int)(speed * motor_multiplier[pin]);

	if(useSlewRate) {
		motorDesiredSpeed[pin] = speed_multiplied * (motor_flipped[pin]? -1 : 1);
	}
	else {
		motorSet(pin + 1, speed_multiplied * (motor_flipped[pin]? -1 : 1));
	}
}

void updateSlewController() {
	if(!useSlewRate) {
		return;
	}
	for(int i = 0; i < 10; i++) {
		int previousMotorValue = motorGet(i + 1); //0 -> 127
		int difference = motorDesiredSpeed[i] - previousMotorValue;

		if(difference > 0) { difference = 1; }
		else if(difference < 0) { difference = -1; }
		else { difference = 0; }

		motorSet(i + 1, previousMotorValue + difference);
	}
}

float float_abs(float a) {
	if(a < 0) {
		return a * -1;
	}
	return a;
}
