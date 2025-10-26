#include "WheelPID.h"
#include <math.h>

namespace WHEEL_PID {

    // --- État interne ---
    unsigned long previousTime   = 0;

    int leftDesiredPulse  = 0;  // pulses/s (signé)
    int rightDesiredPulse = 0;  // pulses/s (signé)

    int leftTotalPulse  = 0;    // somme brute des pulses (signés)
    int rightTotalPulse = 0;

    float lastLeftError  = 0.0f;  // erreur (pulses sur fenêtre dt)
    float lastRightError = 0.0f;

    float iLeftError  = 0.0f;     // intégrale (pulses·s sur fenêtre)
    float iRightError = 0.0f;

    // Lissage / mémoires pour D sur la mesure + slew-rate
    static float lastLeftDuty   = 0.0f;
    static float lastRightDuty  = 0.0f;
    static int   lastLeftMeas   = 0;     // pulses (mesure sur fenêtre dt)
    static int   lastRightMeas  = 0;

    // Petites corrections asymétriques en ligne droite
    static constexpr float LEFT_SCALE  = 1.00f;
    static constexpr float RIGHT_SCALE = 1.02f;

    // --- Utils ---
    inline float constrainFloat(float v, float lo, float hi) {
        if (v < lo) return lo;
        if (v > hi) return hi;
        return v;
    }

    // Clamp de magnitude [minMag..maxMag] puis application du signe de la consigne
    inline float applySignedClamp(float u, int desiredSign, float minMag, float maxMag) {
        float mag = fabsf(u);
        mag = constrainFloat(mag, minMag, maxMag);
        return (desiredSign >= 0) ? mag : -mag;
    }

    // Limitation de rampe (slew-rate) sur le duty
    inline float slewLimit(float target, float current, float dt, float slewPerSec){
        float maxStep = slewPerSec * dt;
        if (target > current + maxStep) return current + maxStep;
        if (target < current - maxStep) return current - maxStep;
        return target;
    }

    // --- API impl ---
    void init(){
        previousTime  = millis();
        iLeftError    = 0.0f;
        iRightError   = 0.0f;
        lastLeftError = 0.0f;
        lastRightError= 0.0f;
        lastLeftDuty  = 0.0f;
        lastRightDuty = 0.0f;
        lastLeftMeas  = 0;
        lastRightMeas = 0;
        leftTotalPulse  = 0;
        rightTotalPulse = 0;
    }

    void setPIDDesiredPulse(int newLeftDesiredPulse, int newRightDesiredPulse){
        // Détecte déplacement rectiligne (même signe)
        const bool straight = (newLeftDesiredPulse * newRightDesiredPulse) > 0;

        if (straight) {
            leftDesiredPulse  = (int)roundf(LEFT_SCALE  * newLeftDesiredPulse);
            rightDesiredPulse = (int)roundf(RIGHT_SCALE * newRightDesiredPulse);
        } else {
            leftDesiredPulse  = newLeftDesiredPulse;
            rightDesiredPulse = newRightDesiredPulse;
        }
    }

    void stopMotor(){
        MOTOR_SetSpeed(LEFT,  0.0f);
        MOTOR_SetSpeed(RIGHT, 0.0f);

        previousTime   = millis();
        iLeftError     = 0.0f;
        iRightError    = 0.0f;
        lastLeftError  = 0.0f;
        lastRightError = 0.0f;

        lastLeftDuty   = 0.0f;
        lastRightDuty  = 0.0f;
        lastLeftMeas   = 0;
        lastRightMeas  = 0;
    }

    void runPIDController() {
        const unsigned long now = millis();
        float dt = (now - previousTime) / 1000.0f;

        // Si consignes nulles → stop propre
        if (leftDesiredPulse == 0 && rightDesiredPulse == 0) {
            stopMotor();
<<<<<<< Updated upstream
            previousTime = now;
=======
            iLeftError = 0;
            iRightError = 0;
            lastLeftError = 0;
            lastRightError = 0;
            previousTime = currentTime;
>>>>>>> Stashed changes
            return;
        }

<<<<<<< Updated upstream
        // Sécurité dt
        if (dt <= 0.0005f) return;   // < 0.5 ms : ignore
        if (dt > 0.05f) dt = 0.05f;  // borne à 50 ms pour éviter des D trop grandes
=======
        // P
        float leftMotorError = leftMotorCalculatedPulse - leftMotorPulse;
        float rightMotorError = rightMotorCalculatedPulse - rightMotorPulse;
        
        // I
        iLeftError += leftMotorError;
        iRightError += rightMotorError;
        
        iLeftError = constrainFloat(iLeftError, -maxIntegral, maxIntegral);
        iRightError = constrainFloat(iRightError, -maxIntegral, maxIntegral);
        
        // D
        float dLeftMotorError = (leftMotorError - lastLeftError) / elapsedTimeSec;
        float dRightMotorError = (rightMotorError - lastRightError) / elapsedTimeSec;
        
        // Calculation
        float outLeftMotor = kp * leftMotorError + ki * iLeftError + kd * dLeftMotorError;
        float outRightMotor = kp * rightMotorError + ki * iRightError + kd * dRightMotorError;
        
        // Range 0-1
        outLeftMotor = constrainFloat(outLeftMotor, 0, 1.0);
        outRightMotor = constrainFloat(outRightMotor, 0, 1.0);
>>>>>>> Stashed changes

        // Signes & vitesses cibles (pulses/s en magnitude)
        const int   signL = (leftDesiredPulse  >= 0) ? +1 : -1;
        const int   signR = (rightDesiredPulse >= 0) ? +1 : -1;
        const float vRefL = fabsf((float)leftDesiredPulse);
        const float vRefR = fabsf((float)rightDesiredPulse);

        // Cibles de pulses sur la fenêtre dt
        const float targetPulsesL = vRefL * dt;
        const float targetPulsesR = vRefR * dt;

        // Mesures : pulses depuis la dernière itération (peuvent être signés)
        const int rawL  = ENCODER_ReadReset(LEFT);
        const int rawR  = ENCODER_ReadReset(RIGHT);
        const int measL = abs(rawL);
        const int measR = abs(rawR);

        leftTotalPulse  += rawL;
        rightTotalPulse += rawR;

        // Erreurs (en pulses sur la fenêtre dt)
        float eL = targetPulsesL - measL;
        float eR = targetPulsesR - measR;

        // Dérivée sur la mesure (anti-derivative-kick) : d = (y - y_prev)/dt
        float dMeasL = (measL - lastLeftMeas)  / dt;
        float dMeasR = (measR - lastRightMeas) / dt;

        // Intégrale proposée (appliquée après anti-windup conditionnel)
        float iL_prop = iLeftError  + eL * dt;
        float iR_prop = iRightError + eR * dt;

        // Feed-forward : duty de base proportionnel à la consigne de vitesse.
        // NOTE: Mesure rapide pour kFeedForward :
        //  1) MOTOR_SetSpeed(LEFT/RIGHT, 1.0)
        //  2) Lire pulses/s (stabilisé)
        //  3) kFF = 1 / (pulses/s)
        float ffL = kFeedForward * vRefL;
        float ffR = kFeedForward * vRefR;

        // PID brut (sur la magnitude) + D sur la mesure (terme -kd*dMeas)
        float uL = ffL + (kp * eL + ki * iL_prop - kd * dMeasL);
        float uR = ffR + (kp * eR + ki * iR_prop - kd * dMeasR);

        // Clamp magnitude [minDuty..maxDuty] si consigne ≠ 0, puis signe
        float uL_signed = applySignedClamp(uL, signL, (vRefL > 0 ? minDuty : 0.0f), maxDuty);
        float uR_signed = applySignedClamp(uR, signR, (vRefR > 0 ? minDuty : 0.0f), maxDuty);

        // Anti-windup conditionnel :
        // - Si non saturé : on intègre.
        // - Si saturé : on n'intègre QUE si l'erreur pousse vers l'intérieur de la saturation.
        const bool satL = (fabsf(uL) >= maxDuty - 1e-4f);
        const bool satR = (fabsf(uR) >= maxDuty - 1e-4f);

        // Pousse vers l'intérieur ? (si signe positif: e<0 réduit la demande; signe négatif: e<0 aussi)
        const bool pushInL = (eL < 0.0f);
        const bool pushInR = (eR < 0.0f);

        if (!satL || (satL && pushInL)) {
            iLeftError = constrainFloat(iL_prop, -maxIntegral, maxIntegral);
        }
        if (!satR || (satR && pushInR)) {
            iRightError = constrainFloat(iR_prop, -maxIntegral, maxIntegral);
        }

        // Limitation de rampe (lissage mécanique)
        uL_signed = slewLimit(uL_signed, lastLeftDuty,  dt, maxDutySlewPerSec);
        uR_signed = slewLimit(uR_signed, lastRightDuty, dt, maxDutySlewPerSec);

<<<<<<< Updated upstream
        // Appliquer vitesses (-1..+1)
        MOTOR_SetSpeed(LEFT,  uL_signed);
        MOTOR_SetSpeed(RIGHT, uR_signed);

        // Mémoires
        lastLeftDuty   = uL_signed;
        lastRightDuty  = uR_signed;
        lastLeftMeas   = measL;
        lastRightMeas  = measR;
        lastLeftError  = eL;
        lastRightError = eR;
        previousTime   = now;
=======
        Serial.print(">");
        Serial.print("LeftMotorCalculatedPulse:");
        Serial.print(leftMotorCalculatedPulse);
        Serial.print(",");
        Serial.print("leftMotorPulse:");
        Serial.print(leftMotorPulse);
        Serial.print(",");
        Serial.print("D:");
        Serial.print(dRightMotorError);
        Serial.print(",");
        Serial.print("OutRight:");
        Serial.print(outRightMotor);
        Serial.print(",");
        Serial.print("OutLeft:");
        Serial.print(outLeftMotor);
        Serial.print(",");
        Serial.print("DesiredRight:");
        Serial.print(rightDesiredPulse);
        Serial.print(",");
        Serial.print("TimeElapsed:");
        Serial.print(elapsedTimeSec);
        Serial.print(",");
        Serial.print("getRightCoveredDistance:");
        Serial.print(getRightCoveredDistance());
        Serial.println();
>>>>>>> Stashed changes
    }

    void reset(){
        lastLeftError   = 0.0f;
        lastRightError  = 0.0f;
        iLeftError      = 0.0f;
        iRightError     = 0.0f;
        lastLeftDuty    = 0.0f;
        lastRightDuty   = 0.0f;
        lastLeftMeas    = 0;
        lastRightMeas   = 0;
    }

    // Retourne la distance moyenne parcourue (cm)
    float getCoveredDistance(){
        float combinedAveragePulse = (fabsf((float)leftTotalPulse) + fabsf((float)rightTotalPulse)) * 0.5f;
        return pulseToDistance((int)combinedAveragePulse);
    }

    float getRightCoveredDistance() {
        return pulseToDistance(rightTotalPulse);
    }

    float getLeftCoveredDistance(){
        return pulseToDistance(leftTotalPulse);
    }

    // pulse → distance (cm). ROUE_DIAMETRE en pouces, conversion appliquée.
    float pulseToDistance(int pulse) {
        float tours = fabsf((float)pulse) / PULSE_PER_TURN;
        float perimetre_cm = (float)M_PI * ROUE_DIAMETRE * POUCE_TO_CM;
        return tours * perimetre_cm;
    }

    void resetCoveredDistance(){
        previousTime   = millis();
        leftTotalPulse = 0;
        rightTotalPulse= 0;
        // On remet à zéro les compteurs d'itération des encodeurs :
        ENCODER_ReadReset(LEFT);
        ENCODER_ReadReset(RIGHT);
    }

} // namespace WHEEL_PID
