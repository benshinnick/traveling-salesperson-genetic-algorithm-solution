#ifndef CITY_DISTANCES_HPP
#define CITY_DISTANCES_HPP

#include <fstream>
#include <string>

class CityDistances {

    static const int MAX_NUM_CITIES = 20;
    const std::string DISTANCES_INPUT_FILE_NAME = "distances.txt";

    private:
        static CityDistances cityDistancesSingleton;
        int cityDistancesMatrix[MAX_NUM_CITIES][MAX_NUM_CITIES];
        void fillCityDistancesFromInputFile();
        
    public:
        static CityDistances getInst();
        CityDistances();
        int setDistance(int departureCity, int arrivalCity, int distance);
        int getDistance(int departureCity, int arrivalCity);
};

#endif