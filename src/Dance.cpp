#include <Arduino.h>
#include <LibRobus.h>
#include "Dance.h"
#include "ArmControl.h"
#include "LedControl.h"

//fichier contenant la dance et les mouvements du robot dans l'ordre

//temps de délais secondes à millisecondes. //ajouter timer pour que les mouvements se fassent pendant le délai.
void delayS(int secs){
    int msecs = secs * 1000;
    delay(msecs);
}


void dance(){
    //Mouvement 1
    bothArmDown();
    delayS(3);

    //Mouvement 2
    leftArmUp();
    delayS(2);

    //Mouvement 3
    rightArmUp();
    delayS(2);

    //Mouvement 4
    leftArmDown();
    delayS(2);

    //Mouvement 5
    delayS(22);

    //Mouvement 6
    rLedOn();
    delayS(2);
    rLedOff();

    //Mouvement 7
    yLedOn();
    delayS(2);
    yLedOff();

    //Mouvement 8
    gLedOn();
    delayS(2);
    gLedOff();

    //Mouvement 9
    bLedOn();
    delayS(2);
    bLedOff();

    //Mouvement 10
    rLedOn();
    bothArmFront();
    delayS(2);
    rLedOff();

    //Mouvement 11
    yLedOn();
    bothArmUp();
    delayS(2);
    yLedOff();

    //Mouvement 12
    gLedOn();
    bothArmFront();
    delayS(2);
    gLedOff();

    //Mouvement 13
    bLedOn();
    bothArmDown();
    delayS(2);
    bLedOff();

    //Mouvement 14
    /*360 sens horaire!!*/
    bothArmUp();
    randomLed(4);
    delayS(4);  //potential issue here, depending on if it'll wait for the random lights to be done before doing the delayS function (probably fine) 

    //Mouvement 15
    bothArmDown();
    flashYR(2);
    delayS(2);

    //Mouvement 16
    flashYG(2);
    delayS(2);
    
    //Mouvement 17
    flashGB(2);
    delayS(2);
    
    //Mouvement 18
    flashRB(2);
    delayS(2);
    
    //Mouvement 19
    /*move to position 1*/ //attention puisque bouger prends du temps. Ajouter un timer pour le temps pendant qu'il y a
    /*360 sens anti-horaire*/  //incertain de l'ordre de ces deux mouvements
    bothArmFront();
    randomLed(4);
    delayS(4);

    //Mouvement 20
    bothArmDown();
    delayS(4);
    
    //Mouvement 21
    /*move to position 2*/
    delayS(4);
    
    //Mouvement 22
    /*move to position 3*/
    delayS(4);

    //Mouvement 23
    /*move to position 4*/
    delayS(4);

    //Mouvement 24
    /*move to position 1*/
    delayS(4);

    //Mouvement 25
    /*move to position 2*/
    delayS(4);
    
    //Mouvement 26
    /*move to position 3*/
    delayS(4);

    //Mouvement 27
    /*move to position 4*/
    delayS(4);
    
    //Mouvement 28
    /*move to position 0*/
    delayS(4);
    
    //Mouvement 29
    /*Échange de carré*/
    delayS(8);

    //Mouvement 30
    /*move to position 1*/
    rLedOn();
    delayS(4);
    rLedOff();

    //Mouvement 31
    /*move to position 2*/
    yLedOn();
    delayS(4);
    yLedOff();
    
    //Mouvement 32
    /*move to position 3*/
    gLedOn();
    delayS(4);
    gLedOff();
    
    //Mouvement 33
    /*move to position 4*/
    bLedOn();
    delayS(4);
    bLedOff();
    
    //Mouvement 34
    /*move to position 0*/
    yLedOn();
    rLedOn();
    gLedOn();
    bLedOn();
    delayS(4);
    yLedOff();
    rLedOff();
    gLedOff();
    bLedOff();
    
    //Mouvement 35
    /*720 sens horaire*/
    randomLed(4);
    delayS(4);

    //Mouvement 36
    /*Échange de carré*/
    delayS(8);
    
    //Mouvement 37
    /*move to position 1*/
    rLedOn();
    delayS(4);
    rLedOff();
    
    //Mouvement 38
    /*move to position 2*/
    yLedOn();
    delayS(4);
    yLedOff();

    //Mouvement 39
    /*move to position 3*/
    gLedOn();
    delayS(4);
    gLedOff();

    //Mouvement 40
    /*move to position 4*/
    bLedOn();
    delayS(4);
    bLedOff();

    //Mouvement 41
    /*move to position 0*/
    randomLed(4);
    delayS(4);
    
    //Mouvement 42
    /*move to position 1*/
    bothArmFront();
    rLedOn();
    delayS(4);
    rLedOff();
    
    //Mouvement 43
    /*move to position 2*/
    bothArmUp();
    yLedOn();
    delayS(4);
    yLedOff();
    
    //Mouvement 44
    /*move to position 3*/
    bothArmDown();
    gLedOn();
    delayS(4);
    gLedOff();

    //Mouvement 45
    /*move to position 4*/
    bothArmFront();
    bLedOn();
    delayS(4);
    bLedOff();
    
    //Mouvement 46
    /*move to position 1*/
    bothArmUp();
    delayS(4);
    
    //Mouvement 47
    rightArmFront();
    delayS(4);
    
    //Mouvement 48
    leftArmFront();
    delayS(4);
    
    //Mouvement 49
    rightArmUp();
    delayS(4);

    //movements after this are not yet documented by Laurent in the excel



    //Mouvement 50


    //Mouvement 51
    
    //Mouvement 52
    
    //Mouvement 53
    
    //Mouvement 54

    //Mouvement 55
    
    //Mouvement 56
    
    //Mouvement 57
    
    //Mouvement 58
    
    //Mouvement 59

    //Mouvement 60

    //Mouvement 61
    
    //Mouvement 62
    
    //Mouvement 63
    
    //Mouvement 64

    //Mouvement 65
    
    //Mouvement 66
    
    //Mouvement 67
    
    //Mouvement 68
    
    //Mouvement 69

    //Mouvement 70

    //Mouvement 71
    
    //Mouvement 72
    
    //Mouvement 73
    
    //Mouvement 74

    //Mouvement 75
    
    //Mouvement 76
    
    //Mouvement 77
    
    //Mouvement 78
    
    //Mouvement 79

    //Mouvement 80

    //Mouvement 81
    
    //Mouvement 82
    
    //Mouvement 83
    
    //Mouvement 84

    //Mouvement 85
    
    //Mouvement 86
    
    //Mouvement 87
    
    //Mouvement 88
    
    //Mouvement 89
    
    //Mouvement 90

    //Mouvement 91
    
    //Mouvement 92
    
    //Mouvement 93
    
    //Mouvement 94

    //Mouvement 95
    
    //Mouvement 96
    
    //Mouvement 97
    
    //Mouvement 98
    
    //Mouvement 99

    //Mouvement 100

    //Mouvement 101
    
    //Mouvement 102
    
    //Mouvement 103
    
    //Mouvement 104

    //Mouvement 105
    
    //Mouvement 106
    
    //Mouvement 107
    
    //Mouvement 108
    
    //Mouvement 109

    //Mouvement 110

    //Mouvement 111
    
    //Mouvement 112
    
    //Mouvement 113
    
    //Mouvement 114

    //Mouvement 115
    
    //Mouvement 116
    
    //Mouvement 117
    
    //Mouvement 118
    
    //Mouvement 119

    //Mouvement 120

}