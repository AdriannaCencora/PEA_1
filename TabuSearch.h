//
// Created by adrianna on 04/01/19.
//

#pragma once


#include "Algorithm.h"
#include <tuple>
class TabuSearch : public Algorithm {
public:

    TabuSearch(MatrixGraph *graph) :  Algorithm(graph) {}

    ~TabuSearch() {}

    //std::string showInfoBeforeRunning() override;

    void run() override;

    void displayRouteDetails() override;

private:
    void setDefaultParameters();

    bool isAspiration() const;
    bool isDiversification() const;

    int getCadency() const;
    double getTimeToBreakSearch() const;
    int getIterationsToChangeNeighborhood() const;

    void setCadency(int cadency);
    void setTimeToBreakSearch(double timeToBreakSearch);
    void setAspiration(bool aspiration);
    void setDiversification(bool diversification);
    void setIterationsToChangeNeighborhood(int iterationsToChangeNeighborhood);

private:
    int calculateRouteDistance(std::vector<int> &route);
    std::vector<int> generateRandomRoute();
    void prepareToRun();

    void generateStartRoute();

    std::tuple<int, int, int> enumerateNeighbourSolutions();

    void updateTabuList();

    std::string generateOutput() ;

    // city 1, city 2, cadency; blocks exchanging the pair of cities
    std::vector<std::tuple<int, int, int>> tabuList;

    int numberOfChecks;

    unsigned long numberOfCities;

    int startVertex;

    std::vector<int> currentRoute;
    int currentDistance;

    std::vector<int> bestRoute;
    int bestDistance;


    int cadency;
    double timeToBreakSearch;
    bool aspiration;
    bool diversification;
    int iterationsToChangeNeighborhood;

    int iterationWithoutImprovement;
};