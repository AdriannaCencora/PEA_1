//
// Created by adrianna on 27/11/18.
//

#include "DynamicProgramming.h"

void DynamicProgramming::run() {

    prepend();
    startTime = std::chrono::high_resolution_clock::now();
    generateSolution();
    endTime = std::chrono::high_resolution_clock::now();
    timeInMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    displayRouteDetails();

}

void DynamicProgramming::generateSolution() {
    for (int i = 0; i < graph->getNumberOfCities(); i++) {
        setValue(i, 0, graph->getDistance(i, 0));
    }

    result = getCost(0, numberOfSubproblems - 2);
    outputPath.push_back(0);

    getPath(0, numberOfSubproblems - 2);
}

void DynamicProgramming::prepend() {
    valueVector.clear();
    pathVector.clear();

    valueVector.resize(graph->getNumberOfCities());
    pathVector.resize(graph->getNumberOfCities());

    for (auto &value : valueVector) {
        value.resize(numberOfSubproblems, -1);
    }
    for (auto &path : pathVector) {
        path.resize(numberOfSubproblems, -1);
    }

}


int DynamicProgramming::getCost(int start, long long int set) {
    long long int masked;
    long long int mask;
    int result = -1;
    int temp;

    if (getValue(start, set) != -1) {
        return getValue(start, set);
    } else {
        for (int x = 0; x < graph->getNumberOfCities(); x++) {
            mask = numberOfSubproblems - 1 - (1 << x);
            masked = set & mask;

            if (masked != set) {
                temp = graph->getDistance(start, x) + getCost(x, masked);

                if (result == -1 || result > temp) {
                    result = temp;
                    setPathValue(start, set, x);
                }
            }
        }

        setValue(start, set, result);
        return result;
    }
}


void DynamicProgramming::getPath(int start, long long int set) {
    if (getPathValue(start, set) == -1)
        return;

    int x = getPathValue(start, set);
    long long int mask = numberOfSubproblems - 1 - (1 << x);
    long long int masked = set & mask;

    outputPath.push_back(x);

    getPath(x, masked);

}

int DynamicProgramming::getValue(long long int x, long long int y) {
    return valueVector[x][y];

}

int DynamicProgramming::getPathValue(long long int x, long long int y) {
    return pathVector[x][y];
}

void DynamicProgramming::setValue(long long int x, long long int y, int value) {
    valueVector[x][y] = value;
}

void DynamicProgramming::setPathValue(long long int x, long long int y, int value) {
    pathVector[x][y] = value;
}


void DynamicProgramming::displayRouteDetails() {
    std::cout << "Current best route is: ";
    for (const auto &currentTown: outputPath) {
        std::cout << currentTown << "  ";
    }
    std::cout << std::endl << "Distance: " << result << std::endl;
   // std::cout << "Number of checks: " << numberOfChecks << std::endl;
    std::cout << "Time of Brute Force algorithm: " << timeInMilliseconds << std::endl;

}