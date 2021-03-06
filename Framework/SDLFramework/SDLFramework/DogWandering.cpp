#include <iostream>
#include "DogWandering.h"
#include "Vertex.h"
#include "Edge.h"
#include "GraphWalker.h"
#include "Utilities.h"

using namespace std;

DogWandering::DogWandering()
{}

// If bunny in 50px range (DogHunting)
void DogWandering::update(Dog* schaap)
{
	cout << "DogWandering" << endl;

	shared_ptr<Vertex> position = schaap->GraphWalker::getPosition();
	vector<shared_ptr<Edge>> edges = position->getNeighbors();

	// Wander
	bool new_position_found = false;
	shared_ptr<Vertex> newposition;

	// Go look for a new location
	int attempt_counter = 0;
	while (!new_position_found) {
		int random_position_int = Utilities::randomInt(0, edges.size() - 1);
		newposition = edges[random_position_int]->getTarget(position);
		if
			(
				!newposition->isWater() &&
				random_position_int % 2 != _lastDirection % 2 ||
				!newposition->isWater() &&
				attempt_counter > 10
		) {
			_lastDirection = random_position_int;
			new_position_found = true;
		}
		else {
			attempt_counter++;
		}
	}
	position->walker = nullptr;
	newposition->walker = schaap->shared_from_this();
	schaap->GraphWalker::setPosition(newposition);

	// Check if there are rabbits nearby
	bool rabbitInRange = schaap->isRabbitInRange();

	// Make Dog thirstier
	schaap->increaseThirstCount();

	if (schaap->isThirsty()) {
		schaap->changeState(DogStates::DRINKING);
	}
	else if (rabbitInRange) {
		schaap->changeState(DogStates::HUNTING);
	}


	cout << "X: " << newposition->getX() << " Y: " << newposition->getY() << endl;
}

DogWandering::~DogWandering()
{
	cout << "Removed DogWandering" << endl;
}