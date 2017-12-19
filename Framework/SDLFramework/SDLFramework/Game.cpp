#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::createGraph(std::string filename, int blockWidth, int blockHeight)
{
	this->graph = Graph(filename, blockWidth, blockHeight);
}

void Game::drawObjects(FWApplication application)
{
}
