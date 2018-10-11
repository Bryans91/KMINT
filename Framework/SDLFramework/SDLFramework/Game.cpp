#include "Game.h"
#include "Human.h"
#include "Utilities.h"
#include "Dog.h"

Game::Game(FWApplication* application)
{
	this->dog = std::shared_ptr<GraphWalker>(new Dog());
	this->misses = std::shared_ptr<GraphWalker>(new Human('F'));
	this->mister = std::shared_ptr<GraphWalker>(new Human('M'));
	this->createGraph("map.txt", 12, 16);
	this->application = application;

	this->application->AddRenderable(&this->testRabbit);
}


Game::~Game()
{
}


void Game::createGraph(std::string filename, int blockWidth, int blockHeight)
{
	this->graph = Graph(blockWidth, blockHeight);
	this->graph.loadMap(filename, this->dog, this->mister, this->misses);
}

void Game::update(int frame)
{
	// Assuming that 60 frames per second
	if (frame % 15 == 0) {
		this->dog->update(frame);
	}
	if (frame % 30 == 0) {
		this->misses->update(frame);
		this->mister->update(frame);
	}
}

void Game::drawObjects(FWApplication* application)
{
	//std::cout << this->testRabbit.DistanceTo(0,0);

	this->graph.drawMap(application);
	this->testRabbit.draw(application);
}

