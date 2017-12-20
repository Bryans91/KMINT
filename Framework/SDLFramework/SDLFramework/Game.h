#pragma once
#include "Graph.h"
#include <string>
#include <memory>
#include "FWApplication.h"
#include "GraphWalker.h"
#include "Rabbit.h"



class Game
{
public:
	Game(FWApplication* application);
	~Game();

	void createGraph(std::string filename, int blockWidth, int blockHeight);
	void drawObjects(FWApplication* application);

	void update();

	//Testrabbit
	//int x, int y, float cohesion,float seperation,float alignment,float m_Mass,float m_MaxSpeed,float m_MaxTurnrate
	Rabbit testRabbit = Rabbit(500,500,0,0,0,1,1,1);
private:
	Graph graph;
	std::shared_ptr<GraphWalker>  dog;
	std::shared_ptr<GraphWalker>  mister;
	std::shared_ptr<GraphWalker>  misses;
	FWApplication* application;
};

