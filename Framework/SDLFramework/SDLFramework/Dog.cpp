#include "Dog.h"

Dog::Dog()
{
}

bool Dog::isThirsty()
{
	return _thirstLevel >= 100;
}

void Dog::increaseThirstCount()
{
	_thirstLevel++;
}

bool Dog::isRabbitInRange()
{
	return closestRabbitDistance <= 50;
}

int Dog::getClosestRabbit()
{
	closestRabbitDistance = 0; // target->position();
	return 0;
}

int Dog::getDrankCount()
{
	return _drankCount;
}

void Dog::increaseDrankCount()
{
	_drankCount++;
}

Dog::~Dog()
{
}