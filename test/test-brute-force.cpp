#include "catch/catch.hpp"
#include "../src/brute-force-algorithm.hpp"

TEST_CASE("Test Brute Force NumCities = 7") {
    BruteForceAlgorithm sut = BruteForceAlgorithm(7);
    sut.runBruteFoceAlgorithm();
	REQUIRE(sut.getLowestFoundTourCost() > 0);
}

TEST_CASE("Test Brute Force numCities = 5") {
    BruteForceAlgorithm sut = BruteForceAlgorithm(5);
    sut.runBruteFoceAlgorithm();
	REQUIRE(sut.getLowestFoundTourCost() > 0);
}