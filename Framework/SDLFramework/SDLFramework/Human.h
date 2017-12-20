#pragma once
#include "GraphWalker.h"
class Human :
	public GraphWalker
{
public:
	char gender;

	Human(char gender);
	virtual ~Human();
};

