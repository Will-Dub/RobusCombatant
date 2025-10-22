#include <Arduino.h>
#include <LibRobus.h>
#include "WheelPID.h"
#include "Quille.h"
#include "Movement.h"
#include "Line.h"

constexpr int ECHO_PIN = 37;
constexpr int TRIG_PIN = 38;

//-----------------------------
// MAIN CODE.
//-----------------------------
void setup() {
    BoardInit();
    Movement::init();
    Serial.begin(115200);
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
}

void loop() {

}