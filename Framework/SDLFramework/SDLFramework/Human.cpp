#include "Human.h"
#include <iostream>
#include "Vertex.h"
#include "Edge.h"

#include "HumanWandering.h"
//#include "HumanFrozen.h"
//#include "HumanPhotographing.h"


Human::Human(char gender)
{
	this->gender = gender;
	GraphWalker::setType('H');

	this->changeState(HumanStates::WANDER);
}

void Human::update(int frame)
{
	// Increase timer
	if (frame % 2) {
		increaseSecondCount();
	}
	_state->update(this);
}

//Change state
void Human::changeState(HumanStates newState)
{
	switch (newState) {
	case WANDER:
		_state = make_shared<HumanWandering>();
		break;
	/*case PHOTOGRAPHING:
		_state = make_shared<HumanPhotographing>();
		break;
	case FROZEN:
		_state = make_shared<HumanFrozen>();
		break;*/
	}
}

void Human::increaseSecondCount() {
	_seconds++;
}

Human::~Human()
{
}
