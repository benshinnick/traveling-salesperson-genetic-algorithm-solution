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

void Tour::createTourFromPermuation(int permutation[]) {
    int startingIndex = 0;
    int endingIndex = numCitiesInTour;

    tourCities[startingIndex] = START_AND_END_CITY;
    for(int i = 1; i < numCitiesInTour; ++i) {
        tourCities[i] = permutation[i-1];
    }
    tourCities[endingIndex] = START_AND_END_CITY;
}

Tour::Tour(int permutation[], int numCitiesInTour) {
    this->numCitiesInTour = numCitiesInTour;
    createTourFromPermuation(permutation);
}

double Tour::getTourCost() {
    return calculateTourCost();
}

// Tour Tour::getNextPermuation() {

// }

void Tour::setToNextPermuation() {

}

// Tour Tour::getNextMutation() {

// }

void Tour::setToNextMutation() {

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