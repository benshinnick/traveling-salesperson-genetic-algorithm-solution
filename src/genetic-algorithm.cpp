#include "genetic-algorithm.hpp"

void GeneticAlgorithm::setInitialGeneration() {
    for(int i = 0; i < generationSize; ++i) {

    }
}

void GeneticAlgorithm::setNextGeneration() {

}

void GeneticAlgorithm::updateElite() {

}

GeneticAlgorithm::GeneticAlgorithm(int numCities, int genSize, int numGensToRun, float mutatedGenPercent) {
    this->numOfCities = numCities;
    this->generationSize = genSize;
    this->numGenerationsToRun = numGensToRun;
    this->mutatedGenerationPercent = mutatedGenPercent;
    this->currGeneration.resize(genSize);
    
    setInitialGeneration();
}

void GeneticAlgorithm::runGeneticAlgorithm() {

}

double GeneticAlgorithm::getLowestFoundTourCost() {
    return elite.getTourCost();
}