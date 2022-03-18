#ifndef TOUR_HPP
#define TOUR_HPP

#include "city-distances.hpp"

//TESTING
#include <iostream>
//TESTING

class Tour {

    static const int MAX_TOUR_SIZE = 21;
    static const int START_AND_END_CITY = 0;

    private:
        int tourCities[MAX_TOUR_SIZE];
        int numCitiesInTour;
        double calculateTourCost();

        void createThisTourFromPermutationOrMutation(int* permutationOrMutation);
        int* getCurrPermutationOrMutation();
        int* getNextPermutation();
        int* getNewMutation();
        void swap(int* array, int index1, int index2);

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

        //TESTING
        void printPermutationOrMuation();
        //TESTING
};

#endif