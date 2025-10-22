#ifndef LINE_H
#define LINE_H

#include "Movement.h"

#define LEFT_SENSOR_PIN A13
#define MIDDLE_SENSOR_PIN A14
#define RIGHT_SENSOR_PIN A15

constexpr int WHITE_THRESHOLD = 200;

enum StationEnum { NONE, WALL_DODGE };

void vSetupLineSensors();
unsigned char ucReadLineSensors();
void vDecisionTime(unsigned char ucSensorState);

#endif