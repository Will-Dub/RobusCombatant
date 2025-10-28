
#include "Losange.h"
#include "Movement.h"

void faireLosange() {
    const float distance = 45.0f;  // distance des côtés du losange (cm)
    Movement::moveForward(30);

    // Sort de la ligne et commence le losange
    Movement::turnLeft(135.0f);
    Movement::moveForward(distance);

    Movement::turnLeft(80.0f);
    Movement::moveForward(distance);

    Movement::turnLeft(80.0f);
    Movement::moveForward(distance);

    Movement::turnLeft(80.0f);
    Movement::moveUntilLine();
}
