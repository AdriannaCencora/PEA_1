//
// Created by adrianna on 16/11/18.
//

#include <random>
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

void MatrixGraph::fillMatrixWithRandomData() {
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
