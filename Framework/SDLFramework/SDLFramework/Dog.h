#pragma once
#include "GraphWalker.h"
#include "Rabbit.h"

class Dog :
	public GraphWalker
{
public:
	Dog();

	bool isThirsty();
	void increaseThirstCount();

	bool isRabbitInRange();

	int getClosestRabbit();

	int getDrankCount();
	void increaseDrankCount();

	~Dog();
private:
	// Current thirst level
	int _thirstLevel;
	int _drankCount;

	// Targetted rabbit
	Rabbit closestRabbit;
	int closestRabbitDistance;
};