//
// Created by adrianna on 27/11/18.
//

#pragma once


#include "MatrixGraph.h"
#include "FileHandler.h"

class Application {
public:
    Application() = default;

    ~Application() = default;
    void run();
    void displayMenu();


private:
    MatrixGraph* matrixGraph = new MatrixGraph();
    char userChoice{};
    bool isRunning{true};
};


