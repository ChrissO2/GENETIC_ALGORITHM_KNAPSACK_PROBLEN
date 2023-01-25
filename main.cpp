#include <iostream>
#include <cstdlib>

#include "CGeneticAlgorithm.h"
#include "CapacityProblem.h"
#include "CKnapsackProblem.h"

using namespace std;


void testValidFileData() {
    CKnapsackProblem problem;
    if (problem.loadDataFile("/Users/krzysztofotreba/CLionProjects/projekt_v2/data.txt")) {
        CGeneticAlgorithm geneticAlgorithm = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        geneticAlgorithm.run();
        cout << geneticAlgorithm.getResult() << endl;
    }
}


void testInvalidFileData() {
    CKnapsackProblem problem;
    if (problem.loadDataFile("/Users/krzysztofotreba/CLionProjects/projekt_v2/invaliddata1.txt")) {
        CGeneticAlgorithm geneticAlgorithm = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        geneticAlgorithm.run();
        cout << geneticAlgorithm.getResult() << endl;
    }
}


void testDataFromCode() {
    vector<double> sizes = {1, 2, 3, 4, 5};
    vector<double> values = {5, 2, 11, 2, 4};
    CKnapsackProblem problem(5, sizes, values, 4);
    if (problem.isReady()) {
        CGeneticAlgorithm geneticAlgorithm = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        geneticAlgorithm.run();
        cout << geneticAlgorithm.getResult() << endl;
    }
}

void testInvalidFilePath() {
    CKnapsackProblem problem;
    if (problem.loadDataFile("")) {
        CGeneticAlgorithm geneticAlgorithm = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        geneticAlgorithm.run();
        cout << geneticAlgorithm.getResult() << endl;
    }
}

void testInvalidDataFromCode() {
    vector<double> sizes = {1, 2, 3, 4};
    vector<double> values = {5, 2, 11, 2, 4};
    CKnapsackProblem problem(5, sizes, values, -4);
    if (problem.isReady()) {
        CGeneticAlgorithm geneticAlgorithm = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        geneticAlgorithm.run();
        cout << geneticAlgorithm.getResult() << endl;
    }
}



int main() {
    srand(time(NULL));
    testValidFileData();
    testInvalidFileData();
    testDataFromCode();
    testInvalidFilePath();
    testInvalidDataFromCode();
    return 0;
}
