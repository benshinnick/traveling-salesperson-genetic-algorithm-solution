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
    float floatInput;
    do {
        std::cout << message << ": ";
        std::cin >> floatInput;
    } while(floatInput < 0);
    return floatInput;
    // convert to percent if necessary
    if(floatInput > 1) return floatInput/100;
    else return floatInput;
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
    printHeader("Traveling Salesperson Problem");
    int numCities = promptUserForInt("Please enter the number of cities in a tour");
    int genSize = promptUserForInt("Please enter the number of tours in each generation");
    int numGensToRun = promptUserForInt("Please enter the number of generations to run");
    float mutatedGenPercent = promptUserForPercent("Please enter the percent of a generation comprised of mutated tours");
}