//
// Created by adrianna on 02/12/18.
//

#pragma once


#include "Algorithm.h"

class Test {
public:
    Test() = delete;
    Test(MatrixGraph* matrixGraph) : graph(matrixGraph){}
    void run();
    ~Test() { outputFile.clear(); }
private:
    const int MAX_TOWNS_BF = 13;
    const int MAX_TOWNS_BB = 25;
    const int MAX_TOWNS_DP = 20;

    MatrixGraph *graph;
    Algorithm *algorithm{};
    std::fstream outputFile{};
    void prepend();
    std::string measureTime();


};




