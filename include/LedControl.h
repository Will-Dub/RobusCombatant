#pragma once

//permet l'appel des fonctions pour contrôler les DELs
//inclure ce fichier lorsque vous voulez contrôler les DELs
void LEDInit();
void yLedOn();
void yLedOff();
void rLedOn();
void rLedOff();
void gLedOn();
void gLedOff();
void bLedOn();
void bLedOff();
void flashYR(int length);
void flashYG(int length);
void flashYB(int length);
void flashRG(int length);
void flashRB(int length);
void flashGB(int length);
void randomLed(int length);