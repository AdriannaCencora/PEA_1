//
// Created by adrianna on 16/11/18.
//

#include <random>
#include <climits>
#include "MatrixGraph.h"

void MatrixGraph::addEdge(int from, int to, int value) {
    matrix[from][to]= value;
}

void MatrixGraph::setNumberOfCities(int _numberOfCities) {
    numberOfCities = _numberOfCities;
    setMatrixGraphSize();
}

int MatrixGraph::getNumberOfCities() const {
    return  numberOfCities;
}

void MatrixGraph::setMatrixGraphSize() {
    matrix.resize(numberOfCities);
    for (auto &vector : matrix) {
        vector.resize(numberOfCities);
    }
}
void MatrixGraph::printMatrix() const {
    for (const auto &vector : matrix) {
        for (const auto &v : vector) {
            std::cout << v << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void MatrixGraph::fillMatrixWithRandomData(int numberOfCities) {
    setNumberOfCities(numberOfCities);

    const int upperRange = 150;
    std::random_device seed;
    std::mt19937 randomGenerator(seed());
    std::uniform_int_distribution<> transform(1, upperRange);

    for (auto &vector : matrix) {
        for (auto &v : vector) {
            v = transform(randomGenerator);
        }
    }

    for (int diagonal = 0;diagonal < numberOfCities;diagonal++) {
        matrix[diagonal][diagonal] = -1;
    }
}

int MatrixGraph::calculateOverallDistance(const std::vector<int> &route) {
    int distance{};

    for (int town = 0; town < (route.size() - 1); town++) {
        if (isDiagonal(route.at(town), route.at(town + 1))) {
                continue;
        }
        distance += getDistance(route.at(town), route.at(town+1));

    }

    distance += getDistanceFromLastToFirst(route.at(route.size() -1), 0);

    return distance;
}

int MatrixGraph::getDistance(const int from, const int to) const {
    return  matrix[to][from];
}

int MatrixGraph::getDistanceFromLastToFirst(const int from, const int to) const {
    return getDistance(from, to);
}

bool MatrixGraph::isDiagonal(const int from, const int to) {
    return (getDistance(from, to) < 0);
}

int MatrixGraph::getMinDistanceFrom(int town) const{
    int min{INT_MAX};

    for (int i{0}; i < matrix.size(); ++i) {
        if (matrix[town][i] < min && matrix[town][i] > 0) {
            min = matrix[town][i];
        }
    }
    return  min;
}
int MatrixGraph::getMinDistanceTo(int town) const {
    int min{INT_MAX};

    for (const auto &vector : matrix) {
        if(vector[town] < min && vector[town] > 0 ) {
            min = vector[town];
        }
    }
    return  min;
}