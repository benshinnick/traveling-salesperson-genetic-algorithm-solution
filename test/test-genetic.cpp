#include "catch/catch.hpp"
#include "../src/genetic-algorithm.hpp"

TEST_CASE("Test Genetic numCities = 5") {
    GeneticAlgorithm sut = GeneticAlgorithm(5, 6, 5, 0.4);
    // sut.printCurrGeneration();
    double initialLowestCost = sut.getLowestFoundTourCost();
    REQUIRE(initialLowestCost > 0);

    sut.runGeneticAlgorithm();
    // sut.printCurrGeneration();
    REQUIRE(sut.getLowestFoundTourCost() <= initialLowestCost);
}

TEST_CASE("Test Genetic numCities = 8") {
    GeneticAlgorithm sut = GeneticAlgorithm(8, 60, 30, 0.5);
    // sut.printCurrGeneration();
    double initialLowestCost = sut.getLowestFoundTourCost();
    REQUIRE(initialLowestCost > 0);

    sut.runGeneticAlgorithm();
    // sut.printCurrGeneration();
    REQUIRE(sut.getLowestFoundTourCost() <= initialLowestCost);
}

TEST_CASE("Test Genetic numCities = 12") {
    GeneticAlgorithm sut = GeneticAlgorithm(12, 60, 30, 0.5);
    // sut.printCurrGeneration();
    double initialLowestCost = sut.getLowestFoundTourCost();
    REQUIRE(initialLowestCost > 0);

    sut.runGeneticAlgorithm();
    // sut.printCurrGeneration();
    REQUIRE(sut.getLowestFoundTourCost() <= initialLowestCost);
}


TEST_CASE("Test Genetic numCities = 20") {
    GeneticAlgorithm sut = GeneticAlgorithm(20, 60, 30, 0.5);
    // sut.printCurrGeneration();
    double initialLowestCost = sut.getLowestFoundTourCost();
    REQUIRE(initialLowestCost > 0);

    sut.runGeneticAlgorithm();
    // sut.printCurrGeneration();
    REQUIRE(sut.getLowestFoundTourCost() <= initialLowestCost);
}