//
// Created by adrianna on 18/11/18.
//

#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "MatrixGraph.h"

class FileHandler {
public:
    explicit FileHandler(std::string &_fileName) : inputFile(_fileName, std::ios::in) {
       // inputFile.open();
        if (!inputFile.is_open()) {
            std::cerr << "File couldn't be opened!" << std::endl;
            return;
        }
    }
    ~FileHandler()  {
        inputFile.close();
    }

    void readDataFromFile(MatrixGraph *matrixGraph);

private:
    //std::string fileName;
    std::fstream inputFile;


};




