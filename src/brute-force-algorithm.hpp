#ifndef BRUTE_FORCE_ALGORITHM_HPP
#define BRUTE_FORCE_ALGORITHM_HPP

#include "tour.hpp"

class BruteForceAlgorithm {

    private:
        int numOfCities;
        int currPermuation[MAX_TOUR_SIZE - 2];
        double lowestTourCost;
        // Tour currTour; // should only need in runBruteForceAlgorithm()

        void getNextPermuation();
        void getNextTour();

    public:
        BruteForceAlgorithm(int numOfCities);
        void runBruteFoceAlgorithm();
        double getLowestFoundTourCost();
};

#endif