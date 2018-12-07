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
    BruteForce() = default;
    BruteForce(MatrixGraph *graph) : Algorithm(graph) {}
    void run() override ;
    void displayRouteDetails() override ;
    virtual ~BruteForce() = default;

protected:
    std::vector<int> currentRoute;
    std::vector<int> bestRoute;
    std::vector<bool> visitedTowns;
    int numberOfCities{};
    int numberOfChecks{};
    int startTown{};
    int bestDistance{INT_MAX};
    int currentDistance{};

    virtual void handleTheRoute(int town);
    virtual void handleLasElementOfRoute(int town);
    virtual void generateSolution(int town);
    virtual void prepend();
    virtual bool isBetter();
};




