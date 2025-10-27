#include "WallDodge.h"
#include "Movement.h"
#include "Line.h"
#include <Arduino.h>

void vWallDodge()
{
    Movement::turnRight(90);
    Movement::moveForward(50);
    Movement::turnLeft(90);
    Movement::moveForward(50);
    Movement::turnLeft(45);
    Movement::moveUntilLine();
}