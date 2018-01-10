#pragma once
#include <memory>
#include <iostream>
#include "GraphWalker.h"
#include "DogState.h"

using namespace std;

// Forward declaration
class DogState;

enum DogStates {
	WANDERING,
	HUNTING,
	DRINKING,
	SLEEPING
};

class Dog :
	public GraphWalker
{
public:
	Dog();

	void changeState(DogStates newState);

	bool isThirsty();
	void increaseThirstCount();

	bool isRabbitInRange();

	int getClosestRabbit();

	int getDrankCount();
	void increaseDrankCount();

	virtual ~Dog();
private:
	// Current state
	shared_ptr<DogState> _state;

	// Current thirst level
	int _thirstLevel;
	int _drankCount;

	// Targetted rabbit
	//Rabbit closestRabbit;
	int closestRabbitDistance;
};