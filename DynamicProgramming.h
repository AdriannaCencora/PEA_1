//
// Created by adrianna on 27/11/18.
//

#pragma once


#include "MatrixGraph.h"

class DynamicProgramming {
public:
    explicit DynamicProgramming(MatrixGraph *matrixGraph) : graph(matrixGraph) {}
    void generateSolution();

private:
    MatrixGraph *graph{};
};




