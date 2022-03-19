#ifndef BRUTE_FORCE_ALGORITHM_HPP
#define BRUTE_FORCE_ALGORITHM_HPP

#include "tour.hpp"

class BruteForceAlgorithm {

    private:
        int numOfCities;
        double lowestTourCost;
        int calculateFactorial(int n);

    public:
        BruteForceAlgorithm(int numOfCities);
        void runBruteFoceAlgorithm();
        double getLowestFoundTourCost();
};

#endif