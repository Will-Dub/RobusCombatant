#include <Arduino.h>
#include <LibRobus.h>
#include "Movement.h"

//fonction qui permet de contourner le mur lorsque le capteur de couleur détecte le carré jaune.
void contournerMur(){
    //stop
    turnRight(90);
    moveForward(15);
    turnLeft(90);
    moveForward(15);
    turnLeft(90);
    moveForward(15);
    turnRight(90);
    //gets back into position, and send it back to line following code


}