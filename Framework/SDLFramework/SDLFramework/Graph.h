#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include "Edge.h"
#include <string>

class Graph
{
public:
	Graph();
	Graph(int blockWidth,int blockHeight);
	~Graph();
	
	void loadMap(std::string filename, std::shared_ptr<GraphWalker> dog,  std::shared_ptr<GraphWalker> mister, std::shared_ptr<GraphWalker>  misses);
	void drawMap(FWApplication* application);

private:
	void setEdges(std::shared_ptr<Vertex> prev, std::shared_ptr<Vertex> current);
	void setLinks(std::shared_ptr<Vertex> prev , std::shared_ptr<Vertex> current);
	std::shared_ptr<Vertex> topLeft;
	std::vector<std::shared_ptr<Vertex>> verteces;
	int x;
	int y;
	int blockHeight;
	int blockWidth;
	
};

