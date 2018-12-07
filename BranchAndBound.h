//
// Created by adrianna on 26/11/18.
//

#pragma once


#include "MatrixGraph.h"
#include "Algorithm.h"
#include "BruteForce.h"

class BranchAndBound : public  BruteForce {
public:
    BranchAndBound() = default;
    ~BranchAndBound() = default;
    BranchAndBound(MatrixGraph *graph) : BruteForce (graph) {}
    void displayRouteDetails() override;
private:
    void prepend() override;
    void handleTheRoute(int currentTown) override ;

    void calculateStartingLowerBound();
    int currentLowerBound{};
    std::vector<std::vector<int>> lowestDistancesToVertices;
};




