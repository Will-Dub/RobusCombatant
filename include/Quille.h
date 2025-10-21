#include "Detection.h"
#include "WheelPID.h"
#include "Movement.h"

#define IR_LEFT_PIN 39 // Vert
#define IR_RIGHT_PIN 40 // Rouge

enum QuilleState {FINDING, ALIGNING, GOING_TO, GOING_BACK};

struct MovementRecord{
    Movement::MoveEnum type;
    float distance;
};

const int MAX_MOVES = 30;
constexpr float FORWARD_DISTANCE = 12.5f;
constexpr float FORWARD_GOING_TO_MAX = 25.0f;

void waitEndMoveFinding();
void waitEndMoveAligning();
void waitEndMoveGoingTo();
DETECTION::DetectionState getIRDetection();