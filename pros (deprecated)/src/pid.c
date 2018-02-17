#include "pid.h"

float pid_ku = 2.5;
bool pid_enabled[10] = {false, false, false, false, false, false, false, false, false, false};
float pid_kp[10] = {1.9, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float pid_ki[10] = {0.002, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float pid_kd[10] = {0.05, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float pid_error[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float pid_last_error[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float pid_integral[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float pid_integral_limit[10] = {50, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float pid_derivative[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int pid_required_motor_value[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int pid_last_time = 0;

Encoder pid_encoders[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

void calculatePid() {
	for(int i = 0; i < 10; i++) {
		if(!pid_enabled[i]) {
			continue;
		}

		int sensorValue = encoderGet(pid_encoders[i]);
		pid_error[i] = (float)(pid_required_motor_value[i] - sensorValue);

		if(pid_ki[i] != 0) {
			if(float_abs(pid_error[i]) < pid_integral_limit[i]) {
				pid_integral[i] += pid_error[i] * (millis() - pid_last_time);
			}
			else {
				pid_integral[i] = 0;
			}
		}
		else {
			pid_integral[i] = 0;
		}

		pid_derivative[i] = pid_last_error[i] - pid_error[i];
		pid_last_error[i] = pid_error[i];
		pid_last_time = millis();

		float speed = pid_kp[i] * pid_error[i] + pid_ki[i] * pid_integral[i] + pid_kd[i] * pid_derivative[i];

		setMotorSpeed(i, speed);
	}
}
