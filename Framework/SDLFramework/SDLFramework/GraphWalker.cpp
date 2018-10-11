#include "GraphWalker.h"
#include "Edge.h"
#include <iostream>
#include "memory"

using namespace std;

GraphWalker::GraphWalker()
{
}

void GraphWalker::setPosition(shared_ptr<Vertex> position = nullptr)
{
	if (position != nullptr) {
		this->position = position;
		return;
	}
	return;
}


GraphWalker::~GraphWalker()
{
}