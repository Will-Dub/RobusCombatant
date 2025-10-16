#include <Arduino.h>
#include <LibRobus.h>
#include "Detection.h"

#define IR_LEFT_PIN 2 // Vert
#define IR_RIGHT_PIN 3 // Rouge

//-----------------------------
// MAIN CODE.
//-----------------------------
void setup() {
    BoardInit();
    Serial.begin(115200);
    pinMode(IR_LEFT_PIN, INPUT);
    pinMode(IR_RIGHT_PIN, INPUT);
}

void loop() {
    Serial.println("TEST");
}

DETECTION::DetectionState readIR(){
    bool isLeftOn = digitalRead(IR_LEFT_PIN);
    bool isRightOn = digitalRead(IR_LEFT_PIN);
    return DETECTION::getDetection(isLeftOn, isRightOn);
}