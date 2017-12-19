#include "Game.h"



Game::Game()
{
	this->createGraph("map.txt", 10, 10, this->meneer, this->mevrouw);
}


Game::~Game()
{
}

void Game::createGraph(std::string filename, int blockWidth, int blockHeight, GraphWalker meneer, GraphWalker mevrouw)
{
	this->graph = Graph(blockWidth, blockHeight);
	this->graph.loadMap(filename, meneer, mevrouw);
}

void Game::drawObjects(FWApplication application)
{
}
