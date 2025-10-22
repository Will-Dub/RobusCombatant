#include "Quille.h"

QuilleState currentState = QuilleState::FINDING;

MovementRecord moveHistory[MAX_MOVES];
int moveCount = 0;

void saveMove(Movement::MoveEnum type, float value) {
    if (moveCount < MAX_MOVES) {
        moveHistory[moveCount++] = { type, value };
    }
}

void moveForwardLog(float distance) {
    saveMove(Movement::MoveEnum::FORWARD, distance);
    Movement::moveForward(distance);
}

void moveForwardNonBlockingLog(float distance) {
    saveMove(Movement::MoveEnum::FORWARD, distance);
    Movement::moveForwardNonBlocking(distance);
}

void turnLeftLog(float angle) {
    saveMove(Movement::MoveEnum::TURN_LEFT, angle);
    Movement::turnLeft(angle);
}

void turnRightLog(float angle) {
    saveMove(Movement::MoveEnum::TURN_RIGHT, angle);
    Movement::turnRight(angle);
}

void goBackToStart() {
    for (int i = moveCount - 1; i >= 0; i--) {
        MovementRecord m = moveHistory[i];

        switch (m.type) {
            case Movement::MoveEnum::FORWARD:
                // Retourne sur la même distance (méthode simple sans moveBackward)
                Movement::turnRight(180);
                Movement::moveForward(m.distance);
                Movement::turnRight(180);
                break;

            case Movement::MoveEnum::TURN_LEFT:
                Movement::turnRight(m.distance);
                break;

            case Movement::MoveEnum::TURN_RIGHT:
                Movement::turnLeft(m.distance);
                break;
            default:
                break;
        }
        Movement::stop();
    }
    moveCount = 0; // Réinitialise l’historique
}

void actionQuille(SRF04Sonar& sonar){
    // Avancer 12.5cm
    Movement::moveForward(12.5);

    // Faire un carré jusqu'a ce qu'il trouve un objet
    while(currentState == QuilleState::FINDING){
        turnRightLog(90); waitEndMoveFinding(sonar);
        moveForwardNonBlockingLog(FORWARD_DISTANCE); waitEndMoveFinding(sonar);

        turnRightLog(90); waitEndMoveFinding(sonar);
        moveForwardNonBlockingLog(FORWARD_DISTANCE * 2); waitEndMoveFinding(sonar);

        turnRightLog(90); waitEndMoveFinding(sonar);
        moveForwardNonBlockingLog(FORWARD_DISTANCE * 2); waitEndMoveFinding(sonar);

        turnRightLog(90); waitEndMoveFinding(sonar);
        moveForwardNonBlockingLog(FORWARD_DISTANCE * 2); waitEndMoveFinding(sonar);

        turnRightLog(90); waitEndMoveFinding(sonar);
        moveForwardNonBlockingLog(FORWARD_DISTANCE); waitEndMoveFinding(sonar);
        break;
    }

    // Vérifie si la quille n'a pas été trouvé
    if(currentState == QuilleState::FINDING){
        // Tourne à gauche pour est face à la ligne
        Movement::turnLeft(90);
        return;
    }

    // Phase 2: Avance vers objet jusqu'a ce qu'il tombe
    if (currentState == QuilleState::GOING_TO) {
        moveForwardLog(FORWARD_GOING_TO_MAX);
        waitEndMoveGoingTo(sonar);
    }

    // Phase 3: Retour
    if (currentState == QuilleState::GOING_BACK) {
        goBackToStart();
        currentState = QuilleState::FINDING; // prêt pour recommencer
    }
}

void waitEndMoveFinding(SRF04Sonar& sonar){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE && sonar.getRange() > TRIGGER_RANGE){
        Movement::runMovementController();
    }

    Movement::stop();

    // Vérifie si la quille est trouvé
    if(sonar.getRange() <= TRIGGER_RANGE){
        currentState = QuilleState::GOING_TO;

        // Sauvegarde la distance parcouru si il trouve la quille
        moveHistory[moveCount].distance = WHEEL_PID::getCoveredDistance();
    }
}

void waitEndMoveGoingTo(SRF04Sonar& sonar){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE && sonar.getRange() <= TRIGGER_RANGE){
        Movement::runMovementController();
    }

    Movement::stop();

    // Vérifie si la quille est tombé
    if(sonar.getRange() > TRIGGER_RANGE){
        currentState = QuilleState::GOING_BACK;

        // Sauvegarde la distance parcouru
        moveHistory[moveCount].distance = WHEEL_PID::getCoveredDistance();
    }
}