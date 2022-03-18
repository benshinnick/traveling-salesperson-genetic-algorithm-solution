#ifndef TOUR_HPP
#define TOUR_HPP

#include "city-distances.hpp"

static const int MAX_TOUR_SIZE = 21;

class Tour {

    private:
        int tourArray[MAX_TOUR_SIZE];
        int numCitiesInTour;
        double calculateTourCost();

    public:
        Tour(int permutation[], int numCitiesInTour);
        double getTourCost();
        Tour getNextPermuation();
        void setToNextPermuation();
        Tour getNextMutation();
        void setToNextMutation();
        void setTourCity(int cityIndex, int city);
        int getTourCity(int cityIndex);
};

#endif