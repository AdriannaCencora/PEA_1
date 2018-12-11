//
// Created by adrianna on 26/11/18.
//

#pragma once


#include "MatrixGraph.h"
#include "Algorithm.h"
#include "BruteForce.h"

class BranchAndBound : public Algorithm {
public:
    BranchAndBound() = default;
    ~BranchAndBound() = default;
    BranchAndBound(MatrixGraph *graph) : Algorithm (graph) {}
    void displayRouteDetails() override;
private:
    void prepend();

    void calculateStartingLowerBound();
    int currentLowerBound{};
    std::vector<std::vector<int>> lowestDistancesToVertices;
};




