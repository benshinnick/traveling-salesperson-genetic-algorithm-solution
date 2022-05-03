#include "algorithms-runner.hpp"

int main() {
    AlgorithmsRunner algorithmsRunner = AlgorithmsRunner();
    algorithmsRunner.promptUserForValues();
    algorithmsRunner.runAlgorithms();
    algorithmsRunner.printResults();
}