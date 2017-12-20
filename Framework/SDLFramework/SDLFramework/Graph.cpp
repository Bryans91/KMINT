#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>



Graph::Graph()
{
}

Graph::Graph(int blockWidth ,int blockHeight)
{
	this->blockHeight = blockHeight;
	this->blockWidth = blockWidth;
}

Graph::~Graph()
{
}

void Graph::loadMap(std::string filename, std::shared_ptr<GraphWalker>  mister, std::shared_ptr<GraphWalker> misses)
{
	int x = 0;
	int y = 0;

	std::ifstream in(filename);
	std::string str;

	bool mrset = false;
	bool msset = false;
	//per line
	while (std::getline(in, str)) {
		
		//per char in line
		for (char& c : str) {

			if (y == 0) x++;
			std::shared_ptr<Vertex> temp (new Vertex());
			temp->setX(x);
			temp->setY(y);

			switch (c) {
				case '~':
					//water
					temp->setWater(true);
					break;
				case 'M':
					//meneer janssen
					if(!mrset) temp->walker = mister;
					mrset = true;
					temp->setGrass(true);
					break;
				case 'V':
					//mevrouw janssen
					if(!msset) temp->walker = misses;
					msset = true;
					temp->setGrass(true);
					break;
				case 'O':
					//cave
					temp->setCave(true);
					break;
				default:
					//gras
					temp->setGrass(true);
					break;
			}
			this->verteces.push_back(temp);
			if (x == 0 && y == 0) this->topLeft = temp;
		}

		y++;
	}

	this->x = x;
	this->y = y;
	
	int print = 0;
	for each(std::shared_ptr<Vertex> v in this->verteces) {
		if (print == x) {
			print = 0;
			std::cout << "\n";
		}
		
		if (v->isWater()) std::cout << "~";
		if (v->isCave()) std::cout << "O";
		if (v->walker != nullptr) std::cout << "W";
		else if (v->isGrass()) std::cout << "X";
		//mr mss print TODO
		
		print++;
	}


	this->setEdges();
}

void Graph::drawMap(FWApplication application)
{
	
}

void Graph::setEdges()
{
	Edge e;
	e.A = this->verteces[0];
	e.B = this->verteces[1];

	for each(std::shared_ptr<Vertex> vert in this->verteces) {
		

	}
}
