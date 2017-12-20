#include "Game.h"

Game::Game()
{
	this->misses = std::shared_ptr<GraphWalker>(new GraphWalker);
	this->mister = std::shared_ptr<GraphWalker>(new GraphWalker);
	this->createGraph("map.txt", 12, 16);
	
}


Game::~Game()
{
}

void Game::createGraph(std::string filename, int blockWidth, int blockHeight)
{
	this->graph = Graph(blockWidth, blockHeight);
	this->graph.loadMap(filename, this->mister, this->misses);
}

void Game::drawObjects(FWApplication* application)
{
	this->graph.drawMap(application);
}
