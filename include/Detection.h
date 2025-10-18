#ifndef DETECTION_H
#define DETECTION_H

namespace DETECTION{
    enum DetectionState { DETECT_NONE, DETECT_LEFT, DETECT_RIGHT, DETECT_FRONT };

    DetectionState getDetection(bool detectionOnLeft, bool detectionOnRight);
}
#endif