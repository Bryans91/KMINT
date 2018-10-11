#include "DogState.h"

class Dog;
class DogState; // ??
class DogDrinking : public DogState
{
public:
	DogDrinking();
	~DogDrinking();
	virtual void update(Dog* schaap);
protected:
private:
	shared_ptr<GraphWalker> the_chosen_one;
};