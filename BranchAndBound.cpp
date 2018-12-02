//
// Created by adrianna on 26/11/18.
//

#include "BranchAndBound.h"

void BranchAndBound::run() {
    prepend();
    startTime = std::chrono::high_resolution_clock::now();
    generateSolution(startTown);
    endTime = std::chrono::high_resolution_clock::now();
    timeInMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    displayRouteDetails();
}
void generateSolution(int startTown) {

}
void BranchAndBound::prepend() {

}