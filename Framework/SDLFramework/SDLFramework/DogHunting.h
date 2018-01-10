#include "DogState.h"

class Dog;
class DogState; // ??
class DogHunting : public DogState
{
public:
	DogHunting();
	~DogHunting();
	virtual void update(Dog* schaap);
protected:
private:
};