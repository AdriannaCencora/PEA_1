//
// Created by adrianna on 24/11/18.
//

#include <algorithm>
#include "BruteForce.h"

void BruteForce::generateSolution() {

    prepareToStart();

    do {
       currentDistance = graph->calculateOverallDistance(currentRoute);

       if (isBetter()) {
           bestDistance = currentDistance;
           bestRoute = currentRoute;
           displayRoute();
       }

    } while (std::next_permutation(currentRoute.begin(), currentRoute.end()));


}

void BruteForce::prepareToStart() {
    currentRoute.clear();
    bestRoute.clear();

    currentRoute.reserve(graph->getNumberOfCities());
    bestRoute.reserve(graph->getNumberOfCities());

    for (int i = 0; i < graph->getNumberOfCities(); i++) {
        currentRoute.push_back(i);
    }

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