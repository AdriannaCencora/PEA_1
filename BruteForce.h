//
// Created by adrianna on 24/11/18.
//

#pragma once


#include <vector>
#include <climits>
#include "MatrixGraph.h"

class BruteForce {
public:
    BruteForce() = delete;

    explicit BruteForce(MatrixGraph *matrixGraph) : graph(matrixGraph) {}
    void generateSolution();

private:
    MatrixGraph *graph;
    std::vector<int> currentRoute;
    std::vector<int> bestRoute;

    int bestDistance{INT_MAX};
    int currentDistance{};

    void prepareToStart();
    void displayRoute();
    bool isBetter();
};




