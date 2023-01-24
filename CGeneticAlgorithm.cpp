#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm() {
    popSize = 0;
    mutProb = 0;
    crossProb = 0;
    iterations = 0;
    problem = NULL;
    bestIndividual = NULL;
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    if (bestIndividual != NULL)
        delete bestIndividual;
    for (int i = generation.size() - 1; i >= 0; i--) {
        if (generation[i] != NULL)
            delete generation[i];
    }
}

CGeneticAlgorithm::CGeneticAlgorithm(double mutProb, double crossProb, int popSize,
                                     int iterations, CKnapsackProblem *problem){
    if (isDataValid(mutProb, crossProb, popSize, iterations)) {
        this->mutProb = mutProb;
        this->crossProb = crossProb;
        this->popSize = popSize;
        this->iterations = iterations;
    }
    else {
        this->mutProb = 0;
        this->crossProb = 0;
        this->popSize = 0;
        this->iterations = 0;
        cerr << "CGeneticAlgorithm: Invalid data\n";
    }
    this->problem = problem;
    this->bestIndividual = NULL;
}


string CGeneticAlgorithm::getResult() {
    string result = "";
    if (bestIndividual != NULL)
        result = bestIndividual->genotype_to_string();
    return result;
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

bool CGeneticAlgorithm::createFirstGeneration() {
    bool result = false;
    if (problem != NULL && generation.empty()) {
        for (int i = 0; i < popSize; i++) {
            generation.push_back(new CIndividual(problem));
        }
        result =  true;
        bestIndividual = new CIndividual(*findBestIndividual());
    }
    return result;
}

void CGeneticAlgorithm::createNextGeneration() {
    vector<CIndividual*> nextGen;
    while(nextGen.size() < popSize) {
        int parent1Index = rand() % (generation.size());
        int parent2Index = rand() % (generation.size());
        while(parent2Index == parent1Index) {
            parent2Index = rand() % (generation.size());
        }
        CIndividual* parent1 = generation[parent1Index];
        CIndividual* parent2 = generation[parent2Index];
        if ((double)rand() / (double)RAND_MAX <= crossProb) {
            vector<CIndividual*> children = parent1->cross(*parent2);
            nextGen.push_back(children[0]);
            if (nextGen.size() < popSize) {
                nextGen.push_back(children[1]);
            }
        }
        else {
            if (parent1->getFitness() > parent2->getFitness()) {
                nextGen.push_back(new CIndividual(*parent1));
                if (nextGen.size() < popSize)
                    nextGen.push_back(new CIndividual(*parent2));
            }
            else {
                nextGen.push_back(new CIndividual(*parent2));
                if (nextGen.size() < popSize)
                    nextGen.push_back(new CIndividual(*parent1));
            }
        }
    }
    for (int i = generation.size() - 1; i >= 0; i--) {
        if (generation[i] != NULL)
            delete generation[i];
    }
    generation.clear();
    for (int i = 0; i < nextGen.size(); i++) {
        generation.push_back(nextGen[i]);
    }
}


CIndividual* CGeneticAlgorithm::findBestIndividual() {
    CIndividual* best = generation[0];
    for (int i = 0; i < generation.size(); i++) {
        if (generation[i]->getFitness() > best->getFitness())
            best = generation[i];
    }
    return best;
}

void CGeneticAlgorithm::mutateGeneration() {
    for (int i = 0; i < generation.size(); i++) {
        generation[i]->mutate(mutProb);
    }
}

void CGeneticAlgorithm::run() {
    int iteration = 1;
    if (createFirstGeneration()) {
        while (iteration < iterations) {
            createNextGeneration();
            mutateGeneration();
            CIndividual* bestInGeneration = findBestIndividual();
            if (bestInGeneration->getFitness() > bestIndividual->getFitness()) {
                if (bestIndividual != NULL)
                    delete bestIndividual;
                bestIndividual = new CIndividual(*bestInGeneration);
                bestInGeneration = NULL;
            }
            iteration++;
        }
    }
}

