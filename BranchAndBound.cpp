//
// Created by adrianna on 26/11/18.
//

#include "BranchAndBound.h"
#include <stack>
#include <cfloat>

void BranchAndBound::run() {
        prepend();
     //   startTime = std::chrono::high_resolution_clock::now();
          calculateStartingLowerBound();
           DFS();
       // endTime = std::chrono::high_resolution_clock::now();
        //timeInMilliseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}


void BranchAndBound::prepend() {
    numberOfCities = graph->getNumberOfCities();

    if (numberOfCities < 2) {
        throw std::runtime_error("Matrix contains only one city!");
    }

    lowestDistancesToTowns.clear();
    lowestDistancesToTowns.resize(numberOfCities);
    initialRoot.visited.resize(numberOfCities, false);
    initialRoot.path.reserve(numberOfCities);
    initialRoot.path.push_back(startTown);
    initialRoot.visited[0] = true;
    initialRoot.value = INT32_MAX;

}

void BranchAndBound::calculateStartingLowerBound() {


    int tmpDistance{};

    for (unsigned i{0}; i < numberOfCities; ++i) {
        tmpDistance = graph->getMinDistanceTo(i);
        lowestDistancesToTowns[i].push_back(tmpDistance);
        currentLowerBound += tmpDistance;

        tmpDistance = graph->getMinDistanceFrom(i);
        lowestDistancesToTowns[i].push_back(tmpDistance);
        currentLowerBound += tmpDistance;
    }

    currentLowerBound = currentLowerBound / 2;
}
void BranchAndBound::DFS() {
    initialRoot.lowerBound = currentLowerBound;
    stackDFS.push(initialRoot);
    BnBNode child, current;

    do {
        current = stackDFS.top();
        stackDFS.pop();

        if (current.path.size() == numberOfCities) {    //Leaf.

            if (current.value < initialRoot.value) {
                initialRoot = current;
            }

            initialRoot.value = initialRoot.value + graph->getDistance(initialRoot.path.back(), initialRoot.path.front());
            initialRoot.path.push_back(current.path.front());
        }

        else { //not leaf
            for (unsigned int town{1}; town < numberOfCities; ++town) {
                if (current.visited[town] == false) {
                    child = current;
                    child.visited[town] = true;
                    if (child.path.size() == 1) {
                        child.lowerBound = child.lowerBound
                                           - (lowestDistancesToTowns[child.path.back()][1] + lowestDistancesToTowns[town][0]) / 2
                                           + graph->getDistance(child.path.back(), town);
                        child.value = graph->getDistance(child.path.back(), town);
                    }
                    else {
                        child.lowerBound = child.lowerBound
                                           - (lowestDistancesToTowns[child.path.back()][1] + lowestDistancesToTowns[town][0]) / 2
                                           + graph->getDistance(child.path.back(), town);
                        child.value = child.value + graph->getDistance(child.path.back(), town);
                    }

                    child.path.push_back(town);
                    if (child.lowerBound <= initialRoot.value)
                        stackDFS.push(child);


                }
            }
        }

    }  while (!stackDFS.empty());
}


void BranchAndBound::displayRouteDetails() {
    std::cout << "The best route is: ";
    for (auto &town : initialRoot.path) {
        std::cout << town <<" ";
    }

    std::cout << std::endl << "Distance: " << initialRoot.value << std::endl;
    std::cout << "Time of BranchAndBound algorithm: " << timeInMilliseconds << std::endl;


}