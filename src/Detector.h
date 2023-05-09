//
// Created by Isabel Ovalles on 4/26/23.
//
#include <vector>
#include <string>

using namespace std;

#ifndef STINKY_CODE_DETECTOR_DETECTOR_H
#define STINKY_CODE_DETECTOR_DETECTOR_H

class Detector{
public:
    Detector();
    ~Detector();
    int detectLongFunction(const string function);
    int detectLongParameters(const string function);
    double detectDuplicateCode(const string function);

private:
    void processFunction(const string function);
};

#endif //STINKY_CODE_DETECTOR_DETECTOR_H
