#include "Quille.h"

bool isQuilleFound = false;
float distanceTourner = 0;

void faireQuille(){
    // Scan pour la quille
    Movement::turnRightNonBlocking(360, 500, 2500);
    waitEndMoveFinding();

    // Vérifie si la quille a été trouvé
    if(!isQuilleFound){
        Serial.println("quille pas trouvé");
        return;
    }

    Serial.println("Avance");
    // Phase 2: Avance vers la quille
    Movement::moveForward(FORWARD_DISTANCE);

    Serial.println("Fini");

    // Phase 3: Retour
    goBackToStart();
}

void goBackToStart(){
    // Fait un 180
    Movement::turnRight(170);

    // Retourne au milieu
    Movement::moveForward(FORWARD_DISTANCE);

    // Fini le tour de 360
    Movement::turnLeft(180+Movement::distanceToAngle(distanceTourner));

    // Reset
    isQuilleFound = false;
    distanceTourner = 0;
}

void waitEndMoveFinding(){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE){
        Movement::runMovementController();

        if (getIRIsDetected()) {
            Serial.println("Quille trouvé");
            delay(3);
            isQuilleFound = true;
            Movement::stop();
            distanceTourner = WHEEL_PID::getRightCoveredDistance();
            break;
        }
        delay(5);
    }
}

float getIRDistance()
{
    int raw = ROBUS_ReadIR(IR_PIN);

    float vout = float(raw) * 0.0048828125; // Conversion analog to voltage
    int distance = 13 * pow(vout, -1);

    Serial.println(distance);

    return distance;
}

bool getIRIsDetected()
{
    float dist = getIRDistance();
    return (dist <= MAX_QUILLE_SENSOR_DISTANCE && dist != 0);
}