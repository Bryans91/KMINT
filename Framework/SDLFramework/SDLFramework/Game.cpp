#include "Game.h"



Game::Game()
{
	this->createGraph("map.txt", 10, 10, this->meneer, this->mevrouw);
}


Game::~Game()
{
}

void Game::createGraph(std::string filename, int blockWidth, int blockHeight)
{
	this->graph = Graph(blockWidth, blockHeight);
	this->graph.loadMap(filename, this->mister, this->misses);
}

void Game::drawObjects(FWApplication application)
{
}
