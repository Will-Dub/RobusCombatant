#include "Quille.h"

bool isQuilleFound = false;
float distanceTourner = 0;

void faireQuille(){
    Movement::moveForward(30);

    // Scan pour la quille
    Movement::turnRightNonBlocking(360, 1000, 3500);
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
    Movement::moveForward(FORWARD_DISTANCE-15);
    Movement::moveUntilLine();
    Movement::moveForward(6);

    // Fini le tour de 360
    float angle = Movement::distanceToAngle(distanceTourner);
    if(angle <= 170){
        Movement::turnRight(170-angle);
    }else{
        Movement::turnLeft(angle-170);
    }

    // Reset
    isQuilleFound = false;
    distanceTourner = 0;
}

void waitEndMoveFinding(){
    while(Movement::getCurrentMove() != Movement::MoveEnum::NONE){
        Movement::runMovementController();

        if (getIRIsDetected()) {
            Serial.println("Quille trouvé");
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