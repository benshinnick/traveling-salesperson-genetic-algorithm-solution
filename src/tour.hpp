#ifndef TOUR_HPP
#define TOUR_HPP

//TESTING
#include <iostream>
//TESTING

#include <vector>

#include "city-distances.hpp"

class Tour {
    
    static const int START_AND_END_CITY = 0;

    private:
        std::vector<int> tourCities;
        int numCitiesInTour;
        double calculateTourCost();

        void createThisTourFromPermutationOrMutation(std::vector<int> permutationOrMutation);
        std::vector<int> getCurrPermutationOrMutation();
        std::vector<int> getNextPermutation();
        std::vector<int> getNewMutation();
        void swap(std::vector<int>& array, int index1, int index2);

    public:
        Tour(std::vector<int> permutationOrMutation, int numCitiesInTour);
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