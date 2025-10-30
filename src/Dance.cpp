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
    Movement::moveForward(19.5,forwardMinSpeed,forwardMaxSpeed);
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
    delay(delayS(0.4));
    //move to position 3
    //delay(delayS(4));

    //Mouvement 27
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    //move to position 4
    //delay(delayS(4));
    
    //Mouvement 28 
    Movement::turnLeft(141,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(20,forwardMinSpeed,forwardMaxSpeed);
    //move to position 0
    //delay(delayS(4));
    
    forwardMinSpeed = 3500;
    forwardMaxSpeed = 8200;
    turnMinSpeed = 3300;
    turnMaxSpeed = 7400;
    
    //Mouvement 29
    delay(delayS(1.3));
    Movement::turnRight(130,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    Movement::turnRight(34,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(36,forwardMinSpeed,forwardMaxSpeed); //CHANGE THIS FOR FINAL DANCE
    //Movement::moveForward(40);
    //Movement::turnRight(135,turnMinSpeed,turnMaxSpeed);
    /*Échange de carré*/
    //delay(delayS(8));

    //make an adjustment here to recalibrate robot's position in the middle.

    forwardMinSpeed = 2300;
    forwardMaxSpeed = 7200;
    turnMinSpeed = 2000;
    turnMaxSpeed = 6600;

    
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
    delay(delayS(1));
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
    delay(delayS(1));
    allOff();

    turnMinSpeed = 4400;
    turnMaxSpeed = 9200;
    
    //Mouvement 35
    randomLed();
    Movement::turnRight(690,turnMinSpeed,turnMaxSpeed);
    //randomLed(4);
    //delay(delayS(4));
    allOff();

    forwardMinSpeed = 3200;
    forwardMaxSpeed = 8400;
    turnMinSpeed = 2800;
    turnMaxSpeed = 7600;

    //Mouvement 36
    Movement::turnLeft(45,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    Movement::turnRight(45,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(15,forwardMinSpeed,forwardMaxSpeed); //fix this for final dance
    Movement::turnRight(45,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(30,forwardMinSpeed,forwardMaxSpeed);
    /*Échange de carré*/
    //delay(delayS(8));


    //Mouvement 37
    rLedOn();
    Movement::turnRight(45,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(17,forwardMinSpeed,forwardMaxSpeed);
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
    delay(delayS(0.6));
    gLedOff();

    //Mouvement 40
    bLedOn();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //delay(delayS(4));
    delay(delayS(0.6));
    bLedOff();

    //Mouvement 41
    randomLed();
    Movement::turnLeft(140,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(22,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 0*/
    //randomLed(4);
    //delay(delayS(4));
    
    
    //Mouvement 42
    Movement::turnRight(90,turnMinSpeed,turnMaxSpeed);
    allOff();
    rLedOn();
    bothArmFront();
    Movement::moveForward(20,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    //delay(delayS(4));
    delay(delayS(0.6));
    
    
    //Mouvement 43
    Movement::turnLeft(135,turnMinSpeed,turnMaxSpeed);
    rLedOff(); 
    yLedOn();
    bothArmUp();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    //delay(delayS(4));
    delay(delayS(0.5));
    
    
    //Mouvement 44
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    yLedOff();
    gLedOn();
    bothArmDown();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    //delay(delayS(4));
    delay(delayS(1));
    gLedOff();

    //Mouvement 45
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    bLedOn();
    bothArmFront();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //delay(delayS(4));
    delay(delayS(1));
    
    //Mouvement 46
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    bLedOff();
    bothArmUp();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    delay(delayS(0.8));
    //delay(delayS(4));
    
    //Mouvement 47
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    rightArmFront();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    delay(delayS(0.8));
    //delay(delayS(4));
    
    //Mouvement 48
    Movement::turnLeft(93,turnMinSpeed,turnMaxSpeed);
    leftArmFront();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    delay(delayS(0.8));
    //delay(delayS(4));
    
    //Mouvement 49
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    rightArmUp();
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //delay(delayS(4));
    delay(delayS(0.8));

    forwardMinSpeed = 6000;
    forwardMaxSpeed = 11000;
    turnMinSpeed = 5500;
    turnMaxSpeed = 10300;

    //movements after this were documented by Samuel in the excel

    //Mouvement 50
    randomLed();
    bothArmUp();
    Movement::turnLeft(93,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(27.5,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();

    //Mouvement 51
    randomLed();
    rightArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(27.5,forwardMinSpeed,forwardMaxSpeed);
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
    
    //=================seuil de succès================== 


    //start of fast part

    forwardMinSpeed = 6200;
    forwardMaxSpeed = 11000;
    turnMinSpeed = 5800;
    turnMaxSpeed = 10800;
    
    //Mouvement 54
    randomLed();
    bothArmUp();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    turnMinSpeed = 6700;
    turnMaxSpeed = 12000;
    Movement::turnRight(360,turnMinSpeed,turnMaxSpeed);
    //randomLed(3);
    //delay(delayS(3));
    allOff();

    turnMinSpeed = 6000;
    turnMaxSpeed = 11000;

    //Mouvement 55
    randomLed();
    rightArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(27.5,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    //randomLed(3);
    //delay(delayS(3));
    allOff();


    //Mouvement 56
    randomLed();
    bothArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    //randomLed(3);
    //delay(delayS(3));
    allOff();

    
    //Mouvement 57
    randomLed();
    rightArmUp();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();

    forwardMinSpeed = 6600;
    forwardMaxSpeed = 11500;
    turnMinSpeed = 6000;
    turnMaxSpeed = 10800;
    
    //Mouvement 58
    randomLed();
    bothArmUp();
    Movement::turnLeft(85,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    turnMinSpeed = 6700;
    turnMaxSpeed = 12000;
    Movement::turnRight(350,turnMinSpeed,turnMaxSpeed);
    //randomLed(3);
    //delay(delayS(3));
    allOff();

    turnMinSpeed = 6000;
    turnMaxSpeed = 11000;


    //Mouvement 59
    randomLed();
    rightArmFront();
    Movement::turnLeft(85,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/    
    //randomLed(2);
    //delay(delayS(2));
    allOff();


    //Mouvement 60
    randomLed();
    bothArmFront();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/
    //randomLed(3);
    //delay(delayS(3));
    allOff();


    //Mouvement 61
    randomLed();
    rightArmUp();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();

    //================= seuil de test ==================

    //Mouvement 62
    randomLed();
    bothArmUp();
    Movement::turnLeft(90,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    turnMinSpeed = 9000;
    turnMaxSpeed = 14500;
    Movement::turnRight(350,turnMinSpeed,turnMaxSpeed);
    //randomLed(3);
    //delay(delayS(3));
    allOff();

    //turnMinSpeed = 6000;
    //turnMaxSpeed = 11000;

    forwardMinSpeed = 8800;
    forwardMaxSpeed = 14400;
    turnMinSpeed = 7600;
    turnMaxSpeed = 13200;

    
    //Mouvement 63
    randomLed();
    rightArmFront();
    Movement::turnLeft(85,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 2*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();


    //Mouvement 64
    randomLed();
    bothArmFront();
    Movement::turnLeft(94,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 3*/


    Movement::turnRight(350,turnMinSpeed,turnMaxSpeed);
    //randomLed(3);
    //delay(delayS(3));
    allOff();


    //Mouvement 65
    randomLed();
    rightArmUp();
    Movement::turnLeft(75,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 4*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();

    
    //Mouvement 66
    randomLed();
    bothArmUp();
    Movement::turnLeft(94,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(28.28,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 1*/
    Movement::turnRight(350,turnMinSpeed,turnMaxSpeed);
    //randomLed(3);
    //delay(delayS(3));
    allOff();

    
    //Mouvement 67
    randomLed();
    Movement::turnLeft(135,turnMinSpeed,turnMaxSpeed);
    Movement::moveForward(20,forwardMinSpeed,forwardMaxSpeed);
    /*move to position 0*/
    //randomLed(2);
    //delay(delayS(2));
    allOff();

    
    //Mouvement 68
    randomLed();
    Movement::turnRight(1050,turnMinSpeed,turnMaxSpeed);
    //randomLed(2);
    //delay(delayS(2));
    allOff();


    //Mouvement 69
    //FIN ICI!!!
    armsOFF();
    //================= seuil de test ==================

}


//modifications: 

// 1- increased final move forward from 34 to 36 on move 29 
// + added a delay before move 43 + decreased the delay before move 44 from 1 to 0.5

// 2- reduced angle of turning at move 42 from 96 to 90 
// + raised distance of travel between squares of move 36 from 10 to 13

// 3- increase fainl move forward in re-entry on move 36 from 28.28 to 32
// + discovered upgrading move 29 from 34 to 36 was a mistake, I confused it with move 36, but it still works, and seems to help. So we will keep it this way

// 4- reduced movement amount from position 1 to position 2 in move 55 from 28.28 to 27.5

// 5- when re-entering at move 36, 32 was too much, so reduced movement back down to 30

// 6- 30 seems to not be enough moving for the transfer at move 36, so I'll increase it from 13 to 15

// 7- when re-entry, it tends to move past position 0, causing the move to position 1 to be too high
// on move 36. I'll reduce it from 20 to 17.

// 8- move 41 had it's angle increased from 135 to 140 in order to put the robot back into the middle during that turn, and help recenter it.
// + in order to help recenter the the path, at move 63, increased movement from 28.28 to 30, to put the robot closer to the target.

//In this last test, everything went perfect until the 2nd 360 at position 1 at move 62. I need to increase the speed here, as it took 1 whole move of delay

// 9- changed the 360s to 350s at moves 58, 62, 64 and 66 to reduce the angle as the robot tends to overspin. removed 30 degrees from the 1080 for the same reason.
//I will need to increase speed still, but I'll test these new angles to observe results

//the 350s work and the code is now better. However, some fixes that used to compensate for that issue now over-correct

// 10- decreased the angle of move 63 from 90 to 85 to hopefully help send the robot more towards the middle.

//did 2 tests. Went out of place early in the first attempt, right before the first transfer, but
// was perfect until move 62 when the delay and moving out of place started

// 11- commented the turn speed decrease after move 62 as speed is too slow at that point.
// + added move forward speed increase from min 6600 to 7000 and max from 11500 to 12200
// try to observe starting at 3:40, at which point it starts moving out of whack for position only,
//not timing.

//unsure which move is the issue. It starts after the first fast turn. And it does seem to be angles.
//I'll check for any angles that aren't supposed to be there.
// 12- put move distance at 63 back down to 28.28, as 30 is too far. 
// + changed all 90 angles to 94 after move 64, to see if this helps

//didn't make it to above so don't know the results of it yet.

// 13- raised the angle of move 48 from 90 to 96 to put it closer to point 4 after it moves forward
//as this seems to be the first big drift out of place.

//so far so good, but it now gets misaligned towards move 58-59. 
// 14- reducing angle there from 90 to 85
// + undoing angles after 64 back down to 90, bringing them to 94 was dumb.

//got a bad test. Started around position 3-4 on the second square. got misaligned bad and snowballed from there
//re-running it before next changes
//got a good test. Made it until the 2nd 360, at the breakpoint. It started with a surprisingly high first transfer, 
//but it stuck it out and stayed in position until breakpoint.

// 15- raising turn speed before 360 at move 62. min from 6700 to 7600, and max from 12000 to 13200
// + raising forward speed min from 7800 to 8800 and max from 12200 to 14400

//look for the point the first angle breaks if it makes it to super fast spot. 
//The moment it's out of whack, stop and check the time. After 3:42.

//got a great test. Seems the first out of whack parts are around 3:48-49, but it came back ish
//also, it made it to the end too early. I will need to slow down a bit near the last turn, but increase the spin speed

// 16- reduced forward speed after move 62 min from 8800 down to 8400, and max from 14400 to 13400.
// + adding high speed spins. With min: 9200 and max 15000, and also reducing most normal turns:
//min from 7600 back down to 7200 and max from 13200 to 126000.
// + raising angles past move 63 from 90 to 94. spins misalign it, and I need to counter it.

//we will need some luck, and to work on the positions. Be sure to check if it still gets too
//far from where it's supposed to be at the end, and look at the timings.

//test went great!
//forgot to reduce speed after spins and increase them back lol
//messed up around 3:51-52 this time. check the angles going from position 3 to 4 after the position 3 360
//timings are messy, but closer to end goal.

// 17- fixed the disajusted spin and performance speed by setting normal speed to 7600 - 13200,
//and spin to 9000 - 14500.
// + *actually* raised angles from 90 to 94 after 63. This should help compensate for the spins's
//misalignments.

//timings are basically perfect!!!
//it drifted somewhere between 48 and 50.

// 18- reduced angles at 48 and 50 from 96 to 93.
//probably going to be ending soon


//19...
//timings were... fine. It will need more work tomorrow. It messed up around 2:55, came back to normal,
//then it messed up moving from 3 to 4 towards the end. Badly. Either the last or second to last time.
//decreased from 94 to 88 at move 65... screw it

//=============notes for tomorrow============

//there will not be a 20 today
//found when it gets really misaligned. The angle at 65 is too high

//brought it down to 75. Will test tomorrow.



//reminder to also make the transfers as straight as possible for when we have more distance to cover