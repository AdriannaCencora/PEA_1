//
// Created by adrianna on 26/11/18.
//

#pragma once


#include "MatrixGraph.h"
#include "Algorithm.h"
#include "BruteForce.h"
#include <stack>
#include <queue>

struct BnBNode {
    std::vector<unsigned int> path{};
    std::vector<bool> visited{false};
    double lowerBound{};
    double value{};

    bool operator<(const BnBNode& rhs) const {
        return (value > rhs.value);
    }

};

class BranchAndBound : public Algorithm {


public:
    BranchAndBound() = default;
    ~BranchAndBound() = default;
    BranchAndBound(MatrixGraph *graph) : Algorithm (graph) {}
    void run() override;
    void displayRouteDetails() override;

private:
    BnBNode best{};

    void prepend();
    void calculateStartingLowerBound();
    void DFS();
    void BeFS();
    int numberOfCities{};
    int currentLowerBound{};
    std::vector<std::vector<int>> lowestDistancesToTowns;

    int startTown{0};
    std::stack<BnBNode> containerDFS;
    std::priority_queue<BnBNode, std::vector<BnBNode>> containerBeFS;




};




