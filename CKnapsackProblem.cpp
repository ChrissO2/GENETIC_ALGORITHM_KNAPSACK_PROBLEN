#include "CKnapsackProblem.h"


CKnapsackProblem::CKnapsackProblem() {
    itemsAmount = 0;
    knapsackSize = 0;
}


CKnapsackProblem::CKnapsackProblem(vector<double> sizes, vector<double> values) {
    int newItemsAmount = sizes.size();
    double newKnapsackSize = 0;
    for (int i = 0; i < sizes.size(); i++) {
        newKnapsackSize += sizes[i];
    }
    if (isDataValid(newItemsAmount, newKnapsackSize, sizes, values)) {
        this->itemsAmount = newItemsAmount;
        this->knapsackSize = newKnapsackSize;
        this->values = values;
        this->sizes = sizes;
    }
    else
        cerr << "CKnapsackProblem: Invalid input data\n";
}


CKnapsackProblem::CKnapsackProblem(int itemsAmount, const vector<double> &sizes,
                                   const vector<double> &values, double knapsackSize){
    if (isDataValid(itemsAmount, knapsackSize, sizes, values)) {
        this->itemsAmount = itemsAmount;
        this->knapsackSize = knapsackSize;
        this->values = values;
        this->sizes = sizes;
    }
    else {
//        cerr << "CKnapsackProblem: Invalid input data\n";
    }

}


int CKnapsackProblem::getNumberOfItems() {
    return itemsAmount;
}


double CKnapsackProblem::calculateFitness(const vector<int> &genotype) {
    double genotype_size = 0;
    double genotype_value = 0;

    for (int i = 0; i < itemsAmount; i++) {
        if(genotype[i] == 1) {
            genotype_value += values[i];
            genotype_size += sizes[i];
        }
    }
    if (genotype_size <= knapsackSize)
        return genotype_value;
    return 0;
}


bool CKnapsackProblem::isDataValid(int itemsAmount, int knapsackSize, vector<double> sizes, vector<double> values) {
    bool result = true;
    if (itemsAmount < 0 || itemsAmount != sizes.size() || itemsAmount < values.size())
        result = false;
    if (knapsackSize <= 0)
        result = false;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i] <= 0 || values[i] <= 0)
            result = false;
    }
    return result;
}


bool CKnapsackProblem::loadDataFile(const string &filePath) {
    fstream file;
    int newItemAmount;
    double newKnapsackSize;
    vector<double> newValues;
    vector<double> newSizes;
    try {
        file.open(filePath, ios::in);
        if (file.good()) {
            file >> newItemAmount;
            file >> newKnapsackSize;
            double line;
            while(!file.eof()) {
                file >> line;
                newValues.push_back(line);
                file >> line;
                newSizes.push_back(line);
            }
        }
        file.close();
        if (isDataValid(newItemAmount, newKnapsackSize, newSizes, newValues)) {
            this->itemsAmount = newItemAmount;
            this->knapsackSize = newKnapsackSize;
            this->values = newValues;
            this->sizes = newSizes;
            return true;
        }
//        else
//            cerr << "CKnapsackProblem::loadDataFile: Invalid input data\n";

    } catch (exception &err) {
//        cerr << "CKnapsackProblem::loadDataFile: No file found\n";
    }
    return false;
}


bool CKnapsackProblem::isReady() {
    return isDataValid(itemsAmount, knapsackSize, sizes, values);
}
