#include "Dog.h"
#include <iostream>
#include "Vertex.h"
#include "Edge.h"

#include "DogWandering.h"
#include "DogHunting.h"
#include "DogDrinking.h"
#include "DogSleeping.h"

using namespace std;

Dog::Dog()
{
	GraphWalker::setType('D');

	// Starting state (:
	this->changeState(DogStates::WANDERING);
}

void Dog::update(int frame)
{
	_state->update(this);
}

//Change state
void Dog::changeState(DogStates newState)
{
	switch (newState) {
		case WANDERING:
			_state = make_shared<DogWandering>();
			break;
		case HUNTING:
			_state = make_shared<DogHunting>();
			break;
		case DRINKING:
			_state = make_shared<DogDrinking>();
			break;
		case SLEEPING:
			_state = make_shared<DogSleeping>();
			break;
	}
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
	// Get rabbit position
	if (getClosestRabbit() <= 15) {
		// Eat the rabbit
	}
	if (getClosestRabbit() <= 50) {
		return true;
	}

	return false;
}

int Dog::getClosestRabbit()
{
	return 100; // target->position();
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