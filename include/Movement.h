#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>
#include <LibRobus.h>
#include "WheelPID.h"

namespace Movement {
    constexpr float RAYON (0.19 / 2.0);
    constexpr float ACCEL_FORWARD_DISTANCE = 9.0f;
    constexpr float ACCEL_TURN_DISTANCE = 4.8f;
    constexpr int MAX_TURNING_SPEED = 4500;
    constexpr int MIN_TURNING_SPEED = 1500;
    constexpr int MAX_STRAIGHT_SPEED = 6000;
    constexpr int MIN_STRAIGHT_SPEED = 1000;

    enum MoveEnum { FORWARD, TURN_LEFT, TURN_RIGHT, NONE };

    //function prototypes
    void init();
    void moveForward(float pDistance);
    void moveForwardNonBlocking(float pDistance);
    void turnRight(float angle);
    void turnRightNonBlocking(float angle);
    void turnLeft(float angle);
    void turnLeftNonBlocking(float angle);
    void stop();
    void waitEndMove();
    void runMovementController();
    MoveEnum getCurrentMove();
}
#endif