#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>



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

void Graph::loadMap(std::string filename, GraphWalker mister, GraphWalker misses)
{
	int x = 0;
	int y = 0;

	std::ifstream in(filename);
	std::string str;
	//per line
	while (std::getline(in, str)) {
		
		//per char in line
		for (char& c : str) {
			if (y == 0) x++;
			Vertex temp;
			switch (c) {
				case '~':
					//water
					temp.setWater(true);
					break;
				case 'M':
					//meneer janssen
					temp.setWalker(mister);
					temp.setGrass(true);
					break;
				case 'V':
					//mevrouw janssen
					temp.setWalker(misses);
					temp.setGrass(true);
					break;
				case 'O':
					//cave
					temp.setCave(true);
					break;
				default:
					//gras
					temp.setGrass(true);
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
	for each(Vertex v in this->verteces) {
		if (print == x) {
			print = 0;
			std::cout << "\n";
		}
		
		if (v.isWater()) std::cout << "~";
		if (v.isCave()) std::cout << "O";
		if (v.isGrass()) std::cout << "X";
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
}
