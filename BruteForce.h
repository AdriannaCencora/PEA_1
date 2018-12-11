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

private:
    std::vector<int> currentRoute;
    std::vector<int> bestRoute;

    int numberOfCities{};
    int numberOfChecks{};
    int startTown{0};
    int bestDistance{INT_MAX};
    int currentDistance{};


    void generateSolution();
    void prepend();
    bool isBetter();
};




