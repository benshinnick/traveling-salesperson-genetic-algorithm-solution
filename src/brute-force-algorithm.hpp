#ifndef BRUTE_FORCE_ALGORITHM_HPP
#define BRUTE_FORCE_ALGORITHM_HPP

#include "tour.hpp"

class BruteForceAlgorithm {

    private:
        int numOfCities;
        int currPermuation[MAX_PERMUTATION_SIZE];
        double lowestTourCost;
        // Tour currTour; // only need runBruteForceAlgorithm()

        void getNextPermuation();
        void getNextTour();

    public:
        BruteForceAlgorithm(int numOfCities);
        void runBruteFoceAlgorithm();
        double getLowestFoundTourCost();
};

#endif