//
// Created by adrianna on 26/11/18.
//

#include "BranchAndBound.h"


//void BranchAndBound::prepend() {
//    BruteForce::prepend();
//    calculateStartingLowerBound();
//}
//
//void BranchAndBound::calculateStartingLowerBound() {
//    lowestDistancesToVertices.clear();
//    lowestDistancesToVertices.resize(numberOfCities);
//
//    int tmp{};
//
//    for (int i{0}; i < numberOfCities; ++i) {
//        tmp = graph->getMinDistanceTo(i);
//        lowestDistancesToVertices[i].push_back(tmp);
//        currentLowerBound += tmp;
//
//        tmp = graph->getMinDistanceFrom(i);
//        lowestDistancesToVertices[i].push_back(tmp);
//        currentLowerBound += tmp;
//    }
//
//    currentLowerBound = currentLowerBound / 2;
//}
//
//void BranchAndBound::handleTheRoute(int currentTown) {
//    int distanceToNext{};
//
//    for (unsigned  nextTown{0}; nextTown< numberOfCities; ++nextTown) {
//        if (!visitedTowns[nextTown]) {
//            distanceToNext = graph->getDistance(currentTown, nextTown);
//
//            if (distanceToNext < 0) {
//                continue;
//            }
//            int tmpLowerBound = currentLowerBound;
//            currentLowerBound -= (lowestDistancesToVertices[currentTown][1] + lowestDistancesToVertices[nextTown][0]) / 2;
//            currentDistance += distanceToNext;
//
//            if (currentDistance + currentLowerBound < bestDistance) {
//                generateSolution(nextTown);
//            }
//
//            currentDistance -= distanceToNext;
//            currentLowerBound = tmpLowerBound;
//        }
//    }
//}

//void BranchAndBound::displayRouteDetails() {
//    std::cout << "Current best route is: ";
//    for (const auto &currentTown: bestRoute) {
//        std::cout << currentTown << "  ";
//
//    }
//    std::cout << std::endl << "Distance: " << bestDistance << std::endl;
//    std::cout << "Number of checks: " << numberOfChecks << std::endl;
//    std::cout << "Time of BranchAndBound algorithm: " << timeInMilliseconds << std::endl;
//
//
//}