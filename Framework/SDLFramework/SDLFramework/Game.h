#pragma once
#include "Graph.h"
#include <string>
#include "FWApplication.h"
#include "GraphWalker.h"
#include <memory>

class Game
{
public:
	Game();
	~Game();

	void createGraph(std::string filename, int blockWidth, int blockHeight);
	void drawObjects(FWApplication* application);

private:
	Graph graph;
	std::shared_ptr<GraphWalker>  dog;
	std::shared_ptr<GraphWalker>  mister;
	std::shared_ptr<GraphWalker>  misses;

};

