//
// Created by adrianna on 02/12/18.
//

#pragma once


#include <chrono>
#include "MatrixGraph.h"

class Algorithm {
public:
    Algorithm() = default;
    Algorithm(MatrixGraph *matrixGraph)  : graph(matrixGraph) {}
    virtual void run() = 0;
    virtual void displayRouteDetails() = 0;
    virtual ~Algorithm() = default;
protected:
    MatrixGraph *graph;
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
    long long timeInMilliseconds{};
};




