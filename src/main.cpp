#include <Arduino.h>
#include <LibRobus.h>
#include "WheelPID.h"
#include "Quille.h"
#include "Movement.h"
#include "Line.h"
#include "LedControl.h"
#include "Losange.h"
#include "ColorSquares.h"
#include "WallDodge.h"
#include "LostLine.h"

constexpr int FRONT_BUMPER_ID = 2;
constexpr int LEFT_BUMPER_ID = 0;
constexpr int RIGHT_BUMPER_ID = 1;
constexpr float WHISTLE_THRESHOLD = 200;
bool quilleRight = true;

unsigned long lastRead = 0;

void waitForWhistle();

void setup() {
    BoardInit();
    Movement::init();
    vInitColorSensor();
    LEDInit();
    Serial.begin(115200);

    waitForWhistle();
}

void loop() {
    if(Movement::getCurrentMove() == Movement::MoveEnum::NONE){
        Movement::moveForwardNonBlocking(99999, 1000, 7000);
    }

    if (millis() - lastRead >= 100) {
        lastRead = millis();
        StationEnum station = ucDecideStation();
        switch(station){
            case WALL_DODGE:
                yLedOn();
                vWallDodge();
                yLedOff();
                break;
            case LOSANGE:
                bLedOn();
                faireLosange();
                bLedOff();
                break;
            case LOST_LINE:
                gLedOn();
                faireLostLine();
                gLedOff();
                break;
            case QUILLE:
                rLedOn();
                faireQuille(quilleRight);
                rLedOff();
                break;
            default:
                break;
        }
    }

    vCourseCorrection();
    Movement::runMovementController();
}

void waitForWhistle(){
    while(true)
    {
        int A2Value = analogRead(A0);
        int A4Value = analogRead(A1);
        if((A2Value - A4Value) >= WHISTLE_THRESHOLD || ROBUS_IsBumper(FRONT_BUMPER_ID))
        {
            return;
        }

        if(ROBUS_IsBumper(LEFT_BUMPER_ID)){
            quilleRight = false;
        }else if(ROBUS_IsBumper(RIGHT_BUMPER_ID)){
            quilleRight = true;
        }

        delay(10);
    }
}
