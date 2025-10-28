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

constexpr int FRONT_BUMPER_ID = 2;
unsigned long lastRead = 0;

void setup() {
    BoardInit();
    Movement::init();
    vInitColorSensor();
    //LEDInit();
    Serial.begin(115200);
}

void loop() {
    if(Movement::getCurrentMove() == Movement::MoveEnum::NONE){
        Movement::moveForwardNonBlocking(99999, 400, 4000);
    }

    if (millis() - lastRead >= 50) {
        lastRead = millis();
        StationEnum station = ucDecideStation();
        switch(station){
            case WALL_DODGE:
                vWallDodge();
                break;
            case LOSANGE:
                faireLosange();
                break;
            case LOST_LINE:
                Movement::moveUntilLine();
                break;
            case QUILLE:
                faireQuille();
                break;
            default:
                break;
        }
    }

    vCourseCorrection();
    Movement::runMovementController();
}










/*
void setup() {
  BoardInit();
  Movement::init();
  Serial.begin(115200);
  delay(500);

  faireLosange();
}

void loop() {
  //Movement::turnRight(90);
  getIRDistance();
  delay(500);
  Serial.println("sodfij");
  if(ROBUS_IsBumper(FRONT_BUMPER_ID)){
    faireQuille();
  }
}*/

// void setup() {
//   BoardInit();
//   Movement::init();
//   Serial.begin(115200);
//   delay(500);

//   faireLosange();

//   Movement::stop();
// }

// void loop() {}

