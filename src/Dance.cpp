#include <Arduino.h>
#include <LibRobus.h>
#include "Dance.h"
#include "ArmControl.h"
#include "LedControl.h"

//fichier contenant la dance et les mouvements du robot dans l'ordre

//temps de délais secondes à microsecondes.
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
    /*360 sens horaire!!*/
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
    /*move to position 1*/ //attention puisque bouger prends du temps. Ajouter un timer pour le temps pendant qu'il y a
    /*360 sens anti-horaire*/  //incertain de l'ordre de ces deux mouvements
    bothArmFront();
    randomLed(4);

    //Mouvement 20
    bothArmDown();
    delay(delayS(4));
    
    //Mouvement 21
    /*move to position 2*/
    delay(delayS(4));
    
    //Mouvement 22
    /*move to position 3*/
    delay(delayS(4));

    //Mouvement 23
    /*move to position 4*/
    delay(delayS(4));

    //Mouvement 24
    /*move to position 1*/
    delay(delayS(4));

    //Mouvement 25
    /*move to position 2*/
    delay(delayS(4));
    
    //Mouvement 26
    /*move to position 3*/
    delay(delayS(4));

    //Mouvement 27
    /*move to position 4*/
    delay(delayS(4));
    
    //Mouvement 28
    /*move to position 0*/
    delay(delayS(4));
    
    //Mouvement 29
    /*Échange de carré*/
    delay(delayS(8));

    //Mouvement 30
    /*move to position 1*/
    rLedOn();
    delay(delayS(4));
    rLedOff();

    //Mouvement 31
    /*move to position 2*/
    yLedOn();
    delay(delayS(4));
    yLedOff();
    
    //Mouvement 32
    /*move to position 3*/
    gLedOn();
    delay(delayS(4));
    gLedOff();
    
    //Mouvement 33
    /*move to position 4*/
    bLedOn();
    delay(delayS(4));
    bLedOff();
    
    //Mouvement 34
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
    /*720 sens horaire*/
    randomLed(4);

    //Mouvement 36
    /*Échange de carré*/
    delay(delayS(8));
    
    //Mouvement 37
    /*move to position 1*/
    rLedOn();
    delay(delayS(4));
    rLedOff();
    
    //Mouvement 38
    /*move to position 2*/
    yLedOn();
    delay(delayS(4));
    yLedOff();

    //Mouvement 39
    /*move to position 3*/
    gLedOn();
    delay(delayS(4));
    gLedOff();

    //Mouvement 40
    /*move to position 4*/
    bLedOn();
    delay(delayS(4));
    bLedOff();

    //Mouvement 41
    /*move to position 0*/
    randomLed(4);
    
    //Mouvement 42
    /*move to position 1*/
    bothArmFront();
    rLedOn();
    delay(delayS(4));
    rLedOff();
    
    //Mouvement 43
    /*move to position 2*/
    bothArmUp();
    yLedOn();
    delay(delayS(4));
    yLedOff();
    
    //Mouvement 44
    /*move to position 3*/
    bothArmDown();
    gLedOn();
    delay(delayS(4));
    gLedOff();

    //Mouvement 45
    /*move to position 4*/
    bothArmFront();
    bLedOn();
    delay(delayS(4));
    bLedOff();
    
    //Mouvement 46
    /*move to position 1*/
    bothArmUp();
    delay(delayS(4));
    
    //Mouvement 47
    /*move to position 2*/
    rightArmFront();
    delay(delayS(4));
    
    //Mouvement 48
    /*move to position 3*/
    leftArmFront();
    delay(delayS(4));
    
    //Mouvement 49
    /*move to position 4*/
    rightArmUp();
    delay(delayS(4));

    //movements after this were documented by Samue; in the excel

    //Mouvement 50
    /*move to position 1*/
    bothArmUp();
    randomLed(2);

    //Mouvement 51
    /*move to position 2*/
    rightArmFront();
    randomLed(2);
    
    //Mouvement 52
    /*move to position 3*/
    bothArmFront();
    randomLed(2);
    
    //Mouvement 53
    /*move to position 4*/
    rightArmUp();
    randomLed(3);

    //Mouvement 54
    /*move to position 1*/
    /*do a 360*/
    bothArmUp();
    randomLed(3);

    //Mouvement 55
    /*move to position 2*/
    rightArmFront();
    randomLed(3);

    //Mouvement 56
    /*move to position 3*/
    bothArmFront();
    randomLed(3);
    
    //Mouvement 57
    /*move to position 4*/
    rightArmUp();
    randomLed(2);
    
    //Mouvement 58
    /*move to position 1*/
    /*do a 360*/
    bothArmUp();
    randomLed(3);

    //Mouvement 59
    /*move to position 2*/
    rightArmFront();
    randomLed(2);

    //Mouvement 60
    /*move to position 3*/
    bothArmFront();
    randomLed(3);

    //Mouvement 61
    /*move to position 4*/
    rightArmUp();
    randomLed(2);
    
    //Mouvement 62
    /*move to position 1*/
    /*do a 360*/
    bothArmUp();
    randomLed(3);

    //Mouvement 63
    /*move to position 2*/
    rightArmFront();
    randomLed(2);

    //Mouvement 64
    /*move to position 3*/
    /*do a 360*/
    bothArmFront();
    randomLed(3);

    //Mouvement 65
    /*move to position 4*/
    rightArmUp();
    randomLed(2);
    
    //Mouvement 66
    /*move to position 1*/
    /*do a 360*/
    bothArmUp();
    randomLed(3);
    
    //Mouvement 67
    /*move to position 0*/
    randomLed(2);
    
    //Mouvement 68
    /*do a 1080*/
    randomLed(2);

    //Mouvement 69
    //FIN ICI!!!
    armsOFF();

}