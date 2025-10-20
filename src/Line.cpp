#include "Line.h"
#include <Arduino.h>

unsigned char ucStation = NONE;  // CURRENT STATION, MIGHT BECOME A GLOBAL VARIABLE WHEN WE CODE COLOR DETECTION

void vsetupLineSensors(){
    pinMode(LEFT_SENSOR_PIN, INPUT);
    pinMode(MIDDLE_SENSOR_PIN, INPUT);
    pinMode(RIGHT_SENSOR_PIN, INPUT);
}

unsigned char ucReadLineSensors(){
    bool bLeftSensor = false;
    bool bMiddleSensor = false; 
    bool bRightSensor = false;

    int iLeftSensorValue = analogRead(LEFT_SENSOR_PIN);
    int iMiddleSensorValue = analogRead(MIDDLE_SENSOR_PIN);
    int iRightSensorValue = analogRead(RIGHT_SENSOR_PIN);

    if (iLeftSensorValue < WHITE_THRESHOLD) { bLeftSensor = true;}
    if (iMiddleSensorValue < WHITE_THRESHOLD) { bMiddleSensor = true;}
    if (iRightSensorValue < WHITE_THRESHOLD) { bRightSensor = true;}

    unsigned char ucSensorState = ((bLeftSensor << 2) | (bMiddleSensor << 1) | bRightSensor);
    return ucSensorState;
}

void vDecisionTime(unsigned char ucSensorState){
    switch (ucSensorState) {
        case 0b000:
            Serial.println("No line detected");
            if (ucStation == WALL_DODGE) {/* WALL DODGING BEHAVIOR */}
            if (ucStation == NONE) {/* LOST THE LINE, SWEEPING TO FIND IT AGAIN */ }
            break; 
        case 0b001:
            Serial.println("Right sensor on line");
            //TURN RIGHT A LOT
            break;
        case 0b010:
            Serial.println("Middle sensor on line");
            //GO STRAIGHT
            break;
        case 0b011:
            Serial.println("Middle and Right sensor on line");
            //TURN RIGHT A LITTLE
            break;
        case 0b100:
            Serial.println("Left sensor on line");
            //TURN LEFT A LOT
            break;
        case 0b101:
            Serial.println("Left and Right sensor on line");
            //IDK THATS FUCKED UP G, GO STRAIGHT I GUESS
            break;
        case 0b110:
            Serial.println("Left and Middle sensor on line");
            //TURN LEFT A LITTLE
            break;
        case 0b111:
            Serial.println("All sensors on line");
            //GO STRAIGHT
            break;
        default:
            Serial.println("Error: 0_0 au secours!");
            break;
    }
}