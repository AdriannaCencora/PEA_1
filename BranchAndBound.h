//
// Created by adrianna on 26/11/18.
//

#pragma once


#include "MatrixGraph.h"

class BranchAndBound {
public:
    BranchAndBound() = delete;
    ~BranchAndBound() = default;
    explicit BranchAndBound(MatrixGraph *matrixGraph) : graph(matrixGraph) {}
    void generateSolution();

private:
    MatrixGraph *graph;
};




