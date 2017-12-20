#include "Edge.h"

Edge::Edge()
{
}


Edge::~Edge()
{
}

std::shared_ptr<Vertex> Edge::getTarget(std::shared_ptr<Vertex> current)
{
	if (current == this->A) return this->B;
	return this->A;
}
