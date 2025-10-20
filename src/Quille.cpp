#include "Quille.h"

void actionQuille(){
    // Avancer 12.5cm

    // Tourner en rond en même temps de chercher un objet
    while(true){}

    // Quand capteur allume: arrête de tourner en rond, tourne vers objet

    // Avance vers objet jusqu'a ce qu'il tombe

    // Retour
}

DETECTION::DetectionState getIRDetection(){
    bool isLeftOn = digitalRead(IR_LEFT_PIN);
    bool isRightOn = digitalRead(IR_LEFT_PIN);
    return DETECTION::getDetection(isLeftOn, isRightOn);
}