#pragma once

#include "WheelPID.h"
#include "Movement.h"

// Rayon du cercle
constexpr float MAX_QUILLE_DISTANCE = 30.0f;

void actionQuille(SRF04Sonar& sonar);
void waitEndMoveFinding(SRF04Sonar& sonar);
void waitEndMoveGoingTo(SRF04Sonar& sonar);
void goBackToStart();