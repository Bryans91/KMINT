#include <iostream>
#include "DogSleeping.h"

using namespace std;

DogSleeping::DogSleeping()
{}

// Return to (DogHunting) if bunny within 50 pixels.
void DogSleeping::update(Dog* schaap)
{
	cout << "DogSleeping" << endl;

	if (schaap->isRabbitInRange()) {
		schaap->changeState(DogStates::HUNTING);
	}
}

DogSleeping::~DogSleeping()
{
	cout << "Removed DogSleeping" << endl;
}