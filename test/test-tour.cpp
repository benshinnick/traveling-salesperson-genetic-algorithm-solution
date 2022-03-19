#include "catch/catch.hpp"
#include "../src/tour.hpp"

#include <vector>

TEST_CASE("Test basic tour functionality")
{
    int testNumCities = 5;
	std::vector<int> testPermutation = {1, 2, 3, 4};
    Tour sut = Tour(testPermutation, testNumCities);

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
    REQUIRE(sut.getTourCost() == 309.57);
}

TEST_CASE("Test permutations")
{
    int testNumCities = 5;
	std::vector<int> testPermutation = {1, 2, 3, 4};
    
    Tour sut = Tour(testPermutation, testNumCities);

    sut.printPermutationOrMuation();
    for(int i = 0; i < 23; ++i) {
        sut.setToNextPermutedTour();
        sut.printPermutationOrMuation();
    }

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
}

TEST_CASE("Test mutations")
{
    int testNumCities = 11;
	std::vector<int> testPermutation = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    Tour sut = Tour(testPermutation, testNumCities);

    sut.printPermutationOrMuation();
    for(int i = 0; i < 20; ++i) {
        sut.setToNewMutatedTour();
        sut.printPermutationOrMuation();
    }

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
}