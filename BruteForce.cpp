//
// Created by adrianna on 24/11/18.
//

#include <algorithm>
#include <chrono>
#include "BruteForce.h"

void BruteForce::run() {
    prepend();
 //   startTime = std::chrono::high_resolution_clock::now();
    generateSolution();
   // endTime = std::chrono::high_resolution_clock::now();
   // timeInMilliseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

}

void BruteForce::prepend() {
    numberOfCities = graph->getNumberOfCities();

    if (numberOfCities < 2) {
        throw std::runtime_error("Matrix contains only one city!");
    }

    currentRoute.clear();
    bestRoute.clear();

    currentRoute.reserve(numberOfCities);
    bestRoute.reserve(numberOfCities + 1);

    for (int town = 0; town < graph->getNumberOfCities(); town++) {
        currentRoute.push_back(town);
    }

    currentRoute.push_back(startTown);

}

void BruteForce::generateSolution() {

    do {
        currentDistance = graph->calculateOverallDistance(currentRoute);

        if (isBetter()) {
            bestDistance = currentDistance;
            bestRoute = currentRoute;
        }

    } while (std::next_permutation(currentRoute.begin() + 1, currentRoute.end() - 1));

}



void BruteForce::displayRouteDetails() {
    std::cout << "Current best route is: ";
    for (const auto &currentTown: bestRoute) {
        std::cout << currentTown << "  ";

    }
    std::cout << std::endl << "Distance: " << bestDistance << std::endl;
    std::cout << "Number of checks: " << numberOfChecks << std::endl;
    std::cout << "Time of Brute Force algorithm: " << timeInMilliseconds << std::endl;


}

bool BruteForce::isBetter() {
    return (currentDistance < bestDistance);
}