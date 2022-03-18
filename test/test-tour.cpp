#include "catch/catch.hpp"
#include "../src/tour.hpp"

TEST_CASE("Test basic tour functionality")
{
    int testNumCities = 5;
	int testPermutation[] = {1, 2, 3, 4};
    Tour sut = Tour(testPermutation, testNumCities);

    REQUIRE(sut.getNumCitiesInTour() == testNumCities);
    REQUIRE(sut.getTourCost() == 309.57);
}