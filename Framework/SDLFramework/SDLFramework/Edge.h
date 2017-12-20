#pragma once
#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"
#include <memory>
class Vertex;

class Edge
{
public:
	Edge();
	~Edge();

	std::shared_ptr<Vertex> getTarget(Vertex current);

	std::shared_ptr<Vertex> A;
	std::shared_ptr<Vertex> B;

private:
	
};

#endif
