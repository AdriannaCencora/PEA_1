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
         //  DFS();
    BeFS();
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
    best.visited.resize(numberOfCities, false);
    best.path.reserve(numberOfCities);
    best.path.push_back(startTown);
    best.visited[0] = true;
    best.value = INT32_MAX;

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

void BranchAndBound::BeFS() {
    best.lowerBound = currentLowerBound;
    containerBeFS.push(best);
    BnBNode current{}, child{};

    do {
        current = containerBeFS.top();
        containerBeFS.pop();

        if (current.path.size() == numberOfCities) {    //Leaf.

            if (current.value < best.value) {
                best = current;
            }

            best.value = best.value + graph->getDistance(best.path.back(), best.path.front());
            best.path.push_back(current.path.front());
        } else { //not leaf
            for (unsigned int town{1}; town < numberOfCities; ++town) {
                if (current.visited[town] == false) {
                    child = current;
                    child.visited[town] = true;
                    if (child.path.size() == 1) { //Level one.
                        child.lowerBound = child.lowerBound
                                           - (lowestDistancesToTowns[child.path.back()][1] +
                                              lowestDistancesToTowns[town][0]) / 2
                                           + graph->getDistance(child.path.back(), town);
                        child.value = graph->getDistance(child.path.back(), town);
                    } else {
                        child.lowerBound = child.lowerBound
                                           - (lowestDistancesToTowns[child.path.back()][1] +
                                              lowestDistancesToTowns[town][0]) / 2
                                           + graph->getDistance(child.path.back(), town);
                        child.value = child.value + graph->getDistance(child.path.back(), town);
                    }

                    child.path.push_back(town);
                    if (child.lowerBound <= best.value)
                        containerBeFS.push(child);


                }
            }


        }

    } while (!containerBeFS.empty());

}

void BranchAndBound::DFS() {
    best.lowerBound = currentLowerBound;
    containerDFS.push(best);
    BnBNode child, current;

    do {
        current = containerDFS.top();
        containerDFS.pop();

        if (current.path.size() == numberOfCities) {    //Leaf.

            if (current.value < best.value) {
                best = current;
            }

            best.value = best.value + graph->getDistance(best.path.back(), best.path.front());
            best.path.push_back(current.path.front());
        }

        else { //not leaf
            for (unsigned int town{1}; town < numberOfCities; ++town) {
                if (current.visited[town] == false) {
                    child = current;
                    child.visited[town] = true;
                    if (child.path.size() == 1) { //Level one.
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
                    if (child.lowerBound <= best.value)
                        containerDFS.push(child);


                }
            }
        }

    }  while (!containerDFS.empty());
}


void BranchAndBound::displayRouteDetails() {
    std::cout << "The best route is: ";
    for (auto &town : best.path) {
        std::cout << town <<" ";
    }

    std::cout << std::endl << "Distance: " << best.value << std::endl;
    std::cout << "Time of BranchAndBound algorithm: " << timeInMilliseconds << std::endl;


}