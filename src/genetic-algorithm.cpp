#include "genetic-algorithm.hpp"

void GeneticAlgorithm::setInitialGeneration() {
    Tour initialTour = Tour(numOfCities);
    for(int i = 0; i < generationSize; ++i) {
        initialTour.setToNextPermutedTour();
        currGeneration.at(i) = initialTour;
    }
}

void GeneticAlgorithm::setNextGeneration() {

}

void GeneticAlgorithm::updateElite() {
    Tour foundElite = currGeneration.at(0);
    for(int i = 0; i < generationSize; ++i) {
        if(foundElite.getTourCost() > currGeneration.at(i).getTourCost())
            foundElite = currGeneration.at(i);
    }
    elite = foundElite;
}

GeneticAlgorithm::GeneticAlgorithm(int numCities, int genSize, int numGensToRun, float mutatedGenPercent) {
    this->numOfCities = numCities;
    this->generationSize = genSize;
    this->numGenerationsToRun = numGensToRun;
    this->numMutationsInGeneration = (int) (mutatedGenPercent * genSize);
    this->currGeneration.resize(genSize);
    
    setInitialGeneration();
    updateElite();
}

void GeneticAlgorithm::runGeneticAlgorithm() {

}

double GeneticAlgorithm::getLowestFoundTourCost() {
    return elite.getTourCost();
}

Tour GeneticAlgorithm::getElite() {
    return elite;
}

//TESTING
void GeneticAlgorithm::printCurrGeneration() {
    std::cout << "Num Cities = " << numOfCities << std::endl;
    std::cout << "Gen Size = " << generationSize << std::endl;
    std::cout << "Num Gens to run = " << numGenerationsToRun << std::endl;
    std::cout << "Num Mutations in Gen = " << numMutationsInGeneration << std::endl;
    for(int i = 0; i < generationSize; ++i) {
        currGeneration.at(i).printPermutationOrMutation();
        std::cout << "Tour Cost: " <<  currGeneration.at(i).getTourCost() << std::endl;
    }
}
//TESTING