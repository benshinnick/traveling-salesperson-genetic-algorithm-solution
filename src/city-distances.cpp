#include "city-distances.hpp"

CityDistances& CityDistances::getInst() {
    // only instantiated on first use and guarenteed to be destroyed
    static CityDistances cityDistancesSingleton;
    return cityDistancesSingleton;
}

void CityDistances::fillCityDistancesFromInputFile() {
    std::ifstream distancesFileInput;
    distancesFileInput.open(DISTANCES_INPUT_FILE_NAME);
    if(!distancesFileInput.is_open()) exit(EXIT_FAILURE);

    for(int r = 0; r < MAX_NUM_CITIES; ++r) {
        for(int c = 0; c < MAX_NUM_CITIES; ++c) {
            if(r == c) continue;
            float distance;
            distancesFileInput >> distance;
            cityDistancesMatrix[r][c] = distance;
        }
    }

    distancesFileInput.close();
}

CityDistances::CityDistances() {
    fillCityDistancesFromInputFile();
}

void CityDistances::setDistance(int departureCity, int arrivalCity, float distance) {
    cityDistancesMatrix[departureCity][arrivalCity] = distance;
}

float CityDistances::getDistance(int departureCity, int arrivalCity) {
    return cityDistancesMatrix[departureCity][arrivalCity];
}