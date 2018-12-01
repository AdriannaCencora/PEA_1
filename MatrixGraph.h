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
    int calculateOverallDistance(const std::vector<int> &route);
    int getDistance(const int from, const int to) const;

private:
    std::vector<std::vector<int>> matrix;
    int numberOfCities{};

    int getDistanceFromLastToFirst(const int from, const int to) const;
    void setMatrixGraphSize();
    bool isDiagonal(const int from, const int to);

};




