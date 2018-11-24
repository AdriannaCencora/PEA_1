#include <iostream>
#include "MatrixGraph.h"
#include "FileHandler.h"

using namespace std;

int main() {

    auto matrixGraph = new MatrixGraph();
    char userChoice{};
    bool isRunning{true};

    while (isRunning) {
        cout << "MENU" << endl;
        cout << "Pick a number." << endl;
        cout << "1. Read data from file." << endl;
        cout << "2. Generate random data." << endl;
        cout << "3. Print graph matrix representation." << endl;
        cout << "4. Brute force algorithm." << endl;
        cout << "5. Branch and bound algorithm." << endl;
        cout << "6. Dynamic programming." << endl;
        cout << "0. Exit." << endl;

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
            }
            case '3': {
                matrixGraph->printMatrix();
                break;
            }

            case '0':
                isRunning = false;
                break;
            default:
                cout << "Wrooong number, choose better!" << endl << endl;
                break;
        }
    }


    delete matrixGraph;
    return 0;
}