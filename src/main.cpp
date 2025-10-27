#include <Arduino.h>
#include <LibRobus.h>
#include "WheelPID.h"
#include "Quille.h"
#include "Movement.h"
#include "Line.h"
#include "LedControl.h"
#include "Losange.h"

constexpr int FRONT_BUMPER_ID = 2;

/*void setup() {
   BoardInit();
   Movement::init();
   //LEDInit();
   Serial.begin(115200);
   Serial.println("iuhasdfiuhuisdfh");
   //vSetupLineSensors();
}

void loop() {
   if(Movement::getCurrentMove() == Movement::MoveEnum::NONE){
    Serial.println("iuhasdfiuhuisdfh");
       Movement::moveForwardNonBlocking(99999);
   }

   Serial.println("aosdjf");
   //vCourseCorrection();
   Movement::runMovementController();
   delay(5);
}*/












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

