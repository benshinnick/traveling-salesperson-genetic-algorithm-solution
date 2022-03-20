#ifndef GENETIC_ALGORITHM_HPP
#define GENETIC_ALGORITHM_HPP

#include "tour.hpp"

#include <vector>

//TESTING
#include <iostream>
//TESTING

class GeneticAlgorithm {

    private:
        int numOfCities;
        int generationSize;
        int numGenerationsToRun;
        int numMutationsInGeneration;

        std::vector<Tour> currGeneration;
        Tour elite;

        void setInitialGeneration();
        void setNextGeneration();
        void updateElite();

    public:
        GeneticAlgorithm(int numCities, int genSize, int numGensToRun, float mutatedGenPercent);
        void runGeneticAlgorithm();
        double getLowestFoundTourCost();
        double getPercentOptimal(double optimalTourCost);
        Tour getElite();

        //TESTING
        void printCurrGeneration();
        //TESTING
};

#endif