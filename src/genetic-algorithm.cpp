#include "genetic-algorithm.hpp"

void GeneticAlgorithm::setInitialGeneration() {
    Tour initialTour = Tour(numOfCities);
    int numInitialMutationSwaps = 5;
    //First generation made up of inital default tour mutations
    for(int i = 0; i < generationSize; ++i) {
        currGeneration.at(i) = initialTour.getNewMutatedTour(numInitialMutationSwaps);
    }
}

void GeneticAlgorithm::setNextGeneration() {
    int i;
    int numEliteMutationSwaps = 1, numMutationSwaps = 2;
    if(numOfCities > 11) numMutationSwaps = 4;
    
    currGeneration.at(0) = elite;
    for(i = 1; i < numMutationsInGeneration+1; ++i) {
        if(i % 3 == 0) currGeneration.at(i) = elite.getNewMutatedTour(numEliteMutationSwaps);
        else currGeneration.at(i).setToNewMutatedTour(numMutationSwaps);
    }
    if(i < generationSize) {
        currGeneration.at(i) = elite.getNextPermutedTour();
        i++;
    }
    for(; i < generationSize; ++i) {
        currGeneration.at(i).setToNextPermutedTour();
    }
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
    for(int i = 0; i < numGenerationsToRun - 1; ++i) {
        setNextGeneration();
        updateElite();
        std::cout << "Gen" << i + 2 << " elite cost: " << elite.getTourCost() << std::endl;
    }
}

double GeneticAlgorithm::getLowestFoundTourCost() {
    return elite.getTourCost();
}

double GeneticAlgorithm::getPercentOptimal(double optimalTourCost)  {
    return getLowestFoundTourCost()/optimalTourCost * 100;
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
        // std::cout << "Tour Cost: " <<  currGeneration.at(i).getTourCost() << std::endl;
    }
}
//TESTING