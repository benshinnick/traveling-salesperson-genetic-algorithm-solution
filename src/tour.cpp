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

void Tour::createTourFromPermutationOrMutation(int* permutationOrMutation) {
    int startingIndex = 0;
    int endingIndex = numCitiesInTour;

    tourCities[startingIndex] = START_AND_END_CITY;
    for(int i = 1; i < numCitiesInTour; ++i) {
        tourCities[i] = permutationOrMutation[i-1];
    }
    tourCities[endingIndex] = START_AND_END_CITY;
}

int* Tour::getNextPermuation() {

}

int* Tour::getNewMutation() {
    
}

Tour::Tour(int* permutationOrMutation, int numCitiesInTour) {
    this->numCitiesInTour = numCitiesInTour;
    createTourFromPermutationOrMutation(permutationOrMutation);
}

double Tour::getTourCost() {
    return calculateTourCost();
}

Tour Tour::getNextPermutedTour() {
    
}

void Tour::setToNextPermutedTour() {
    // Tour permutedTour = getNextPermutation();
}

Tour Tour::getNewMutatedTour() {

}

void Tour::setToNewMutatedTour() {

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