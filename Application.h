//
// Created by adrianna on 27/11/18.
//

#pragma once


#include "MatrixGraph.h"
#include "FileHandler.h"
#include "Algorithm.h"

class Application {
public:
    Application() = default;

    ~Application() = default;
    void run();
    void displayMenu();


private:
    MatrixGraph *matrixGraph = new MatrixGraph();
    Algorithm *algorithm;
    char userChoice{};
    bool isRunning{true};
};


