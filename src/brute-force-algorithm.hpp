#ifndef BRUTE_FORCE_ALGORITHM_HPP
#define BRUTE_FORCE_ALGORITHM_HPP

#include "tour.hpp"

class BruteForceAlgorithm {

    private:
        int numOfCities;
        double optimalTourCost;
        int calculateFactorial(int n);

    public:
        BruteForceAlgorithm(int numOfCities);
        void runBruteForceAlgorithm();
        double getOptimalTourCost();
};

#endif