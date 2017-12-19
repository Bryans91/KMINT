#pragma once
#include "Graph.h"
#include <string>
#include "FWApplication.h"
#include "GraphWalker.h"
class Game
{
public:
	Game();
	~Game();

	void createGraph(std::string filename, int blockWidth, int blockHeight,GraphWalker meneer,GraphWalker mevrouw);
	void drawObjects(FWApplication application);

private:
	Graph graph;
	GraphWalker dog;
	GraphWalker meneer;
	GraphWalker mevrouw;

};

