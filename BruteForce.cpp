//
// Created by adrianna on 24/11/18.
//

#include <algorithm>
#include "BruteForce.h"

void BruteForce::generateSolution() {
    prepend();

 do {
        currentDistance = graph->calculateOverallDistance(currentRoute);

        if (isBetter()) {
            bestDistance = currentDistance;
            bestRoute = currentRoute;
            displayRoute();
        }

    } while (std::next_permutation(currentRoute.begin() + 1, currentRoute.end() - 1));
 
}

void BruteForce::prepend() {
    currentRoute.clear();
    bestRoute.clear();

    currentRoute.reserve(graph->getNumberOfCities());
    bestRoute.reserve(graph->getNumberOfCities() + 1);

    for (int town = 0; town < graph->getNumberOfCities(); town++) {
        currentRoute.push_back(town);
    }

    currentRoute.push_back(startTown);

}

void BruteForce::displayRoute() {
    std::cout << "Current best route is: ";
    for (const auto &town : bestRoute) {
        std::cout << town << "  ";

    }
    std::cout << bestDistance << std::endl;
}

bool BruteForce::isBetter() {
    return (currentDistance < bestDistance);
}