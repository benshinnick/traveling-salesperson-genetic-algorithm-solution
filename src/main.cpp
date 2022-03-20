/*
    Student Name: Ben Shinnick
    File Name: main.cpp
    Assignment: COP4534 Project 3
*/

#include <iostream>

#include "brute-force-algorithm.hpp"
#include "genetic-algorithm.hpp"

int promptUserForInt(std::string message) {
    int intInput;
    do {
        std::cout << message << ": ";
        std::cin >> intInput;
    } while(intInput < 0);
    return intInput;
}

float promptUserForPercent(std::string message) {
    float floatInput, percent;
    do {
        std::cout << message << ": ";
        std::cin >> floatInput;
    } while(floatInput < 0);
    if(floatInput >= 1) percent = floatInput / 100;
    else percent = floatInput;
    return percent;
}

void printDivider() {
    std::cout<< "-------------------------------------"
    << "-------------------------------" << std::endl;
}

void printHeader(std::string headerText) {
    printDivider();
    std::cout << headerText << std::endl;
    printDivider();
}

int main() {
    printHeader("Traveling Salesperson Problem Input");
    int numCities = promptUserForInt("Please enter the number of cities in a tour");
    int genSize = promptUserForInt("Please enter the number of tours in each generation");
    int numGensToRun = promptUserForInt("Please enter the number of generations to run");
    float mutatedGenPercent = promptUserForPercent("Please enter the percent of mutated tours in a generation");

    printHeader("Running The Algorithms");

    std::cout << "running brute force algorithm..." << std::endl;
    BruteForceAlgorithm bruteForce = BruteForceAlgorithm(numCities);
    bruteForce.runBruteForceAlgorithm();

    std::cout << "running genetic algorithm..." << std::endl;
    GeneticAlgorithm genetic = GeneticAlgorithm(numCities, genSize, numGensToRun, mutatedGenPercent);
    genetic.runGeneticAlgorithm();

    printHeader("Results");
    std::cout << "Number of cities run = " << numCities << std::endl;
    std::cout << "Optimal tour cost from brute force = " << bruteForce.getOptimalTourCost() << std::endl;
    // add time it took brute force to run
    std::cout << "Lowest tour cost found from genetic = " << genetic.getLowestFoundTourCost() << std::endl;
    // add time it took genetic to run
    std::cout << "Genetic algorithm percent of optimal = " << genetic.getPercentOptimal(bruteForce.getOptimalTourCost()) << std::endl;
    printDivider();
}