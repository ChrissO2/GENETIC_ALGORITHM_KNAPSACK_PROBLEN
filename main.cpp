#include <iostream>

#include "CGeneticAlgorithm.h"

using namespace std;

void test() {
    srand(time(NULL));
    CKnapsackProblem problem;
    if (problem.loadDataFile("/Users/krzysztofotreba/CLionProjects/projekt_v2/data.txt")) {
        CGeneticAlgorithm ag = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        ag.run();
        cout << ag.getResult() << endl;
    }
}

void test_invalid_data() {
    srand(time(NULL));
    CKnapsackProblem problem;
    if (problem.loadDataFile("/Users/krzysztofotreba/CLionProjects/projekt_v2/invaliddata1.txt")) {
        CGeneticAlgorithm ag = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        ag.run();
        cout << ag.getResult() << endl;
    }
}

int main() {
    test();
    test_invalid_data();
    return 0;
}
