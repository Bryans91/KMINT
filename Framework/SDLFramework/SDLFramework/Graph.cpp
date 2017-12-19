#include "Graph.h"
#include <fstream>
#include <iostream>



Graph::Graph()
{
}

Graph::Graph(std::string filename, int blockWidth ,int blockHeight)
{
	this->blockHeight = blockHeight;
	this->blockWidth = blockWidth;
	this->loadMap(filename);
}

Graph::~Graph()
{
}

Vertex Graph::loadMap(std::string filename)
{
	std::ifstream in(filename);
	std::string str;
	while (std::getline(in, str)) {
		// output the line
		std::cout << str << std::endl;

		// now we loop back and get the next line in 'str'
	}


	//return first of list
	return Vertex();
}

void Graph::drawMap(FWApplication application)
{
}
