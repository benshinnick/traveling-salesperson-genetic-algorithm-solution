#include "tour.hpp"

// Helper Functions

double Tour::calculateTourCost() {
    double totalCost = 0;
    for(int i = 0; i < numCitiesInTour; ++i) {
        int departureCity = tourCities[i];
        int arrivalCity = tourCities[i+1];
        totalCost += CityDistances::getInst().getDistance(departureCity, arrivalCity);
    }
    return totalCost;
}

void Tour::createThisTourFromPermutationOrMutation(int permutationOrMutation[]) {
    int startingIndex = 0, endingIndex = numCitiesInTour;

    tourCities[startingIndex] = startEndCity;
    for(int i = 1; i < numCitiesInTour; ++i) {
        tourCities[i] = permutationOrMutation[i-1];
    }
    tourCities[endingIndex] = startEndCity;
}

void Tour::setToDefaultTour() {
    int startingIndex = 0, endingIndex = numCitiesInTour;

    tourCities[startingIndex] = startEndCity;
    int currCity = 0;
    for(int i = 1; i < numCitiesInTour; ++i) {
        if(currCity == startEndCity) currCity++;
        tourCities[i] = currCity;
        currCity++;
    }
    tourCities[endingIndex] = startEndCity;
}

void Tour::setArrayToCurrPermutationOrMutation(int array[]) {
    for(int i = 0; i < numCitiesInTour; ++i) {
        array[i] = tourCities[i+1];
    }
}

void Tour::setArrayToNextPermutation(int array[]) {
    setArrayToCurrPermutationOrMutation(array);

    const int NUM_ELEMENTS = numCitiesInTour - 1;

    int m = NUM_ELEMENTS - 2;
    while(array[m] > array[m+1]) m--;

    int k = NUM_ELEMENTS - 1;
    while(array[m] > array[k]) k--;

    // permutations like 4,3,2,1 might dip into negative indexes
    if(m >= 0 && k >= 0) swap(array, m, k);
    int p = m + 1;
    int q = NUM_ELEMENTS - 1;
    while(p < q) {
        // permutations like 4,3,2,1 might dip into negative indexes
        if(p >= 0 && q >= 0) swap(array, p, q);
        p++;
        q--;
    }
}

void Tour::setArrayToNewMutation(int array[], int numOfMutationSwaps) {
    setArrayToCurrPermutationOrMutation(array);

    const int MUTATION_SIZE = numCitiesInTour - 1;

    int minIndex = 0;
    int midIndex = MUTATION_SIZE / 2;
    int maxIndex = MUTATION_SIZE - 1;

    for(int i = 0; i < numOfMutationSwaps; ++i) {
        if(i % 2 == 0) {
            // swap city from first half with any other city in the tour
            swap(
                array,
                getRandomIntInRange(minIndex, midIndex),
                getRandomIntInRange(minIndex, maxIndex)
            );
        }
        if(i % 3 == 0) {
            // swap city from first half with a city from last half of the tour
            swap(
                array,
                getRandomIntInRange(minIndex, midIndex),
                getRandomIntInRange(midIndex+1, maxIndex)
            );
        }
        else {
            // swap two values in the first half of the tour
            swap(
                array,
                getRandomIntInRange(minIndex, midIndex),
                getRandomIntInRange(minIndex, midIndex)
            );
        }
    }
}

void Tour::swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int Tour::getRandomIntInRange(int min, int max) {
    std::uniform_int_distribution<> distr(min, max);
    return distr(this->gen);
}

// Public

Tour::Tour() {
    this->numCitiesInTour = 10;
    this->startEndCity = startEndCity;
    setToDefaultTour();
}

Tour::Tour(int numCitiesInTour, int startEndCity) {
    this->numCitiesInTour = numCitiesInTour;
    this->startEndCity = startEndCity;
    setToDefaultTour();
}

Tour::Tour(int numCitiesInTour, std::mt19937 gen, int startEndCity) {
    this->gen = gen;
    this->numCitiesInTour = numCitiesInTour;
    this->startEndCity = startEndCity;
    setToDefaultTour();
}

Tour::Tour(int permutationOrMutation[], int numCitiesInTour, int startEndCity) {
    this->numCitiesInTour = numCitiesInTour;
    this->startEndCity = startEndCity;
    createThisTourFromPermutationOrMutation(permutationOrMutation);
}

Tour::Tour(int permutationOrMutation[], int numCitiesInTour, std::mt19937 gen, int startEndCity) {
    this->numCitiesInTour = numCitiesInTour;
    this->gen = gen;
    this->startEndCity = startEndCity;
    createThisTourFromPermutationOrMutation(permutationOrMutation);
}

double Tour::getTourCost() {
    return calculateTourCost();
}

void Tour::setToNextPermutedTour() {
    int nextPermutation[MAX_TOUR_SIZE - 2];
    setArrayToNextPermutation(nextPermutation);
    createThisTourFromPermutationOrMutation(nextPermutation);
}

Tour Tour::getNextPermutedTour() {
    int nextPermutation[MAX_TOUR_SIZE - 2];
    setArrayToNextPermutation(nextPermutation);
    return Tour(nextPermutation, numCitiesInTour, gen, startEndCity);
}

void Tour::setToNewMutatedTour(int numOfMutationSwaps) {
    int newMutation[MAX_TOUR_SIZE - 2];
    setArrayToNewMutation(newMutation, numOfMutationSwaps);
    createThisTourFromPermutationOrMutation(newMutation);
}

Tour Tour::getNewMutatedTour(int numOfMutationSwaps) {
    int newMutation[MAX_TOUR_SIZE - 2];
    setArrayToNewMutation(newMutation, numOfMutationSwaps);
    return Tour(newMutation, numCitiesInTour, gen, startEndCity);
}

void Tour::setTourCity(int cityIndex, int city) {
    tourCities[cityIndex] = city;
}

int Tour::getTourCity(int cityIndex) {
    return tourCities[cityIndex];
}

int Tour::getNumCitiesInTour() {
    return numCitiesInTour;
}