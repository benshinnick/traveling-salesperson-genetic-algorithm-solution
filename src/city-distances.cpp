#include "city-distances.hpp"

CityDistances CityDistances::getInst() {
    bool isInitialized = cityDistancesSingleton.getDistance(0, 1) != 0;
    if(!isInitialized) cityDistancesSingleton = CityDistances();
    return cityDistancesSingleton;
}

void CityDistances::fillCityDistancesFromInputFile() {
    std::ifstream distancesFileInput;
    distancesFileInput.open(DISTANCES_INPUT_FILE_NAME);
    if(!distancesFileInput.is_open()) exit(EXIT_FAILURE);

    for(int r = 0; r < MAX_NUM_CITIES; ++r) {
        for(int c = 0; c < MAX_NUM_CITIES; ++c) {
            if(r == c) continue;
            double distance;
            distancesFileInput >> distance;
            cityDistancesMatrix[r][c] = distance;
        }
    }

    distancesFileInput.close();
}

CityDistances::CityDistances() {
    fillCityDistancesFromInputFile();
}

int CityDistances::setDistance(int departureCity, int arrivalCity, int distance) {
    cityDistancesMatrix[departureCity][arrivalCity] = distance;
}

int CityDistances::getDistance(int departureCity, int arrivalCity) {
    return cityDistancesMatrix[departureCity][arrivalCity];
}