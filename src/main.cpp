/*
    Student Name: Ben Shinnick
    File Name: main.cpp
    Assignment: COP4534 Project 3
*/

#include <iostream>

#include <sys/time.h>
#include <unistd.h>

#include "brute-force-algorithm.hpp"
#include "genetic-algorithm.hpp"

void runAlgorithmsAndPrintResults();

void runAlgorithms();

void printResults();

int promptUserForInt(std::string message);

int promptUserForIntInRange(std::string message, int low, int high);

float promptUserForPercent(std::string message);

void printHeader(std::string headerText);

long getAlgorithmTimeMS(timeval startTime, timeval endTime);

void printDivider();

int main() {
    printHeader("Traveling Salesperson Problem");
    int numCities = promptUserForIntInRange("Please enter the number of cities in a tour", 0, 20);
    int startEndCity = promptUserForIntInRange("Please enter the start and end city", 0, numCities-1);
    int genSize = promptUserForInt("Please enter the number of tours in each generation");
    int numGensToRun = promptUserForInt("Please enter the number of generations to run");
    float mutatedGenPercent = promptUserForPercent("Please enter the percent of mutated tours in a generation");

    printHeader("Running The Algorithms");
    struct timeval startTime, endTime;

    std::cout << "running brute force algorithm..." << std::endl;
    BruteForceAlgorithm bruteForce = BruteForceAlgorithm(numCities, startEndCity);
    gettimeofday(&startTime, NULL);
    bruteForce.runBruteForceAlgorithm();
    gettimeofday(&endTime, NULL);
    long bruteForceTimeMS = getAlgorithmTimeMS(startTime, endTime);

    std::cout << "running genetic algorithm..." << std::endl;
    GeneticAlgorithm genetic = GeneticAlgorithm(numCities, startEndCity, genSize, numGensToRun, mutatedGenPercent);
    gettimeofday(&startTime, NULL);
    genetic.runGeneticAlgorithm();
    gettimeofday(&endTime, NULL);
    long geneticTimeMS = getAlgorithmTimeMS(startTime, endTime);

    printHeader("Results");
    std::cout << "Number of cities run = " << numCities << std::endl;
    std::cout << "Optimal tour cost from brute force = " << bruteForce.getOptimalTourCost() << std::endl;
    std::cout << "Brute force time = " << bruteForceTimeMS << "ms" << std::endl;
    std::cout << "Lowest tour cost found from genetic = " << genetic.getLowestFoundTourCost() << std::endl;
    std::cout << "Genetic time = " << geneticTimeMS << "ms"  << std::endl;
    std::cout << "Genetic algorithm percent of optimal = " << genetic.getPercentOptimal(bruteForce.getOptimalTourCost()) << "%" << std::endl;
    printDivider();

    std::cout << "Brute Force Optimal Tour:\n" << bruteForce.getOptimalTour().getTourOrderString() << std::endl;
    printDivider();
    std::cout << "Genetic Tour:\n" << genetic.getElite().getTourOrderString() << std::endl;
    printDivider();
}

int promptUserForInt(std::string message) {
    int intInput;
    do {
        std::cout << message << ": ";
        std::cin >> intInput;
    } while(intInput < 0);
    return intInput;
}
int promptUserForIntInRange(std::string message, int low, int high) {
    int intInput;
    do {
        std::cout << message << " [" << low << "," << high << "]: ";
        std::cin >> intInput;
    } while(intInput < low || intInput > high);
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

void printHeader(std::string headerText) {
    printDivider();
    std::cout << headerText << std::endl;
    printDivider();
}

long getAlgorithmTimeMS(timeval startTime, timeval endTime) {
    long seconds = endTime.tv_sec - startTime.tv_sec;
    long useconds = endTime.tv_usec - startTime.tv_usec;
    return ((seconds) * 1000 + useconds/1000.0);
}

void printDivider() {
    std::cout << "--------------------------------------------";
    std::cout << "--------------------------------------------";
    std::cout << std::endl;
}