//
// Created by adrianna on 26/11/18.
//

#pragma once


#include "MatrixGraph.h"
#include "Algorithm.h"

class BranchAndBound : public  Algorithm {
public:
    BranchAndBound() = delete;
    ~BranchAndBound() = default;
    explicit BranchAndBound(MatrixGraph *grap) : Algorithm (graph) {}
    void run() override ;

private:
    void prepend();
    void generateSolution(int startTown);
    void calculateStartingLowerBound();
    void handleTheRoute(int town);
    void handleLasElementOfRoute(int town);
    void displayRouteDetails();
    int currentLowerBound;
    std::vector<std::vector<int>> lowestDistancesToVertices;
};




