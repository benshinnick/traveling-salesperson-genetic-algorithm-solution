#include "random-number-generator.hpp"

std::random_device RandomNumberGenerator::rd;
std::mt19937 RandomNumberGenerator::rng(RandomNumberGenerator::rd());

int RandomNumberGenerator::getRandomIntInRange(int rangeStart, int rangeEnd) {
    std::uniform_real_distribution<> randomizer(rangeStart, rangeEnd);
    return randomizer(rng);
}