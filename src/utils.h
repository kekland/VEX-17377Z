#ifndef UTILS_H_
#include "main.h"
#include "constants.h"
#define UTILS_H_
void setMotorSpeed(int pin, float speed);
void updateSlewController();
float float_abs(float a);
#endif
