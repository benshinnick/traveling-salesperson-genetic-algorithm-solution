#ifndef RANDOM_NUMBER_GENERATOR_HPP
#define RANDOM_NUMBER_GENERATOR_HPP

#include <random>

class RandomNumberGenerator
{
    static std::random_device rd;
    static std::mt19937 rng;

    public:
        static int getRandomIntInRange(int rangeStart, int rangeEnd);
};

#endif