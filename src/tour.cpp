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

    tourCities[startingIndex] = START_AND_END_CITY;
    for(int i = 1; i < numCitiesInTour; ++i) {
        tourCities[i] = permutationOrMutation[i-1];
    }
    tourCities[endingIndex] = START_AND_END_CITY;
}

void Tour::setToDefaultTour() {
    int startingIndex = 0, endingIndex = numCitiesInTour;

    tourCities[startingIndex] = START_AND_END_CITY;
    int currCity = 0;
    for(int i = 1; i < numCitiesInTour; ++i) {
        if(currCity == START_AND_END_CITY) currCity++;
        tourCities[i] = currCity;
        currCity++;
    }
    tourCities[endingIndex] = START_AND_END_CITY;
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

    swap(array, m, k);
    int p = m + 1;
    int q = NUM_ELEMENTS - 1;
    while(p < q) {
        swap(array, p, q);
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
        else {
            // swap city from first half with a city from last half of the tour
            swap(
                array,
                getRandomIntInRange(minIndex, midIndex),
                getRandomIntInRange(midIndex+1, maxIndex)
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
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    return distr(gen); // generate random number in that range
}

// Public
Tour::Tour() {
    // num cities set to 10 by default
    this->numCitiesInTour = 10;
    setToDefaultTour();
}

Tour::Tour(int numCitiesInTour) {
    this->numCitiesInTour = numCitiesInTour;
    setToDefaultTour();
}

Tour::Tour(int permutationOrMutation[], int numCitiesInTour) {
    this->numCitiesInTour = numCitiesInTour;
    createThisTourFromPermutationOrMutation(permutationOrMutation);
}

double Tour::getTourCost() {
    return calculateTourCost();
}

void Tour::setToNextPermutedTour() {
    int nextPermutation[numCitiesInTour - 1];
    setArrayToNextPermutation(nextPermutation);
    createThisTourFromPermutationOrMutation(nextPermutation);
}

Tour Tour::getNextPermutedTour() {
    int nextPermutation[numCitiesInTour - 1];
    setArrayToNextPermutation(nextPermutation);
    return Tour(nextPermutation, numCitiesInTour);
}

void Tour::setToNewMutatedTour(int numOfMutationSwaps) {
    int newMutation[numCitiesInTour - 1];
    setArrayToNewMutation(newMutation, numOfMutationSwaps);
    createThisTourFromPermutationOrMutation(newMutation);
}

Tour Tour::getNewMutatedTour(int numOfMutationSwaps) {
    int newMutation[numCitiesInTour - 1];
    setArrayToNewMutation(newMutation, numOfMutationSwaps);
    return Tour(newMutation, numCitiesInTour);
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

//TESTING
void Tour::printPermutationOrMutation() {
    int array[MAX_TOUR_SIZE];
    setArrayToCurrPermutationOrMutation(array);
    for(int i = 0; i < numCitiesInTour - 1; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
//TESTING