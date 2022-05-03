#include "algorithms-runner.hpp"

long AlgorithmsRunner::getAlgorithmTimeMS() {
    long seconds = endTime.tv_sec - startTime.tv_sec;
    long useconds = endTime.tv_usec - startTime.tv_usec;
    return ((seconds) * 1000 + useconds/1000.0);
}

int AlgorithmsRunner::promptUserForInt(std::string message) {
    int intInput;
    do {
        std::cout << message << ": ";
        std::cin >> intInput;
    } while(intInput < 0);
    return intInput;
}
int AlgorithmsRunner::promptUserForIntInRange(std::string message, int low, int high) {
    int intInput;
    do {
        std::cout << message << " [" << low << "," << high << "]: ";
        std::cin >> intInput;
    } while(intInput < low || intInput > high);
    return intInput;
}

float AlgorithmsRunner::promptUserForPercent(std::string message) {
    float floatInput, percent;
    do {
        std::cout << message << ": ";
        std::cin >> floatInput;
    } while(floatInput < 0);
    if(floatInput >= 1) percent = floatInput / 100;
    else percent = floatInput;
    return percent;
}

void AlgorithmsRunner::printHeader(std::string headerText) {
    printDivider();
    std::cout << headerText << std::endl;
    printDivider();
}

void AlgorithmsRunner::printDivider() {
    std::cout << "--------------------------------------------";
    std::cout << "--------------------------------------------";
    std::cout << std::endl;
}

AlgorithmsRunner::AlgorithmsRunner() {
    printHeader("Traveling Salesperson Problem");
}

void AlgorithmsRunner::promptUserForValues() {
    numCities = promptUserForIntInRange("Please enter the number of cities in a tour", 0, 20);
    startEndCity = promptUserForIntInRange("Please enter the start and end city", 0, numCities-1);
    genSize = promptUserForInt("Please enter the number of tours in each generation");
    numGensToRun = promptUserForInt("Please enter the number of generations to run");
    mutatedGenPercent = promptUserForPercent("Please enter the percent of mutated tours in a generation");
}

void AlgorithmsRunner::runAlgorithms() {
    printHeader("Running The Algorithms");
    runBruteForce();
    runGenetic();
}

void AlgorithmsRunner::runBruteForce() {
    bruteForce = BruteForceAlgorithm(numCities, startEndCity);

    std::cout << "running brute force algorithm (checking all ";
    std::cout << bruteForce.getNumPermuations() << " permutations)..." << std::endl;
    gettimeofday(&startTime, NULL);
    bruteForce.runBruteForceAlgorithm();
    gettimeofday(&endTime, NULL);
    bruteForceTimeMS = getAlgorithmTimeMS();
}

void AlgorithmsRunner::runGenetic() {
    genetic = GeneticAlgorithm(numCities, startEndCity, genSize, numGensToRun, mutatedGenPercent);

    std::cout << "running genetic algorithm..." << std::endl;
    gettimeofday(&startTime, NULL);
    genetic.runGeneticAlgorithm();
    gettimeofday(&endTime, NULL);
    geneticTimeMS = getAlgorithmTimeMS();
}

void AlgorithmsRunner::printResults() {
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

