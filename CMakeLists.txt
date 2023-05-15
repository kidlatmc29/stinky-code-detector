cmake_minimum_required(VERSION 3.25)
project(stinky_code_detector)

set(CMAKE_CXX_STANDARD 11)

add_executable(stinky_code_detector src/main.cpp src/longFunctionDetector.h src/longFunctionDetector.cpp src/Detector.cpp src/Detector.h)
