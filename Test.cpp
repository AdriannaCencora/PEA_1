//
// Created by adrianna on 02/12/18.
//

#include <fstream>
#include <sstream>
#include "Test.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
#include "DynamicProgramming.h"

void Test::run() {
    prepend();
std::cout <<    measureTime();
}

void Test::writeToFile() {

}

void Test::prepend() {
    std::string path = "../results/";
    path += "test-";
    path += "DP";
    path += ".txt";
    outputFile.open(path, std::fstream::out);

    if (!outputFile.is_open()) {
        throw std::runtime_error("Cannot open file!");
    }

}

std::string Test::measureTime() {
    std::stringstream outputConsole;
    outputConsole.setf(std::ios::fixed);
    int townsNumber = 20;
    int tests = 100;

    // algorithm = new BruteForce(graph);
   // algorithm = new BranchAndBound(graph);

    algorithm = new DynamicProgramming(graph);

    for (int numberOfTowns{3}; numberOfTowns <townsNumber; numberOfTowns++) {
        outputFile << "Ilość miast: " << numberOfTowns << std::endl;

        outputConsole << "Test " << numberOfTowns << " \n ";
        int sumOfResults = 0;
        for (int numberOfTests{0}; numberOfTests < tests; numberOfTests++) {
            graph->fillMatrixWithRandomData(numberOfTowns);

            std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
            algorithm->run();
            std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();

            auto result = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

            outputFile << result << std::endl;
            outputConsole << result << std::endl;

            sumOfResults += result;

        }
        sumOfResults /= tests;
        outputConsole << "Średnia: " << sumOfResults << std::endl;
        outputFile << "Srednia: " << sumOfResults << std::endl;

    }
    std::string output = outputConsole.str();
    return output;
}