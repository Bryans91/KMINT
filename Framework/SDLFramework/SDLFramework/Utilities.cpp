#include "Utilities.h"

//init
std::default_random_engine Utilities::randomEngine = std::default_random_engine{};


Utilities::Utilities()
{

}


Utilities::~Utilities()
{
}


int Utilities::randomInt(int min, int max)
{
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(randomEngine, Dist::param_type{ min,max });
}

double Utilities::randomDouble(double min, double max)
{
	using Dist = std::uniform_real_distribution<double>;
	static Dist uid{};
	return uid(randomEngine, Dist::param_type{ min,max });
}

float Utilities::randomFloat(float min, float max)
{
	using Dist = std::uniform_real_distribution<float>;
	static Dist uid{};
	return uid(randomEngine, Dist::param_type{ min,max });
}


std::default_random_engine Utilities::getRandomEngine()
{
	return randomEngine;
}