#include "tour.hpp"

double Tour::calculateTourCost() {
    double totalCost = 0;
    for(int i = 0; i < numCitiesInTour; ++i) {
        int departureCity = tourCities[i];
        int arrivalCity = tourCities[i+1];
        totalCost += CityDistances::getInst().getDistance(departureCity, arrivalCity);
    }
    return totalCost;
}

void Tour::createThisTourFromPermutationOrMutation(int* permutationOrMutation) {
    int startingIndex = 0;
    int endingIndex = numCitiesInTour;

    tourCities[startingIndex] = START_AND_END_CITY;
    for(int i = 1; i < numCitiesInTour; ++i) {
        tourCities[i] = permutationOrMutation[i-1];
    }
    tourCities[endingIndex] = START_AND_END_CITY;
}

int* Tour::getCurrPermutationOrMutation() {
    int currPermuationOrMutation[MAX_TOUR_SIZE - 2];
    for(int i = 0; i < numCitiesInTour; ++i) {
        currPermuationOrMutation[i] = tourCities[i+1];
    }
    return currPermuationOrMutation;
}

int* Tour::getNextPermutation() {
    int* nextPermuation = getCurrPermutationOrMutation();
    const int NUM_ELEMENTS = numCitiesInTour - 1;

    int m = NUM_ELEMENTS - 2;
    while(nextPermuation[m] > nextPermuation[m+1])
        m = m - 1;

    int k = NUM_ELEMENTS - 1;
    while(nextPermuation[m] > nextPermuation[k])
        k = k - 1;

    swap(nextPermuation, m, k);
    int p = m + 1;
    int q = NUM_ELEMENTS - 1;
    while(p < q) {
        swap(nextPermuation, p, q);
        p++;
        q--;
    }

    return nextPermuation;
}

int* Tour::getNewMutation() {
    // TODO
    return getCurrPermutationOrMutation();
}

void Tour::swap(int* array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

Tour::Tour(int* permutationOrMutation, int numCitiesInTour) {
    this->numCitiesInTour = numCitiesInTour;
    createThisTourFromPermutationOrMutation(permutationOrMutation);
}

double Tour::getTourCost() {
    return calculateTourCost();
}

Tour Tour::getNextPermutedTour() {
    return Tour(getNextPermutation(), numCitiesInTour);
}

void Tour::setToNextPermutedTour() {
    createThisTourFromPermutationOrMutation(getNextPermutation());
}

Tour Tour::getNewMutatedTour() {
    return Tour(getNewMutation(), numCitiesInTour);
}

void Tour::setToNewMutatedTour() {
    createThisTourFromPermutationOrMutation(getNewMutation());
}

void Tour::setTourCity(int cityIndex, int city) {
    tourCities[cityIndex] = city;
}

int Tour::getTourCity(int cityIndex) {
    return tourCities[cityIndex];
}

void Tour::setNumCitiesInTour(int numCitiesInTour) {
    this->numCitiesInTour = numCitiesInTour;
}

int Tour::getNumCitiesInTour() {
    return numCitiesInTour;
}

//TESTING
void Tour::printPermutationOrMuation() {
    int* permutationOrMutation = getCurrPermutationOrMutation();
    for(int i = 0; i < numCitiesInTour - 1; ++i) {
        std::cout << permutationOrMutation[i] << " ";
    }
    std::cout << std::endl;
}
//TESTING