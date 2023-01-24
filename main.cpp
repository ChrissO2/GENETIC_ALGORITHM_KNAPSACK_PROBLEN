#include <iostream>

#include "CGeneticAlgorithm.h"
#include "CKnapsackProblem.h"
#include "CIndividual.h"

using namespace std;

void test() {
    srand(time(NULL));
    CKnapsackProblem problem;
    if (problem.import_file("/Users/krzysztofotreba/CLionProjects/projekt_v2/data.txt")) {
        CGeneticAlgorithm ag = CGeneticAlgorithm(0.1, 0.5, 4, 10, &problem);
        ag.run();
        cout << ag.getResult() << endl;
    }
}

void test_invalid_data() {
    srand(time(NULL));
    CKnapsackProblem problem;
    if (problem.import_file("/Users/krzysztofotreba/CLionProjects/projekt_v2/invaliddata1.txt")) {
        CGeneticAlgorithm ag = CGeneticAlgorithm(0.1, 0.5, 10, 50, &problem);
        ag.run();
        cout << ag.getResult() << endl;
    }
}

void test_errors(){
    srand(time(NULL));
    CKnapsackProblem problem;
    if (problem.import_file("/Users/krzysztofotreba/CLionProjects/projekt_v2/data.txt")) {
        vector<int> g1 = {0, 1, 1, 0};
        vector<int> g2 = {0, 1, 0, 1};
        vector<int> g3 = {1, 1, 1, 0};
        vector<int> g4 = {1, 1, 1, 0};
        CIndividual c1(g1, &problem);
        CIndividual c2(g2, &problem);
        CIndividual c3(g3, &problem);
        CIndividual c4(g4, &problem);
        vector<CIndividual> v = {c1, c2, c3 ,c4};
        CGeneticAlgorithm ag = CGeneticAlgorithm(0.1, 0.5, 4, 10, &problem, v);
        ag.run2();
        cout << ag.getResult() << endl;
    }
}

int main() {
//    test();
//    test_invalid_data();
    test_errors();
    return 0;
}


// infinite loop
//0001
//1001
//1000
//1101

// red error after
//1011
//0110
//1011
//1011

// red error before
//0110
//0101
//1110
//1110

// code 139
//0000
//0111
//1111
//1101