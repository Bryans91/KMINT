#include "Vertex.h"

Vertex::Vertex()
{
}


Vertex::~Vertex()
{
}

void Vertex::addNeighbor(std::shared_ptr<Edge> e)
{
	this->neighbors.push_back(e);
}
