#ifndef _DOGSTATE_H_
#define _DOGSTATE_H_

#include "Dog.h"

class Dog;
class DogState
{
	public:
		virtual void update(Dog* schaap) = 0;
		~DogState();
	protected:
		DogState();
	private:
};

#endif