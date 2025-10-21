#include "Movement.h"

namespace Movement {
    MoveEnum currentMove;
    float goalDistance;
    float currentAngle;

    void init(){
        WHEEL_PID::init();
        WHEEL_PID::setPIDDesiredPulse(0, 0);
        currentMove = MoveEnum::NONE;
    }

    void moveForward(float pDistance){
        moveForwardNonBlocking(pDistance);
        waitEndMove();
    }

    void moveForwardNonBlocking(float pDistance){
        WHEEL_PID::resetCoveredDistance();
        currentMove = MoveEnum::FORWARD;
        goalDistance = pDistance;
    }

    void turnRight(float angle){
        turnRightNonBlocking(angle);
        waitEndMove();
    }

    void turnRightNonBlocking(float angle){
        WHEEL_PID::resetCoveredDistance();
        currentMove = MoveEnum::TURN_RIGHT;
        goalDistance = angle*DEG_TO_RAD*RAYON;
    }

    void turnLeft(float angle){
        turnLeftNonBlocking(angle);
        waitEndMove();
    }

    void turnLeftNonBlocking(float angle){
        WHEEL_PID::resetCoveredDistance();
        currentMove = MoveEnum::TURN_LEFT;
        goalDistance = angle*DEG_TO_RAD*RAYON;
        waitEndMove();
    }

    void waitEndMove(){
        while(currentMove != MoveEnum::NONE){
            runMovementController();
        }
    }

    void stop(){
        WHEEL_PID::setPIDDesiredPulse(0, 0);
        WHEEL_PID::reset();
        currentMove = MoveEnum::NONE;
    }

    float computeScaledSpeed(float remainingDistance, float totalDistance,
                         float accelDistance,
                         float minSpeed, float maxSpeed) {
        if (remainingDistance <= 0) return 0;

        float coveredDistance = totalDistance - remainingDistance;

        float accelFactor = constrain(coveredDistance / accelDistance, 0.0f, 1.0f);
        float decelFactor = constrain(remainingDistance / accelDistance, 0.0f, 1.0f);

        float accelSmooth = pow(accelFactor, 2.0f);
        float decelSmooth = pow(decelFactor, 2.0f);

        float speedFactor = min(accelSmooth, decelSmooth);

        return minSpeed + (maxSpeed - minSpeed) * speedFactor;
    }

    void runMovementController(){
        switch(currentMove){
            case MoveEnum::TURN_RIGHT: {
                float coveredDistance = WHEEL_PID::getRightCoveredDistance();
                float remainingDistance = goalDistance - coveredDistance;
                if (remainingDistance <= 0.1f) {
                    stop();
                } else {
                    float speed = computeScaledSpeed(
                        remainingDistance,
                        goalDistance,
                        ACCEL_TURN_DISTANCE,
                        MIN_TURNING_SPEED,
                        MAX_TURNING_SPEED
                    );
                    WHEEL_PID::setPIDDesiredPulse(speed, -speed);
                }
                break;
            }
            case MoveEnum::TURN_LEFT: {
                float coveredDistance = WHEEL_PID::getRightCoveredDistance();
                float remainingDistance = goalDistance - coveredDistance;
                if (remainingDistance <= 0.1f) {
                    stop();
                } else {
                    float speed = computeScaledSpeed(
                        remainingDistance,
                        goalDistance,
                        ACCEL_TURN_DISTANCE,
                        MIN_TURNING_SPEED,
                        MAX_TURNING_SPEED
                    );
                    WHEEL_PID::setPIDDesiredPulse(-speed, speed);
                }
                break;
            }
            case MoveEnum::FORWARD: {
                float remainingDistance = goalDistance - WHEEL_PID::getCoveredDistance();
                if (remainingDistance <= 0.2f) {
                    stop();
                } else {
                    float speed = computeScaledSpeed(
                        remainingDistance,
                        goalDistance,
                        ACCEL_FORWARD_DISTANCE,
                        MIN_STRAIGHT_SPEED,
                        MAX_STRAIGHT_SPEED
                    );
                    WHEEL_PID::setPIDDesiredPulse(speed, speed);
                }
                break;
            }
            default: {
                break;
            }
        }

        WHEEL_PID::runPIDController();
    }

    MoveEnum getCurrentMove(){
        return currentMove;
    }

    void resetCurrentAngle(){
        currentAngle = 0;
    }

    float getCurrentAngle(){
        return fmod(currentAngle, 360.0f);
    }
}