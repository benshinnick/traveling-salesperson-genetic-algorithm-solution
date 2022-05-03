#ifndef GENETIC_ALGORITHM_HPP
#define GENETIC_ALGORITHM_HPP

#include "tour.hpp"
#include "default-constants.hpp"

#include <vector>

class GeneticAlgorithm {

    private:
        int numOfCities;
        int startEndCity;
        int generationSize;
        int numGenerationsToRun;
        int numMutationsInGeneration;

        std::vector<Tour> currGeneration;
        Tour elite;

        void setInitialGeneration();
        void setNextGeneration();
        void updateElite();

    public:
        GeneticAlgorithm();
        GeneticAlgorithm(int numCities, int startEndCity, int genSize, int numGensToRun, float mutatedGenPercent);
        void runGeneticAlgorithm();
        double getLowestFoundTourCost();
        double getPercentOptimal(double optimalTourCost);
        Tour getElite();
};

#endif