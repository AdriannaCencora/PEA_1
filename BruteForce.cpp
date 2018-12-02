//
// Created by adrianna on 24/11/18.
//

#include <algorithm>
#include <chrono>
#include "BruteForce.h"

void BruteForce::run() {
    prepend();
    startTime = std::chrono::high_resolution_clock::now();
    generateSolution(startTown);
    endTime = std::chrono::high_resolution_clock::now();
    timeInMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    displayRouteDetails();

}

void BruteForce::prepend() {
    numberOfCities = graph->getNumberOfCities();

    if (numberOfCities < 2) {
        throw std::runtime_error("Matrix contains only one city!");
    }

    currentRoute.clear();
    bestRoute.clear();
    visitedTowns.clear();

    currentRoute.reserve(numberOfCities);
    bestRoute.reserve(numberOfCities + 1);
    visitedTowns.resize(numberOfCities);

}

void BruteForce::generateSolution(int currentTown) {
    currentRoute.push_back(currentTown);
    visitedTowns[currentTown] = true;

    if (currentRoute.size() < numberOfCities) {
        handleTheRoute(currentTown);
    } else {
        handleLasElementOfRoute(currentTown);
    }

    visitedTowns[currentTown] = false;
    currentRoute.pop_back();

}

void BruteForce::handleTheRoute(int currentTown) {
    int distanceToNext{};
    for (unsigned nextTown{0}; nextTown < numberOfCities; ++nextTown) {
        if (!visitedTowns[nextTown]) {
            distanceToNext = graph->getDistance(currentTown, nextTown);

            if (distanceToNext < 0) {
                continue;
            }
            currentDistance += distanceToNext;

            generateSolution(nextTown);

            currentDistance -= distanceToNext;
        }
    }
}

void BruteForce::handleLasElementOfRoute(int currentTown) {
    numberOfChecks++;

    int distanceToNext = graph->getDistance(currentTown, startTown);

    if (distanceToNext < 0)
        return;

    currentDistance += distanceToNext;

    if (isBetter()) {
        bestDistance = currentDistance;
        bestRoute = currentRoute;
        bestRoute.push_back(startTown);
    }
    currentDistance -= distanceToNext;

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