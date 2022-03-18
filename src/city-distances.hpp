#ifndef CITY_DISTANCES_HPP
#define CITY_DISTANCES_HPP

#include <fstream>
#include <string>

class CityDistances {

    static const int MAX_NUM_CITIES = 20;
    const std::string DISTANCES_INPUT_FILE_NAME = "distances.txt";

    private:
        float cityDistancesMatrix[MAX_NUM_CITIES][MAX_NUM_CITIES];
        void fillCityDistancesFromInputFile();
        CityDistances();
        
    public:
        static CityDistances& getInst();
        void setDistance(int departureCity, int arrivalCity, float distance);
        float getDistance(int departureCity, int arrivalCity);

        // to ensure we wont ever make copies of our singleton
        CityDistances(CityDistances const&) = delete;
        void operator=(CityDistances const&) = delete;
};

#endif