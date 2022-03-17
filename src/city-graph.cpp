#include "city-graph.hpp"

CityGraph CityGraph::getInstance() {
    bool isInitialized = (cityGraphSingleton.getDistance(0, 1) != 0);
    if(!isInitialized) {
        cityGraphSingleton = CityGraph();
    }
    return cityGraphSingleton;
}

void CityGraph::fillCityDistancesFromInputFile() {
    std::ifstream distancesFileInput;
}

CityGraph::CityGraph() {

}

int CityGraph::setDistance(int departureCity, int arrivalCity, int distance) {

}

int CityGraph::getDistance(int departureCity, int arrivalCity) {

}