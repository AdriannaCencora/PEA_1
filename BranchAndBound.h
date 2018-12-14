//
// Created by adrianna on 26/11/18.
//

#pragma once


#include "MatrixGraph.h"
#include "Algorithm.h"
#include "BruteForce.h"
#include <stack>
class BranchAndBound : public Algorithm {
    struct BnBNode {
        std::vector<unsigned int> path;
        std::vector<bool> visited;
        double lowerBound;
        double value;
    };

public:
    BranchAndBound() = default;
    ~BranchAndBound() = default;
    BranchAndBound(MatrixGraph *graph) : Algorithm (graph) {}
    void run() override;
    void displayRouteDetails() override;
private:
    void prepend();
    void calculateStartingLowerBound();
    void DFS();
    int numberOfCities{};
    int currentLowerBound{};
    std::vector<std::vector<int>> lowestDistancesToTowns;

    int startTown{0};
    BnBNode initialRoot{};
    std::stack<BnBNode> stackDFS;





};




