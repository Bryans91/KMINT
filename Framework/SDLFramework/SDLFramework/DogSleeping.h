#include "DogState.h"

class Dog;
class DogState; // ??
class DogSleeping : public DogState
{
public:
	DogSleeping();
	~DogSleeping();
	virtual void update(Dog* schaap);
protected:
private:
};