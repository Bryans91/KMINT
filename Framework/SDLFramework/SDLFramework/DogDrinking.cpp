#include <iostream>
#include "DogDrinking.h"

using namespace std;

DogDrinking::DogDrinking()
{}

// Choose which owner to move to, depending on distance and amount of water to gain.
// Return to (DogHunting) if bunny within 50 pixels, else (DogWandering).
void DogDrinking::update(Dog* schaap)
{
	cout << "DogDrinking" << endl;

	if (this->the_chosen_one == nullptr)  {
		// Choose a human
		// Pretend Dog is stupid? 50% until both figured out, use last amount as reference, but increase opponents chance after every drink
		// M ~40
		// F ~45
	}

	// A* TO THE CHOSEN ONE
}

DogDrinking::~DogDrinking()
{
	cout << "Removed DogDrinking" << endl;
}