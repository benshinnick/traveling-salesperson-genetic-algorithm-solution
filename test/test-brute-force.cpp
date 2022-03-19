#include "catch/catch.hpp"
#include "../src/brute-force-algorithm.hpp"

TEST_CASE("Test basic functionality") {
    BruteForceAlgorithm sut = BruteForceAlgorithm(5);
    sut.runBruteFoceAlgorithm();
	REQUIRE(sut.getLowestFoundTourCost() > 0);

    sut = BruteForceAlgorithm(7);
    sut.runBruteFoceAlgorithm();
	REQUIRE(sut.getLowestFoundTourCost() > 0);
}