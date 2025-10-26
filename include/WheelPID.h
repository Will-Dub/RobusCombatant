#pragma once

#include <LibRobus.h>
#include <Arduino.h>
#include <math.h>

<<<<<<< Updated upstream
namespace WHEEL_PID {
=======
namespace WHEEL_PID{
    constexpr float PULSE_PER_TURN = 3200.0f;
    constexpr float POUCE_TO_CM = 2.54f;
    constexpr float ROUE_DIAMETRE = 3.0f;
    const float kp = 0.2f;
    const float ki = 0.07f;
    const float kd = 0.04f;
    const float maxIntegral = 1000.0f;
>>>>>>> Stashed changes

// --- Paramètres mécaniques / conversion ---
// ROUE_DIAMETRE en pouces (ex.: 3.0"), conversion en cm appliquée dans pulseToDistance().
inline constexpr float PULSE_PER_TURN = 3200.0f;
inline constexpr float POUCE_TO_CM    = 2.54f;
inline constexpr float ROUE_DIAMETRE  = 3.0f;   // pouces

// --- PID (gains d'origine) ---
inline constexpr float kp = 0.03f;
inline constexpr float ki = 0.003f;
inline constexpr float kd = 0.0005f;

// Limite d'intégrale (anti-windup)
inline constexpr float maxIntegral = 300.0f;

// --- Pilotage (ajouts légers) ---
// kFeedForward : duty ≈ kFF * (pulses/s). À ajuster avec une mesure (voir commentaire dans .cpp).
inline constexpr float kFeedForward       = 1.0f / 900.0f; // si à 100% tu lis ~900 pulses/s
inline constexpr float minDuty            = 0.08f;         // vaincre frottements
inline constexpr float maxDuty            = 1.00f;         // plafond duty
inline constexpr float maxDutySlewPerSec  = 3.0f;          // rampe (duty/s)

// --- API ---
void init();
void setPIDDesiredPulse(int newLeftDesiredPulse, int newRightDesiredPulse);
void runPIDController();
void stopMotor();
void reset();

float getCoveredDistance();
float getRightCoveredDistance();
float getLeftCoveredDistance();
void resetCoveredDistance();
float pulseToDistance(int pulse);

} // namespace WHEEL_PID
