#include "WheelPID.h"
#include "Movement.h"

enum QuilleState {FINDING, GOING_TO, GOING_BACK};

struct MovementRecord{
    Movement::MoveEnum type;
    float distance;
};

const int MAX_MOVES = 30;
constexpr float FORWARD_DISTANCE = 12.5f;
constexpr float FORWARD_GOING_TO_MAX = 25.0f;
constexpr float TRIGGER_RANGE = 10.0f;

void actionQuille(SRF04Sonar& sonar);
void waitEndMoveFinding(SRF04Sonar& sonar);
void waitEndMoveGoingTo(SRF04Sonar& sonar);
void scanLeft(SRF04Sonar& sonar);