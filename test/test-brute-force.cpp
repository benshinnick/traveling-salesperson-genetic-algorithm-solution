#include "catch/catch.hpp"
#include "../src/brute-force-algorithm.hpp"

TEST_CASE("Test Brute Force numCities = 5") {
    BruteForceAlgorithm sut = BruteForceAlgorithm(5);
    sut.runBruteForceAlgorithm();
	REQUIRE(sut.getOptimalTourCost() > 0);
}

TEST_CASE("Test Brute Force numCities = 6") {
    BruteForceAlgorithm sut = BruteForceAlgorithm(6);
    sut.runBruteForceAlgorithm();
	REQUIRE(sut.getOptimalTourCost() > 0);
}

TEST_CASE("Test Brute Force NumCities = 7") {
    BruteForceAlgorithm sut = BruteForceAlgorithm(7);
    sut.runBruteForceAlgorithm();
	REQUIRE(sut.getOptimalTourCost() > 0);
}

TEST_CASE("Test Brute Force NumCities = 8") {
    BruteForceAlgorithm sut = BruteForceAlgorithm(8);
    sut.runBruteForceAlgorithm();
	REQUIRE(sut.getOptimalTourCost() > 0);
}