#include <Arduino.h>
#include <LibRobus.h>
#include "WheelPID.h"
#include "Movement.h"
#include "LedControl.h"
#include "ArmControl.h"
#include "Dance.h"

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
//-----------------------------
// MAIN CODE.
//-----------------------------

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