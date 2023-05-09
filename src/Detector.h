//
// Created by Isabel Ovalles on 4/26/23.
//
#include <vector>

using namespace std;

#ifndef STINKY_CODE_DETECTOR_DETECTOR_H
#define STINKY_CODE_DETECTOR_DETECTOR_H

class Detector{
public:
    virtual vector<string> detect();
};

#endif //STINKY_CODE_DETECTOR_DETECTOR_H
