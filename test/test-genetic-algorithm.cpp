#include "catch/catch.hpp"
#include "../src/genetic-algorithm.hpp"

TEST_CASE("Test Genetic numCities = 5") {
    GeneticAlgorithm sut = GeneticAlgorithm(5);
    sut.runGeneticAlgorithmAlgorithm();
    sut.printCurrGeneration();
	// REQUIRE(sut.getLowestFoundTourCost() > 0);
}