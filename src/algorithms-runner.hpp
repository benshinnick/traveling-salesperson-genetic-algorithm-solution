#ifndef ALGORITHMS_RUNNER_HPP
#define ALGORITHMS_RUNNER_HPP

#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#include "brute-force-algorithm.hpp"
#include "genetic-algorithm.hpp"

class AlgorithmsRunner {

    private:
        GeneticAlgorithm genetic;
        BruteForceAlgorithm bruteForce;

        struct timeval startTime;
        struct timeval endTime;
        long bruteForceTimeMS;
        long geneticTimeMS;

        int numCities;
        int startEndCity;
        int genSize;
        int numGensToRun;
        float mutatedGenPercent;

        long getAlgorithmTimeMS();
        int promptUserForInt(std::string message);
        int promptUserForIntInRange(std::string message, int low, int high);
        float promptUserForPercent(std::string message);
        void printDivider();
        void printHeader(std::string headerText);

    public:
        AlgorithmsRunner();
        void promptUserForValues();
        void runAlgorithms();
        void runBruteForce();
        void runGenetic();
        void printResults();
};

#endif