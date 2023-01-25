#include <iostream>

#include "CGeneticAlgorithm.h"
#include "CapacityProblem.h"
#include "CKnapsackProblem.h"

using namespace std;


void testValidData() {
    srand(time(NULL));
    CKnapsackProblem problem;
    if (problem.loadDataFile("/Users/krzysztofotreba/CLionProjects/projekt_v2/data.txt")) {
        CGeneticAlgorithm geneticAlgorithm = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        geneticAlgorithm.run();
        cout << geneticAlgorithm.getResult() << endl;
    }
}


void testInvalidData() {
    srand(time(NULL));
    CKnapsackProblem problem;
    if (problem.loadDataFile("/Users/krzysztofotreba/CLionProjects/projekt_v2/invaliddata1.txt")) {
        CGeneticAlgorithm geneticAlgorithm = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        geneticAlgorithm.run();
        cout << geneticAlgorithm.getResult() << endl;
    }
}


void testInvalidFilePath() {
    srand(time(NULL));
    CKnapsackProblem problem;
    if (problem.loadDataFile("")) {
        CGeneticAlgorithm geneticAlgorithm = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        geneticAlgorithm.run();
        cout << geneticAlgorithm.getResult() << endl;
    }
}


int main() {
    testValidData();
    testInvalidData();
    testInvalidFilePath();
    return 0;
}
