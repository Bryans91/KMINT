#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include <string>

class Graph
{
public:
	Graph();
	Graph(std::string filename, int blockWidth,int blockHeight);
	~Graph();
	
	Vertex loadMap(std::string filename);
	void drawMap(FWApplication application);

private:
	Vertex topLeft;
	int x;
	int y;
	int blockHeight;
	int blockWidth;
	
};

