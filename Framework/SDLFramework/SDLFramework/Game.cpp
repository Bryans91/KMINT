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
	
	this->liveRabbits = std::make_shared<std::vector<Rabbit*>>();

	//generate rabbits
	for (int i = 0; i < 10; i++) {
		this->liveRabbits->push_back(new Rabbit(200 + (i * 10), 500, 1, -1, -0.5, 1, 1, 1));
	}
	
	//set rabbit collections
	for (Rabbit* rabbit : *this->liveRabbits) {
		this->application->AddRenderable(rabbit);
		rabbit->setRabbits(this->liveRabbits);
	}

}


Game::~Game()
{
}


void Game::createGraph(std::string filename, int blockWidth, int blockHeight) 
{
	this->graph = Graph(blockWidth, blockHeight);
	this->graph.loadMap(filename, this->dog, this->mister, this->misses);
}

void Game::drawObjects(FWApplication* application)
{
	
	this->graph.drawMap(application);
	for (Rabbit* rabbit : *this->liveRabbits) {
		rabbit->draw(application);
	}
}

