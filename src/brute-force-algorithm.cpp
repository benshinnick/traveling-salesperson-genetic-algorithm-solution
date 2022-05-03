#include "brute-force-algorithm.hpp"

int BruteForceAlgorithm::calculateFactorial(int n) {
    int factorial[n];
    factorial[0] = 1;
    for(int i = 1; i <= n; ++i) {
        factorial[i] = i * factorial[i-1];
    }
    return factorial[n];
}

BruteForceAlgorithm::BruteForceAlgorithm() {
    this->numOfCities = DEFAULT_NUM_CITIES;
    this->startEndCity = DEFAULT_START_END_CITY;
    this->optimalTour = Tour();
}

BruteForceAlgorithm::BruteForceAlgorithm(int numOfCities, int startEndCity) {
    this->numOfCities = numOfCities;
    this->startEndCity = startEndCity;
    this->optimalTour = Tour();
}

void BruteForceAlgorithm::runBruteForceAlgorithm() {
    Tour currTour = Tour(numOfCities, startEndCity);
    optimalTour = currTour;
    double optimalTourCost = optimalTour.getTourCost();

    int numOfPermutations = getNumPermuations();
    for(int i = 0; i < numOfPermutations - 1; ++i) {
        currTour.setToNextPermutedTour();
        double currTourCost = currTour.getTourCost();
        if(currTourCost < optimalTourCost) {
            optimalTour = currTour;
            optimalTourCost = currTourCost;
        }
    }
}

Tour BruteForceAlgorithm::getOptimalTour() {
    return optimalTour;
}

double BruteForceAlgorithm::getOptimalTourCost() {
    return optimalTour.getTourCost();
}

int BruteForceAlgorithm::getNumPermuations() {
    return calculateFactorial(numOfCities - 1);
}