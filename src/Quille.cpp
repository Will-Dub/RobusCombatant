#include "Quille.h"

QuilleState currentState = QuilleState::FINDING;

void actionQuille(){
    // Avancer 12.5cm
    Movement::moveForward(12.5);

    // Faire un carré jusqu'a ce qu'il trouve un objet
    while(currentState == QuilleState::FINDING){
        Movement::moveForwardNonBlocking(FORWARD_DISTANCE);
        waitEndMoveFinding();
        Movement::turnRight(90);
        waitEndMoveFinding();
        Movement::moveForwardNonBlocking(FORWARD_DISTANCE*2);
        waitEndMoveFinding();
        Movement::turnRight(90);
        waitEndMoveFinding();
        Movement::moveForwardNonBlocking(FORWARD_DISTANCE*2);
        waitEndMoveFinding();
        Movement::turnRight(90);
        waitEndMoveFinding();
        Movement::moveForwardNonBlocking(FORWARD_DISTANCE*2);
        waitEndMoveFinding();
        Movement::turnRight(90);
        waitEndMoveFinding();
        Movement::moveForwardNonBlocking(FORWARD_DISTANCE);
        waitEndMoveFinding();
        break;
    }

    if(currentState == QuilleState::FINDING){
        // TODO quoi faire si on trouve pas la quille(continuer??)
        return;
    }

    // Phase 2: Quand capteur allume: arrête de tourner en rond, tourne vers objet
    if (currentState == QuilleState::ALIGNING) {
        DETECTION::DetectionState ir = getIRDetection();
        if (ir == DETECTION::DetectionState::DETECT_LEFT) {
            Movement::turnLeft(45);
        } else if (ir == DETECTION::DetectionState::DETECT_RIGHT) {
            Movement::turnRight(45);
        }

        waitEndMoveAligning();
    }

    // Phase 3: Avance vers objet jusqu'a ce qu'il tombe
    if (currentState == QuilleState::GOING_TO) {
        Movement::moveForward(FORWARD_GOING_TO_MAX);
        waitEndMoveGoingTo();
    }

    // Phase 4: Retour
    if (currentState == QuilleState::GOING_BACK) {
        // TODO: retourner à la ligne blanche ici
    }
}

void waitEndMoveFinding(){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE && getIRDetection() == DETECTION::DETECT_NONE){
        Movement::runMovementController();
    }

    Movement::stop();

    if(getIRDetection() != DETECTION::DETECT_NONE){
        currentState = QuilleState::ALIGNING;
    }
}

void waitEndMoveAligning(){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE && getIRDetection() != DETECTION::DETECT_FRONT){
        Movement::runMovementController();
    }

    Movement::stop();

    if(getIRDetection() == DETECTION::DETECT_FRONT){
        currentState = QuilleState::GOING_TO;
    }
}

void waitEndMoveGoingTo(){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE && getIRDetection() != DETECTION::DETECT_NONE){
        Movement::runMovementController();
    }

    Movement::stop();

    if(getIRDetection() == DETECTION::DETECT_NONE){
        currentState = QuilleState::GOING_BACK;
    }
}

DETECTION::DetectionState getIRDetection(){
    bool isLeftOn = digitalRead(IR_LEFT_PIN);
    bool isRightOn = digitalRead(IR_RIGHT_PIN);
    return DETECTION::getDetection(isLeftOn, isRightOn);
}