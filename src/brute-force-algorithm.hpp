#ifndef BRUTE_FORCE_ALGORITHM_HPP
#define BRUTE_FORCE_ALGORITHM_HPP

#include "tour.hpp"

class BruteForceAlgorithm {

    static const int MAX_PERMUTATION_SIZE = 19;

    private:
        int numOfCities;
        int currPermuation[MAX_PERMUTATION_SIZE];
        double lowestTourCost;
        // Tour currTour; // probably only need in runBruteForce

        void getNextPermuation();
        void getNextTour();

    public:
        BruteForceAlgorithm(int numOfCities);
        void runBruteFoceAlgorithm();
        double getLowestFoundTourCost();
};

#endif