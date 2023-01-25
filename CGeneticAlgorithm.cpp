#include "CGeneticAlgorithm.h"


CGeneticAlgorithm::CGeneticAlgorithm() {
    popSize = DEF_POP_SIZE;
    mutProb = DEF_MUT_PROB;
    crossProb = DEF_CROSS_PROB;
    iterations = DEF_ITERATIONS;
    problem = NULL;
    bestIndividual = NULL;
}


CGeneticAlgorithm::CGeneticAlgorithm(double mutProb, double crossProb, int popSize,
                                     int iterations, CapacityProblem *problem){
    if (isDataValid(mutProb, crossProb, popSize, iterations)) {
        this->mutProb = mutProb;
        this->crossProb = crossProb;
        this->popSize = popSize;
        this->iterations = iterations;
    }
    else {
        this->mutProb = DEF_MUT_PROB;
        this->crossProb = DEF_CROSS_PROB;
        this->popSize = DEF_POP_SIZE;
        this->iterations = DEF_ITERATIONS;
        cerr << "CGeneticAlgorithm: Invalid data\n";
    }
    this->problem = problem;
    this->bestIndividual = NULL;
}


CGeneticAlgorithm::~CGeneticAlgorithm() {
    if (bestIndividual != NULL)
        delete bestIndividual;
    for (int i = oldGeneration.size() - 1; i >= 0; i--) {
        if (oldGeneration[i] != NULL)
            delete oldGeneration[i];
        if (newGeneration[i] != NULL)
            delete newGeneration[i];
    }
}


bool CGeneticAlgorithm::isDataValid(double mutProb, double crossProb, int popSize, int iterations) {
    bool result = true;
    if (mutProb < 0 || mutProb > 1)
        result = false;
    if (crossProb < 0 || crossProb > 1)
        result = false;
    if (popSize < 2)
        result = false;
    if (iterations < 1)
        return false;
    return result;
}


string CGeneticAlgorithm::getResult() {
    string result = "";
    if (bestIndividual != NULL)
        result = bestIndividual->genotypeToString();
    return result;
}

CIndividual *CGeneticAlgorithm::chooseParent() {
    int parent1Index = rand() % popSize;
    int parent2Index = rand() % popSize;
    while (parent2Index == parent1Index) {
        parent2Index = rand() % popSize;
    }
    if (oldGeneration[parent1Index]->getFitness() > oldGeneration[parent2Index]->getFitness())
        return oldGeneration[parent1Index];
    return oldGeneration[parent2Index];
}

void CGeneticAlgorithm::mutateGeneration() {
    for (int i = 0; i < newGeneration.size(); i++) {
        newGeneration[i]->mutate(mutProb);
    }
}

void CGeneticAlgorithm::crossGeneration() {
    while (newGeneration.size() < popSize) {
        CIndividual* parent1 = chooseParent();
        CIndividual* parent2 = chooseParent();
        vector<CIndividual*> children = parent1->cross(*parent2);
        newGeneration.push_back(children[0]);
        if (newGeneration.size() < popSize)
            newGeneration.push_back(children[1]);
    }
}

void CGeneticAlgorithm::findBestIndividual() {
    if (bestIndividual == NULL)
        bestIndividual = new CIndividual(*oldGeneration[0]);
    for (int i = 0; i < oldGeneration.size(); i++) {
        if (oldGeneration[i]->getFitness() > bestIndividual->getFitness()) {
            delete bestIndividual;
            bestIndividual = new CIndividual(*oldGeneration[i]);
        }
    }
}


void CGeneticAlgorithm::run() {
    createFirstGeneration();
    findBestIndividual();
    int iteration = 1;
    while (iteration < iterations) {
        crossGeneration();
        mutateGeneration();
        moveGeneration();
        findBestIndividual();
        iteration++;
    }
}

void CGeneticAlgorithm::createFirstGeneration() {
    for (int i = 0; i < popSize; i++) {
        oldGeneration.push_back(new CIndividual(problem));
    }
}

void CGeneticAlgorithm::moveGeneration() {
    for (int i = 0; i < oldGeneration.size(); i++) {
        delete oldGeneration[i];
        oldGeneration[i] = newGeneration[i];
        newGeneration[i] = NULL;
    }
    newGeneration.clear();
}
