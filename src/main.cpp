#include <Arduino.h>
#include <LibRobus.h>
#include "Detection.h"
#include "WheelPID.h"
#include "ArmControl.h"
#include "LedControl.h"
#include "Dance.h"

#define IR_LEFT_PIN 39 // Vert
#define IR_RIGHT_PIN 40 // Rouge

//-----------------------------
// MAIN CODE.
//-----------------------------
void setup() {
    BoardInit();
    WHEEL_PID::initPID();
    LEDInit();
    Serial.begin(115200);
    pinMode(IR_LEFT_PIN, INPUT);
    pinMode(IR_RIGHT_PIN, INPUT);
}

bool doDanceOnce = false;

void loop() {
    Serial.println("TEST");
    //!!ajouter ici le code qui attends le trigger de départ!! (à mettre une fois que nous saurons comment ils veulent faire démarrer la dance)
    if(doDanceOnce == false){
        dance();
        doDanceOnce = true;
    }
}

DETECTION::DetectionState getIRDetection(){
    bool isLeftOn = digitalRead(IR_LEFT_PIN);
    bool isRightOn = digitalRead(IR_LEFT_PIN);
    return DETECTION::getDetection(isLeftOn, isRightOn);
}