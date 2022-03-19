#include "catch/catch.hpp"
#include "../src/genetic-algorithm.hpp"

TEST_CASE("Test Genetic numCities = 5") {
    GeneticAlgorithm sut = GeneticAlgorithm(5, 20, 15, 0.4);
    sut.printCurrGeneration();
    REQUIRE(sut.getLowestFoundTourCost() > 0);
    
    // sut.runGeneticAlgorithmAlgorithm();
	// REQUIRE(sut.getLowestFoundTourCost() > 0);
}