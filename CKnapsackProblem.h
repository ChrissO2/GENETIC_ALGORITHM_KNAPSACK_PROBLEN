#pragma once

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class CKnapsackProblem {
private:
    int items_amount;
    vector<double> sizes;
    vector<double> values;
    double knapsack_size;

    bool is_data_correct(int items_amount, int knapsack_size, vector<double> sizes, vector<double> values);
public:
    CKnapsackProblem();
    CKnapsackProblem(vector<double> new_sizes, vector<double> new_values);
    CKnapsackProblem(int itemsAmount, const vector<double> &sizes, const vector<double> &values, double knapsackSize);

    int getNumberOfItems() const;
    double calculateFitness(const vector<int> &genotype);
    bool import_file(string file_name);
};
