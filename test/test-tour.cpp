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
    Tour sut = Tour(testNumCities);

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
    REQUIRE(sut.getTourCost() == 309.57);
    REQUIRE(isValidTour(sut));
}

TEST_CASE("Test permutations") {
    int testNumCities = 5;
    Tour sut = Tour(testNumCities);

    sut.printPermutationOrMutation();
    for(int i = 0; i < 23; ++i) {
        sut.setToNextPermutedTour();
        REQUIRE(isValidTour(sut));
        sut.printPermutationOrMutation();
    }

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
}

TEST_CASE("Test mutations") {
    int testNumCities = 9;
    Tour sut = Tour(testNumCities);

    sut.printPermutationOrMutation();
    for(int i = 0; i < 6; ++i) {
        sut.setToNewMutatedTour(2);
        REQUIRE(isValidTour(sut));
        sut.printPermutationOrMutation();
    }

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
}