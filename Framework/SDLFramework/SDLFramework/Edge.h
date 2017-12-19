#pragma once
#include "Vertex.h"
class Edge
{
public:
	Edge();
	~Edge();

	Vertex getTarget(Vertex current);

private:
	Vertex A;
	Vertex B;
};

