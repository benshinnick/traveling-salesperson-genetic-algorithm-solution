#ifndef BRUTE_FORCE_ALGORITHM_HPP
#define BRUTE_FORCE_ALGORITHM_HPP

#include "tour.hpp"

class BruteForceAlgorithm {

    private:
        int numOfCities;
        int startEndCity;
        double optimalTourCost;
        int calculateFactorial(int n);

    public:
        BruteForceAlgorithm(int numOfCities, int startEndCity);
        void runBruteForceAlgorithm();
        double getOptimalTourCost();
};

#endif