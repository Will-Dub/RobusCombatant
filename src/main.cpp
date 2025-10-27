#include <Arduino.h>
#include <LibRobus.h>
#include "WheelPID.h"
#include "Quille.h"
#include "Movement.h"
#include "Line.h"
#include "LedControl.h"
#include "Losange.h"

constexpr int FRONT_BUMPER_ID = 2;

/*
void setup() {
   BoardInit();
   Movement::init();
   LEDInit();
   Serial.begin(115200);
   vSetupLineSensors();
}

void loop() {
   if(Movement::getCurrentMove() == Movement::MoveEnum::NONE){
       Movement::moveForwardNonBlocking(99999);
   }

   unsigned int ucSensorState = ucReadLineSensors();
   vDecisionTime(ucSensorState);
   Movement::runMovementController();
}
*/











void setup() {
  BoardInit();
  Movement::init();
  Serial.begin(115200);
  delay(500);

  //faireQuille();
}

void loop() {
  //Movement::turnRight(90);
  getIRDistance();
  delay(500);
  if(ROBUS_IsBumper(FRONT_BUMPER_ID)){
    faireQuille();
  }
}

// void setup() {
//   BoardInit();
//   Movement::init();
//   Serial.begin(115200);
//   delay(500);

//   faireLosange();

//   Movement::stop();
// }

// void loop() {}

