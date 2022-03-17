#ifndef CITY_GRAPH_HPP
#define CITY_GRAPH_HPP

#include <fstream>
#include <string>

class CityGraph {

    static const int MAX_NUM_CITIES = 20;
    const std::string DISTANCES_INPUT_FILE_NAME = "distances.txt";

    private:
        int cityDistances[MAX_NUM_CITIES][MAX_NUM_CITIES];
        void fillCityDistancesFromInputFile();
        
    public:
        CityGraph();
        int setDistance(int departureCity, int arrivalCity, int distance);
        int getDistance(int departureCity, int arrivalCity);
};

#endif