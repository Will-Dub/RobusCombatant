#ifndef LINE_H
#define LINE_H

#include "Movement.h"

#define LEFT_SENSOR_PIN A7
#define MIDDLE_SENSOR_PIN A6
#define RIGHT_SENSOR_PIN A5

constexpr int WHITE_THRESHOLD = 940;

enum StationEnum { NONE, WALL_DODGE };

void vSetupLineSensors();
unsigned char ucReadLineSensors();
void vDecisionTime(unsigned char ucSensorState);

#endif