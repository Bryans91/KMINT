#include "Dog.h"
#include <iostream>

#include "DogWandering.h"
#include "DogHunting.h"
#include "DogDrinking.h"
#include "DogSleeping.h"

using namespace std;

Dog::Dog()
{
	GraphWalker::setType('D');
	changeState(DogStates::WANDERING);
	_state->update(this);
	changeState(DogStates::HUNTING);
	_state->update(this);
	changeState(DogStates::DRINKING);
	_state->update(this);
	changeState(DogStates::SLEEPING);
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