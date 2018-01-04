#include <iostream>
#include "DogHunting.h"

using namespace std;

DogHunting::DogHunting()
{}

// Move towards bunny and eat if within 15px
// If bunny out of 50px range (DogWandering) OR if thirst level is 100 (DogDrinking).
void DogHunting::update(Dog* schaap)
{
	cout << "DogHunting" << endl;
	if (schaap->isThirsty()) {
		schaap->changeState(DogStates::DRINKING);
	}
	else if (!schaap->isRabbitInRange()) {
		schaap->changeState(DogStates::WANDERING);
	}
	schaap->increaseThirstCount();
}

DogHunting::~DogHunting()
{
	cout << "Removed DogHunting" << endl;
}