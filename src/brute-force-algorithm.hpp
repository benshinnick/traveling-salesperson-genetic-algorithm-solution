#ifndef BRUTE_FORCE_ALGORITHM_HPP
#define BRUTE_FORCE_ALGORITHM_HPP

#include "tour.hpp"

class BruteForceAlgorithm {

    private:
        int numOfCities;
        float lowestTourCost;
        // Tour currTour; // should only need in runBruteForceAlgorithm()

    public:
        BruteForceAlgorithm(int numOfCities);
        void runBruteFoceAlgorithm();
        float getLowestFoundTourCost();
};

#endif