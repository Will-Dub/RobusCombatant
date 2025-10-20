#include <Arduino.h>
#include <LibRobus.h>
#include "Detection.h"
#include "WheelPID.h"
#include "Quille.h"
#include "Movement.h"

//-----------------------------
// MAIN CODE.
//-----------------------------
void setup() {
    BoardInit();
    Movement::init();
    Serial.begin(115200);
    pinMode(IR_LEFT_PIN, INPUT);
    pinMode(IR_RIGHT_PIN, INPUT);
}

void loop() {

}