#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include <string>

class Graph
{
public:
	Graph();
	Graph(int blockWidth,int blockHeight);
	~Graph();
	
	void loadMap(std::string filename, GraphWalker meneer, GraphWalker mevrouw);
	void drawMap(FWApplication application);

private:
	void setEdges();

	Vertex topLeft;
	std::vector<Vertex> verteces;
	int x;
	int y;
	int blockHeight;
	int blockWidth;
	
};

