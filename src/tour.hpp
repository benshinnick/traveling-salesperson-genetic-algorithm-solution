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

        void createTourFromPermutationOrMutation(int* permutationOrMutation);
        int* getNextPermuation();
        int* getNextMutation();

    public:
        Tour(int* permutationOrMutation, int numCitiesInTour);
        double getTourCost();

        Tour getNextPermutedTour();
        void setToNextPermutedTour();
        Tour getNewMutatedTour();
        void setToNewMutatedTour();

        void setTourCity(int cityIndex, int city);
        int getTourCity(int cityIndex);
        void setNumCitiesInTour(int numCitiesInTour);
        int getNumCitiesInTour();
};

#endif