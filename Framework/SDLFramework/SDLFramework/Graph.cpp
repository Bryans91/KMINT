#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include "Human.h"

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
}

void Graph::drawMap(FWApplication* application)
{
	int startPosX = 0;
	int startPosY = 0;

	int print = 0;
	for each(std::shared_ptr<Vertex> v in this->verteces) {
		if (print == this->x) {
			print = 0;
			startPosX = 0;
			startPosY += this->blockHeight;
		}

		if (v->isWater()) application->SetColor(Color(0, 0, 200, 255));
		else if (v->isCave()) application->SetColor(Color(100, 100, 100, 255));
		else if (v->walker != nullptr){
			if (v->walker->getType() == 'H') {
				//cast to human
				std::shared_ptr<Human> human = std::dynamic_pointer_cast<Human>(v->walker);
				if (human->gender == 'M') {
					application->SetColor(Color(200, 0, 0, 255)); //MALE: 200 0 0 255  // FEMALE 255 0 255 255
				}
				else if (human->gender == 'F') {
					application->SetColor(Color(255, 0, 255, 255));
				}
			}
			else if (v->walker->getType() == 'D') {
				//DOG!!!
			}
		}
		else if (v->isGrass()) application->SetColor(Color(0, 200, 0, 255));
		
		application->DrawRect(startPosX,startPosY, this->blockWidth, this->blockHeight, true);

		startPosX += this->blockWidth;
		print++;
	}
	
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
