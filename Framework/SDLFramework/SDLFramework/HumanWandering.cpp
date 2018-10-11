#include <iostream>
#include "HumanWandering.h"
#include "Vertex.h"
#include "Edge.h"
#include "GraphWalker.h"
#include "Utilities.h"

using namespace std;

HumanWandering::HumanWandering()
{}

void HumanWandering::update(Human* human)
{
	cout << "HumanWandering" << endl;

	shared_ptr<Vertex> position = human->GraphWalker::getPosition();
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
	newposition->walker = human->shared_from_this();
	human->GraphWalker::setPosition(newposition);

	// Check if there are rabbits nearby
	//bool rabbitInRange = human->isRabbitInRange();

	if (human->getSecondCount() % 20 == 0) {
		human->changeState(HumanStates::PHOTOGRAPHING);
		cout << "ZOMG" << endl << human->getSecondCount() << endl << "ZOMG" << endl;
	}

	/*
	else if (rabbitInRange) {
		human->changeState(HumanStates::FROZEN);
	}*/


	cout << "X: " << newposition->getX() << " Y: " << newposition->getY() << endl;
}

HumanWandering::~HumanWandering()
{
	cout << "Removed HumanWandering" << endl;
}