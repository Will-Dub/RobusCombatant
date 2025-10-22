#include <Arduino.h>
#include <LibRobus.h>
#include "WheelPID.h"
#include "Quille.h"
#include "Movement.h"
#include "Line.h"
#include "LedControl.h"

constexpr int ECHO_PIN = 37;
constexpr int TRIG_PIN = 38;

SRF04Sonar sonar;

void setup() {
    BoardInit();
    Movement::init();
    LEDInit();
    Serial.begin(115200);
    vSetupLineSensors();
    sonar.init(ECHO_PIN, TRIG_PIN);
}

void loop() {
    if(Movement::getCurrentMove() == Movement::MoveEnum::NONE){
        Movement::moveForwardNonBlocking(99999);
    }

    unsigned int ucSensorState = ucReadLineSensors();
    vDecisionTime(ucSensorState);
    Movement::runMovementController();
}