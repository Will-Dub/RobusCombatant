#pragma once

#include <LibRobus.h>
#include "WheelPID.h"
#include "Movement.h"

// Rayon du cercle
constexpr float FORWARD_DISTANCE = 50.0f;
constexpr float MAX_QUILLE_SENSOR_DISTANCE = 15.0f;
constexpr uint16_t IR_PIN = 3;

void faireQuille();
void waitEndMoveFinding();
void waitEndMoveGoingTo();
void goBackToStart();
float getIRDistance();
bool getIRIsDetected();