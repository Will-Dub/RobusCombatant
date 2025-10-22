#include <Arduino.h>
#include <LibRobus.h>
#include "ArmControl.h"

//fichier qui contrôle les servo_moteurs

//donne un nombre au id du bras. !!!!!!S'assurer d'inverser ici si les bras sont montés de façon inverse.
const int leftArm = 0;
const int rightArm = 1;

//valeur des angles des positions  !!!!!!!À AJUSTER AU BESOIN
const int rightUpAngle = 0;
const int rightFrontAngle = 90;
const int rightDownAngle = 180;

//valeur des angles des positions  !!!!!!!À AJUSTER AU BESOIN
const int leftUpAngle = 180;
const int leftFrontAngle = 90;
const int leftDownAngle = 0;

//temps du délai avant de bouger les bras  !!!!!!!À AJUSTER AU BESOIN
const int moveDelay = 1000;

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

//réinitialise le bras gauche pour le prochain mouvement
void resetLeftArm(){
    SERVO_Disable(leftArm);
    SERVO_Enable(leftArm);
}

//réinitialise le bras droit pour le prochain mouvement
void resetRightArm(){
    SERVO_Disable(rightArm);
    SERVO_Enable(rightArm);
}

//met le bras gauche en haut
void leftArmUp(){
    resetLeftArm();
    delay(moveDelay);
    SERVO_SetAngle(leftArm,leftUpAngle);
}

//met le bras gauche en bas
void leftArmDown(){
    resetLeftArm();
    delay(moveDelay);
    SERVO_SetAngle(leftArm,leftDownAngle);
}

//met le bras gauche devant
void leftArmFront(){
    resetLeftArm();
    delay(moveDelay);
    SERVO_SetAngle(leftArm,leftFrontAngle);
}

//met le bras droit en haut
void rightArmUp(){
    resetRightArm();
    delay(moveDelay);
    SERVO_SetAngle(rightArm,rightUpAngle);
}

//met le bras droit en bas
void rightArmDown(){
    resetRightArm();
    delay(moveDelay);
    SERVO_SetAngle(rightArm,rightDownAngle);
}

//met le bras droit devant
void rightArmFront(){
    resetRightArm();
    delay(moveDelay);
    SERVO_SetAngle(rightArm,rightFrontAngle);
}

//met les bras en haut
void bothArmUp(){
    resetLeftArm();
    resetRightArm();
    delay(moveDelay);
    SERVO_SetAngle(leftArm,leftUpAngle);
    SERVO_SetAngle(rightArm,rightUpAngle);
}

//met les bras en bas
void bothArmDown(){
    resetLeftArm();
    resetRightArm();
    delay(moveDelay);
    SERVO_SetAngle(leftArm,leftDownAngle);
    SERVO_SetAngle(rightArm,rightDownAngle);
}

//met les bras devant
void bothArmFront(){
    resetLeftArm();
    resetRightArm();
    delay(moveDelay);
    SERVO_SetAngle(leftArm,leftFrontAngle);
    SERVO_SetAngle(rightArm,rightFrontAngle);
}