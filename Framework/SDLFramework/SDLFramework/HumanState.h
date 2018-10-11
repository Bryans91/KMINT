#ifndef _HUMANSTATE_H_
#define _HUMANSTATE_H_

#include "Human.h"

class Human;
class HumanState
{
public:
	virtual void update(Human* human) = 0;
	~HumanState();
protected:
	HumanState();
private:
};

#endif