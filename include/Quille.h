#include "Detection.h"
#include "WheelPID.h"
#include "Movement.h"

#define IR_LEFT_PIN 39 // Vert
#define IR_RIGHT_PIN 40 // Rouge

enum QuilleState {FINDING, ALIGNING, GOING_TO, GOING_BACK};

constexpr float FORWARD_DISTANCE = 12.5f;

void waitEndMoveFinding();
void waitEndMoveAligning();
void waitEndMoveGoingTo();
DETECTION::DetectionState getIRDetection();