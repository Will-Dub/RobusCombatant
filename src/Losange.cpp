
#include "Losange.h"
#include "Movement.h"

void faireLosange() {
    const float distance = 45.0f;  // distance des côtés du losange (cm)
    const int vmin = Movement::MIN_TURNING_SPEED;
    const int vmax = Movement::MAX_TURNING_SPEED;

    Movement::moveForward(30);

    // Sort de la ligne et commence le losange
    Movement::turnLeft(135.0f, vmin, vmax);
    Movement::moveForward(distance);

    Movement::turnLeft(80.0f, vmin, vmax);
    Movement::moveForward(distance);

    Movement::turnLeft(80.0f, vmin, vmax);
    Movement::moveForward(distance);

    Movement::turnLeft(80.0f, vmin, vmax);
    Movement::moveUntilLine();
}
