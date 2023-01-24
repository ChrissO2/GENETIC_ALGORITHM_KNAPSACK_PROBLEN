#pragma once

#include <vector>
#include <cstdlib>
#include <string>

#include "CKnapsackProblem.h"

using namespace std;

class CIndividual {
private:
    vector<int> genotype;
    CKnapsackProblem* problem;
    double fitness;

    void setFitness();
public:
    CIndividual();
    CIndividual(CKnapsackProblem *problem);
    CIndividual(const vector<int>& genotype, CKnapsackProblem *problem);
    CIndividual(const CIndividual& other);

    double getFitness() const;

    void mutate(double mut_prob);
    vector<CIndividual*> cross(CIndividual& other);
    string genotypeToString();



};
