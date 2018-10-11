#pragma once
#include <memory>
#include <iostream>
#include "GraphWalker.h"
#include "HumanState.h"

using namespace std;

class HumanState;

enum HumanStates {
	WANDER,
	PHOTOGRAPHING,
	FROZEN
};

class Human :
	public GraphWalker
{
public:
	Human(char gender);
	char gender;

	void update(int frame);

	void changeState(HumanStates newState);

	bool isThirsty();
	void increaseSecondCount();
	int getSecondCount() { return _seconds; };

	bool isRabbitInRange();

	int getClosestRabbit();

	int getDrankCount();
	void increaseDrankCount();

	virtual ~Human();
private:
	// Current state
	shared_ptr<HumanState> _state;

	// Counting seconds
	int _seconds = 0;

	// Targetted rabbit
	//Rabbit closestRabbit;
	int closestRabbitDistance;
};