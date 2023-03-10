#include "CIndividual.h"


CIndividual::CIndividual() {
    problem = NULL;
    fitness = 0;
}


CIndividual::CIndividual(CapacityProblem *problem) {
    this->problem = problem;
    for (int i = 0; i < problem->getNumberOfItems(); i++) {
        if (rand() % 2 == 0)
            genotype.push_back(1);
        else
            genotype.push_back(0);
    }
    setFitness();
}


CIndividual::CIndividual(const vector<int>& genotype, CapacityProblem *problem) {
    this->genotype = genotype;
    this->problem = problem;
    setFitness();
}


CIndividual::CIndividual(const CIndividual &other) {
    problem = other.problem;
    fitness = other.fitness;
    genotype = vector<int>(other.genotype);
}


void CIndividual::setFitness() {
    fitness = problem->calculateFitness(genotype);
}


double CIndividual::getFitness() const {
    return fitness;
}


void CIndividual::mutate(double mut_prob) {
    for (int i = 0; i < genotype.size(); i++) {
        if ((double)rand() / (double)RAND_MAX <= mut_prob) {
            if (genotype[i] == 1)
                genotype[i] = 0;
            else
                genotype[i] = 1;
        }
    }
    setFitness();
}


pair<CIndividual*, CIndividual*> CIndividual::cross(CIndividual &other) {
    pair<CIndividual*, CIndividual*> children;
    int slice_index = 1 + (rand() % (genotype.size() - 1));
    vector<int> child1_genotype;
    vector<int> child2_genotype;
    for (int i = 0; i < slice_index; i++) {
        child1_genotype.push_back(genotype[i]);
        child2_genotype.push_back(other.genotype[i]);
    }
    for (int i = slice_index; i < genotype.size(); i++) {
        child1_genotype.push_back(other.genotype[i]);
        child2_genotype.push_back(genotype[i]);
    }
    children.first = new CIndividual(child1_genotype, problem);
    children.second = new CIndividual(child2_genotype, problem);

    return children;
}


string CIndividual::genotypeToString() {
    string result = "";
    for (int i = 0; i < genotype.size(); i++) {
        result += to_string(genotype[i]);
    }
    return result;
}
