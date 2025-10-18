#include <Arduino.h>
#include <LibRobus.h>
#include "ArmControl.h"

//section qui contrôle les servo_moteurs


//donne un nombre au id du bras. S'assurer d'inverser ici si les bras sont montés de façon inverse.
const int leftArm = 0;
const int rightArm = 1;


//intialise les servo moteurs
void armsInit(){
    SERVO_Enable(0);
    SERVO_Enable(1);
}

//met le bras gauche en haut
void leftArmUp(){
    delay(100);
    SERVO_SetAngle(leftArm,180);
}

//met le bras gauche en bas
void leftArmDown(){
    delay(100);
    SERVO_SetAngle(leftArm,0);
}

//met le bras gauche devant
void leftArmFront(){
    delay(100);
    SERVO_SetAngle(leftArm,90);
}

//met le bras droit en haut
void rightArmUp(){
    delay(100);
    SERVO_SetAngle(rightArm,180);
}

//met le bras droit en bas
void rightArmDown(){
    delay(100);
    SERVO_SetAngle(rightArm,0);
}

//met le bras droit devant
void rightArmFront(){
    delay(100);
    SERVO_SetAngle(rightArm,90);
}

//met les bras en haut
void bothArmUp(){
    delay(100);
    SERVO_SetAngle(leftArm,180);
    SERVO_SetAngle(rightArm,180);
}

//met les bras en bas
void bothArmDown(){
    delay(100);
    SERVO_SetAngle(leftArm,0);
    SERVO_SetAngle(rightArm,0);
}

//met les bras devant
void bothArmFront(){
    delay(100);
    SERVO_SetAngle(leftArm,90);
    SERVO_SetAngle(rightArm,90);
}