#ifndef TOUR_HPP
#define TOUR_HPP

//TESTING
#include <iostream>
//TESTING

#include <random>

#include "city-distances.hpp"

class Tour {

    static const int START_AND_END_CITY = 0;
    static const int MAX_TOUR_SIZE = 21;

    private:
        int tourCities[MAX_TOUR_SIZE];
        int numCitiesInTour;
        double calculateTourCost();

        void createThisTourFromPermutationOrMutation(int permutationOrMutation[]);
        void setToDefaultTour();
        void setArrayToCurrPermutationOrMutation(int array[]);
        void setArrayToNextPermutation(int array[]);
        void setArrayToNewMutation(int array[], int numOfMutationSwaps);

        void swap(int array[], int index1, int index2);
        int getRandomIntInRange(int min, int max);

    public:
        Tour();
        Tour(int numCitiesInTour);
        Tour(int permutationOrMutation[], int numCitiesInTour);
        double getTourCost();

        void setToNextPermutedTour();
        Tour getNextPermutedTour();
        void setToNewMutatedTour(int numOfMutationSwaps);
        Tour getNewMutatedTour(int numOfMutationSwaps);

        void setTourCity(int cityIndex, int city);
        int getTourCity(int cityIndex);
        int getNumCitiesInTour();

        //TESTING
        void printPermutationOrMutation();
        //TESTING
};

#endif