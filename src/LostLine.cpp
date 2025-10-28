#include "LostLine.h"
#include "Movement.h"
#include "Line.h"
#include <Arduino.h>

void faireLostLine()
{
    Movement::turnLeft(80);
    Movement::moveForward(30);
    Movement::turnRight(80);
    Movement::moveForward(90);
    Movement::turnRight(40);
    Movement::moveUntilLine();
}