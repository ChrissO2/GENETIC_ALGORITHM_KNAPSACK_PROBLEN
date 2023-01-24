#pragma once

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class CKnapsackProblem {
private:
    int itemsAmount;
    vector<double> sizes;
    vector<double> values;
    double knapsackSize;

    bool isDataValid(int itemsAmount, int knapsackSize, vector<double> sizes, vector<double> values);
public:
    CKnapsackProblem();
    CKnapsackProblem(vector<double> sizes, vector<double> values);
    CKnapsackProblem(int itemsAmount, const vector<double> &sizes, const vector<double> &values, double knapsackSize);

    int getNumberOfItems() const;
    double calculateFitness(const vector<int> &genotype);
    bool loadDataFile(string filePath);
};
