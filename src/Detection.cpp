#include "Detection.h"

namespace DETECTION{
    DetectionState getDetection(bool detectionOnLeft, bool detectionOnRight){
        if(detectionOnLeft && detectionOnRight){
            return DetectionState::DETECT_FRONT;
        }else if(detectionOnLeft){
            return DetectionState::DETECT_LEFT;
        }else if(detectionOnRight){
            return DetectionState::DETECT_RIGHT;
        }
        
        return DetectionState::DETECT_NONE;
    }
}