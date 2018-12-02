//
// Created by adrianna on 24/11/18.
//

#pragma once


#include <vector>
#include <climits>
#include "MatrixGraph.h"
#include "Algorithm.h"

class BruteForce : public  Algorithm {
public:
    BruteForce() = delete;
    BruteForce(MatrixGraph *graph) : Algorithm(graph) {}
    void run() override ;
    virtual ~BruteForce() = default;

private:
    std::vector<int> currentRoute;
    std::vector<int> bestRoute;
    std::vector<bool> visitedTowns;
    int numberOfCities{};
    int numberOfChecks{};
    int startTown{};
    int bestDistance{INT_MAX};
    int currentDistance{};
    void handleTheRoute(int town);
    void handleLasElementOfRoute(int town);
    void displayRouteDetails();
    void generateSolution(int town);
    void prepend();
    bool isBetter();
};




