#ifndef LINE_H
#define LINE_H

#include "Movement.h"

#define LEFT_SENSOR_PIN A13
#define MIDDLE_SENSOR_PIN A14
#define RIGHT_SENSOR_PIN A15

constexpr int NONE = 0;
constexpr int WALL_DODGE = 1;
constexpr int WHITE_THRESHOLD = 200;

void vSetupLineSensors();
unsigned char ucReadLineSensors();
void vDecisionTime(unsigned char ucSensorState);

#endif