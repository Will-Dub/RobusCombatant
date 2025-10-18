#include <Arduino.h>
#include <LibRobus.h>
#include "ArmControl.h"

//fichier qui contrôle les servo_moteurs

//donne un nombre au id du bras. !!!!!!S'assurer d'inverser ici si les bras sont montés de façon inverse.
const int leftArm = 0;
const int rightArm = 1;

//valeur des angles des positions  !!!!!!!À AJUSTER AU BESOIN
const int upAngle = 180;
const int frontAngle = 90;
const int downAngle = 0;

//temps du délai avant de bouger les bras  !!!!!!!À AJUSTER AU BESOIN
const int moveDelay = 100;

//intialise les servo moteurs
void armsInit(){
    SERVO_Enable(leftArm);
    SERVO_Enable(rightArm);
}

//désactive les bras (fonction ajouté au cas où on en aurait besoin plus tard)
void armsOFF(){
    SERVO_Disable(leftArm);
    SERVO_Disable(rightArm);
}

//met le bras gauche en haut
void leftArmUp(){
    delay(moveDelay);
    SERVO_SetAngle(leftArm,upAngle);
}

//met le bras gauche en bas
void leftArmDown(){
    delay(moveDelay);
    SERVO_SetAngle(leftArm,downAngle);
}

//met le bras gauche devant
void leftArmFront(){
    delay(moveDelay);
    SERVO_SetAngle(leftArm,frontAngle);
}

//met le bras droit en haut
void rightArmUp(){
    delay(moveDelay);
    SERVO_SetAngle(rightArm,upAngle);
}

//met le bras droit en bas
void rightArmDown(){
    delay(moveDelay);
    SERVO_SetAngle(rightArm,downAngle);
}

//met le bras droit devant
void rightArmFront(){
    delay(moveDelay);
    SERVO_SetAngle(rightArm,frontAngle);
}

//met les bras en haut
void bothArmUp(){
    delay(moveDelay);
    SERVO_SetAngle(leftArm,upAngle);
    SERVO_SetAngle(rightArm,upAngle);
}

//met les bras en bas
void bothArmDown(){
    delay(moveDelay);
    SERVO_SetAngle(leftArm,downAngle);
    SERVO_SetAngle(rightArm,downAngle);
}

//met les bras devant
void bothArmFront(){
    delay(moveDelay);
    SERVO_SetAngle(leftArm,frontAngle);
    SERVO_SetAngle(rightArm,frontAngle);
}