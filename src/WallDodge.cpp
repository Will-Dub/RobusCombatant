#include "WallDodge.h"
#include "Movement.h"
#include "Line.h"
#include <Arduino.h>

void vWallDodge()
{
    Movement::turnRight(80);
    Movement::moveForward(40);
    Movement::turnLeft(80);
    Movement::moveForward(110);
    Movement::turnLeft(80);
    Movement::moveUntilLine();
    Movement::turnRight(50);
}