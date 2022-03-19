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
    this->lowestTourCost = -1;
}

void BruteForceAlgorithm::runBruteFoceAlgorithm() {
    Tour currTour = Tour(numOfCities);
    lowestTourCost = currTour.getTourCost();
    int numOfPermutations = calculateFactorial(numOfCities - 1);
    for(int i = 0; i < numOfPermutations - 1; ++i) {
        currTour.setToNextPermutedTour();
        double currTourCost = currTour.getTourCost();
        if(currTourCost < lowestTourCost) lowestTourCost = currTourCost;
    }
}

double BruteForceAlgorithm::getLowestFoundTourCost() {
    return lowestTourCost;
}