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




void dance()
{
    
    int forwardMinSpeed = 2700;
    int forwardMaxSpeed = 7800;
    int turnMinSpeed = 1600;
    int turnMaxSpeed = 6600;

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
    Movement::turnRight(350,turnMinSpeed,turnMaxSpeed);
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
    Movement::turnLeft(350,turnMinSpeed,turnMaxSpeed);
    //randomLed(4);
    //delay(delayS(4));
    allOff();
    
    forwardMinSpeed = 2700;
    forwardMaxSpeed = 7800;
    turnMinSpeed = 2300;
    turnMaxSpeed = 7000;

    //Mouvement 20
    bothArmDown();
    //Movement::turnLeft(180,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(20,forwardMinSpeed,forwardMaxSpeed);
    //move to position 1
    //delay(delayS(4));
    
    //Mouvement 21
    Movement::turnLeft(135,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    //move to position 2
    //delay(delayS(4));
    
    //Mouvement 22
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    //move to position 3
    //delay(delayS(4));

    //Mouvement 23
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    //move to position 4
    //delay(delayS(4));

    //Mouvement 24
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    //move to position 1
    //delay(delayS(4));

    //Mouvement 25
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    //move to position 2
    //delay(delayS(4));
    
    //Mouvement 26
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    //move to position 3
    //delay(delayS(4));

    //Mouvement 27
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    //move to position 4
    //delay(delayS(4));
    
    //Mouvement 28 
    Movement::turnLeft(135,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(20,forwardMinSpeed,forwardMaxSpeed);
    //move to position 0
    //delay(delayS(4));
    
    forwardMinSpeed = 3500;
    forwardMaxSpeed = 8200;
    turnMinSpeed = 3300;
    turnMaxSpeed = 7400;
    
    //Mouvement 29
    Movement::turnRight(135,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    Movement::turnRight(38,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(30,forwardMinSpeed,forwardMaxSpeed); //CHANGE THIS FOR FINAL DANCE
    //Movement::moveForward(40);
    //Movement::turnRight(135,turnMinSpeed,turnMaxSpeed);
    /*Échange de carré*/
    //delay(delayS(8));

    //make an adjustment here to recalibrate robot's position in the middle.

    forwardMinSpeed = 2700;
    forwardMaxSpeed = 7800;
    turnMinSpeed = 2300;
    turnMaxSpeed = 7000;

    
    //Mouvement 30
    delay(delayS(1));
    rLedOn();
    delay(delayS(2.5));
    //Movement::moveForward(25,3000,forwardMaxSpeed);
    /*move to position 1*/
    //delay(delayS(4));
    
    //Mouvement 31
    Movement::turnRight(135,turnMinSpeed,turnMaxSpeed);
    rLedOff();
    yLedOn();
    Movement::moveForward(27,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    //delay(delayS(4));
    

    //Mouvement 32
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    yLedOff();
    gLedOn();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    //delay(delayS(4));
    
    
    //Mouvement 33
    Movement::turnLeft(100,turnMinSpeed,turnMaxSpeed);
    gLedOff();
    bLedOn();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //delay(delayS(4));
    bLedOff();
    
    forwardMinSpeed = 3200;
    forwardMaxSpeed = 8400;
    turnMinSpeed = 2800;
    turnMaxSpeed = 7600;

    //Mouvement 34
    allOn();
    Movement::turnLeft(135,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(20,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 0*/
    //delay(delayS(4));
    delay(delayS(0.8));
    allOff();

    //quick test zone

    turnMinSpeed = 4400;
    turnMaxSpeed = 9200;
    
    //Mouvement 35
    randomLed();
    Movement::turnRight(690,turnMinSpeed,turnMaxSpeed);
    //randomLed(4);
    //delay(delayS(4));
    allOff();

    //end of quick test zone

    forwardMinSpeed = 3500;
    forwardMaxSpeed = 8200;
    turnMinSpeed = 3300;
    turnMaxSpeed = 7400;

    //Mouvement 36
    Movement::turnLeft(45,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    Movement::turnRight(45,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(10,forwardMinSpeed,forwardMaxSpeed); //fix this for final dance
    Movement::turnRight(45,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*Échange de carré*/
    //delay(delayS(8));


    //Mouvement 37
    rLedOn();
    Movement::turnRight(48,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(20,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    
    //delay(delayS(4));
    rLedOff();
    
    //Mouvement 38
    yLedOn();
    Movement::turnLeft(135,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    //delay(delayS(4));
    yLedOff();

    //Mouvement 39
    gLedOn();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    //delay(delayS(4));
    gLedOff();

    //Mouvement 40
    bLedOn();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //delay(delayS(4));
    bLedOff();

    //Mouvement 41
    randomLed();
    Movement::turnLeft(135,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(22,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 0*/
    //randomLed(4);
    //delay(delayS(4));
    allOff();
    
    //Mouvement 42
    rLedOn();
    bothArmFront();
    Movement::turnRight(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(20,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    //delay(delayS(4));
    rLedOff(); 
    
    //Mouvement 43
    yLedOn();
    bothArmUp();
    Movement::turnLeft(135,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    //delay(delayS(4));
    delay(delayS(1));
    yLedOff();
    
    //Mouvement 44
    gLedOn();
    bothArmDown();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    //delay(delayS(4));
    delay(delayS(1));
    gLedOff();

    //Mouvement 45
    bLedOn();
    bothArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //delay(delayS(4));
    delay(delayS(1));
    bLedOff();
    
    //Mouvement 46
    bothArmUp();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    delay(delayS(1));
    //delay(delayS(4));
    
    //Mouvement 47
    rightArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    delay(delayS(1));
    //delay(delayS(4));
    
    //Mouvement 48
    leftArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    delay(delayS(1));
    //delay(delayS(4));
    
    //Mouvement 49
    rightArmUp();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //delay(delayS(4));

//=================seuil de succès================== 

    forwardMinSpeed = 6000;
    forwardMaxSpeed = 11000;
    turnMinSpeed = 5500;
    turnMaxSpeed = 10300;

    //movements after this were documented by Samuel in the excel

    //Mouvement 50
    randomLed();
    bothArmUp();
    Movement::turnLeft(96,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();

    //Mouvement 51
    randomLed();
    rightArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();
    
    //Mouvement 52
    randomLed();
    bothArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();

    
    //Mouvement 53
    randomLed();
    rightArmUp();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //randomLed(3);
    //delay(delayS(3));
    allOff();

    //================= seuil de test ==================


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