#pragma once

#include <iostream>
#include <vector>

#include "CIndividual.h"
#include "CKnapsackProblem.h"


class CGeneticAlgorithm {
private:
    double mutProb;
    double crossProb;
    int popSize;
    CKnapsackProblem* problem;
    CIndividual* bestIndividual;
    int iterations;
    vector<CIndividual*> generation;

    bool isDataValid(double mutProb, double crossProb, int popSize, int iterations);
    bool createFirstGeneration();
    void createNextGeneration();
    CIndividual* findBestIndividual();
    void mutateGeneration();

public:
    CGeneticAlgorithm();
    CGeneticAlgorithm(double mutProb, double crossProb, int popSize,
                      int iterations, CKnapsackProblem *problem);
    ~CGeneticAlgorithm();

    string getResult();
    void run();
};
