//
// Created by adrianna on 16/11/18.
//

#pragma once

#include <iostream>
#include <vector>

class MatrixGraph {
public:
    MatrixGraph() = default;
    ~MatrixGraph() = default;
    void addEdge(int from, int to, int value);
    void setNumberOfCities(int _numberOfCities);
    int getNumberOfCities () const;
    void printMatrix() const;
    void fillMatrixWithRandomData();

private:
    std::vector<std::vector<int>> matrix;
    int numberOfCities{};


    void setMatrixGraphSize();

};




