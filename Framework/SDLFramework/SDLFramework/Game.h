#pragma once
#include "Graph.h"
#include <string>
#include <memory>
#include "FWApplication.h"
#include "GraphWalker.h"
#include "Rabbit.h"
#include <vector>


class Game
{
public:
	Game(FWApplication* application);
	~Game();

	void createGraph(std::string filename, int blockWidth, int blockHeight);
	void drawObjects(FWApplication* application);

	void update();
	std::shared_ptr<std::vector<Rabbit*>> liveRabbits;
private:
	Graph graph;
	std::shared_ptr<GraphWalker>  dog;
	std::shared_ptr<GraphWalker>  mister;
	std::shared_ptr<GraphWalker>  misses;
	FWApplication* application;
};

