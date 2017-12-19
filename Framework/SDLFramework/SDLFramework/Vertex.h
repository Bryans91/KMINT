#pragma once
#include "GraphWalker.h"
class Vertex
{
public:
	Vertex();
	~Vertex();



	
	//getters/setters
	void setWalker(GraphWalker w) { this->walker = w; }
	GraphWalker getWalker() const { return this->walker; }

	void setGrass(bool w) { this->grass = w; }
	bool isGrass() const { return this->grass; }

	void setCave(const bool w) { this->cave = w; }
	bool isCave() const { return this->cave; }

	void setWater(bool w) { this->water = w; }
	bool isWater() const { return this->water; }
private:
	bool water = false;
	bool cave = false;
	bool grass = false;
	
	GraphWalker walker;
};

