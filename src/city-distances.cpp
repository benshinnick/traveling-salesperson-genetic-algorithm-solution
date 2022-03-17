#include "city-distances.hpp"

CityDistances CityDistances::getInst() {
    bool isInitialized = (cityDistancesSingleton.getDistance(0, 1) != 0);
    if(!isInitialized) {
        cityDistancesSingleton = CityDistances();
    }
    return cityDistancesSingleton;
}

void CityDistances::fillCityDistancesFromInputFile() {
    std::ifstream distancesFileInput;
}

CityDistances::CityDistances() {

}

int CityDistances::setDistance(int departureCity, int arrivalCity, int distance) {

}

int CityDistances::getDistance(int departureCity, int arrivalCity) {

}