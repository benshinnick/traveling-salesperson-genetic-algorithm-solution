#include "catch/catch.hpp"
#include "../src/city-distances.hpp"

#include <iostream>

TEST_CASE("Test basic functionality")
{
	REQUIRE(CityDistances::getInst().getDistance(0, 0) == 0.0f);
	REQUIRE(CityDistances::getInst().getDistance(0, 1) == 25.410000f);
	REQUIRE(CityDistances::getInst().getDistance(0, 2) == 109.670000f);
	REQUIRE(CityDistances::getInst().getDistance(19, 18) == 65.180000f);
	REQUIRE(CityDistances::getInst().getDistance(12, 12) == 0.0f);
}