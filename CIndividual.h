#pragma once

#include <vector>
#include <cstdlib>
#include <string>

#include "CapacityProblem.h"


using namespace std;

class CIndividual {
private:
    vector<int> genotype;
    CapacityProblem* problem;
    double fitness;

    void setFitness();
public:
    CIndividual();
    CIndividual(CapacityProblem *problem);
    CIndividual(const vector<int>& genotype, CapacityProblem *problem);
    CIndividual(const CIndividual& other);

    double getFitness() const;

    void mutate(double mut_prob);
    vector<CIndividual*> cross(CIndividual& other);
    string genotypeToString();



};
