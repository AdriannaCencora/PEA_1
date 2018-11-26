//
// Created by adrianna on 18/11/18.
//

#include "FileHandler.h"

void FileHandler::readDataFromFile(MatrixGraph *matrixGraph) {

    //std::string dataName;
    int buffer{};
    int numberOfCities{};
    int column{}, row{};
    //inputFile >> dataName;
    inputFile >> numberOfCities;
    matrixGraph->setNumberOfCities(numberOfCities);

    while (inputFile >> buffer) {
        matrixGraph->addEdge(column, row, buffer);
        ++column;
        if (column == numberOfCities) {
            column = 0;
            ++row;
        }
        if (row == numberOfCities)
            break;
    }

    if (row != numberOfCities)
        std::cerr << "File doesn't contain enough data!";


}