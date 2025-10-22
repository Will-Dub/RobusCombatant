#include "Losange.h"

void faireLosange() {
    float distance = 10.0; 

    // Suit la ligne 

    // tourne pour sortir de la ligne 
    Movement::turnLeft(135);
    Movement::moveForward(distance);
    
    Movement::turnLeft(45);
    Movement::moveForward(distance);
    
    Movement::turnLeft(45);
    Movement::moveForward(distance);
    
    Movement::turnLeft(45);
    Movement::moveForward(distance);
}
