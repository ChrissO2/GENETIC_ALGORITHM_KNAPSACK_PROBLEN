cmake_minimum_required(VERSION 3.23)
project(projekt_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(projekt_v2 main.cpp CIndividual.cpp CIndividual.h CKnapsackProblem.cpp CKnapsackProblem.h CGeneticAlgorithm.cpp CGeneticAlgorithm.h CapacityProblem.cpp CapacityProblem.h GeneticAlgorithmDefValues.h)
