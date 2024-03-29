#ifndef TOUR_HPP
#define TOUR_HPP

#include <random>
#include <sstream>

#include "city-distances.hpp"
#include "random-number-generator.hpp"

class Tour {

    static const int MAX_TOUR_SIZE = 21;

    private:
        int tourCities[MAX_TOUR_SIZE];
        int numCitiesInTour;
        int startEndCity;

        double calculateTourCost();

        void createThisTourFromPermutationOrMutation(int permutationOrMutation[]);
        void setToDefaultTour();
        void setArrayToCurrPermutationOrMutation(int array[]);
        void setArrayToNextPermutation(int array[]);
        void setArrayToNewMutation(int array[], int numOfMutationSwaps);

        void swap(int array[], int index1, int index2);

    public:
        Tour();
        Tour(int numCitiesInTour, int startEndCity);
        Tour(int permutationOrMutation[], int numCitiesInTour, int startEndCity);
        double getTourCost();

        void setToNextPermutedTour();
        Tour getNextPermutedTour();
        void setToNewMutatedTour(int numOfMutationSwaps);
        Tour getNewMutatedTour(int numOfMutationSwaps);

        void setTourCity(int cityIndex, int city);
        int getTourCity(int cityIndex);
        int getNumCitiesInTour();

        std::string getTourOrderString();
};

#endif