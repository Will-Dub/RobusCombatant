#include "Quille.h"

QuilleState currentState;

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

    // Quand capteur allume: arrête de tourner en rond, tourne vers objet
    if(getIRDetection() == DETECTION::DetectionState::DETECT_LEFT){
        Movement::turnLeft(45);
    }else if(getIRDetection() == DETECTION::DetectionState::DETECT_RIGHT){
        Movement::turnRight(45);
    }
    waitEndMoveAligning();

    if(currentState == QuilleState::FINDING){
        // TODO quoi faire si on perd la quille(retour?)
    }

    // Avance vers objet jusqu'a ce qu'il tombe
    Movement::moveForward(25);
    waitEndMoveGoingTo();

    // Retour
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

    if(getIRDetection() != DETECTION::DETECT_FRONT){
        currentState = QuilleState::GOING_TO;
    }
}

void waitEndMoveGoingTo(){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE && getIRDetection() != DETECTION::DETECT_NONE){
        Movement::runMovementController();
    }

    Movement::stop();

    if(getIRDetection() != DETECTION::DETECT_NONE){
        currentState = QuilleState::GOING_BACK;
    }
}

DETECTION::DetectionState getIRDetection(){
    bool isLeftOn = digitalRead(IR_LEFT_PIN);
    bool isRightOn = digitalRead(IR_LEFT_PIN);
    return DETECTION::getDetection(isLeftOn, isRightOn);
}