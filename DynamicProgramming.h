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

private:
    long long numberOfSubproblems{};
    std::vector<std::vector<int>> pathVector;
    std::vector<std::vector<int>> valueVector;
    std::vector<int> outputPath;
    int result{};
    int getCost(int start, long long int set);
    void getPath(int start, long long int set);

    int getValue(long long int x, long long int y);
    int getPathValue(long long int x, long long int y);

    void setValue(long long int x, long long int y, int value);
    void setPathValue(long long int x, long long int y, int value);
    void generateSolution();
    void prepend();
    void displayRouteDetails();
};




