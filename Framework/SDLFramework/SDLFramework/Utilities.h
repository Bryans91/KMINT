#pragma once
#include <random>

class Utilities
{
public:
	Utilities();
	~Utilities();
	static std::default_random_engine randomEngine;

	static int randomInt(int min, int max);
	static double randomDouble(double min, double max);
	static float randomFloat(float min, float max);
	static  std::default_random_engine getRandomEngine();

};

