#include "DogState.h"

class Dog;
class DogState; // ??
class DogWandering : public DogState
{
public:
	DogWandering();
	~DogWandering();
	virtual void update(Dog* schaap);
protected:
private:
};