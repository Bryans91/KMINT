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
	int xLength = 0;
	int y = 0;
	

	std::ifstream in(filename);
	std::string str;

	bool mrset = false;
	bool msset = false;
	std::shared_ptr<Vertex> prev = nullptr;
	std::shared_ptr<Vertex> prevRow = nullptr;
	int vertecesCount = 0;
	//per line
	while (std::getline(in, str)) {
		if (y == 1) xLength = x;
		x = 0;
		//per char in line
		for (char& c : str) {
			//create temp vertex
			std::shared_ptr<Vertex> temp (new Vertex());

			//set topleft of graph
			if (x == 0 && y == 0) {
				this->topLeft = temp;
				prevRow = temp;
			}

			// leftright neighbor and edge
			if (prev != nullptr) {
				//std::cout << "RIGHTLEFT";
				setLinks(prev, temp);
				if(x > 0) this->setEdges(prev, temp);
			}
			//set previous in linked list
			prev = temp;
	
			// add north south edges
			if (prevRow != nullptr && y > 0) {
				this->setEdges(prevRow, temp);
				prevRow = prevRow->next;
			}

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
					vertecesCount;
					break;
				default:
					//gras
					temp->setGrass(true);
					break;
			}
			this->verteces.push_back(temp);
			x++;
			vertecesCount++;
		}
		y++;
	}

	this->x = xLength;
	this->y = y;
	

	//cave == x30 y19  / 1246 nr
	//test strings vector
	int print = 0;
	for each(std::shared_ptr<Vertex> v in this->verteces) {
		if (print == this->x) {
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
	

	std::cout << "\n\n\n\n";

	//checking neighbors
	//expecting
	std::shared_ptr<Vertex> test = this->verteces[1245];
	for each(std::shared_ptr<Edge> e in test->getNeighbors()) 
	{
		std::shared_ptr<Vertex> v = e->getTarget(test);
		if (v->isWater()) std::cout << "~";
		if (v->isCave()) std::cout << "O";
		if (v->walker != nullptr) std::cout << "W";
		else if (v->isGrass()) std::cout << "X";
	}


	//test strings Linked list
	/*std::shared_ptr<Vertex> v = this->topLeft;
	while (v != nullptr) {

		if (v->isWater()) std::cout << "~";
		if (v->isCave()) std::cout << "O";
		if (v->walker != nullptr) std::cout << "W";
		else if (v->isGrass()) std::cout << "X";
		v = v->next;
	}*/
}

void Graph::drawMap(FWApplication application)
{
	
}

void Graph::setEdges(std::shared_ptr<Vertex> prev, std::shared_ptr<Vertex> current)
{
	//create edge
	std::shared_ptr<Edge> edge(new Edge());
	//set optional edge things
	edge->A = prev;
	edge->B = current;
	prev->addNeighbor(edge);
	current->addNeighbor(edge);

}

void Graph::setLinks(std::shared_ptr<Vertex> prev, std::shared_ptr<Vertex> current)
{
	prev->next = current;
}
