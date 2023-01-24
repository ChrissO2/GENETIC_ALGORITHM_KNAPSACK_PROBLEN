#include "CKnapsackProblem.h"


CKnapsackProblem::CKnapsackProblem() {
    items_amount = 0;
    knapsack_size = 0;
}

CKnapsackProblem::CKnapsackProblem(vector<double> new_sizes, vector<double> new_values) {
    int new_items_amount = new_sizes.size();
    double new_knapsack_size = 0;
    for (int i = 0; i < new_sizes.size(); i++) {
        new_knapsack_size += new_sizes[i];
    }
    if (is_data_correct(new_items_amount, new_knapsack_size, new_sizes, new_values)) {
        this->items_amount = new_items_amount;
        this->knapsack_size = new_knapsack_size;
        this->values = new_values;
        this->sizes = new_sizes;
    }
    else
        cerr << "CKnapsackProblem: Invalid input data\n";
}

CKnapsackProblem::CKnapsackProblem(int itemsAmount, const vector<double> &sizes,
                                   const vector<double> &values, double knapsackSize){
    if (is_data_correct(itemsAmount, knapsackSize, sizes, values)) {
        this->items_amount = itemsAmount;
        this->knapsack_size = knapsackSize;
        this->values = values;
        this->sizes = sizes;
    }
    else
        cerr << "CKnapsackProblem: Invalid input data\n";
}

int CKnapsackProblem::getNumberOfItems() const {
    return items_amount;
}

double CKnapsackProblem::calculateFitness(const vector<int> &genotype) {
    double genotype_size = 0;
    double genotype_value = 0;

    for (int i = 0; i < items_amount; i++) {
        if(genotype[i] == 1) {
            genotype_value += values[i];
            genotype_size += sizes[i];
        }
    }
    if (genotype_size <= knapsack_size)
        return genotype_value;
    return 0;
}

bool CKnapsackProblem::is_data_correct(int items_amount, int knapsack_size, vector<double> sizes, vector<double> values) {
    bool result = true;
    if (items_amount < 0 || items_amount != sizes.size() || items_amount < values.size())
        result = false;
    if (knapsack_size <= 0)
        result = false;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i] <= 0 || values[i] <= 0)
            result = false;
    }
    return result;
}



bool CKnapsackProblem::import_file(string file_name) {
    fstream file;
    int new_item_amount;
    double new_knapsack_size;
    vector<double> new_values;
    vector<double> new_sizes;
    try {
        file.open(file_name, ios::in);
        if (file.good()) {
            file >> new_item_amount;
            file >> new_knapsack_size;
            double line;
            while(!file.eof()) {
                file >> line;
                new_values.push_back(line);
                file >> line;
                new_sizes.push_back(line);
            }
        }
        file.close();
        if (is_data_correct(new_item_amount, new_knapsack_size, new_sizes, new_values)) {
            this->items_amount = new_item_amount;
            this->knapsack_size = new_knapsack_size;
            this->values = new_values;
            this->sizes = new_sizes;
            return true;
        }
        else
            cerr << "CKnapsackProblem::import_file: Invalid input data\n";

    } catch (exception &err) {
        cerr << "CKnapsackProblem::import_file: cannot read from file\n";
    }
    return false;
}
