#include <Arduino.h>
#include <LibRobus.h>
#include "Movement.h"

//fonction qui permet de contourner le mur lorsque le capteur de couleur détecte le carré jaune.
void contournerMur(){
    //stop
    Movement::turnRight(90);
    Movement::moveForward(15);
    Movement::turnLeft(90);
    Movement::moveForward(15);
    Movement::turnLeft(90);
    Movement::moveForward(15);
    Movement::turnRight(90);
    //gets back into position, and send it back to line following code


}