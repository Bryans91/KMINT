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
		//int x, int y, float cohesion, float seperation, float alignment, float m_Mass, float m_MaxSpeed, float m_MaxTurnrate
		this->liveRabbits->push_back(new Rabbit(200 + (i * 10), 500,/* Coh */ 1 ,/* sep */ 0.00075 , /* ali */1 , 1, 25, 0.5));
		if (i == 5)this->liveRabbits->at(i)->leader = true;
	}
	int i = 0;
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

