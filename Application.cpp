//
// Created by adrianna on 27/11/18.
//

#include <chrono>
#include "Application.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
#include "DynamicProgramming.h"

using namespace std;

void Application::displayMenu() {
    cout << "MENU" << endl;
    cout << "Pick a number." << endl;
    cout << "1. Read data from file." << endl;
    cout << "2. Generate random data." << endl;
    cout << "3. Print graph matrix representation." << endl;
    cout << "4. Brute force algorithm." << endl;
    cout << "5. Branch and bound algorithm." << endl;
    cout << "6. Dynamic programming." << endl;
    cout << "0. Exit." << endl;

}

void Application::run() {
    while (isRunning) {
        displayMenu();

        cin >> userChoice;

        switch (userChoice) {
            case '1': {
                std::string fileName;
                std::cout << "Filename: " << std::endl;
                cin >> fileName;
                auto fileHandler = new FileHandler(fileName);
                fileHandler->readDataFromFile(matrixGraph);
                cout << "Number of cities: " << matrixGraph->getNumberOfCities() << endl;
                delete fileHandler;
                break;
            }
            case '2': {
                int sizeOfMatrix{};
                std::cout << "Number of cities: " << std::endl;
                std::cin >> sizeOfMatrix;
                matrixGraph->setNumberOfCities(sizeOfMatrix);
                matrixGraph->fillMatrixWithRandomData();
                break;
            }
            case '3': {
                matrixGraph->printMatrix();
                break;
            }
            case '4': {
                algorithm = new BruteForce(matrixGraph);
                algorithm->run();
                break;
            }
            case '5': {
                algorithm = new BranchAndBound(matrixGraph);
                algorithm->run();
                break;
            }
            case '6': {
                algorithm = new DynamicProgramming(matrixGraph);
                algorithm->run();
                break;
            }
            case '0':
                isRunning = false;
                break;
            default:
                cout << "Wrooong number, next time choose better!" << endl << endl;
                break;
        }

    }


    delete matrixGraph;
    delete algorithm;
}

