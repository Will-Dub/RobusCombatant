#ifndef LINE_H
#define LINE_H

#define NONE 0
#define WALL_DODGE 1

#define LEFT_SENSOR_PIN A13
#define MIDDLE_SENSOR_PIN A14
#define RIGHT_SENSOR_PIN A15

#define WHITE_THRESHOLD 200

void vsetupLineSensors();
unsigned char ucReadLineSensors();

#endif