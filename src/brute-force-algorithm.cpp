#include "brute-force-algorithm.hpp"

int BruteForceAlgorithm::calculateFactorial(int n) {
    int factorial[n];
    factorial[0] = 1;
    for(int i = 1; i <= n; ++i) {
        factorial[i] = i * factorial[i-1];
    }
    return factorial[n];
}

BruteForceAlgorithm::BruteForceAlgorithm(int numOfCities) {
    this->numOfCities = numOfCities;
    this->optimalTourCost = -1;
}

void BruteForceAlgorithm::runBruteForceAlgorithm() {
    Tour currTour = Tour(numOfCities);
    optimalTourCost = currTour.getTourCost();
    int numOfPermutations = calculateFactorial(numOfCities - 1);
    for(int i = 0; i < numOfPermutations - 1; ++i) {
        currTour.setToNextPermutedTour();
        double currTourCost = currTour.getTourCost();
        if(currTourCost < optimalTourCost) optimalTourCost = currTourCost;
    }
}

double BruteForceAlgorithm::getOptimalTourCost() {
    return optimalTourCost;
}