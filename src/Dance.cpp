#include <Arduino.h>
#include <LibRobus.h>
#include "Dance.h"
#include "WheelPID.h"
#include "Movement.h"
#include "ArmControl.h"
#include "LedControl.h"

//fichier contenant la dance et les mouvements du robot dans l'ordre

//temps de délais secondes à millisecondes.
int delayS(int secs){
    int msecs = secs * 1000;
    return msecs;
}

//!!!!MAKE SURE THE DELAYS IN THE BLINKING LED CODE DOESN'T COUNT AS DELAYS BEFORE THE NEXT MOVE, 
//SO IT DOESN'T DOUBLE HOW LONG IT TAKES BEFORE DOING THE NEXT MOVE (probably does actually, 
//same way delayS works). But easy fix if yes.

void dance(){
    //Mouvement 1
    bothArmDown();
    Serial.println("move 1");
    delay(delayS(3));   //adust the time here, depending on how long the robot takes to bootup so it syncs with the dance.

    
    //Mouvement 2
    leftArmUp();
    Serial.println("move 2");
    delay(delayS(2));

    //Mouvement 3
    rightArmUp();
    Serial.println("move 3");
    delay(delayS(2));

    //Mouvement 4
    leftArmDown();
    Serial.println("move 4");
    delay(delayS(2));

    //Mouvement 5
    delay(delayS(22));

    //Mouvement 6
    rLedOn();
    delay(delayS(2));
    rLedOff();

    //Mouvement 7
    yLedOn();
    delay(delayS(2));
    yLedOff();

    //Mouvement 8
    gLedOn();
    delay(delayS(2));
    gLedOff();

    //Mouvement 9
    bLedOn();
    delay(delayS(2));
    bLedOff();

    //Mouvement 10
    rLedOn();
    bothArmFront();
    delay(delayS(2));
    rLedOff();

    //Mouvement 11
    yLedOn();
    bothArmUp();
    delay(delayS(2));
    yLedOff();

    //Mouvement 12
    gLedOn();
    bothArmFront();
    delay(delayS(2));
    gLedOff();

    //Mouvement 13
    bLedOn();
    bothArmDown();
    delay(delayS(2));
    bLedOff();

    //Mouvement 14
    Movement::turnRight(360);
    bothArmUp();
    randomLed(4);

    //Mouvement 15
    bothArmDown();
    flashYR(2);

    //Mouvement 16
    flashYG(2);
    
    //Mouvement 17
    flashGB(2);
    
    //Mouvement 18
    flashRB(2);
    
    //Mouvement 19
    Movement::turnLeft(180);
    Movement::moveForward(20); //attention puisque bouger prends du temps. Ajouter un timer pour le temps pendant qu'il y a
    Movement::turnLeft(360);  //incertain de l'ordre de ces deux mouvements
    /*move to position 1*/
    bothArmFront();
    randomLed(4);

    //Mouvement 20
    bothArmDown();
    delay(delayS(4));
    
    //Mouvement 21
    Movement::turnLeft(135);
    Movement::moveForward(28.28);
    /*move to position 2*/
    delay(delayS(4));
    
    //Mouvement 22
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    delay(delayS(4));

    //Mouvement 23
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    delay(delayS(4));

    //Mouvement 24
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    delay(delayS(4));

    //Mouvement 25
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    delay(delayS(4));
    
    //Mouvement 26
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    delay(delayS(4));

    //Mouvement 27
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    delay(delayS(4));
    
    //Mouvement 28 
    Movement::turnLeft(135);
    Movement::moveForward(20);
    /*move to position 0*/
    delay(delayS(4));
    
    //Mouvement 29
    Movement::turnRight(135);
    Movement::moveForward(28.28);
    Movement::turnRight(45);
    Movement::moveForward(40);
    Movement::turnRight(45);
    Movement::moveForward(28.28);
    /*Échange de carré*/
    delay(delayS(8));

    //Mouvement 30
    Movement::turnLeft(135);
    Movement::moveForward(20);
    /*move to position 1*/
    rLedOn();
    delay(delayS(4));
    rLedOff();

    //Mouvement 31
    Movement::turnLeft(135);
    Movement::moveForward(28.28);
    /*move to position 2*/
    yLedOn();
    delay(delayS(4));
    yLedOff();
    
    //Mouvement 32
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    gLedOn();
    delay(delayS(4));
    gLedOff();
    
    //Mouvement 33
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    bLedOn();
    delay(delayS(4));
    bLedOff();
    
    //Mouvement 34
    Movement::turnLeft(135);
    Movement::moveForward(20);
    /*move to position 0*/
    yLedOn();
    rLedOn();
    gLedOn();
    bLedOn();
    delay(delayS(4));
    yLedOff();
    rLedOff();
    gLedOff();
    bLedOff();
    
    //Mouvement 35
    Movement::turnRight(720);
    randomLed(4);

    //Mouvement 36
    Movement::turnLeft(45);
    Movement::moveForward(28.28);
    Movement::turnRight(45);
    Movement::moveForward(40);
    Movement::turnRight(45);
    Movement::moveForward(28.28);
    /*Échange de carré*/
    delay(delayS(8));
    
    //Mouvement 37
    Movement::turnRight(45);
    Movement::moveForward(20);
    /*move to position 1*/
    rLedOn();
    delay(delayS(4));
    rLedOff();
    
    //Mouvement 38
    Movement::turnLeft(135);
    Movement::moveForward(28.28);
    /*move to position 2*/
    yLedOn();
    delay(delayS(4));
    yLedOff();

    //Mouvement 39
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    gLedOn();
    delay(delayS(4));
    gLedOff();

    //Mouvement 40
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    bLedOn();
    delay(delayS(4));
    bLedOff();

    //Mouvement 41
    Movement::turnLeft(135);
    Movement::moveForward(20);
    /*move to position 0*/
    randomLed(4);
    
    //Mouvement 42
    Movement::turnRight(90);
    Movement::moveForward(20);
    /*move to position 1*/
    bothArmFront();
    rLedOn();
    delay(delayS(4));
    rLedOff();
    
    //Mouvement 43
    Movement::turnLeft(135);
    Movement::moveForward(28.28);
    /*move to position 2*/
    bothArmUp();
    yLedOn();
    delay(delayS(4));
    yLedOff();
    
    //Mouvement 44
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    bothArmDown();
    gLedOn();
    delay(delayS(4));
    gLedOff();

    //Mouvement 45
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    bothArmFront();
    bLedOn();
    delay(delayS(4));
    bLedOff();
    
    //Mouvement 46
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    bothArmUp();
    delay(delayS(4));
    
    //Mouvement 47
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    rightArmFront();
    delay(delayS(4));
    
    //Mouvement 48
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    leftArmFront();
    delay(delayS(4));
    
    //Mouvement 49
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    rightArmUp();
    delay(delayS(4));

    //movements after this were documented by Samuel in the excel

    //Mouvement 50
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    bothArmUp();
    randomLed(2);

    //Mouvement 51
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    rightArmFront();
    randomLed(2);
    
    //Mouvement 52
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    bothArmFront();
    randomLed(2);
    
    //Mouvement 53
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    rightArmUp();
    randomLed(3);

    //Mouvement 54
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    Movement::turnRight(360);
    bothArmUp();
    randomLed(3);

    //Mouvement 55
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    rightArmFront();
    randomLed(3);

    //Mouvement 56
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    bothArmFront();
    randomLed(3);
    
    //Mouvement 57
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    rightArmUp();
    randomLed(2);
    
    //Mouvement 58
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    Movement::turnRight(360);
    bothArmUp();
    randomLed(3);

    //Mouvement 59
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    rightArmFront();
    randomLed(2);

    //Mouvement 60
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    bothArmFront();
    randomLed(3);

    //Mouvement 61
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    rightArmUp();
    randomLed(2);
    
    //Mouvement 62
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    Movement::turnRight(360);
    bothArmUp();
    randomLed(3);

    //Mouvement 63
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    rightArmFront();
    randomLed(2);

    //Mouvement 64
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    Movement::turnRight(360);
    bothArmFront();
    randomLed(3);

    //Mouvement 65
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    rightArmUp();
    randomLed(2);
    
    //Mouvement 66
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    Movement::turnRight(360);
    bothArmUp();
    randomLed(3);
    
    //Mouvement 67
    Movement::turnLeft(135);
    Movement::moveForward(20);
    /*move to position 0*/
    randomLed(2);
    
    //Mouvement 68
    Movement::turnRight(1080);
    randomLed(2);

    //Mouvement 69
    //FIN ICI!!!
    armsOFF();

}