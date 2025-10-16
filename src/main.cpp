#include <Arduino.h>
#include <LibRobus.h>
#include "Detection.h"
#include "WheelPID.h"

#define IR_LEFT_PIN 39 // Vert
#define IR_RIGHT_PIN 40 // Rouge

//-----------------------------
// MAIN CODE.
//-----------------------------
void setup() {
    BoardInit();
    WheelPID::initPID();
    Serial.begin(115200);
    pinMode(IR_LEFT_PIN, INPUT);
    pinMode(IR_RIGHT_PIN, INPUT);
}

void loop() {
    Serial.println("TEST");
}

DETECTION::DetectionState getIRDetection(){
    bool isLeftOn = digitalRead(IR_LEFT_PIN);
    bool isRightOn = digitalRead(IR_LEFT_PIN);
    return DETECTION::getDetection(isLeftOn, isRightOn);
}