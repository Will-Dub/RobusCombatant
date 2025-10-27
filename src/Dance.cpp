#include <Arduino.h>
#include <LibRobus.h>
#include "Dance.h"
#include "WheelPID.h"
#include "Movement.h"
#include "ArmControl.h"
#include "LedControl.h"

//fichier contenant la dance et les mouvements du robot dans l'ordre

//temps de délais secondes à millisecondes.
int delayS(float secs){
    int msecs = secs * 1000;
    return msecs;
}

//!!!!MAKE SURE THE DELAYS IN THE BLINKING LED CODE DOESN'T COUNT AS DELAYS BEFORE THE NEXT MOVE, 
//SO IT DOESN'T DOUBLE HOW LONG IT TAKES BEFORE DOING THE NEXT MOVE (probably does actually, 
//same way delayS works). But easy fix if yes.

void dance()
{

    //Mouvement 1
    bothArmDown();
    Serial.println("move 1");
    delay(delayS(4.7));   //adust the time here, depending on how long the robot takes to bootup so it syncs with the dance.

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
    rightArmDown();
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
    randomLed();
    bothArmUp();
    Movement::turnRight(360,1600,6600);
    //randomLed(4);
    //delay(delayS(4));
    allOff();

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
    randomLed();
    bothArmFront();
    Movement::turnLeft(360,1600,6600);
    //randomLed(4);
    //delay(delayS(4));
    allOff();

    //=================seuil de succès==================
    //Mouvement 20
    bothArmDown();
    //Movement::turnLeft(180,1600,6600);
    Movement::moveForward(20,1600,6800);
    /*move to position 1*/
    //delay(delayS(4));
    
    //Mouvement 21
    Movement::turnLeft(135,1600,6600);
    Movement::moveForward(28.28,1600,6800);
    /*move to position 2*/
    //delay(delayS(4));
    
    //Mouvement 22
    Movement::turnLeft(90,1600,6600);
    Movement::moveForward(28.28,1600,6800);
    /*move to position 3*/
    //delay(delayS(4));

    //Mouvement 23
    Movement::turnLeft(90,1600,6600);
    Movement::moveForward(28.28,1600,6800);
    /*move to position 4*/
    delay(delayS(4));

//=================seuil de test=============

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
    allOn();
    delay(delayS(4));
    allOff();
    
    //Mouvement 35
    randomLed();
    Movement::turnRight(720);
    //randomLed(4);
    delay(delayS(4));
    allOff();

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
    randomLed();
    Movement::turnLeft(135);
    Movement::moveForward(20);
    /*move to position 0*/
    //randomLed(4);
    delay(delayS(4));
    allOff();
    
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
    randomLed();
    bothArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    //randomLed(2);
    delay(delayS(2));
    allOff();

    //Mouvement 51
    randomLed();
    rightArmFront();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    //randomLed(2);
    delay(delayS(2));
    allOff();
    
    //Mouvement 52
    randomLed();
    bothArmFront();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    //randomLed(2);
    delay(delayS(2));
    allOff();

    
    //Mouvement 53
    randomLed();
    rightArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    //randomLed(3);
    delay(delayS(3));
    allOff();


    //Mouvement 54
    randomLed();
    bothArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    Movement::turnRight(360);
    //randomLed(3);
    delay(delayS(3));
    allOff();


    //Mouvement 55
    randomLed();
    rightArmFront();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    //randomLed(3);
    delay(delayS(3));
    allOff();


    //Mouvement 56
    randomLed();
     bothArmFront();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    //randomLed(3);
    delay(delayS(3));
    allOff();

    
    //Mouvement 57
    randomLed();
    rightArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    //randomLed(2);
    delay(delayS(2));
    allOff();

    
    //Mouvement 58
    randomLed();
    bothArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    Movement::turnRight(360);
    //randomLed(3);
    delay(delayS(3));
    allOff();


    //Mouvement 59
    randomLed();
    rightArmFront();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/    
    //randomLed(2);
    delay(delayS(2));
    allOff();


    //Mouvement 60
    randomLed();
    bothArmFront();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    //randomLed(3);
    delay(delayS(3));
    allOff();


    //Mouvement 61
    randomLed();
    rightArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    //randomLed(2);
    delay(delayS(2));
    allOff();

    
    //Mouvement 62
    randomLed();
    bothArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    Movement::turnRight(360);
    //randomLed(3);
    delay(delayS(3));
    allOff();


    //Mouvement 63
    randomLed();
    rightArmFront();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 2*/
    //randomLed(2);
    delay(delayS(2));
    allOff();


    //Mouvement 64
    randomLed();
    bothArmFront();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 3*/
    Movement::turnRight(360);
    //randomLed(3);
    delay(delayS(3));
    allOff();


    //Mouvement 65
    randomLed();
    rightArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 4*/
    //randomLed(2);
    delay(delayS(2));
    allOff();

    
    //Mouvement 66
    randomLed();
    bothArmUp();
    Movement::turnLeft(90);
    Movement::moveForward(28.28);
    /*move to position 1*/
    Movement::turnRight(360);
    //randomLed(3);
    delay(delayS(3));
    allOff();

    
    //Mouvement 67
    randomLed();
    Movement::turnLeft(135);
    Movement::moveForward(20);
    /*move to position 0*/
    //randomLed(2);
    delay(delayS(2));
    allOff();

    
    //Mouvement 68
    randomLed();
    Movement::turnRight(1080);
    //randomLed(2);
    delay(delayS(2));
    allOff();


    //Mouvement 69
    //FIN ICI!!!
    armsOFF();

}