#include "Quille.h"

bool isQuilleFound = false;
float distanceTourner = 0;
float distanceAvancer = 0;

void faireQuille(){
    // Scan pour la quille
    Serial.println("Tourne");
    Movement::turnRightNonBlocking(360, 500, 3000);
    waitEndMoveFinding();

    Serial.println("Tourné fini");

    // Vérifie si la quille a été trouvé
    if(!isQuilleFound){
        Serial.println("quille pas trouvé");
        return;
    }

    Serial.println("Avance");
    // Phase 2: Avance vers la quille
    Movement::moveForwardNonBlocking(MAX_QUILLE_DISTANCE);
    waitEndMoveGoingTo();

    Serial.println("Fini");

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

void waitEndMoveFinding(){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE){
        Movement::runMovementController();

        if (getIRIsDetected()) {
            Serial.println("Quille trouvé");
            isQuilleFound = true;
            distanceTourner = WHEEL_PID::getRightCoveredDistance();
            Movement::stop();
            break;
        }
    }
}

void waitEndMoveGoingTo(){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE){
        Movement::runMovementController();

        if (!getIRIsDetected()) {
            Serial.println("Quille tombé");
            // La quille n’est plus visible
            distanceAvancer = WHEEL_PID::getCoveredDistance();
            Movement::stop();
            break;
        }
    }
}

float getIRDistance()
{
    int raw = ROBUS_ReadIR(IR_PIN);

    float vout = float(raw) * 0.0048828125; // Conversion analog to voltage
    int distance = 13 * pow(vout, -1);

    Serial.println(distance);

    if (distance < 10.0f) distance = 10.0f;
    if (distance > 80.0f) distance = 80.0f;

    return distance;
}

bool getIRIsDetected()
{
    float dist = getIRDistance();
    return (dist <= MAX_QUILLE_DISTANCE);
}