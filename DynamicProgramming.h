//
// Created by adrianna on 27/11/18.
//

#pragma once


#include "MatrixGraph.h"
#include "Algorithm.h"

class DynamicProgramming : public Algorithm {
public:
    explicit DynamicProgramming(MatrixGraph *matrixGraph) : Algorithm(matrixGraph) {
        numberOfSubproblems = (1 << (graph->getNumberOfCities() ));
    }
    void run() override;
    void displayRouteDetails() override ;

private:
    long long numberOfSubproblems{};
    std::vector<std::vector<int>> pathVector;
    std::vector<std::vector<int>> valueVector;
    std::vector<int> outputPath;
    int result{};
    int getCost(int start, long set);
    void getPath(int start, long set);

    int getValue(long x, long y);
    int getPathValue(long  x, long y);

    void setValue(long x, long  y, int value);
    void setPathValue(long x, long  y, int value);
    void generateSolution();
    void prepend();
};




