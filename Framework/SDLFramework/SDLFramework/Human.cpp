#include "Human.h"



Human::Human(char gender)
{
	this->gender = gender;
	GraphWalker::setType('H');
}


Human::~Human()
{
}
