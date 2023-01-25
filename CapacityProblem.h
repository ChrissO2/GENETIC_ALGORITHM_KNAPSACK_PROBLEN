#pragma once

#include <iostream>

using namespace std;

class CapacityProblem {
public:
    virtual int getNumberOfItems() = 0;
    virtual bool loadDataFile(const string& filePath) = 0;
    virtual double calculateFitness(const vector<int> &genotype) = 0;
    virtual bool isReady() = 0;
};
