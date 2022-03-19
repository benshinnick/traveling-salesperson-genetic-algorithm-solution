#include "catch/catch.hpp"
#include "../src/tour.hpp"

#include <vector>

#include <iostream>

bool isValidTour(Tour& tour) {
    // make sure all cities appear at least once
    for(int i = 0; i < tour.getNumCitiesInTour(); ++i) {
        bool containsCity = false;
        int currCity = i;
        for(int j = 0; j < tour.getNumCitiesInTour(); ++j) {
            if(tour.getTourCity(j) == currCity) {
                containsCity = true;
                break;
            }
        }
        if(!containsCity) return false;
    }
    if(tour.getTourCity(tour.getNumCitiesInTour()) != 0) return false;
    else return true;
}

TEST_CASE("Test basic tour functionality") {
    int testNumCities = 5;
	std::vector<int> testPermutation = {1, 2, 3, 4};
    Tour sut = Tour(testPermutation, testNumCities);

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
    REQUIRE(sut.getTourCost() == 309.57);
    REQUIRE(isValidTour(sut));
}

TEST_CASE("Test permutations") {
    int testNumCities = 4;
	std::vector<int> testPermutation = {1, 2, 3};
    Tour sut = Tour(testPermutation, testNumCities);

    sut.printPermutationOrMutation();
    for(int i = 0; i < 5; ++i) {
        sut = sut.getNextPermutedTour();
        REQUIRE(isValidTour(sut));
        sut.printPermutationOrMutation();
    }

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
}

TEST_CASE("Test mutations") {
    int testNumCities = 11;
	std::vector<int> testPermutation = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tour sut = Tour(testPermutation, testNumCities);

    sut.printPermutationOrMutation();
    for(int i = 0; i < 6; ++i) {
        sut = sut.getNewMutatedTour();
        REQUIRE(isValidTour(sut));
        sut.printPermutationOrMutation();
    }

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
}