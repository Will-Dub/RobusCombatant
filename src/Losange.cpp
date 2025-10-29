
#include "Losange.h"
#include "Movement.h"

void faireLosange() {
    const float distance = 35.0f;  // distance des côtés du losange (cm)
    Movement::moveForward(35);

    // Sort de la ligne et commence le losange
    Movement::turnLeft(125.0f);
    Movement::moveForward(distance);

    Movement::turnLeft(80.0f);
    Movement::moveForward(distance);

    Movement::turnLeft(80.0f);
    Movement::moveForward(distance);

    Movement::turnLeft(90.0f);
    Movement::moveUntilLine();
}
