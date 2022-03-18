#ifndef TOUR_HPP
#define TOUR_HPP

#include "city-distances.hpp"

static const int MAX_TOUR_SIZE = 21;

class Tour {

    private:
        int tourArray[MAX_TOUR_SIZE];
        int numCitiesInTour;
        float calculateTourCost();

    public:
        Tour(int permutation[], int numCitiesInTour);
        float getTourCost();
        void setTourCity(int cityIndex, int city);
        int getTourCity(int cityIndex);
        
};

#endif