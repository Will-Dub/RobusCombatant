#include "Quille.h"

bool isQuilleFound = false;
float distanceTourner = 0;
float distanceAvancer = 0;

void actionQuille(SRF04Sonar& sonar){
    // Scan pour la quille
    Movement::turnRightNonBlocking(360, 500, 3000);
    waitEndMoveFinding(sonar);

    // Vérifie si la quille a été trouvé
    if(!isQuilleFound){
        return;
    }

    // Phase 2: Avance vers la quille
    Movement::moveForwardNonBlocking(MAX_QUILLE_DISTANCE);
    waitEndMoveGoingTo(sonar);

    // Phase 3: Retour
    goBackToStart();
}

void goBackToStart(){
    // Fait un 180
    Movement::turnRight(180);

    // Retourne au milieu
    Movement::moveForward(distanceAvancer);

    // Fini le tour de 360
    float angleRestant = 360.0f - Movement::distanceToAngle(distanceTourner);
    Movement::turnRight(angleRestant);

    // Reset
    isQuilleFound = false;
    distanceTourner = 0;
    distanceAvancer = 0;
}

void waitEndMoveFinding(SRF04Sonar& sonar){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE){
        Movement::runMovementController();

        float distance = sonar.getRange();
        if (distance <= MAX_QUILLE_DISTANCE) {
            isQuilleFound = true;
            distanceTourner = WHEEL_PID::getRightCoveredDistance();
            Movement::stop();
            break;
        }
    }
}

void waitEndMoveGoingTo(SRF04Sonar& sonar){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE){
        Movement::runMovementController();

        float distance = sonar.getRange();
        if (distance > MAX_QUILLE_DISTANCE) {
            // La quille n’est plus visible
            distanceAvancer = WHEEL_PID::getCoveredDistance();
            Movement::stop();
            break;
        }
    }
}