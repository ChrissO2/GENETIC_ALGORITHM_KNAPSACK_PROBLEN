//
// Created by Krzysztof Otręba on 24/01/2023.
//

#ifndef PROJEKT_V2_CINDIVIDUAL_H
#define PROJEKT_V2_CINDIVIDUAL_H

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
    CIndividual(CKnapsackProblem *newProblem);
    CIndividual(const vector<int>& genotype, CKnapsackProblem *problem);

    double getFitness() const;

    void mutate(double mut_prob);
    vector<CIndividual*> cross(CIndividual& other);
    string genotype_to_string();



};


#endif //PROJEKT_V2_CINDIVIDUAL_H
