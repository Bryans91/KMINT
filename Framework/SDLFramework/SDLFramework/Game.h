#pragma once
#include "Graph.h"
#include <string>
#include "FWApplication.h"
class Game
{
public:
	Game();
	~Game();

	void createGraph(std::string filename, int blockWidth, int blockHeight);
	void drawObjects(FWApplication application);

private:
	Graph graph;

};

