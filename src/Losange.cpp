
#include "Losange.h"
#include "Movement.h"

void faireLosange() {
    const float distance = 100.0f;  // distance des côtés du losange (cm)
    const int vmin = Movement::MIN_TURNING_SPEED;
    const int vmax = Movement::MAX_TURNING_SPEED;

    // Sort de la ligne et commence le losange
    Movement::turnLeft(135.0f, vmin, vmax);
    Movement::moveForward(distance);

    Movement::turnLeft(90.0f, vmin, vmax);
    Movement::moveForward(distance);

    Movement::turnLeft(90.0f, vmin, vmax);
    Movement::moveForward(distance);

    Movement::turnLeft(90.0f, vmin, vmax);
    Movement::moveForward(distance);

    // Retour à l'orientation de départ
    Movement::turnRight(45.0f, vmin, vmax);
}
