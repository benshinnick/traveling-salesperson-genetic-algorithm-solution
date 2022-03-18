#ifndef TOUR_HPP
#define TOUR_HPP

#include "city-distances.hpp"

class Tour {

    static const int MAX_TOUR_SIZE = 21;
    static const int START_AND_END_CITY = 0;

    private:
        int tourCities[MAX_TOUR_SIZE];
        int numCitiesInTour;
        double calculateTourCost();
        void createTourFromPermuation(int permutation[]);

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