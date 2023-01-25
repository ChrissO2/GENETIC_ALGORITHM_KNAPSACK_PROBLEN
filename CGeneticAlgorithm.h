#pragma once

#include <iostream>
#include <vector>

#include "CIndividual.h"
#include "CapacityProblem.h"


class CGeneticAlgorithm {
private:
    double mutProb;
    double crossProb;
    int popSize;
    CapacityProblem* problem;
    CIndividual* bestIndividual;
    int iterations;
    vector<CIndividual*> oldGeneration;
    vector<CIndividual*> newGeneration;

    bool isDataValid(double mutProb, double crossProb, int popSize, int iterations);
    void crossGeneration();
    void mutateGeneration();
    void findBestIndividual();
    void moveGeneration();
    CIndividual* chooseParent();
    void createFirstGeneration();



public:
    CGeneticAlgorithm();
    CGeneticAlgorithm(double mutProb, double crossProb, int popSize,
                      int iterations, CapacityProblem *problem);
    ~CGeneticAlgorithm();

    string getResult();
    void run();
};
