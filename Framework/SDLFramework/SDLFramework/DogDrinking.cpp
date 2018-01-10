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
}

DogDrinking::~DogDrinking()
{
	cout << "Removed DogDrinking" << endl;
}