#include "Edge.h"

Edge::Edge()
{
}


Edge::~Edge()
{
}

std::shared_ptr<Vertex> Edge::getTarget(Vertex current)
{
	if (current == this->A) return this->A;
	return this->B;
}
