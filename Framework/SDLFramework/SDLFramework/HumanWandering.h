#pragma once
#include "HumanState.h"

class Human;
class HumanState; // ??
class HumanWandering : public HumanState
{
public:
	HumanWandering();
	~HumanWandering();
	virtual void update(Human* human);
protected:
private:
	int _lastDirection = -5;
};