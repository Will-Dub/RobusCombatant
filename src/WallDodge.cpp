#include "WallDodge.h"
#include "Movement.h"
#include "Line.h"
#include <Arduino.h>

void vWallDodge()
{
    //Turn 90 degrees to the right
    Movement::turnRight(90);
    //Go forwards 50cm
    Movement::moveForward(50);
    //Turn 90 degrees to the left
    Movement::turnLeft(90);
    //Go forwards 50cm (passes wall)
    Movement::moveForward(50);
    //Turn 45 degrees to the left
    Movement::turnLeft(45);
    //Go forwards until line is detected
    Movement::moveUntilLine();
    vCourseCorrection();
}