#pragma once
#include "GraphWalker.h"
class Vertex
{
public:
	Vertex();
	~Vertex();

	bool operator==(const Vertex& rhs) const {
		return this->x == rhs.x && this->y == rhs.y;
	}
	
	//getters/setters
	void setWalker(GraphWalker w) { this->walker = w; }
	GraphWalker getWalker() const { return this->walker; }

	void setGrass(bool w) { this->grass = w; }
	bool isGrass() const { return this->grass; }

	void setCave(const bool w) { this->cave = w; }
	bool isCave() const { return this->cave; }

	void setWater(bool w) { this->water = w; }
	bool isWater() const { return this->water; }

	void setX(int x) { this->x = x; }
	bool getX() const { return this->x; }

	void setY(int y) { this->y = y; }
	bool getY() const { return this->y; }

private:
	bool water = false;
	bool cave = false;
	bool grass = false;

	int x;
	int y;
	
	GraphWalker walker;
};

