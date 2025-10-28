#include <Arduino.h>
#include <LibRobus.h>
#include <stdlib.h>
#include "LedControl.h"

//fichier qui contrôle les LED de couleurs pour la dance

//choisi les sorties digitales associés à chaque LED !!!!!!!!!(changer lorsqu'on aura choisit quelles pin utiliser pour les DELs)
const int YLED = 47;
const int RLED = 49;
const int GLED = 48;
const int BLED = 46;

//ADJUST DELAYS FOR THE FUTURE!!!! -> should be fine now
const int flashDelay = 250; //durée d'un flash

//initialise les DELs
void LEDInit(){
pinMode(YLED,OUTPUT);
pinMode(RLED,OUTPUT);
pinMode(GLED,OUTPUT);
pinMode(BLED,OUTPUT);
}

//fonctions qui allument ou éteignent chaque DEL

//allume DEL Jaune
void yLedOn(){
    digitalWrite(YLED,HIGH);
}

//éteint DEL Jaune
void yLedOff(){
    digitalWrite(YLED,LOW);
}

//allume DEL Rouge
void rLedOn(){
    digitalWrite(RLED,HIGH);
}

//éteint DEL Rouge
void rLedOff(){
    digitalWrite(RLED,LOW);
}

//allume DEL Verte
void gLedOn(){
    digitalWrite(GLED,HIGH);
}

//éteint DEL Verte
void gLedOff(){
    digitalWrite(GLED,LOW);
}
//allume DEL Bleue
void bLedOn(){
    digitalWrite(BLED,HIGH);
}

//éteint DEL Bleue
void bLedOff(){
    digitalWrite(BLED,LOW);
}

/************************* 
    PLUS BAS EST SEULEMENT POUR LA DANCE!!
    POUR LE SUIVEUR DE LIGNES, LES FONCTIONS PLUS HAUT SONT UTILES.
 *************************/




//fait alterner DEL Jaune et Rouge
void flashYR(int length){
    int count = 0;
    int counterMax = length * 2;
    while(count < counterMax)  
    {
        digitalWrite(YLED,HIGH);
        digitalWrite(RLED,LOW);
        delay(flashDelay);
        digitalWrite(YLED,LOW);
        digitalWrite(RLED,HIGH);
        delay(flashDelay);
        count++;
    }
    digitalWrite(RLED,LOW);
}

//fait alterner DEL Jaune et Verte
void flashYG(int length){
    int count = 0;
    int counterMax = length * 2;
    while(count < counterMax)  
    {
        digitalWrite(YLED,HIGH);
        digitalWrite(GLED,LOW);
        delay(flashDelay);
        digitalWrite(YLED,LOW);
        digitalWrite(GLED,HIGH);
        delay(flashDelay);
        count++;
    }
    digitalWrite(GLED,LOW);
}

//fait alterner DEL Jaune et Bleue
void flashYB(int length){
    int count = 0;
    int counterMax = length * 2;
    while(count < counterMax)  
    {
        digitalWrite(YLED,HIGH);
        digitalWrite(BLED,LOW);
        delay(flashDelay);
        digitalWrite(YLED,LOW);
        digitalWrite(BLED,HIGH);
        delay(flashDelay);
        count++;
    }
    digitalWrite(BLED,LOW);
}

//fait alterner DEL Rouge et Verte
void flashRG(int length){
    int count = 0;
    int counterMax = length * 2;
    while(count < counterMax)  
    {
        digitalWrite(RLED,HIGH);
        digitalWrite(GLED,LOW);
        delay(flashDelay);
        digitalWrite(RLED,LOW);
        digitalWrite(GLED,HIGH);
        delay(flashDelay);
        count++;
    }
    digitalWrite(GLED,LOW);
}

//fait alterner DEL Rouge et Bleue
void flashRB(int length){
    int count = 0;
    int counterMax = length * 2;
    while(count < counterMax)  
    {
        digitalWrite(RLED,HIGH);
        digitalWrite(BLED,LOW);
        delay(flashDelay);
        digitalWrite(RLED,LOW);
        digitalWrite(BLED,HIGH);
        delay(flashDelay);
        count++;
    }
    digitalWrite(GLED,LOW);
}

//fait alterner DEL Verte et Bleue
void flashGB(int length){
    int count = 0;
    int counterMax = length * 2;
    while(count < counterMax)  
    {
        digitalWrite(GLED,HIGH);
        digitalWrite(BLED,LOW);
        delay(flashDelay);
        digitalWrite(GLED,LOW);
        digitalWrite(BLED,HIGH);
        delay(flashDelay);
        count++;
    }
    digitalWrite(BLED,LOW);
}

//allume des lumières aléatoires
void randomLed(int length){
    int count = 0;
    int counterMax = length * 4;
    int ledChoice = 0;
    while(count < counterMax)
    {
        ledChoice = rand()%(3-0+1)+0;
        if(ledChoice == 0)
        {
            yLedOn();
            delay(flashDelay);
            yLedOff();
        }
        if(ledChoice == 1)
        {
            rLedOn();
            delay(flashDelay);
            rLedOff();
        }
        if(ledChoice == 2)
        {
            gLedOn();
            delay(flashDelay);
            gLedOff();
        }
        if(ledChoice == 3)
        {
            bLedOn();
            delay(flashDelay);
            bLedOff();
        }
        count++;
    }
}